"""specs_s2723.py - unclaimed-27 batch 23 (gap band): FUN_59a280 (GUESS, thiscall, void). The callees 0x59a8f0 and 0x59a2d0 are
HOOKED (stubs, NOT verified): each counts its calls in a heap record. The object is 0x2000 bytes (stores reach +0x1d17)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f280(c):
    rec = c.emu.alloc(0x10, 4)   # +0 0x59a8f0 calls, +4 0x59a2d0 calls

    def h8f(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.ret(argbytes=0)

    def h2d(e, r, rec=rec):
        e.w32(rec + 4, (e.r32(rec + 4) + 1) & 0xffffffff)
        e.ret(argbytes=0)

    c.emu.hook(0x59a8f0, h8f)
    c.emu.hook(0x59a2d0, h2d)
    o = _rnd(c, 0x2000)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x59a280, 'FUN_59a280 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f280,
  note='gap band batch 23; 0x59a8f0 and 0x59a2d0 are hooks (stubs)')
