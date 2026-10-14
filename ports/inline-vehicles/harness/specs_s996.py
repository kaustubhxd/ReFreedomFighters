"""specs_s996.py - residue-10, batch 996: ZFFActor::Load (0x5a0be0). The base 0x479190 and the helpers 0x5a0b80 and 0x59d3a0 are stood in
(counting stubs; the stack pointer argument is not recorded in the load object's slots). The load object's slots write random dwords
through their pointer argument (stack pointers skipped); the render manager's +0x44 is random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def g(c):
    ss.patch(c, 0x479190, ss.rec(c, 1))
    ss.patch(c, 0x5a0b80, ss.rec(c, 1))
    ss.patch(c, 0x59d3a0, ss.rec(c, 1))
    L = obj(c, 0x80)
    vt = c.emu.r32(L)
    for off in (0x40, 0x48, 0x4c, 0x50, 0x68, 0x6c):
        src = c.emu.alloc(4, 4)
        c.emu.w32(src, r32(c))
        c.emu.w32(vt + off, _stub(c, 1, skip=(0,), ofills=((0, 0, src, 1),)))
    c.emu.w32(vt + 0x18, ss.rec(c, 2))
    rm = obj(c, 0x100)
    c.emu.w32(rm + 0x44, r32(c))
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x1000)
    c.emu.w32(t + 0x54, obj(c, 0x40))
    return [t, L]


S(0x5a0be0, 'ZFFActor::Load', 'thiscall', ret='al', gen=g)
