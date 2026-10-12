"""specs_s6205.py - unclaimed-62 claim 3 (slice-1 leaves): six getters. Each object is random bytes; the field values are random, so each
result is sensitive to its own field. PathLen's object has a logged slot 0x10 that returns a value (eax)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _obj(c, n=0x600):
    return rnd(c, n)


def _plain(c):
    return [_obj(c)]


def _pathlen(c):
    e = c.emu
    r = c.rng
    self_ = _obj(c)
    o = rnd(c, 0x40)
    value = r.getrandbits(32)
    e.w32(o, vtable(c, 'pathobj', 0x20, impl={0x10: lambda em, a: value}, argwords={0x10: 0}))
    e.w32(self_ + 0x5c, o)
    return [self_]


S(0x468210, 'ZCTRLIKLNKOBJ::LightReceived', 'thiscall', None, ret='st0', gen=_plain, n=300)
S(0x46eed0, 'ZLNKOBJ::GetAnimFile', 'thiscall', None, ret='eax', gen=_plain, n=300)
S(0x483a10, 'ZPlayer::GetCenterHeight', 'thiscall', None, ret='st0', gen=_plain, n=300)
S(0x483f10, 'ZPlayer::IsWalking', 'thiscall', None, ret='eax', gen=_plain, n=300)
S(0x5abcd0, 'CMessageBasics::IsVisible', 'thiscall', None, ret='al', gen=_plain, n=300)
S(0x5139d0, 'ZMoveOnSpline::PathLen', 'thiscall', None, ret='eax', gen=_pathlen, n=300)
