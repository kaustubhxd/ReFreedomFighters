"""specs_s5741.py - unclaimed-57, band batch 41: 0x5de900 (GUESS), the 40-byte record append (thiscall, one stack arg, ret 4, no calls).
The count is 0 to 6. The record's dword at +0xc points at the destination's +0x10 slot in half the cases (the skipped-store branch), and
at a random value otherwise (both branches run). Heap addresses are the same in both runs, so the pointer compare is portable."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _app(c):
    obj = _rnd(c, 0x400)
    cnt = c.rng.randrange(0, 7)
    c.emu.w32(obj, cnt)
    rec = _rnd(c, 0x40)
    dest = obj + 40 * cnt + 0x10
    if c.rng.random() < 0.5:
        c.emu.w32(rec + 0xc, dest)
    return [obj, rec]


S(0x5de900, 'unnamed_5de900 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_app,
  note='unclaimed-57 band batch 41; 40-byte record append; no calls; pointer-equality branch both ways')
