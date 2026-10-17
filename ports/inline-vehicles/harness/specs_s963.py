"""specs_s963.py - residue-05, batch 963: 0x5e7590 (true, three ignored args), 0x46ba90 (forwarder to 0x46b800, stood in with
hookrec: ECX and the two args recorded, EAX answered by a constant) and 0x514410 (SetNextPath; 0x523b90 stood in with hookrec)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _rnd, hookrec, obj, r32, rf


def g_true(c):
    return [_rnd(c, 0x40), r32(c), r32(c), r32(c)]


def g_fwd(c):
    hookrec(c, 0x46b800, 2, ret=r32(c), this=True)
    return [_rnd(c, 0x40), r32(c), r32(c)]


def g_next(c):
    hookrec(c, 0x523b90, 2, ret=0, this=True)
    t = obj(c, 0x80)
    child = obj(c, 0x40)
    c.emu.w32(t + 0x5c, child)
    return [t, c.rng.randint(0, 0xffffffff), rf(c, -100, 100)]


S(0x5e7590, 'GUESS FUN_5e7590 (true)', 'thiscall', ret='al', gen=g_true)
S(0x46ba90, 'GUESS FUN_46ba90 (tail to 0x46b800, stood in)', 'thiscall', ret='eax', gen=g_fwd)
S(0x514410, 'ZMoveOnSpline::SetNextPath (0x523b90 stood in)', 'thiscall', gen=g_next)
