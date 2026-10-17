"""specs_s242024.py - Sonnet-w4b hand specs."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g40c5c0(c):
    import math
    from unicorn.x86_const import UC_X86_REG_EIP
    clear_hooks(c)
    r = c.rng
    em = c.emu
    code = bytes([0x83, 0xEC, 0x10, 0xD9, 0x3C, 0x24, 0x66, 0x8B, 0x04, 0x24, 0x66, 0x89, 0x44, 0x24, 0x02,
                  0x66, 0x81, 0x4C, 0x24, 0x02, 0x00, 0x0C, 0xD9, 0x6C, 0x24, 0x02, 0xDF, 0x7C, 0x24, 0x08,
                  0xD9, 0x2C, 0x24, 0x8B, 0x44, 0x24, 0x08, 0x8B, 0x54, 0x24, 0x0C, 0x83, 0xC4, 0x10, 0xC3])
    ft = em._alloc_stub_code(code)
    em.stub_import('_ftol', lambda e, rr: e.mu.reg_write(UC_X86_REG_EIP, ft))
    ctx = rnd(c, 0x20); ob = rnd(c, 0x40); T = rnd(c, 0x40); P = rnd(c, 0x20)
    em.w32(ctx, r.choice([0, 1, 5])); em.w32(ctx + 4, ob); em.w32(ob + 0x1c, T)
    for k in range(8): em.w32(T + 4 * k, r.choice([0, 1, 2, 3, 8, 15, 20, 21, -2 & 0xffffffff]))
    pidx = rnd(c, 8); em.w32(pidx, r.randrange(0, 8))
    em.w32(P, r.getrandbits(32)); em.w32(P + 4, r.choice([8000, 16000, 22050, 44100, 1, 100000]))
    em.w32(P + 8, r.choice([1, 2, 3, 5, 8, 20]))
    cb = rnd(c, 0x40)
    for k in range(0x34): em.wbytes(cb + k, b'\0')
    mb = [rnd(c, 0x100), rnd(c, 0x100)]
    hook_rec(c, 0x634df4, 2, ret=cb, pop=0)
    hook_rec(c, 0x634d58, 1, ret=lambda emu, k: mb[k % 2], pop=0)
    hook_rec(c, 0x407980, 3, pop=0)
    def fl(emu, k):
        v = struct.unpack('<d', struct.pack('<II', emu.arg32(0), emu.arg32(1)))[0]
        if r.random() < 0.1: return float(r.choice([-1.0, 0.0, 50.0]))
        return float(math.floor(v)) if v == v and abs(v) < 1e15 else v
    hook_rec(c, 0x634dca, 2, pop=0, st0=fl)
    return [ctx, pidx, P]


S(0x40c5c0, 'GUESS hand port', 'cdecl', None, ret='eax', gen=g40c5c0, note='batch242024')
