"""specs_s5746.py - unclaimed-57, band batch 46: 0x5d3a10 (GUESS). Thiscall, two stack args (w, a), ret 8, returns eax = 0. The word w equals
this+0x7a in about half the cases (the store path), otherwise not (the skip path). Leaf: no calls."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _wa(c):
    obj = _rnd(c, 0x200)
    f = c.rng.getrandbits(16)
    c.emu.wbytes(obj + 0x7a, bytes([f & 0xff, f >> 8]))
    w = f if c.rng.random() < 0.5 else (f ^ 0x8000)
    return [obj, w | (c.rng.getrandbits(16) << 16), c.rng.getrandbits(32)]


S(0x5d3a10, 'unnamed_5d3a10 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_wa,
  note='unclaimed-57 band batch 46; leaf; store to +0x48 when w matches the word at +0x7a')
