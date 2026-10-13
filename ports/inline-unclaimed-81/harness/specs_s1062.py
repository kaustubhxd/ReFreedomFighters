"""specs_s1062.py - area 81 (residue 0), batch 1062: 0x634340 __allmul.
CRT 64-bit multiply: (a_high:a_low) * b, returns EDX:EAX.
"""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def g(c):
    # Generate random 64-bit and 32-bit values for multiplication
    a_low = c.rng.randint(0, 0xffffffff)
    a_high = c.rng.randint(0, 0xffffffff)
    b = c.rng.randint(1, 0xffffffff)  # Avoid b=0 to see actual multiplication
    unused = c.rng.randint(0, 0xffffffff)  # 4th argument (unused)

    # Stdcall with 4 args: a_low, a_high, b, unused (ret 0x10)
    # Returns 64-bit value in EDX:EAX
    return [a_low, a_high, b, unused]


S(0x634340, 'batch1062_allmul', 'stdcall', gen=g, ret='edx:eax')
