"""specs_s942.py - vehicles batch 942: ZTank::ClassInit. Stood in: the vehicle class init (0x515630), the sub-object
name step (0x4cc1d0, 0x4cbec0), the debug object, the tank's cannon/machine-gun lookups (slot 0x25c, in order), the
turret (its slots 0x1d8 and 0x8c), the position objects (slot 0x84), the render manager (0x138 / 0x58) and the script
object (slot 0x88, written through the wr stub). The turret child is the child's +0x54 object (its +4 is the name)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf, cstub


def cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text.encode() + b'\0')
    return a


def vecblk(c):
    a = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.wf32(a + 4 * k, c.rng.uniform(-40, 40))
    return a


def g(c):
    ss.patch(c, 0x515630, ss.rec(c, 0))
    ss.patch(c, 0x4cc1d0, ss.rec(c, 0, ret=r32(c)))
    ss.patch(c, 0x4cbec0, ss.rec(c, 0))
    dbgo = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgo)})
    c.emu.w32(0x700390, dbg)
    # the turret chain (child list): the turret object's +4 is the name, +0xc the flags object
    names = ['Tower_1', 'Turret_2', 'MainTurret_3']   # all match *Tower* or *Turret*
    flags = obj(c, 0x40)
    c.emu.w32(flags + 0x23, 0x100000 if c.rng.random() < 0.9 else 0)
    tmp = _rnd(c, 0x40)
    turret = obj(c, 0x40, {0x1d8: _stub(c, 2, skip=(0,), ret=tmp), 0x8c: _stub(c, 1, skip=(0,))})
    c.emu.w32(turret + 4, cstr(c, names[c.rng.randrange(len(names))]))
    c.emu.w32(turret + 0xc, flags)
    head = 0
    if True:   # a turret child always exists (the cannon and machine-gun steps read it; the exe faults without one)
        ch = _rnd(c, 0x80)
        c.emu.w32(ch + 0x54, turret)
        c.emu.w32(ch + 0x60, 0)
        head = ch
    # cannon and machine-gun positions: slot 0x25c of the tank gives them in call order (cannon first)
    cannon = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), fills=((0, vecblk(c), 3),))}) if c.rng.random() < 0.8 else 0
    mg = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), fills=((0, vecblk(c), 3),))}) if c.rng.random() < 0.8 else 0
    tank = obj(c, 0x2800, {0x80: _stub(c, 2, skip=(0, 1)), 0x25c: ss.seqr(c, 2, [cannon, mg])})
    c.emu.w32(tank + 0x50, head)
    c.emu.w32(tank + 4, cstr(c, 'Tank_' + str(c.rng.randrange(9))) if c.rng.random() < 0.8 else 0)
    c.emu.w32(tank + 0x25d1, 0)
    c.emu.w32(tank + 0x25dd, 0)
    c.emu.w32(tank + 0x2707, 0)
    # render manager: 0x138 -> the script object (0x88 writes its id through the out pointer), 0x58 -> the player
    script = obj(c, 0x40, {0x88: ss.wr(c, 2, 1, 4, r32(c))})
    rmo = obj(c, 0x40, {0x138: _stub(c, 0, ret=script), 0x58: _stub(c, 1, ret=r32(c))})
    sysm = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(sysm, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    c.emu.w32(sysm + 0x9b, rmo)
    c.emu.w32(0x70039c, sysm)
    c.emu._image_dirty = True
    c.emu.mu.ctl_flush_tb()
    return [tank]


S(0x5207e0, 'ZTank::ClassInit', 'thiscall', gen=g)
