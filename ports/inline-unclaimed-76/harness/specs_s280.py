"""specs_s280.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 leaf: 0x438c30, a tagged head accessor."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _head(c):
    e = c.emu
    self_ = _rnd(c, 0x40)
    choice = c.rng.random()
    if choice < 0.15:
        e.w32(self_ + 8, 0)
    else:
        p = _rnd(c, 0x40)
        tag = c.rng.choice([1, 1, 3, 2, c.rng.getrandbits(32)])
        e.w32(p, tag)
        if c.rng.random() < 0.5:
            e.w32(p + 8, 0 if c.rng.random() < 0.3 else _rnd(c, 0x40))
        else:
            e.w32(p + 8, c.rng.getrandbits(32))
        e.w32(self_ + 8, p)
    return [self_]


S(0x438c30, 'headAddr (GUESS)', 'thiscall', None, ret='eax', gen=_head, note='batch280; no args')
