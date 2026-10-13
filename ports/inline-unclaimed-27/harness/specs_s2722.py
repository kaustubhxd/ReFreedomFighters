"""specs_s2722.py - unclaimed-27 batch 22 (gap band): FUN_5895b0 (GUESS, thiscall, void). Its callee 0x63418c is HOOKED (a stub,
NOT verified): it records its four arguments and counts calls, then returns with ret 0x10. The SEH frame is not modelled (no
exceptions in this harness)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f5b0(c):
    rec = c.emu.alloc(0x20, 4)   # +0 call count, +4..+0x10 the four arguments

    def h(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        for i in range(4):
            e.w32(rec + 4 + 4 * i, e.arg32(i))
        e.ret(argbytes=16)

    c.emu.hook(0x63418c, h)
    o = _rnd(c, 0x800)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5895b0, 'FUN_5895b0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f5b0,
  note='gap band batch 22; 0x63418c is a hook (stub); SEH frame not modelled')
