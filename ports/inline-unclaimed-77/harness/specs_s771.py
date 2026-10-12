"""specs_s771.py - unclaimed-77 claim 1 (docs/20-unclaimed-77.md): CMAINCAMERACONTROL::SetCrossHairMode(int, float*).
Thiscall, two arguments, ret 8. The object is 0x1000 random bytes; this+0x44 holds a stand-in object (serial_stubs.mkobj)
whose vtable slot 0x12c is a logger (ret 12). It logs the first two arguments and the four dwords the third points to (the
struct contents, not its stack address). The float pointer is null in half the cases, otherwise a random 12-byte block."""
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
    """Like serial_stubs.rec, but logs the first two arguments of each call (8 calls, 16 dwords per call), returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc2' + struct.pack('<H', 4 * nargs))
    return ss.code(c, b)


def _rec_struct(c):
    """Thiscall stub, three arguments (ret 12). Logs the first two arguments and the four dwords the third (a stack struct
    pointer) points to, so the struct's contents are compared, not its address. 8 entries of 8 dwords, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(256, 4)
    c.emu.wbytes(ring, bytes(256))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x05\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'                       # arg0 -> [eax]
         + b'\x8b\x54\x24\x08\x89\x50\x04'                   # arg1 -> [eax+4]
         + b'\x8b\x4c\x24\x0c'                                  # ecx = struct pointer (arg2)
         + b'\x8b\x11\x89\x50\x08'                             # struct[0] -> [eax+8]
         + b'\x8b\x51\x04\x89\x50\x0c'                        # struct[1] -> [eax+12]
         + b'\x8b\x51\x08\x89\x50\x10'                        # struct[2] -> [eax+16]
         + b'\x8b\x51\x0c\x89\x50\x14'                        # struct[3] -> [eax+20]
         + b'\xb8' + ss.P(0) + b'\xff\x05' + ss.P(cnt) + b'\xc2\x0c\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x1000)
    obj = ss.mkobj(c, {0x12c: _rec_struct(c)})
    c.emu.w32(self + 0x44, obj)
    mode = c.rng.getrandbits(32)
    p = 0 if c.rng.random() < 0.5 else _rnd(c, 12)
    return [self, mode, p]


S(0x4fda40, 'CMAINCAMERACONTROL::SetCrossHairMode (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 1; vtable slot 0x12c stand-in logs two arguments (GUESS)')
