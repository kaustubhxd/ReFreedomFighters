"""specs_s614.py - band 0x421000-0x441000, batch 614 (see src/batch614.cpp). Plain stores: the heap compare checks them.
"""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S  # noqa: E402


def _gen(nargs):
    def gen(c):
        r = c.rng
        self_ = c.emu.alloc(0x2000, 16)
        c.emu.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x2000)))
        return [self_] + [r.getrandbits(32) for _ in range(nargs)]
    return gen


S(0x42cc20, 'ZSysInterface::FollowRealtime', 'thiscall', None, ret=None, gen=_gen(1))
S(0x4335d0, 'byte +0x100 = arg (no map name)', 'thiscall', None, ret=None, gen=_gen(1))
S(0x43d950, 'byte +0x90 = arg (map name ZHapticsBase::GetEffectID)', 'thiscall', None, ret=None, gen=_gen(1))
S(0x42ee50, 'ZSysInterface::Rand (LCG)', 'thiscall', None, ret='eax', gen=_gen(2))
