"""specs_s945.py - vehicles batch 945: ZHeli::CopyDataBlock. The base copy (0x512850), the reads (0x4e12e0), the finish
(0x4e1b30) and the debug object are stood in; the block type (0x4e1600) is exe code on the block's bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, r32, cstub, obj, _stub


def g(c):
    ss.patch(c, 0x512850, ss.rec(c, 1))
    ss.patch(c, 0x4e12e0, ss.rec(c, 2))
    ss.patch(c, 0x4e1b30, ss.rec(c, 0))
    dbgo = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgo)})
    c.emu.w32(0x700390, dbg)
    blk = _rnd(c, 0x40)
    tb = c.emu.alloc(4, 4)
    c.emu.w8(tb, c.rng.choice([8, 8, 3, 0xff]))
    c.emu.w32(blk + 4, 1)
    c.emu.w32(blk + 8, tb)
    heli = _rnd(c, 0x1000)
    c.emu.w32(heli + 0x44d, c.rng.choice([0, 1, 2]))   # the read stubs leave these as the spec sets them
    c.emu.w32(heli + 0x451, c.rng.choice([0, 1]))
    c.emu.w32(heli + 4, c.rng.choice([0, r32(c)]))
    c.emu.mu.ctl_flush_tb()
    return [heli, blk]


S(0x51c210, 'ZHeli::CopyDataBlock', 'thiscall', gen=g)
