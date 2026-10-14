"""specs_s976.py - residue-05, batch 976: ZItemWeapon::Load (0x46f7d0). The base (0x46f520) is a counting stub. The load object
and every object the calls return are one generic object G whose slots (0x40, 0x48, 0x50, 0x68, 0x6c) write a random dword through
their pointer argument and return G itself, so the chains stay on G. Slot 0x70 is a counting stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32


def g(c):
    ss.patch(c, 0x46f520, ss.rec(c, 1))
    G = obj(c, 0x80)
    vt = c.emu.r32(G)
    for off in (0x40, 0x48, 0x68, 0x6c, 0x50):
        src = c.emu.alloc(4, 4)
        c.emu.w32(src, r32(c))
        c.emu.w32(vt + off, _stub(c, 1, skip=(0,), ret=G, ofills=((0, 0, src, 1),)))
    c.emu.w32(vt + 0x70, ss.rec(c, 1))
    t = obj(c, 0x200)
    c.emu.w32(t + 0xd9, r32(c))
    return [t, G]


S(0x46f7d0, 'ZItemWeapon::Load', 'thiscall', ret='al', gen=g)
