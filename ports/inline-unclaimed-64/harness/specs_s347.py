"""specs_s347.py - decomp area 64 (docs/20-unclaimed-64.md): exe predicate 0x4da3a0 over obj[+0x54][+0x10][+8]."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _pred(c):
    e = c.emu
    obj = _rnd(c, 0x80)
    r = c.rng.random()
    if r < 0.15:
        e.w32(obj + 0x54, 0)                              # first level null
    else:
        a = _rnd(c, 0x40)
        e.w32(obj + 0x54, a)
        if r < 0.3:
            e.w32(a + 0x10, 0)                            # second level null
        else:
            b = _rnd(c, 0x40)
            e.w32(a + 0x10, b)
            e.w32(b + 0x8, 0 if r < 0.5 else c.rng.getrandbits(32) | 1)   # third-level word zero or nonzero
    return [obj]


S(0x4da3a0, 'hasTarget (GUESS)', 'thiscall', None, ret='al', gen=_pred,
  note='batch347; no stack words; returns al; three null-checked levels')
