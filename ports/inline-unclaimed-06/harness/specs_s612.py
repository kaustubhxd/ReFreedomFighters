"""specs_s612.py - unclaimed-06 claim 12 (docs/20-unclaimed-06.md): CMoveAlongPath::SetSplineVal(float). Thiscall, one float
argument (random bit pattern, NaN included), ret 4. The object is 0x1000 random bytes. The object at this+0x4b is a
stand-in: null in half the cases, otherwise a mkobj with a counting rec stub on vtable slot 0x84. The callee 0x460aa0 is
stubbed on both sides with a two-argument logger (GUESS). Both are stand-ins, not verified code."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rec2(c, nargs):
    """Like serial_stubs.rec, but logs the first two arguments of each call (see specs_s606.py)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc2' + struct.pack('<H', 4 * nargs))
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x1000)
    ss.patch(c, 0x460aa0, _rec2(c, 2))   # GUESS-stub: thiscall with two stack arguments (ret 8)
    if c.rng.random() < 0.5:
        obj = ss.mkobj(c, {0x84: ss.rec(c, 1)})
        c.emu.w32(self + 0x4b, obj)
    else:
        c.emu.w32(self + 0x4b, 0)
    return [self, c.rng.getrandbits(32)]


S(0x523e10, 'CMoveAlongPath::SetSplineVal (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-06 claim 12; callee 0x460aa0 stubbed (GUESS), object slot 0x84 stubbed')
