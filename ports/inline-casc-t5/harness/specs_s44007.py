"""specs_s44007.py - t5 (Sonnet) batch 44007: 0x4ae160."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

NAN = 0x7fc00000


def _bits(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def g4ae160(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, this=True)
    n = r.choice([1, 2, 3, 6, 12, 20])
    base = rnd(c, 0x35 * n + 0x10)
    keys = [r.choice([1.0, 2.0, 3.0, 5.0, r.uniform(-10, 10), r.randrange(0, 4) * 1.0]) for _ in range(n)]
    for i in range(n):
        v = r.choice([_bits(keys[i]), NAN]) if r.random() < 0.05 else _bits(keys[i])
        e.w32(base + 0x35 * i, v)
    idx = r.randrange(0, n)
    top = r.choice([0, 0, 0, r.randrange(0, n), 1])
    key = r.choice([r.choice(keys), r.uniform(-12, 12), 100.0, -100.0])
    kb = NAN if r.random() < 0.05 else _bits(key)
    rest = [r.getrandbits(32) for _ in range(13)]
    return [base, idx, top, kb] + rest


S(0x4ae160, 'GUESS heap sift up 0x35 byte elements', 'fastcall', None, ret=None, gen=g4ae160, nan_heap=True, note='batch44007')
