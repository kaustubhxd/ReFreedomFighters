"""specs_s1106.py - unclaimed-11 batch 6 (core-todo residue-10): GUESS FUN_4778e0 at 0x4778e0, thiscall, seven stack
arguments (ret 0x1c). Predicate: when this+0x726 (byte) is nonzero and this+0x64c is 10, the result is false. Otherwise
it calls 0x465a80 with the seven arguments in the same order and returns that call's result. 0x465a80 is stubbed (no GC
name; unverified): the stub records its seven arguments in a heap ring and returns a random value (al). The object is
0x800 random bytes; the flag is nonzero in two thirds of the cases and the field equals 10 in about a third."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _stub7(c, ring, ret):
    b = b'\xb8' + ss.P(ring)
    for i in range(7):
        b += b'\x8b\x4c\x24' + bytes([4 + 4 * i]) + b'\x89\x48' + bytes([4 * i])
    b += b'\xb8' + ss.P(ret) + b'\xc2\x1c\x00'
    return ss.code(c, b)


def _fn(c):
    o = c.emu.alloc(0x800, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    c.emu.w8(o + 0x726, c.rng.choice([0, 1, 3]))
    if c.rng.random() < 0.33:
        c.emu.w32(o + 0x64c, 10)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    ss.patch(c, 0x465a80, _stub7(c, ring, c.rng.getrandbits(8)))
    return [o] + [c.rng.getrandbits(32) for _ in range(7)]


S(0x4778e0, 'GUESS FUN_4778e0 (no name) thiscall', 'thiscall', None, ret='al', gen=_fn,
  note='unclaimed-11 batch 6 (residue 10); 0x465a80 stubbed')
