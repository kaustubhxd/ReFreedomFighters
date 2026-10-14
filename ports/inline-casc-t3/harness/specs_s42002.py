"""specs_s42002.py - batch 42002. 0x4c2e70: pow runs for real; 0x44c230 hooked (this + float arg). Object has a helper object at +0x44 (+0x1c flag, +0x18 -> block)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub
import math
from unicorn.x86_const import UC_X86_REG_XMM0, UC_X86_REG_XMM1


def _fl(r):
    return struct.unpack('<I', struct.pack('<f', r.choice([0.0, -0.0, r.uniform(-50, 50), r.uniform(-1e5, 1e5), 1.0, -1.0, float('nan')])))[0]


def g4c2e70(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x44c230, 1, this=True)

    def pw(em, res_):
        b = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM0) & (2 ** 64 - 1)))[0]
        e = struct.unpack('<d', struct.pack('<Q', em.mu.reg_read(UC_X86_REG_XMM1) & (2 ** 64 - 1)))[0]
        em.calllog.append(('pow', struct.pack('<d', b), struct.pack('<d', e)))
        try:
            y = math.pow(b, e)
        except (ValueError, OverflowError):
            y = float('nan')
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', y))[0])
        em.ret()
    c.emu.stub_import('_libm_sse2_pow_precise', pw)
    blk = rnd(c, 0x100)
    p = rnd(c, 0x40)
    c.emu.w32(p + 0x18, blk)
    c.emu.w32(p + 0x1c, r.choice([0, 1, 1, r.getrandbits(32) | 1]))
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x44, p if r.random() < 0.9 else 0)
    c.emu.w32(me + 0x64, r.choice([0, 1, r.getrandbits(32)]))
    c.emu.w32(me + 0x48, _fl(r))
    c.emu.w32(me + 0x54, _fl(r))
    return [me]


S(0x4c2e70, 'GUESS flag bit, pow-based value, notify helper', 'thiscall', None, ret=None, gen=g4c2e70, note='batch42002')
