"""specs_s978.py - residue-05, batch 978: ZFFSimpleTrain2::Load (0x5b8b50). The allocator (0x41e290, cdecl) returns a block or
zero (zero skips the constructor); the constructor (0x4ccbe0, thiscall, two args) is a counting stub that returns the block.
The load object and every object its calls return are one generic object (as in batch 976); the render manager's slot 0x58
answers a random value."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    buf = c.emu.alloc(0x40, 4)
    null = c.rng.random() < 0.2
    ss.patch(c, 0x41e290, cstub(c, 1, ret=(0 if null else buf)))
    ss.patch(c, 0x4ccbe0, _stub(c, 2, ret=buf))
    G = obj(c, 0x80)
    vt = c.emu.r32(G)
    for off in (0x40, 0x50, 0x68, 0x6c, 0x74):
        src = c.emu.alloc(4, 4)
        c.emu.w32(src, r32(c))
        c.emu.w32(vt + off, _stub(c, 1, skip=(0,), ret=G, ofills=((0, 0, src, 1),)))
    c.emu.w32(vt + 0x70, ss.rec(c, 1))
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=r32(c))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x200)
    return [t, G]


S(0x5b8b50, 'ZFFSimpleTrain2::Load', 'thiscall', ret='al', gen=g)
