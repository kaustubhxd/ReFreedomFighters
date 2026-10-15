"""specs_s939.py - vehicles batch 939: ZTank::ClassInit2. Stood in: the vehicle class init (0x515620), the undercarriage
Init (0x527ee0), InitTankPosDir (0x520f20), the render manager's slot 0x4c, the turret's child lookup and the weapon
slots (0x328 on the tank is a stub; the turret's 0x25c/0x10c and the weapon's 0x350/0x330 are stubs)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, cstub


def g(c):
    ss.patch(c, 0x515620, ss.rec(c, 0))
    ss.patch(c, 0x527ee0, ss.rec(c, 4))
    ss.patch(c, 0x520f20, ss.rec(c, 1))
    # debug object (only the no-turret branch)
    dbgo = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgo)})
    c.emu.w32(0x700390, dbg)
    c.emu.w32(0x7003b0, cstub(c, 0))
    # turret chain: T (geom) -> 0x25c -> X -> 0x10c -> Y (flags word +4), T+0xc -> flags object (+0x23)
    Y = obj(c, 0x40, {8: _stub(c, 0), 0x4c: _stub(c, 0), 0x54: _stub(c, 1)})
    flagw = c.rng.getrandbits(32)
    c.emu.w32(Y + 4, flagw & ~1)   # bit 0 clear: the normal path (the other path stores through a null child in the exe)
    c.emu.w32(Y + 0x30, r32(c))
    X = obj(c, 0x40, {0x10c: _stub(c, 2, skip=(0, 1), ret=Y)})
    flags = obj(c, 0x40)
    c.emu.w32(flags + 0x23, c.rng.choice([0x100000, 0, 0x20000]))
    T = obj(c, 0x40, {0x25c: _stub(c, 2, skip=(0, 1), ret=X)})
    c.emu.w32(T + 0xc, flags)
    # the tank: 0x328 creates a weapon, the weapon's class comes from 0x350 / 0x330
    W2 = obj(c, 0x40, {0x330: _stub(c, 0, ret=c.rng.choice([0xb, 3]))})
    W = obj(c, 0x40, {0x350: _stub(c, 0, ret=W2)})
    tank = obj(c, 0x2800, {0x328: _stub(c, 3, ret=W)})
    for off in (0x4, 0x25cd):
        c.emu.wf32(tank + off, c.rng.uniform(-3, 3))
    c.emu.w32(tank + 0x133, 0)
    c.emu.w8(tank + 0x133, c.rng.choice([0, 1]))
    c.emu.w32(tank + 0x25d1, T)   # without a turret the exe reads [0+0xc] after its debug line (faults in both builds)
    c.emu.w32(tank + 0x25d5, c.rng.choice([0, r32(c)]))
    c.emu.w32(tank + 0x25d9, c.rng.choice([0, r32(c)]))
    c.emu.w32(tank + 0x25e1, 0)
    c.emu.w32(tank + 0x25dd, 0)
    c.emu.w8(tank + 0x260a, 0)
    # render manager: 0x4c returns a value for the tank
    rmo = obj(c, 0x40, {0x4c: _stub(c, 1, ret=r32(c))})
    sysm = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(sysm, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(sysm + 0x9b, rmo)
    c.emu.w32(0x70039c, sysm)
    c.emu._image_dirty = True
    c.emu.mu.ctl_flush_tb()
    return [tank]


S(0x520670, 'ZTank::ClassInit2', 'thiscall', gen=g)
