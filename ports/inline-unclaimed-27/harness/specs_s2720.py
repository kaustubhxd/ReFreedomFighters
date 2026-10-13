"""specs_s2720.py - unclaimed-27 batch 20 (gap band): FUN_589560 (GUESS, thiscall, void). The object holds begin (+0) and end (+8);
begin and end are chosen so that (end - begin) >> 6 is 0 in about a third of cases, and otherwise a small positive or negative
count. The callee 0x54f870 is HOOKED (stub, NOT verified): it records its two arguments and counts calls. The SEH frame is not
modelled (no exceptions in this harness)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f560(c):
    rec = c.emu.alloc(0x20, 4)   # +0 call count, +4 begin, +8 size

    def h(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.arg32(0))
        e.w32(rec + 8, e.arg32(1))
        e.ret(argbytes=8)

    c.emu.hook(0x54f870, h)
    o = _rnd(c, 0x800)
    begin = c.emu.alloc(0x2000, 64)
    k = c.rng.choice([0, 0, 1, 2, -1, -3, 5])
    end = (begin + (k << 6)) & 0xffffffff
    if c.rng.random() < 0.15:
        end = c.rng.getrandbits(32)
    c.emu.w32(o + 0, begin)
    c.emu.w32(o + 8, end)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x589560, 'FUN_589560 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f560,
  note='gap band batch 20; 0x54f870 is a hook (stub); SEH frame not modelled')
