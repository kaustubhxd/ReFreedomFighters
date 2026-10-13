"""specs_s2726.py - unclaimed-27 batch 26 (gap band): FUN_5855c0 (GUESS, thiscall, void). The callee 0x54f870 is HOOKED (stub, NOT
verified): it records its two arguments and counts calls. begin (+0) and end (+8) are chosen so that (end - begin) / 72 is 0 in
about a third of cases and otherwise a small signed count; sometimes a random pair. SEH not modelled."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f5c0(c):
    rec = c.emu.alloc(0x20, 4)   # +0 call count, +4 begin, +8 size

    def h(e, r, rec=rec):
        e.w32(rec, (e.r32(rec) + 1) & 0xffffffff)
        e.w32(rec + 4, e.arg32(0))
        e.w32(rec + 8, e.arg32(1))
        e.ret(argbytes=8)

    c.emu.hook(0x54f870, h)
    o = _rnd(c, 0x800)
    blk = c.emu.alloc(0x2000, 16)
    k = c.rng.choice([0, 0, 1, 2, -1, -3, 7])
    end = (blk + 72 * k + c.rng.randint(0, 71)) & 0xffffffff if k >= 0 else (blk + 72 * k) & 0xffffffff
    if c.rng.random() < 0.15:
        end = c.rng.getrandbits(32)
    c.emu.w32(o + 0, blk)
    c.emu.w32(o + 8, end)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5855c0, 'FUN_5855c0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_f5c0,
  note='gap band batch 26; 0x54f870 is a hook (stub); SEH frame not modelled')
