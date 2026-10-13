"""specs_s348.py - decomp area 64 (docs/20-unclaimed-64.md): exe allocator 0x41e290; mm object slot 0x8 and the fallback pointer at 0x6762f0."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _alloc(c):
    e = c.emu
    ret = c.rng.getrandbits(32)
    # mm object: its slot 0x8 takes one word and returns a value (logging, so the size argument is compared).
    mm_vt = e.logging_vtable('mm41e2', 0x20, argwords={0x8: 1}, impl={0x8: lambda em, a: (ret, None)})
    mm = _rnd(c, 0x40)
    e.w32(mm, mm_vt)
    if c.rng.random() < 0.7:
        e.w32(0x70038c, mm)
    else:
        e.w32(0x70038c, 0)
        # Fallback: a stub at the pointer target that records its (masked) size word and returns a fixed value.
        cell = e.alloc(8, 4)
        e.wbytes(cell, bytes(8))
        fb = ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell) + b'\xb8' + ss.P(0x2468) + b'\xc3')
        e.w32(0x6762f0, fb)
    size = c.rng.getrandbits(32)
    return [size]


S(0x41e290, 'alloc (GUESS)', 'cdecl', None, ret='eax', gen=_alloc,
  note='batch348; one stack word (size); cdecl; mm object slot 0x8 or the fallback pointer 0x6762f0')
