"""specs_s349.py - decomp area 64 (docs/20-unclaimed-64.md): exe free wrapper 0x41e2c0; mm object slot 0x10 (one word) or no manager."""
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


def _free(c):
    e = c.emu
    if c.rng.random() < 0.8:
        # mm object: its slot 0x10 takes one word (logged, so the freed pointer is compared) and returns nothing.
        mm_vt = e.logging_vtable('mm41e2c', 0x40, argwords={0x10: 1})
        mm = _rnd(c, 0x40)
        e.w32(mm, mm_vt)
        e.w32(0x70038c, mm)
    else:
        e.w32(0x70038c, 0)
        # Fallback free pointer (0x6762ec): a cdecl recorder stub (stores its word, returns).
        cell = e.alloc(8, 4)
        e.wbytes(cell, bytes(8))
        fb = ss.code(c, b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell) + b'\xc3')
        e.w32(0x6762ec, fb)
    return [c.rng.getrandbits(32)]


S(0x41e2c0, 'free (GUESS)', 'cdecl', None, ret=None, gen=_free,
  note='batch349; one stack word (pointer); cdecl; void; mm object slot 0x10 when set')
