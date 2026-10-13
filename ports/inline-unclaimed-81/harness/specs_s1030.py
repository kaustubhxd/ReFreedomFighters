"""specs_s1030.py - area 81, batch 1030: 0x5121e0 (thiscall, no arguments). The object's +0x159 is a vector-source object with slot 0x74 (two stack arguments; the
stack pointers are skipped in the log and written through with random floats). The helper 0x4e7930 is a stand-in that returns a random float in st0 and pops its
16 bytes. The fastcall helpers 0x4de420, 0x4de480 and 0x441940 copy three floats from edx into ecx. this's slot 0x130 counts; the debug object's slot 0x20 returns
a channel whose slot 0x2c is a cdecl stub. Both the early exit (+0x159 == 0) and the print path (float below zero) run."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32, rf


def code_bytes(c, body):
    a = c.emu.alloc(len(body) + 16, 16)
    c.emu.wbytes(a, body)
    return a


def copy3():
    b = b''
    for i in range(3):
        b += b'\x8b\x42' + bytes([4 * i]) + b'\x89\x41' + bytes([4 * i])   # mov eax,[edx+4i]; mov [ecx+4i],eax
    return b + b'\xc3'


def g(c):
    rnd = c.rng
    fl = c.emu.alloc(4, 4)
    c.emu.w32(fl, rf(c, -3, 3))
    ss.patch(c, 0x4e7930, code_bytes(c, b'\xd9\x05' + struct.pack('<I', fl) + b'\xc2\x10\x00'))
    ss.patch(c, 0x4de420, code_bytes(c, copy3()))
    ss.patch(c, 0x4de480, code_bytes(c, copy3()))
    ss.patch(c, 0x441940, code_bytes(c, copy3()))
    srcA = c.emu.alloc(12, 4)
    srcB = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(srcA + 4 * k, rf(c, -3, 3))
        c.emu.w32(srcB + 4 * k, rf(c, -3, 3))
    O = obj(c, 0x40, {0x74: _stub(c, 2, skip=(0, 1), ofills=((0, 0, srcA, 3), (1, 0, srcB, 3)))})
    dbgchan = obj(c, 0x40, {0x2c: cstub(c, 2)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=dbgchan)})
    c.emu.w32(0x700390, dbg)
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, rnd.randint(0, 9999))
    self_ = obj(c, 0x300, {0x130: _stub(c, 3)})
    c.emu.w32(self_ + 0x159, O if rnd.random() < 0.8 else 0)
    c.emu.wbytes(self_ + 0x20d, bytes([rnd.randint(0, 255), rnd.randint(0, 255)]))
    c.emu.w32(self_ + 0x144, r32(c))
    for k in range(3):
        c.emu.w32(self_ + 0x15d + 4 * k, rf(c, -3, 3))
        c.emu.w32(self_ + 0x169 + 4 * k, rf(c, -3, 3))
    return [self_]


S(0x5121e0, 'GUESS 0x5121e0 vector update and print', 'thiscall', gen=g)
