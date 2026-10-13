"""specs_s769.py - gap band batch 769 (docs/20-gap-band-401000.md): 0x403ea0, cdecl (out, x, y, s). The three arrays hold 56 floats each; the
out array is compared through memory. s is a random float."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct as st


def _fl(c):
    return st.unpack('<I', st.pack('<f', c.rng.uniform(-10, 10)))[0]


def _gen(c):
    out = c.emu.alloc(0x100, 4)
    x = c.emu.alloc(0x100, 4)
    y = c.emu.alloc(0x100, 4)
    for k in range(0x40):
        c.emu.w32(out + 4 * k, _fl(c))
        c.emu.w32(x + 4 * k, _fl(c))
        c.emu.w32(y + 4 * k, _fl(c))
    return [out, x, y, st.unpack('<I', st.pack('<f', c.rng.uniform(-3, 3)))[0]]


S(0x403ea0, 'CRT helper 0x403ea0 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 769: 56-step x87 loop writing the out array')
