"""specs_s943.py - vehicles batch 943: ZVehicle::CopyDataBlock. The base copy (0x512850), the flag read (0x4e14a0) and the
finish (0x4e1b30) are stood in. The block type (0x4e1600) is exe code and reads the block: a type byte at +8 and the
presence word at +4."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, r32


def g(c):
    ss.patch(c, 0x512850, ss.rec(c, 1))
    ss.patch(c, 0x4e14a0, ss.rec(c, 2))
    ss.patch(c, 0x4e1b30, ss.rec(c, 0))
    blk = _rnd(c, 0x40)
    tb = c.emu.alloc(4, 4)
    c.emu.w8(tb, c.rng.choice([3, 3, 0xff, c.rng.getrandbits(8)]))
    c.emu.w32(blk + 4, c.rng.choice([0, 1]))
    c.emu.w32(blk + 8, tb)
    v = _rnd(c, 0x400)
    c.emu.mu.ctl_flush_tb()
    return [v, blk]


S(0x515790, 'ZVehicle::CopyDataBlock', 'thiscall', gen=g)
