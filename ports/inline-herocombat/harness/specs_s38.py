"""specs_s38.py - inline session batch 38 (Haiku, night): throw-tree leaves 0x59a6a0 (byte store at +0x22ce) and
0x59a6b0 (ZGameOSD::ProgressValue, clamp to [0, 1] into +0x22cf)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _byte(c):
    return [_rnd(c, 0x2400), c.rng.getrandbits(32)]


def _prog(c):
    r = c.rng
    obj = _rnd(c, 0x2400)
    v = c.fv() if r.random() < 0.8 else r.choice([0.0, 1.0, -0.0, float('nan')])
    return [obj, F(v)]


S(0x59a6a0, 'ZGameOSD::SetByte22ce', 'thiscall', None, ret=None, gen=_byte,
  note='batch38; low byte of the stack arg goes to this+0x22ce')
S(0x59a6b0, 'ZGameOSD::ProgressValue', 'thiscall', None, ret=None, gen=_prog,
  note='batch38; clamp to [0,1] with the exe compare order; result to this+0x22cf')
