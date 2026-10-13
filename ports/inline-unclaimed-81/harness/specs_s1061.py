"""specs_s1061.py - area 81 (residue 0), batch 1061: 0x57fa80 data initializer.
Copies arguments from stack to object fields. No exe calls, pure data movement.
"""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S, F


def g(c):
    # Allocate object for result (0x29 bytes minimum for all fields)
    o = c.emu.alloc(0x40, 4)

    # Generate random arguments (9 dwords, 1 float, 1 byte)
    args = [c.rng.randint(0, 0xffffffff) for _ in range(9)]
    f = F(c.rng.gauss(0, 100))  # Random float
    b = c.rng.randint(0, 255)   # Random byte

    # Fastcall: ecx=o, edx=unused, then 9 dwords + float + byte on stack
    return [o, 0] + args + [f, b]


S(0x57fa80, 'batch1061_init', 'fastcall', gen=g)
