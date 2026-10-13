"""specs_s1017.py - area 81, batch 1017: ZMatPosAnim::Load (0x4a55e0). The object M at this+0x44 has slot 0x4c (returns null in 40% of cases), 0x1d8 (writes
a pointer to its stack argument's object and returns it), 0x21c (counting). M+0xc is an object whose dword at +0x23 is 0x400003 in most cases and has bit
0x800000 set in about half. The load object's vtable slot 0 is a code buffer whose first byte is random (0xff, or a byte with the low six bits 2 or 3),
so both type branches run. The helpers 0x4e5e60, 0x4e5e40 return random words, 0x4e5e80 returns a random float (fld from memory), 0x4e6180 and 0x4cbec0
are counting stubs, 0x4cc1d0 returns a random word. The debug object at 0x700390 has slot 0x20 returning a channel whose slot 0x2c is a cdecl stub.
Self's slot 0x58 returns a random word."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32, rf


def float_stub(c, addr):
    code = b'\xd9\x05' + struct.pack('<I', addr) + b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def g(c):
    rnd = c.rng
    ss.patch(c, 0x4e5e60, ss.rec(c, 0, ret=rnd.choice([0, 1, 5])))
    fl = c.emu.alloc(4, 4)
    c.emu.w32(fl, rf(c, -3, 3))
    ss.patch(c, 0x4e5e80, float_stub(c, fl))
    ss.patch(c, 0x4e5e40, ss.rec(c, 0, ret=r32(c)))
    ss.patch(c, 0x4e6180, ss.rec(c, 1))
    ss.patch(c, 0x4cc1d0, ss.rec(c, 0, ret=r32(c)))
    ss.patch(c, 0x4cbec0, ss.rec(c, 0))
    code0 = c.emu.alloc(16, 16)
    c.emu.wbytes(code0, bytes([rnd.choice([0xff, 0x02, 0x03, 0x42, 0x43, 0x00, 0x7f])]) + b'\xc3')
    lg = obj(c, 0x40, {0: code0, 0x44: _stub(c, 1), 0x50: _stub(c, 1), 0x58: _stub(c, 1), 0x68: _stub(c, 1)})
    Q = obj(c, 0x40)
    R = obj(c, 0x40) if rnd.random() < 0.6 else 0
    M = obj(c, 0x40, {0x4c: _stub(c, 1, ret=R), 0x1d8: _stub(c, 2, skip=(0,), ret=Q), 0x21c: _stub(c, 0, ret=r32(c))})
    K = obj(c, 0x40)
    c.emu.w32(K + 0x23, 0x400003 if rnd.random() < 0.8 else r32(c))
    c.emu.w32(M + 0xc, K)
    chan = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=chan)})
    c.emu.w32(0x700390, dbg)
    self_ = obj(c, 0x200, {0x58: _stub(c, 0, ret=r32(c))})
    c.emu.w32(self_ + 0x44, M)
    return [self_, lg]


S(0x4a55e0, 'ZMatPosAnim::Load', 'thiscall', None, ret='eax', gen=g)
