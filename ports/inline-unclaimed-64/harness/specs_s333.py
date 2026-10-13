"""specs_s333.py - decomp area 64 (docs/20-unclaimed-64.md): 0x55bcf0 sets or clears a flag bit chosen by a table entry."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flag(c):
    e = c.emu
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Indices 0 and 1.
    data = _rnd(c, 0x100)
    base = c.rng.randrange(0, 4)
    if c.rng.random() < 0.5:
        e.w32(data + 8 * base, 0)                    # index-0 entry is zero: the clear branch
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    e.w32(T + 0x4, base)
    e.w32(T + 0x8, c.rng.randrange(2, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)
    # Global at 0x7003b8: its +0x2c15 word is the sub-object; the flags word is sub[+0x423].
    sub = _rnd(c, 0x500)
    g = _rnd(c, 0x2c20)
    e.w32(g + 0x2c15, sub)
    e.w32(0x7003b8, g)
    self_ = _rnd(c, 0x40)
    return [self_, p]


S(0x55bcf0, 'setFlagBit (GUESS)', 'thiscall', None, ret=None, gen=_flag,
  note='batch333; one stack pointer p; ret 4; lookups at 0 and 1; flags word sub[+0x423] via global 0x7003b8')
