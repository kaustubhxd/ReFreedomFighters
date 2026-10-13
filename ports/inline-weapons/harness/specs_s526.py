"""specs_s526.py - weapons batch 526: ZLnkAction constructors (the seven used by CreateLnkAction)."""
from pilot import S
from wkit import rnd


def _ctor(n):
    def g(c):
        o = rnd(c, 0x40)
        return [o] + [c.rng.getrandbits(32) for _ in range(n)]
    return g


S(0x485d30, 'ZLnkAction ctor A (5 args)', 'thiscall', None, ret='eax', gen=_ctor(5))
S(0x485df0, 'ZLnkAction ctor B (5 args)', 'thiscall', None, ret='eax', gen=_ctor(5))
S(0x485d00, 'ZLnkAction ctor C (4 args)', 'thiscall', None, ret='eax', gen=_ctor(4))
S(0x485d70, 'ZLnkAction ctor D (4 args)', 'thiscall', None, ret='eax', gen=_ctor(4))
S(0x485e90, 'ZLnkAction ctor E (5 args)', 'thiscall', None, ret='eax', gen=_ctor(5))
S(0x485db0, 'ZLnkAction ctor F (4 args)', 'thiscall', None, ret='eax', gen=_ctor(4))
S(0x485e30, 'ZLnkAction ctor G (10 args)', 'thiscall', None, ret='eax', gen=_ctor(10))
