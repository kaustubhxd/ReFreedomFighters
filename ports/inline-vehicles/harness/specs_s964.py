"""specs_s964.py - residue-05, batch 964: ZInputActions::CheckActionAnalog (0x438050, st0 result) and ZMatPosAnim::FrameUpdate
(0x4a58d0). The vslots of the input object (0x38, 0xa4) are stubs; for FrameUpdate the helpers 0x4a5f20 (float result on
the x87 stack, from a constant) and 0x4a5fe0 are stood in. The engine tick counter is a random dword at [0x70039c]+0x40."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, fconst, obj, r32, rf


def g_check(c):
    t = obj(c, 0x40, {0x38: _stub(c, 2, ret=c.rng.randint(0, 1)), 0xa4: _stub(c, 1, ret=r32(c))})
    return [t, _rnd(c, 0x20), _rnd(c, 0x20)]


def g_frame(c):
    ss.patch(c, 0x4a5f20, _stub(c, 1, fld=fconst(c, rf(c, -2, 2))))
    ss.patch(c, 0x4a5fe0, ss.rec(c, 0))
    sysobj = c.emu.alloc(0x100, 4)
    c.emu.w32(sysobj + 0x40, r32(c))
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x100)
    c.emu.w32(t + 0xbb, rf(c, -200, 200))
    return [t]


S(0x438050, 'ZInputActions::CheckActionAnalog', 'thiscall', ret='st0', gen=g_check)
S(0x4a58d0, 'ZMatPosAnim::FrameUpdate (0x4a5f20 and 0x4a5fe0 stood in)', 'thiscall', gen=g_frame)
