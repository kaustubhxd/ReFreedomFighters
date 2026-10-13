"""specs_s341.py - decomp area 64 (docs/20-unclaimed-64.md): 0x501430 vector length into a table entry; child slot 0x8c; exe lookups."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ff(c):
    # A float in a sane range, or a special value (0, negative, large).
    r = c.rng.random()
    if r < 0.1:
        return c.rng.choice([0.0, -0.0, 1.0, -1.0, 1e-3, 3000.0])
    return c.rng.uniform(-20.0, 20.0)


def _table(c, base_max=3):
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    c.emu.w32(inner, data)
    c.emu.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    c.emu.w32(T, inner)
    c.emu.w32(T + 0x4, c.rng.randrange(0, base_max))
    c.emu.w32(T + 0x8, c.rng.randrange(3, 8))
    return T, data


def _len(c):
    e = c.emu
    # Table T: the three entries read as the vector. Table T2: the entry that receives the length (tag byte 0 or 2).
    T, data = _table(c)
    for i in range(3):
        base = e.r32(T + 0x4)
        e.wf32(data + 8 * (base + i), _ff(c))
    T2, data2 = _table(c)
    base2 = e.r32(T2 + 0x4)
    e.wbytes(data2 + 8 * base2 + 4, bytes([c.rng.choice([0, 2])]))

    # Child: slot 0x8c takes a pointer (one word), writes three new floats through it, and pops the word.
    new = [_ff(c), _ff(c), _ff(c)]
    upd = c.rng.random() < 0.6

    def upd8c(em, a):
        if upd:
            for i in range(3):
                em.wbytes(a[0] + 4 * i, struct.pack('<f', new[i]))
        return (0, None)

    child_vt = e.logging_vtable('child501', 0x100, argwords={0x8c: 1}, impl={0x8c: upd8c})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0xc, child)
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)
    e.w32(p + 0x8, T2)
    return [self_, p]


S(0x501430, 'setLength (GUESS)', 'thiscall', None, ret=None, gen=_len,
  note='batch341; one stack pointer p; ret 4; lookups at 2, 1, 0 and 0 of T2; child slot 0x8c (one word) updates the vector')
