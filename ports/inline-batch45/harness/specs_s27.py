"""specs_s27.py - inline session batch 27 (Haiku, overnight): 0x4ec720, 0x5248e0, 0x524930."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x4ec720 thiscall, one dword arg. The count byte at +0x1c is 0 to 7; the entries at +0 are small values so hits happen.
def _has(c):
    r = c.rng
    obj = _rnd(c, 0x40)
    n = r.randint(0, 7)
    c.emu.w32(obj + 0x1c, 0)
    vals = [r.randint(1, 9) for _ in range(8)]
    for i in range(8):
        c.emu.w32(obj + 4 * i, vals[i])
    c.emu.wbytes(obj + 0x1c, bytes([n]))
    return [obj, r.randint(1, 9)]


S(0x4ec720, 'hasEntry (unknown) thiscall', 'thiscall', None, ret='al', gen=_has,
  note='batch27; linear search over count dwords at +0; count byte at +0x1c')


# 0x5248e0 and 0x524930: one float arg, zero in about a fifth of the cases.
def _tune(c):
    r = c.rng
    obj = _rnd(c, 0x20)
    if r.random() < 0.2:
        arg = 0.0
    else:
        arg = c.fv()
    return [obj, F(arg)]


S(0x5248e0, 'setTuningA (unknown) thiscall', 'thiscall', None, ret=None, gen=_tune,
  note='batch27; exact 0.0 becomes 50.0; the 0.1f branch at +0x14 is unreachable (the constant is not 0)')

S(0x524930, 'setTuningB (unknown) thiscall', 'thiscall', None, ret=None, gen=_tune,
  note='batch27; exact 0.0 becomes 30.0; the 0.1f branch at +0x14 is unreachable (the constant is not 0)')
