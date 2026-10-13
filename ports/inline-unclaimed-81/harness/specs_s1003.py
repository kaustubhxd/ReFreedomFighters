"""specs_s1003.py - area 81 (residue 0), batch 1003: CRagdoll2::Setup (0x645000). The helpers 0x644660 (thiscall, no stack arguments) and
0x540ed0 (thiscall, returns a random word) are counting stubs; 0x41e290 (cdecl, one argument) returns null or a fresh object. The argument
object has a vtable with slot 0x24c (returns q) and q has slot 0x58 (one stack argument). The render manager's +0x18 object has slot 0xb4."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    ss.patch(c, 0x644660, ss.rec(c, 0, log=False))
    ss.patch(c, 0x540ed0, ss.rec(c, 0, ret=r32(c)))
    res = obj(c, 0x40) if c.rng.random() < 0.6 else 0
    ss.patch(c, 0x41e290, cstub(c, 1, ret=res))
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, r32(c))
    b = obj(c, 0x40, {0xb4: _stub(c, 1, ret=r32(c))})
    rm = obj(c, 0x1000)
    c.emu.w32(rm + 0x18, b)
    c.emu.w32(sysobj + 0x1aa3, rm)
    q = obj(c, 0x40, {0x58: _stub(c, 1, ret=r32(c))})
    arg = obj(c, 0x40, {0x24c: _stub(c, 0, ret=q)})
    c.emu.w32(arg + 0x20, r32(c))
    t = obj(c, 0x80)
    c.emu.w32(arg + 8, t)
    c.emu.w32(t + 0x6c, r32(c))
    self_ = obj(c, 0x400)
    c.emu.w32(self_ + 0x17f, 0 if c.rng.random() < 0.5 else r32(c))
    return [self_, arg if c.rng.random() < 0.85 else 0]


S(0x645000, 'CRagdoll2::Setup', 'thiscall', gen=g)
