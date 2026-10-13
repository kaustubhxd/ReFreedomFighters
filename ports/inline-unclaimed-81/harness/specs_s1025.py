"""specs_s1025.py - area 81, batch 1025: 0x4a21b0 (thiscall: this, n, a2). The index n is -2..9. The words this+0x800+4k (start) and this+0x804+4k (limit) are
small random ints (the start is taken from the word at n, the limit from n). The element array at this+4 holds random values. The queue global Q (0x70038c)
returns a non-null R in every case (the null-R branch calls 0x4a1710 and does not advance the loop, which would not terminate with a counting stub);
R+0x44 is an object whose slot 0x84 is a counting stub. The helper 0x4e0870 is a stand-in that leaves a random float in st0 (fld), which the exe pops (fstp).
The helpers 0x4a15b0 and 0x4a0150 return their argument (so the index advances). 0x4a1710 counts."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def float_stub(c, addr):
    code = b'\xd9\x05' + struct.pack('<I', addr) + b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def echo_stub(c):
    code = b'\x8b\x44\x24\x04' + b'\xc2\x04\x00'     # mov eax,[esp+4]; ret 4
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def g(c):
    rnd = c.rng
    ss.patch(c, 0x4a1710, ss.rec(c, 1))
    ss.patch(c, 0x4a15b0, echo_stub(c))
    ss.patch(c, 0x4a0150, echo_stub(c))
    fl = c.emu.alloc(4, 4)
    c.emu.w32(fl, rf(c, -100, 1000))
    ss.patch(c, 0x4e0870, float_stub(c, fl))
    M = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,))})
    R = obj(c, 0x80)
    c.emu.w32(R + 0x44, M)
    Q = obj(c, 0x40, {0xcc: _stub(c, 1, ret=R)})
    c.emu.w32(0x70038c, Q)
    self_ = obj(c, 0xa00)
    for k in range(-2, 11):
        c.emu.w32(self_ + 0x800 + 4 * k, rnd.randint(-1, 3) & 0xffffffff)
    for k in range(-2, 11):
        c.emu.w32(self_ + 0x804 + 4 * k, rnd.randint(-1, 6) & 0xffffffff)
    for k in range(0, 12):
        c.emu.w32(self_ + 4 + 4 * k, r32(c))
    n = rnd.randint(-2, 9)
    a2 = obj(c, 0x40)
    return [self_, n & 0xffffffff, a2]


S(0x4a21b0, 'GUESS 0x4a21b0 element check', 'thiscall', None, ret='eax', gen=g)
