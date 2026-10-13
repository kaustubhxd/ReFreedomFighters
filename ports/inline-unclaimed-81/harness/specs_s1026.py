"""specs_s1026.py - area 81, batch 1026: 0x4644f0 (thiscall: this, X, Y). The count at this+0x20 is 1 to 3. X is a block of random floats (the struct source),
Y holds small element indices at Y+0xc+0x30k. The stand-ins: 0x4de420 copies three floats from edx into ecx (V); 0x4de4f0 and 0x43e960 and 0x441a60 record
their edx source (values only, in heap records); 0x4de1d0 copies three floats from edx into ecx and writes zero to the fourth. this's slot 0x2b4 (one
argument) returns a random count of 0..3. The output buffer is at this+0x1c."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def code_bytes(c, body):
    a = c.emu.alloc(len(body) + 16, 16)
    c.emu.wbytes(a, body)
    return a


def copy3(zero_fourth=False):
    b = b''
    for i in range(3):
        b += b'\x8b\x42' + bytes([4 * i]) + b'\x89\x41' + bytes([4 * i])     # mov eax,[edx+4i]; mov [ecx+4i],eax
    if zero_fourth:
        b += b'\xc7\x41\x0c\x00\x00\x00\x00'                                 # mov dword [ecx+12],0
    return b + b'\xc3'


def record3(c):
    rec = c.emu.alloc(16, 4)
    b = b''
    for i in range(3):
        b += b'\x8b\x42' + bytes([4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)  # mov eax,[edx+4i]; mov [rec+4i],eax
    return code_bytes(c, b + b'\xc3')


def g(c):
    rnd = c.rng
    ss.patch(c, 0x4de420, code_bytes(c, copy3()))
    ss.patch(c, 0x4de1d0, code_bytes(c, copy3(zero_fourth=True)))
    ss.patch(c, 0x4de4f0, record3(c))
    ss.patch(c, 0x43e960, record3(c))
    ss.patch(c, 0x441a60, record3(c))
    X = obj(c, 0x400)
    for off in range(0, 0x400, 4):
        c.emu.w32(X + off, rf(c, -50, 50))
    count = rnd.randint(1, 3)
    Y = obj(c, 0x200)
    for k in range(0, 4):
        c.emu.w32(Y + 0xc + 0x30 * k, rnd.randint(0, 3))
    P1 = obj(c, 0x100)
    R = rnd.randint(0, 3)
    self_ = obj(c, 0x40, {0x2b4: _stub(c, 1, ret=R)})
    c.emu.w32(self_ + 0x1c, P1)
    c.emu.w32(self_ + 0x20, count)
    return [self_, X, Y]


S(0x4644f0, 'GUESS 0x4644f0 struct elements update', 'thiscall', gen=g)
