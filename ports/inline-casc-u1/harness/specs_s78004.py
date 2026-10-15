"""Spec for batch 78004: 0x5d0f10 stick motion update."""
import math, struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _fb(x): return struct.unpack('<I', struct.pack('<f', x))[0]

def _pow(e, r):
    from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1
    x = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM0) & ((1<<64)-1)))[0]
    y = struct.unpack('<d', struct.pack('<Q', e.mu.reg_read(UC_X86_REG_XMM1) & ((1<<64)-1)))[0]
    try: z = float(math.pow(x, y))
    except (OverflowError, ValueError): z = float('inf')
    e.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    e.ret()

def _g5d0f10(c):
    clear_hooks(c)
    r, em = c.rng, c.emu
    em.stub_import('_libm_sse2_pow_precise', _pow)
    hook_rec(c, 0x7003b0, 0, pop=0, ret=lambda e, k: e.reg('eax'))
    selfp = rnd(c, 0xe40)
    for off in range(0xa40, 0xe20, 4):
        em.w32(selfp+off, _fb(r.uniform(-3.0, 3.0)))
    for off in (0xb1f, 0xb23):
        em.w32(selfp+off, r.choice([0, 0, 0x80000000, _fb(r.uniform(-1,1)), _fb(r.uniform(-1,1))]))
    em.w32(selfp+0xa9e, r.choice([0xbf9c61aa, 0xbfa78d36]))
    em.w32(selfp+0xaa2, r.choice([0x3f860a92, 0x3fa78d36]))
    em.w32(selfp+0xadd, r.choice([0x3f800000, 0x3e800000, 0x3dcccccd]))
    for off in (0xa70, 0xa71, 0xb45, 0xab6): em.w8(selfp+off, r.choice([0,0,1]))
    em.w32(selfp+0xad5, r.choice([5,1,4]))
    so = rnd(c, 0x80)
    em.w32(0x70039c, so)
    em.w32(so+0x48, _fb(r.uniform(0.0, 0.1)))
    return [selfp]

S(0x5d0f10, 'GUESS camera stick motion update', 'thiscall', None, ret=None, gen=_g5d0f10)
