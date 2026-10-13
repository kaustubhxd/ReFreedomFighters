"""specs_s3007.py - unclaimed-30 batch 7 (docs/20-unclaimed-30.md, claim 1): CPullToValueAccel::Save (0x527190). The save object's
slots (+0x4c float, +0x60 byte, +0x10 buffer and count) are logged with their arguments (pfspec.vtable), so the call sequence and
the values are both compared. Returns true (al)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _pull(c):
    e = c.emu
    obj = rnd(c, 0x40)
    save = rnd(c, 0x40)
    e.w32(save, vtable(c, 'zsave', 0x80, argwords={0x4c: 1, 0x60: 1, 0x10: 2}))
    return [obj, save]


S(0x527190, 'CPullToValueAccel::Save', 'thiscall', None, ret='al', gen=_pull)
