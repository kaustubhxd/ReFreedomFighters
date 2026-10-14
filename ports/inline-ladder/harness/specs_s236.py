"""specs_s236.py - ladder thread batch 236: ZLNKWHANDS::GetPickupAction (assert stub, returns 0)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _gpa(c):
    e, r = c.emu, c.rng
    if r.random() < 0.6:
        def ah(e2, res):
            e2.calllog.append(('assert',))
            e2.ret()
        e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    else:
        e.w32(0x7003b0, 0)
    return [K.rnd(c, 0x80)] + [K.rnd(c, 0x40) for _ in range(5)] + [r.getrandbits(1)]


S(0x4744c0, 'ZLNKWHANDS::GetPickupAction', 'thiscall', None, ret='eax', gen=_gpa, note='batch236')
