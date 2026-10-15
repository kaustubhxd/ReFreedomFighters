"""specs_s992.py - residue-10, batch 992: CWheel::InitEmitters (0x529ae0). The emitter helpers 0x516b60 (three args, logged), 0x516f40 and
0x516fd0 (stack pointers not recorded) are stood in; the slots s vslot 0x84 and g vslot 0x8c write three random floats through their
pointer argument (stack pointers skipped in the records)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, rf


def g(c):
    ss.patch(c, 0x516b60, ss.rec(c, 3))
    ss.patch(c, 0x516f40, ss.rec(c, 1, log=False))
    ss.patch(c, 0x516fd0, ss.rec(c, 1, log=False))
    src1 = c.emu.alloc(12, 4)
    src2 = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(src1 + 4 * j, rf(c, -30, 30))
        c.emu.w32(src2 + 4 * j, rf(c, -30, 30))
    s = obj(c, 0x80, {0x84: _stub(c, 1, skip=(0,), ofills=((0, 0, src1, 3),))})
    gg = obj(c, 0x80, {0x8c: _stub(c, 1, skip=(0,), ofills=((0, 0, src2, 3),))})
    t = obj(c, 0x200)
    c.emu.w32(t + 0x14, rf(c, -30, 30))
    return [t, gg, s]


S(0x529ae0, 'CWheel::InitEmitters', 'thiscall', gen=g)
