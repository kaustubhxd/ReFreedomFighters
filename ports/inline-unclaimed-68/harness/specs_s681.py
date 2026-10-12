"""specs_s681.py - unclaimed-68 batch 1 (claim 1): three one-line leaves. Each object is 0x800 random bytes; the byte
store and load land inside it. The float return is compared in ST0 (ret 'st0')."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x800)]


S(0x4827b0, 'ZPlayer::ControlsEnabled (unknown) thiscall const', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-68 batch 1; byte at +0x600')
S(0x4831b0, 'ZPlayer::DisableT1 (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-68 batch 1; byte 1 at +0x5fe')
S(0x513170, 'ZMoveOnSpline::GetVerticalVisionOffset (unknown) thiscall const', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-68 batch 1; returns the constant at 0x67cd40 in ST0')
