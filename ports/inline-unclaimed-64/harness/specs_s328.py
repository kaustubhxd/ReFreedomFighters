"""specs_s328.py - decomp area 64 (docs/20-unclaimed-64.md): 0x5589b0 lookup (exe 0x5003d0) then search (exe 0x59e610)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _search(c):
    e = c.emu
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Index is 0.
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    e.w32(T + 0x4, c.rng.randrange(0, 8))
    e.w32(T + 0x8, c.rng.randrange(1, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)
    # obj: a counter at +0x7ce (kept 0..10 so the search stays in the object) and entries from +0x7c2, 8 bytes apart x2.
    obj = _rnd(c, 0x1000)
    e.w32(obj + 0x7ce, c.rng.randrange(0, 11))
    for i in range(12):
        e.w32(obj + 0x7c2 + 16 * i, c.rng.getrandbits(32))
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, obj)
    return [self_, p]


S(0x5589b0, 'searchEntry (GUESS)', 'thiscall', None, ret='eax', gen=_search,
  note='batch328; one stack pointer p; ret 4; exe 0x5003d0 (lookup) and 0x59e610 (search, ecx = obj) run as original code')
