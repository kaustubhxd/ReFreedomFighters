"""specs_s1915.py - unclaimed-66 batch 1915: GUESS FUN_00628c80 (encoding/BOM dispatcher), cdecl, six arguments (T, R, mode,
pos, end, out), returns EAX.

Coverage (every case index, plus the out-of-range ones that still have a stub):
- T is a 1024-byte table with its middle at T: T[-128..127] are valid for every (signed char) mode byte; each entry is one of
  eight entry objects X. X[m] (m = 0..7) is a GUESS stub that logs (X, pos, end, out) and returns a random EAX, so every mode
  index is covered and no call goes to 0.
- R+0x49 (the mode byte) takes each interesting value: 0..5 (the BOM and mode tests), 0xfe, 0xff, and random bytes.
- R+0x4c points to P, a 4-byte result slot whose first byte is b1 (0x00, 0xbb, 0xbf, 0xef, 0x3c, random).
- pos/end: a buffer of 0..4 bytes (lengths 0, 1, 2 and 3 or 4 are the separate branches), with bytes drawn from the BOM values
  (0x00, 0x3c, 0xef, 0xbb, 0xbf, 0xfe, 0xff, 0xfd, 0xf0, 0x41) and random bytes.
- mode is 0..7 (mode 1 is the special case in most tests).
The stubs are stub_fn addresses in X (a dword table at X+0).
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


BOM_BYTES = [0x00, 0x3c, 0xef, 0xbb, 0xbf, 0xfe, 0xff, 0xfd, 0xf0, 0x41]
R49 = [0, 1, 2, 3, 4, 5, 0xfe, 0xff]
BOM_PAIRS = [(0x3c, 0x00), (0xfe, 0xff), (0xff, 0xfe), (0xef, 0xbb), (0x00, 0x00), (0xef, 0x41), (0xfe, 0x00), (0xf0, 0x41), (0xff, 0x41)]


def _entries(c):
    if getattr(c, '_bom_entries', None) is not None:
        return c._bom_entries
    xs = []
    for k in range(8):
        x = c.emu.alloc(0x20, 4)
        for m in range(8):
            def h(e, r, k=k, m=m):
                args = [e.arg32(i) for i in range(4)]
                e.calllog.append(('bom entry %d mode %d (GUESS stub)' % (k, m), 0, None, tuple(args)))
                e.ret(eax=0x1000 + 16 * k + m, argbytes=0)
            e_addr = c.emu.stub_fn('bom entry %d mode %d' % (k, m), h)
            c.emu.w32(x + 4 * m, e_addr)
        xs.append(x)
    c._bom_entries = xs
    return xs


def _bom(c):
    xs = _entries(c)
    base = c.emu.alloc(1024 + 16, 4)
    T = base + 512
    for i in range(-128, 128):
        c.emu.w32(T + 4 * i, c.rng.choice(xs))
    R = _rnd(c, 0x60)
    c.emu.wbytes(R + 0x49, bytes([c.rng.choice(R49) if c.rng.random() < 0.7 else c.rng.getrandbits(8)]))
    P = c.emu.alloc(8, 4)
    c.emu.wbytes(P, bytes([c.rng.choice([0x00, 0xbb, 0xbf, 0xef, 0x3c, c.rng.getrandbits(8)]), 0, 0, 0]))
    c.emu.w32(R + 0x4c, P)
    n = c.rng.randint(0, 4)
    buf = c.emu.alloc(8, 4)
    data = bytes(c.rng.choice(BOM_BYTES) if c.rng.random() < 0.6 else c.rng.getrandbits(8) for _ in range(4))
    if c.rng.random() < 0.6:                       # force a BOM pair so every 16-bit branch is reached often
        pair = c.rng.choice(BOM_PAIRS)
        data = bytes([pair[0], pair[1], c.rng.choice([0xbf, 0x41, 0x00]), c.rng.getrandbits(8)])
    c.emu.wbytes(buf, data)
    out = c.emu.alloc(4, 4)
    c.emu.w32(out, 0)
    mode = c.rng.randint(0, 7)
    if c.rng.random() < 0.25:                     # biased: mode 1 and the mode bytes that the mode-1 tests look at
        mode = 1
        c.emu.wbytes(R + 0x49, bytes([c.rng.choice([0, 3, 4, 5])]))
        if n >= 2:
            pair = c.rng.choice([(0x3c, 0x00), (0xef, 0xbb), (0xef, 0x41), (0xfe, 0xff), (0x00, 0x00)])
            c.emu.wbytes(buf, bytes([pair[0], pair[1], 0xbf, 0x41]))
    return [T, R, mode, buf, buf + n, out]


S(0x628c80, 'GUESS FUN_00628c80 (encoding/BOM dispatcher)', 'cdecl', None, ret='eax', gen=_bom,
  note='unclaimed-66 batch 1915; GUESS name; every mode index covered by stubs; 256-entry signed table')
