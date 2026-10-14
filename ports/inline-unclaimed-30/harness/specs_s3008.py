"""specs_s3008.py - unclaimed-30 batch 8 (docs/20-unclaimed-30.md, claim 1): CMAINCAMERACONTROL::Save (0x4fd890). The save object's
slots are logged with their arguments (pfspec.vtable); the camera object is random (its flag bit 0x40 at +4 is cleared by the
function, so the memory compare sees it). Returns true (al)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _cam(c):
    e = c.emu
    obj = rnd(c, 0x160)
    save = rnd(c, 0x40)
    e.w32(save, vtable(c, 'zsave_cam', 0x80, argwords={0x3c: 1, 0x60: 1, 0x10: 2, 0x4c: 1, 0x44: 1, 0x40: 1, 0x6c: 1}))
    return [obj, save]


S(0x4fd890, 'CMAINCAMERACONTROL::Save', 'thiscall', None, ret='al', gen=_cam, n=300)
