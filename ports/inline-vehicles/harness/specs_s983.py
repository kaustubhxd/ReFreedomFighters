"""specs_s983.py - residue-11, batch 983: ZFFSimpleTrain2::FrameUpdate (0x5b87f0). The tail target 0x5b8d80 is a counting stub in the
exe image; the render manager's slot 0x114 (six pushed args) answers an id; the child's slot 0x128 is a counting stub. The timer,
the frame counters and the flags are random, so the early return, the tail, the timer branch and the child call are all reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def g(c):
    ss.patch(c, 0x5b8d80, ss.rec(c, 0))
    rm = obj(c, 0x100, {0x114: _stub(c, 6, ret=c.rng.randint(0, 0xffff))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x40, r32(c))
    c.emu.w32(sysobj + 0x44, r32(c))
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x200)
    child = obj(c, 0x40, {0x128: ss.rec(c, 1)}) if c.rng.random() < 0.8 else 0
    c.emu.w32(t + 0xe2, child)
    c.emu.wbytes(t + 0xdd, bytes([1 if c.rng.random() < 0.1 else 0]))
    c.emu.wbytes(t + 0xb2, bytes([1 if c.rng.random() < 0.3 else 0]))
    c.emu.w32(t + 0xb3, rf(c, -2, 2))
    c.emu.w32(t + 0x5c, rf(c, -2, 2))
    return [t]


S(0x5b87f0, 'ZFFSimpleTrain2::FrameUpdate', 'thiscall', gen=g)
