"""specs_s1141.py - unclaimed-11 batch 42 (slice 10): 0x64fe60 (GUESS), thiscall, no args.
If the pointer at this+0x2c is nonzero, cdecl free(pointer, 1) through 0x634273 (stubbed: records the pointer in a heap ring);
then the dword at this+0x2c is cleared. The object is 0x40 random bytes; the pointer is a fresh 8-byte block in most cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _free_stub(c, ring):
    b = b'\xb8' + ss.P(ring) + b'\x8b\x4c\x24\x04' + b'\x89\x08' + b'\xc3'
    return ss.code(c, b)


def _gen(c):
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    p = 0 if c.rng.random() < 0.2 else c.emu.alloc(8, 4)
    c.emu.w32(o + 0x2c, p)
    ring = c.emu.alloc(8, 4)
    c.emu.wbytes(ring, bytes(8))
    ss.patch(c, 0x634273, _free_stub(c, ring))
    return [o]


S(0x64fe60, 'GUESS (no name) free and clear at +0x2c thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 42 (slice 10); free stubbed')
