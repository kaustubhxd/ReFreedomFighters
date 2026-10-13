"""specs_s10.py - inline session batch 10 (Haiku, overnight): 0x647f70, 0x640cc0, 0x648690, 0x648750."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x647f70 thiscall: (this). Null this (about 10%) returns 0; otherwise returns this.
def _rec(c):
    if c.rng.random() < 0.1:
        return [0]
    return [_rnd(c, 0x40)]


S(0x647f70, 'initRecord (unknown) thiscall', 'thiscall', None, ret='eax', gen=_rec,
  note='batch10; null this returns 0')


# 0x640cc0 thiscall: (this). Object of 0x200 bytes so the loop writes stay inside it.
S(0x640cc0, 'initBlock (unknown) thiscall', 'thiscall', None, ret='eax',
  gen=lambda c: [_rnd(c, 0x200)], note='batch10; vtable word 0x6c281c written first')


# 0x648690 and 0x648750 thiscall: (this). Index 0..7 or 0xffff; nodes are 20 bytes apart.
def _adv(c):
    o = _rnd(c, 0x200)
    c.emu.w16(o + 2, 0xffff if c.rng.random() < 0.2 else c.rng.randint(0, 7))
    return [o]


S(0x648690, 'advanceSlot20 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_adv,
  note='batch10; marker 0xffff1204')
S(0x648750, 'advanceSlot20b (unknown) thiscall', 'thiscall', None, ret='eax', gen=_adv,
  note='batch10; marker 0xffff1205')
