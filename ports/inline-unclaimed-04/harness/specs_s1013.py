"""specs_s1013.py - unclaimed-04 batch 14 (docs/20-unclaimed-04.md): comparator 0x5bfdd0, the qsort compare for the
0x17-byte records of CEntityTracker's builder (cdecl, two pointer arguments, plain ret).
Records are 0x17 bytes with the key float at +4; the spec gives keys from a small set so equal keys (which must give -1)
come up often, plus NaN and the +/- zero cases. The threshold at 0x6785d0 is 0.0 in the image."""
import struct

from pilot import S


def _rec(c, key):
    r = c.emu.alloc(0x20, 4)
    c.emu.wbytes(r, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    c.emu.wbytes(r + 4, struct.pack('<f', key))
    return r


def _args(c):
    keys = [0.0, -0.0, 1.5, -1.5, 3.25, float('nan'), c.rng.uniform(-100.0, 100.0)]
    ka = c.rng.choice(keys)
    kb = c.rng.choice(keys) if c.rng.random() < 0.7 else ka
    return [_rec(c, ka), _rec(c, kb)]


S(0x5bfdd0, 'CEntityTracker builder compare (unknown) cdecl', 'cdecl', None, ret='eax', gen=_args,
  note='unclaimed-04 batch 14; qsort comparator for 0x17-byte records (GUESS name)')
