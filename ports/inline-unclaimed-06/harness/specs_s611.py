"""specs_s611.py - unclaimed-06 claim 11 (docs/20-unclaimed-06.md): CAction::Save(ZSaveGame*). Thiscall, one argument,
ret 4. The object is 0x1000 random bytes. The ZSaveGame is a stand-in (serial_stubs.save_obj): counting rec stubs on 0x3c,
0x40, 0x5c, and a two-argument logger (specs_s606 style) on 0x10, which takes a pointer into the object and the count 0x17.
The function has no original callees."""
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
    sg = ss.save_obj(c, {0x3c: ss.rec(c, 1), 0x40: ss.rec(c, 1), 0x5c: ss.rec(c, 1), 0x10: _rec2(c, 2)})
    return [self, sg]


S(0x4a1b90, 'CAction::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-06 claim 11; clears bit 0x40 at +4; ZSaveGame slots 0x5c, 0x40, 0x3c, 0x10 via serial stubs')
