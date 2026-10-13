"""specs_s3009.py - unclaimed-30 batch 9 (docs/20-unclaimed-30.md, claim 1): AimControl::Save (0x513f50). The save object's slots are
logged with their arguments (pfspec.vtable). Returns true (al)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _aim(c):
    e = c.emu
    obj = rnd(c, 0x40)
    save = rnd(c, 0x40)
    e.w32(save, vtable(c, 'zsave_aim', 0x80, argwords={0x3c: 1, 0x64: 1, 0x4c: 1, 0x68: 1}))
    return [obj, save]


S(0x513f50, 'AimControl::Save', 'thiscall', None, ret='al', gen=_aim)
