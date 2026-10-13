"""specs_s30.py - inline session batch 30 (Haiku, evening): 0x4667e0, 0x467aa0, 0x4e09e0, 0x4de7a0, 0x594f10."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cb(c):
    return [_rnd(c, 0x60), _rnd(c, 0x20)]


S(0x4667e0, 'ZTARGET::GetCallBack', 'thiscall', None, ret=None, gen=_cb,
  note='batch30; copies 16 bytes from +0x3d to a caller buffer')


def _mpg(c):
    r = c.rng
    obj = _rnd(c, 0x80)
    a = 0 if r.random() < 0.3 else _rnd(c, 0x40)
    b = 0 if r.random() < 0.3 else _rnd(c, 0x20)
    return [obj, a, b, r.getrandbits(32)]


S(0x467aa0, 'ZTARGET::SetMatPosGeom', 'thiscall', None, ret=None, gen=_mpg,
  note='batch30; null a or b takes the 0x7fffffff path; the mcpy store is then overwritten at +0x25 when b is set')


def _neg(c):
    return [_rnd(c, 0x20), _rnd(c, 0x20)]


S(0x4e09e0, 'vnegFrom', 'fastcall', None, ret=None, gen=_neg, note='batch30; out = -a on three floats')


def _mr(c):
    return [_rnd(c, 0x40)]


S(0x4de7a0, 'mreset', 'thiscall', None, ret=None, gen=_mr, note='batch30; reset of the 0x20-byte block to identity-like values')


def _hf(c):
    r = c.rng
    obj = _rnd(c, 0x700)
    return [obj, r.choice([0, 1])]


S(0x594f10, 'ZFFHERO::SetHoldFire', 'thiscall', None, ret=None, gen=_hf,
  note='batch30; stores the flag byte and sets +0x66b when it becomes nonzero')
