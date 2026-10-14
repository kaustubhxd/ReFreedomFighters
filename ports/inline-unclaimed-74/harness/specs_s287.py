"""specs_s287.py - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 leaves: 0x4cc690 (in-place lower-case of the string
at this's first dword) and 0x5ed3d0 (tagged pair store over an element list, index or walk)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _lower(c):
    e = c.emu
    n = c.rng.randrange(0, 40)
    s = _rnd(c, 64)
    body = bytes(c.rng.choice(b'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefgxyz0[@`{') for _ in range(n)) + b'\x00'
    e.wbytes(s, body)
    self_ = _rnd(c, 0x20)
    e.w32(self_, s)
    return [self_]


def _tagged(c):
    e = c.emu
    n = c.rng.randrange(1, 5)
    self_ = _rnd(c, 0x100)
    arr = _rnd(c, 4 * n + 8)
    els = []
    for i in range(n):
        el = _rnd(c, 0x20)
        els.append(el)
        e.w32(arr + 4 * i, el)
    e.w32(self_ + 0xcb, arr)
    e.w32(self_ + 0xcf, arr + 4 * n)
    e.w8(self_ + 0xa6, 0)
    a = c.rng.choice([c.rng.getrandbits(16), c.rng.getrandbits(32)])
    b = c.rng.choice([c.rng.getrandbits(16), c.rng.getrandbits(32)])
    if c.rng.random() < 0.5:
        e.w32(els[0] + 8, a)
        e.w16(els[0] + 0xe, b)
    c_arg = 0xffffffff if c.rng.random() < 0.5 else c.rng.randrange(0, n)
    return [self_, a & 0xffffffff, b & 0xffffffff, c_arg]


S(0x4cc690, 'lowerInPlace (GUESS)', 'thiscall', None, ret=None, gen=_lower, note='batch287; plain ret')
S(0x5ed3d0, 'setTagged (GUESS)', 'thiscall', None, ret=None, gen=_tagged, note='batch287; ret 0xc')
