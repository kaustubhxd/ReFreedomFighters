"""specs_s5713.py - unclaimed-57, batch 13: ZSoundStream::DataNeeded (0x54e1c0). Thiscall, no arguments, returns al. Leaf (no calls).
The object's flag bytes at +0x57 and +0x1d are 0 or 1 (or random), and the dword at +0x5b is zero in about 40% of cases, so all four
paths run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dn(c):
    o = _rnd(c, 0x800)
    c.emu.w32(o + 0x5b, 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32))
    c.emu.wbytes(o + 0x57, bytes([c.rng.choice([0, 1, c.rng.getrandbits(8)])]))
    c.emu.wbytes(o + 0x1d, bytes([c.rng.choice([0, 1, c.rng.getrandbits(8)])]))
    return [o]


S(0x54e1c0, 'ZSoundStream::DataNeeded (unknown) thiscall', 'thiscall', None, ret='al', gen=_dn,
  note='unclaimed-57 batch 13; leaf; four paths on +0x5b, +0x57 and +0x1d')
