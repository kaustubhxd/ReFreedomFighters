"""specs_s934.py - vehicles batch 934: ZVehicle::Save and ZVehicle::Load. The base header calls (0x513ff0 save,
0x5135c0 load) are stood in with serial_stubs; the save/load objects use rec (save) and wr (load) stubs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, r32, rf, obj


def veh(c):
    v = _rnd(c, 0x400)
    return v


def g_save(c):
    ss.patch(c, 0x513ff0, ss.rec(c, 1, ret=c.rng.choice([0, 1])))
    sg = ss.save_obj(c, {0x10: ss.rec(c, 2), 0x68: ss.rec(c, 1), 0x4c: ss.rec(c, 1), 0x70: ss.rec(c, 1),
                         0x3c: ss.rec(c, 1), 0x64: ss.rec(c, 1)})
    c.emu.mu.ctl_flush_tb()
    return [veh(c), sg]


S(0x515b70, 'ZVehicle::Save', 'thiscall', ret='al', gen=g_save)


def g_load(c):
    ss.patch(c, 0x5135c0, ss.rec(c, 1, ret=c.rng.choice([0, 1])))
    s = _rnd(c, 0x200)
    rmo = obj(c, 0x40, {0x58: ss.rec(c, 1, ret=r32(c))})
    rm = c.emu.alloc(0x200, 4)
    c.emu.w32(rm + 0x9b, rmo)
    c.emu.w32(0x70039c, rm)
    c.emu._image_dirty = True
    lg = ss.load_obj(c, {0x18: ss.wr(c, 2, 0, 4, r32(c)), 0x6c: ss.wr(c, 1, 0, 1, c.rng.getrandbits(8)),
                         0x50: ss.wr(c, 1, 0, 4, r32(c)), 0x74: ss.wr(c, 1, 0, 4, r32(c)),
                         0x40: ss.wr(c, 1, 0, 4, r32(c))})
    c.emu.mu.ctl_flush_tb()
    return [veh(c), lg]


S(0x5159b0, 'ZVehicle::Load', 'thiscall', ret='al', gen=g_load)
