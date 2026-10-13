"""specs_s336.py - decomp area 64 (docs/20-unclaimed-64.md): 0x55c970 two lookups (exe 0x5003d0), then child slot 0x5d8."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _child(c):
    e = c.emu
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Indices 0 and 1.
    data = _rnd(c, 0x100)
    if c.rng.random() < 0.4:
        e.w32(data + 8 * 1, 0)                 # the index-1 entry is zero: flag 0
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    base = c.rng.randrange(0, 3)
    e.w32(T + 0x4, base)
    e.w32(T + 0x8, c.rng.randrange(2, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)

    # Recording child: slot 0x5d8 writes its two arguments into a heap cell and returns a per-case value.
    cell = _rnd(c, 0x10)
    rv = c.rng.getrandbits(32)

    def rec(em, a):
        em.w32(cell, a[0])
        em.w32(cell + 0x4, a[1])
        return (rv, None)

    child_vt = e.logging_vtable('child55c9', 0x600, argwords={0x5d8: 2}, impl={0x5d8: rec})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x1c, child)
    return [self_, p]


S(0x55c970, 'childFlag (GUESS)', 'thiscall', None, ret='eax', gen=_child,
  note='batch336; one stack pointer p; ret 4; lookups at 0 and 1; child slot 0x5d8 with two stack words')
