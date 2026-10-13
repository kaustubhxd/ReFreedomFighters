"""specs_s1027.py - area 81, batch 1027: 0x5457f0 (fastcall: this in ecx, E in edx; a, b, c, d, e on the stack). a is a vector source object, b and d are
float outputs, c is a radius (random 0..10 squared), e is a vector object written by the stand-in. The stand-in 0x43e920 (fastcall) copies random
vectors into its ecx (three calls: V1, V2 and e); 0x443ef0 and 0x547430 count, 0x4e0d00 counts its float argument. The sqrt at 0x634d7c is a sqrtsd hook.
Both the early returns and the full path run (the dot product and the length test are random)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def fast_vec_stub(c, src):
    code = b''
    for j in range(3):
        code += b'\x8b\x05' + struct.pack('<I', src + 4 * j) + b'\x89\x41' + bytes([4 * j])
    code += b'\xc2\x04\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def fill(c, vals):
    a = c.emu.alloc(4 * len(vals), 4)
    for i, v in enumerate(vals):
        c.emu.w32(a + 4 * i, v)
    return a


def g(c):
    rnd = c.rng
    sq = c.emu.alloc(16, 16)
    c.emu.wbytes(sq, b'\xf2\x0f\x51\xc0\xc3')
    ss.patch(c, 0x634d7c, sq)
    ss.patch(c, 0x43e920, fast_vec_stub(c, fill(c, [rf(c, -3, 3) for _ in range(3)])))
    ss.patch(c, 0x443ef0, ss.rec(c, 1, log=False))
    ss.patch(c, 0x4e0d00, ss.rec(c, 1))
    ss.patch(c, 0x547430, ss.rec(c, 0))
    self_ = obj(c, 0x40)
    E = obj(c, 0x40)
    a = obj(c, 0x40)
    for k in range(3):
        c.emu.w32(a + 4 * k, rf(c, -3, 3))
    b = c.emu.alloc(4, 4)
    d = c.emu.alloc(4, 4)
    c_ = c.emu.alloc(4, 4)
    c.emu.w32(c_, rf(c, 0, 10))
    e = obj(c, 0x40)
    return [self_, E, a, b, c_, d, e]


S(0x5457f0, '0x5457f0 ray test', 'fastcall', gen=g)
