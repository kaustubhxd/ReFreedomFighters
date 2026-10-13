"""specs_s1036.py - area 81, batch 1036: 0x5daf20 (thiscall, this; plain ret). The object at this+0x84 is set in 90% of cases. Its slot 0x5c writes a
flag cell X into the out argument and returns a fixed pointer P; slot 0x4c and slot 0 are plain stubs. The free stub 0x634273 records its pointer and clears X,
so the free loop runs once when X starts at 1. The render manager object's slot 0x34 is a plain stub."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj


def P4(v):
    return struct.pack('<I', v & 0xffffffff)


def g(c):
    rnd = c.rng
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    R = obj(c, 0x40, {0x34: _stub(c, 1)})
    c.emu.w32(sysobj + 0x9b, R)
    X = c.emu.alloc(4, 4)
    c.emu.w32(X, rnd.randint(0, 1))
    Pp = c.emu.alloc(16, 4)
    PC = c.emu.alloc(4, 4)
    free_stub = ss.code(c, b'\x8b\x44\x24\x04\xa3' + P4(PC) + b'\xc7\x05' + P4(X) + b'\x00\x00\x00\x00\xc3')
    ss.patch(c, 0x634273, free_stub)
    slot5c = ss.code(c, b'\x8b\x44\x24\x04' + b'\x8b\x0d' + P4(X) + b'\x89\x08' + b'\xb8' + P4(Pp) + b'\xc2\x04\x00')
    M = obj(c, 0x40, {0x4c: _stub(c, 1, skip=(0,)), 0x5c: slot5c, 0: _stub(c, 1)})
    self_ = obj(c, 0x90)
    c.emu.w32(self_ + 0x84, M if rnd.random() < 0.9 else 0)
    c.emu.w32(self_ + 0x44, rnd.getrandbits(32))
    c.emu.w32(self_ + 0x30, rnd.getrandbits(32))
    return [self_]


S(0x5daf20, 'GUESS 0x5daf20 teardown', 'thiscall', None, ret=None, gen=g)
