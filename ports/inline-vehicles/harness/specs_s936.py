"""specs_s936.py - vehicles batch 936: ZVehicle::ClassCommand. Stood in: 0x523ec0 (path drive), 0x5122f0 (base class).
0x523180 (Continue, lifted batch 931) runs as exe code on the path object (slot 8 stubbed)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S, F
from vh import _rnd, _stub, obj, r32, rf, cstub, hookrec
import specs_s931 as b931


def g(c):
    sysx = _rnd(c, 0x200)
    c.emu.w32(0x70039c, sysx)
    c.emu.w32(sysx + 0x40, c.rng.randint(0, 1 << 20))
    c.emu.w32(sysx + 0x48, 0)
    # the object returned by 0x58 answers 0x84 (fill a vector) and the vehicle answers 0x8c (fill a vector)
    def vecblk():
        a = c.emu.alloc(12, 4)
        for k in range(3):
            c.emu.wf32(a + 4 * k, c.rng.uniform(-30, 30))
        return a
    gobj = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), fills=((0, vecblk(), 3),))})
    c.emu.w32(c.emu.r32(0x70039c) + 0x9b, obj(c, 0x40, {0x58: _stub(c, 1, ret=gobj)}))
    v = obj(c, 0x400, {0x8c: _stub(c, 1, skip=(0,), fills=((0, vecblk(), 3),)), 0x368: _stub(c, 1, skip=(0,))})
    p = obj(c, 0x80, {8: _stub(c, 2)})
    c.emu.w32(v + 0x5c, p)
    c.emu.w8(p + 0x46, c.rng.choice([0, 1]))
    c.emu.wf32(p + 0x47, c.rng.uniform(0, 30))
    for off in (0x21b, 0x22b, 0x223):
        c.emu.wf32(v + off, c.rng.uniform(0, 20))
    c.emu.w32(v + 0x2c4, c.rng.randint(0, 1 << 20))
    c.emu.w8(v + 0x2c3, c.rng.choice([0, 1]))
    c.emu.w32(v + 0x233, 0)
    # command words
    words = {0x2ca: 1, 0x2cc: 2, 0x207: 3, 0x2d0: 4}
    for off, val in words.items():
        c.emu.w16(v + off, val)
    msg = _rnd(c, 0x20)
    c.emu.w32(msg, gobj if c.rng.random() < 0.5 else v)
    c.emu.wf32(msg + 4, c.rng.uniform(-5, 5))
    c.emu.wf32(msg + 8, c.rng.choice([-1.0, c.rng.uniform(-5, 5)]))
    ss.patch(c, 0x523ec0, ss.rec(c, 1, log=False))
    ss.patch(c, 0x5122f0, ss.rec(c, 2, ret=c.rng.randint(0, 0xffffffff), log=False))
    cmd = c.rng.choice([1, 2, 3, 4, 9])
    c.emu.mu.ctl_flush_tb()
    return [v, cmd, msg]


S(0x5153e0, 'ZVehicle::ClassCommand', 'thiscall', ret='eax', gen=g)
