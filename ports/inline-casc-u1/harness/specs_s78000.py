"""specs_s78000.py - batch 78000: 0x4045a0 (float array processing with stack allocation)."""
import struct
from pilot import S
from recruits_util import rnd

def _g4045a0(c):
    r = c.rng
    em = c.emu
    arr1 = em.alloc(100, 4)
    for i in range(25):
        f = r.uniform(-1000.0, 1000.0)
        bits = struct.unpack('<I', struct.pack('<f', f))[0]
        em.w32(arr1 + i*4, bits)
    count = r.choice([0, 1, 2, 3, 5, 10, 15, 20, 25])
    range_val = r.choice([1, 10, 100, 1000])
    return [arr1, range_val, count]

S(0x4045a0, 'GUESS process float arrays', 'cdecl', None, ret=None, gen=_g4045a0)
