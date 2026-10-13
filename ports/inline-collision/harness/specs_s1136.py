"""specs_s1136.py - collision thread batch 1136 (GUESS name): 0x4ae2b0, sorted insertion of 0x35-byte records. The array has a
sentinel record first (its float is far below any key), so the shift loop stays inside the array. The insertion point is one of
the records after the sentinel; the key's first float is drawn across the records' range (some keys stop the loop at once).
The stack arguments are 14 words: key (4 floats), v2 (4 words), v3 (4 words), i4, b1."""
import struct
from pilot import S, F


def _f2w(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _ins(c):
    e, r = c.emu, c.rng
    n = r.randrange(3, 9)
    arr = e.alloc(0x35 * n + 0x40, 16)
    e.wbytes(arr, bytes(r.getrandbits(8) for _ in range(0x35 * n + 0x40)))
    e.wf32(arr, -1e30)                                  # sentinel record: float far below any key
    for i in range(1, n):
        e.wf32(arr + 0x35 * i, r.uniform(-100, 100))
    p = arr + 0x35 * r.randrange(1, n)
    kf = [r.uniform(-120, 120) for _ in range(4)]
    if r.random() < 0.5:                                # a record whose first float equals the key's: the strict test matters
        e.wf32(arr + 0x35 * r.randrange(1, n), kf[0])
    key = [_f2w(v) for v in kf]
    v2 = [r.getrandbits(32) for _ in range(4)]
    v3 = [r.getrandbits(32) for _ in range(4)]
    return [p] + key + v2 + v3 + [r.getrandbits(32), r.getrandbits(8)]


S(0x4ae2b0, 'sorted insertion of a 0x35-byte record (name GUESS)', 'thiscall', None, gen=_ins, note='batch1136')
