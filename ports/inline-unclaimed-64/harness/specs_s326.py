"""specs_s326.py - decomp area 64 (docs/20-unclaimed-64.md): 0x55cab0 table lookup (exe 0x5003d0) then setter (exe 0x59d430)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setter(c):
    e = c.emu
    # Lookup structure: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Index is 0.
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    table = _rnd(c, 0x10)
    e.w32(table, inner)
    e.w32(table + 0x4, c.rng.randrange(0, 8))     # base; (base + 0) * 8 stays inside the 0x100-byte data
    e.w32(table + 0x8, c.rng.randrange(1, 8))     # count
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, table)
    # self[+0x1c] = obj; obj[+0x54] = target. The target gets the mode and the exe switch runs on it.
    target = _rnd(c, 0x40)
    e.w32(target + 0x8, c.rng.getrandbits(32))
    obj = _rnd(c, 0x80)
    e.w32(obj + 0x54, target)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, obj)
    return [self_, p]


S(0x55cab0, 'setModeFromTable (GUESS)', 'thiscall', None, ret=None, gen=_setter,
  note='batch326; one stack pointer p; ret 4; exe 0x5003d0 (lookup) and 0x59d430 (setter) run as original code')
