"""specs_s342.py - decomp area 64 (docs/20-unclaimed-64.md): 0x5f4630 vector grow; exe allocator 0x41e290 and free 0x41e2c0 are patched."""
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


def _grow(c):
    e = c.emu
    # Allocator stub (cdecl): records its size word in a cell, returns a block of 0x400 bytes made for this case.
    # Free stub (cdecl): records its pointer word in a cell and returns.
    cell = e.alloc(8, 4)
    e.wbytes(cell, bytes(8))
    block = _rnd(c, 0x400)
    alloc_stub = (b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell)     # mov edx,[esp+4]; mov [cell], edx
                  + b'\xb8' + ss.P(block) + b'\xc3')                  # mov eax, block; ret
    free_stub = (b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell + 4)   # mov edx,[esp+4]; mov [cell+4], edx
                 + b'\xc3')                                          # ret
    ss.patch(c, 0x41e290, ss.code(c, alloc_stub))
    ss.patch(c, 0x41e2c0, ss.code(c, free_stub))

    # The old buffer holds n dwords (n < 0x40, so the new size fits in the 0x400-byte block).
    n = c.rng.randrange(0, 0x40)
    old = _rnd(c, 0x200)
    self_ = _rnd(c, 0x10)
    e.w32(self_, old)
    e.w32(self_ + 0x4, n)
    return [self_]


S(0x5f4630, 'growArray (GUESS)', 'thiscall', None, ret=None, gen=_grow,
  note='batch342; no stack words; exe allocator 0x41e290 and free 0x41e2c0 patched to stubs (both sides)')
