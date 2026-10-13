"""specs_s16.py - inline session batch 16 (Haiku, overnight): 0x582740, 0x5bf850, 0x644e30."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    return [_rnd(c, 0x80), _rnd(c, 0x80)]


S(0x582740, 'copyRecA (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='batch16; unaligned dword and word copies')
S(0x5bf850, 'copyRecB (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='batch16; word and dword copies at odd offsets')


# 0x644e30 thiscall: (this, x). Argument is 0, equal to the dword at +0x29, or random (the usual case).
def _delta(c):
    r = c.rng
    o = _rnd(c, 0x40)
    field29 = r.getrandbits(32)
    c.emu.w32(o + 0x25, r.getrandbits(32))
    c.emu.w32(o + 0x29, field29)
    pick = r.random()
    if pick < 0.1:
        x = 0
    elif pick < 0.25:
        x = field29
    else:
        x = r.getrandbits(32)
    return [o, x]


S(0x644e30, 'scaleDelta (unknown) thiscall', 'thiscall', None, ret='eax', gen=_delta,
  note='batch16; the shift and the +1 rounding come from the original code')
