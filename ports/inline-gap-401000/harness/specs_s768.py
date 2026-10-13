"""specs_s768.py - gap band batch 768 (docs/20-gap-band-401000.md): 0x405bb0, cdecl (n, x, y, s), returns a float in st0. The arrays are
small, the count 0 to 6, the stride 0 to 3 (so the loop reads the right elements); the values are in [-10, 10]."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct


def _gen(c):
    import struct as st
    n = c.rng.randint(0, 6)
    x = c.emu.alloc(0x80, 4)
    y = c.emu.alloc(0x80, 4)
    for k in range(0x20):
        c.emu.w32(x + 4 * k, st.unpack('<I', st.pack('<f', c.rng.uniform(-10, 10)))[0])
        c.emu.w32(y + 4 * k, st.unpack('<I', st.pack('<f', c.rng.uniform(-10, 10)))[0])
    return [n, x, y, c.rng.randint(0, 3)]


S(0x405bb0, 'CRT helper 0x405bb0 (unknown) cdecl', 'cdecl', None, ret='st0', gen=_gen,
  note='gap band batch 768: st0 = c + sum (x - y)^2 over n steps (x87)')
