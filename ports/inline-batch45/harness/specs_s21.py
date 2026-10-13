"""specs_s21.py - inline session batch 21 (Haiku, overnight): 0x470550, 0x45d2b0, 0x4604f0."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x470550 thiscall: count at +0x8b4, entries at +0x8b8 (the count sits just before the array). Values are small
# integers so that hits are common.
def _remove(c):
    r = c.rng
    obj = _rnd(c, 0x900)
    n = r.randint(0, 6)
    for i in range(n):
        c.emu.w32(obj + 0x8b8 + 4 * i, r.randint(1, 6))
    c.emu.w32(obj + 0x8b4, n)
    return [obj, r.randint(1, 7)]


S(0x470550, 'removeLast (unknown) thiscall', 'thiscall', None, ret=None, gen=_remove,
  note='batch21; the last entry moves into the removed slot; count drops by one')


# 0x45d2b0 thiscall: object +8 -> bound object with three floats at +0x40..+0x48. Stack arg: pointer to three floats.
def _bounds(c):
    obj = _rnd(c, 0x40)
    bo = _rnd(c, 0x60)
    for i in range(3):
        c.emu.wf32(bo + 0x40 + 4 * i, abs(c.fv()))
    c.emu.w32(obj + 8, bo)
    v = c.emu.alloc(12, 4)
    for i in range(3):
        c.emu.wf32(v + 4 * i, c.fv())
    return [obj, v]


S(0x45d2b0, 'withinBounds3 (unknown) thiscall', 'thiscall', None, ret='al', gen=_bounds,
  note='batch21; |v[k]| against three bounds; NaN passes (comisd, ja)')


# 0x4604f0 thiscall: object of 13 floats. Stack args: out (3 floats) and t.
def _cubic(c):
    m = c.emu.alloc(13 * 4, 4)
    for i in range(13):
        c.emu.wf32(m + 4 * i, c.fv())
    out = c.fbuf(3)
    return [m, out, F(c.fv())]


S(0x4604f0, 'evalCubic3 (unknown) thiscall', 'thiscall', None, ret=None, gen=_cubic,
  note='batch21; three Horner cubics in t, one per axis; each result stored before the next axis is read')
