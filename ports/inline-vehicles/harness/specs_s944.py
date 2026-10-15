"""specs_s944.py - vehicles batch 944: ZCar::CopyDataBlock and ZTank::CopyDataBlock. The vehicle copy runs as exe code (its
base 0x512850 and the reads are stood in); the reads 0x4e11e0 / 0x4e12f0 / 0x4e12e0 and the finish 0x4e1b30 are stood in."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, r32


def common(c):
    ss.patch(c, 0x512850, ss.rec(c, 1))
    ss.patch(c, 0x4e14a0, ss.rec(c, 2))
    ss.patch(c, 0x4e1b30, ss.rec(c, 0))
    ss.patch(c, 0x4e11e0, ss.rec(c, 2))
    ss.patch(c, 0x4e12f0, ss.rec(c, 2))
    ss.patch(c, 0x4e12e0, ss.rec(c, 2))
    blk = _rnd(c, 0x40)
    tb = c.emu.alloc(4, 4)
    c.emu.w8(tb, 3)
    c.emu.w32(blk + 4, 1)
    c.emu.w32(blk + 8, tb)
    return blk


def g_car(c):
    blk = common(c)
    v = _rnd(c, 0x2000)
    c.emu.mu.ctl_flush_tb()
    return [v, blk]


def g_tank(c):
    blk = common(c)
    v = _rnd(c, 0x2800)
    c.emu.mu.ctl_flush_tb()
    return [v, blk]


S(0x517630, 'ZCar::CopyDataBlock', 'thiscall', gen=g_car)
S(0x520ad0, 'ZTank::CopyDataBlock', 'thiscall', gen=g_tank)
