"""specs_s29.py - inline session batch 29 (Haiku, afternoon): gameplay leaves 0x4e1b60, 0x4daf20, 0x4e09b0, 0x4e0d40, 0x4e0d00,
0x4de420, 0x4db500."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x80)]


S(0x4e1b60, 'COLI::COLI', 'thiscall', None, ret='eax', gen=_obj,
  note='batch29; sets float 1.0 at +0x34, zero at +0x44, byte 1 at +0x6c; returns this')


# 0x4daf20: the special values are hit half the time so every branch runs.
_SPECIAL = [0x4000022, 0x200015, 0x20001c, 0x200012, 0x100000, 0x200000]


def _list(c):
    r = c.rng
    if r.random() < 0.5:
        a = r.choice(_SPECIAL)
        if r.random() < 0.3:
            a ^= 1 << r.randint(0, 31)
    else:
        a = r.getrandbits(32)
    return [a, r.getrandbits(32)]


S(0x4daf20, 'GetBaseGeomListType', 'fastcall', None, ret='eax', gen=_list,
  note='batch29; table of flag values; second argument unused')


def _vec(c):
    r = c.rng
    obj = _rnd(c, 0x20)
    return [obj]


S(0x4e09b0, 'vneg', 'thiscall', None, ret=None, gen=_vec, note='batch29; sign flip of three floats')


def _vs3(c):
    r = c.rng
    out = _rnd(c, 0x20)
    a = _rnd(c, 0x20)
    return [out, a, F(c.fv())]


S(0x4e0d40, 'vscalar3', 'fastcall', None, ret=None, gen=_vs3,
  note='batch29; out = a * s on three floats; s is a stack float')


def _vs1(c):
    obj = _rnd(c, 0x20)
    return [obj, F(c.fv())]


S(0x4e0d00, 'vscalarInPlace', 'thiscall', None, ret=None, gen=_vs1,
  note='batch29; in-place scale of three floats')


def _mc(c):
    dst = _rnd(c, 0x28)
    src = _rnd(c, 0x28)
    return [dst, src]


S(0x4de420, 'mcpy', 'fastcall', None, ret=None, gen=_mc, note='batch29; nine-dword copy')


def _gp(c):
    obj = _rnd(c, 0x40)
    out = _rnd(c, 0x20)
    return [obj, out]


S(0x4db500, 'ZBaseGeom::GetPos', 'thiscall', None, ret=None, gen=_gp,
  note='batch29; copies three dwords from +0x24 to a caller buffer')
