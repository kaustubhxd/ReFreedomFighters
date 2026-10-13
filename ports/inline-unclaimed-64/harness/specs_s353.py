"""specs_s353.py - decomp area 64 residue-18 pass: 0x5625a0; exe helpers 0x562440 (no words) and 0x563510 (one word) stubbed (GUESS)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _reset(c):
    e = c.emu
    # Both helpers record ecx (and the word for 0x563510) and count their calls.
    cell = e.alloc(16, 4)
    e.wbytes(cell, bytes(16))
    ss.patch(c, 0x562440, ss.code(c, b'\x89\x0d' + ss.P(cell) + b'\xc3'))                       # mov [cell], ecx; ret
    ss.patch(c, 0x563510, ss.code(c, b'\x89\x0d' + ss.P(cell + 4)                               # mov [cell+4], ecx
                                  + b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(cell + 8)          # mov edx,[esp+4]; mov [cell+8], edx
                                  + b'\xc2\x04\x00'))                                            # ret 4
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [self_]


S(0x5625a0, 'resetTagged (GUESS)', 'thiscall', None, ret=None, gen=_reset,
  note='batch353; no stack words; exe 0x562440 (no words) and 0x563510 (one word) stubbed (GUESS)')
