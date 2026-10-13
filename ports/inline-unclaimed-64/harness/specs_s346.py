"""specs_s346.py - decomp area 64 (docs/20-unclaimed-64.md): exe table lookup 0x5003d0, in-range inputs only."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _lookup(c):
    e = c.emu
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    e.w32(inner + 0x4, 0)      # an unused field: zero, so a wrong compare against it is visible
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    base = c.rng.randrange(0, 8)
    count = c.rng.randrange(1, 8)
    e.w32(T + 0x4, base)
    e.w32(T + 0x8, count)
    # In-range inputs only: index < count and base + index < inner size, so the out-of-range hook path never runs.
    index = c.rng.randrange(0, count)
    return [T, index]


S(0x5003d0, 'lookup (GUESS)', 'thiscall', None, ret='eax', gen=_lookup,
  note='batch346; one stack word (index); ret 4; in-range inputs only (out-of-range hook path not exercised)')
