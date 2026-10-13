"""specs_c125.py - climb thread batch 125: ZOnScreenDisplay::MessageAdd (0x5aaa30)."""
from pilot import S
from ckit import obj, rnd, cstr


def _ma(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x700)
    e.w8(self_ + 0x658, r.choice([0, 0, 1, 0x80]))
    tgt = obj(e, 'msgsink', 0x40, {0x14: (2, lambda e, t, a: (0, None, (bytes(e.rbytes(a[0], 24)).split(b'\0')[0], a[1])))})
    e.w32(self_ + 0x638, tgt)
    text = cstr(e, r.choice([b'Hello', b'PickUp', b'']))
    return [self_, text, r.getrandbits(32)]


S(0x5aaa30, 'ZOnScreenDisplay::MessageAdd', 'thiscall', None, ret=None, gen=_ma,
  note='c125; the target object is a logging fake (its slot 0x14 takes the two arguments)')
