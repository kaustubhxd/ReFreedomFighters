"""specs_s331.py - decomp area 64 (docs/20-unclaimed-64.md): 0x519b70 two lookups (exe 0x5003d0) then child slot 0x2e0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _two(c):
    e = c.emu
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Indices 0 and 1.
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    e.w32(T + 0x4, c.rng.randrange(0, 4))
    e.w32(T + 0x8, c.rng.randrange(2, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)

    # Recording child: slot 0x2e0 writes its two arguments to a heap cell (so a swapped or wrong entry shows in the
    # memory compare) and returns a value drawn once per case.
    cell = _rnd(c, 0x10)
    rv = c.rng.getrandbits(32)

    def rec(em, a):
        em.w32(cell, a[0])
        em.w32(cell + 0x4, a[1])
        return (rv, None)

    child_vt = e.logging_vtable('child519b', 0x200, argwords={0x2e0: 2}, impl={0x2e0: rec})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x14, child)
    return [self_, p]


S(0x519b70, 'twoEntries (GUESS)', 'thiscall', None, ret='eax', gen=_two,
  note='batch331; one stack pointer p; ret 4; lookups at indices 1 and 0 (exe 0x5003d0); child slot 0x2e0 with 2 args')
