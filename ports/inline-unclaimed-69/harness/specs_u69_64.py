"""specs_u69_64.py - area 69, group 64 (slice 8): 0x432b80, a table lookup on the global 0x70039c -> +0x190b (no callees).
Two entries cover 0..0xffff ([0, 0x8000) and [0x8000, 0x10000)), so the scan always stops; v with a high bit set returns at once."""
from pilot import S
from ckit import rnd


def _md(c):
    e = c.emu
    r = c.rng
    g = rnd(c, 0x2000)
    e.w32(0x70039c, g)
    arr = rnd(c, 0x40)
    e.w32(g + 0x190b, arr)
    e.w32(arr, 0)
    e.w32(arr + 0xc, 0x8000)
    e.w32(arr + 0x10, 0x8000)
    e.w32(arr + 0x1c, 0x8000)
    v = r.choice([0, 1, 0x7fff, 0x8000, 0xffff, 0x10000, 0xdead0000 & 0xffffffff, r.randrange(0, 0x10000)])
    return [v]


S(0x432b80, 'makeDeviceIndex432b80 (stdcall, one arg, ret 4)', 'stdcall', None, ret='eax', gen=_md, note='u69 group 64; no callees')
