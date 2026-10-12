"""specs_s195.py - unclaimed area 19 (docs/20-unclaimed-19.md): 0x519760 calls exe helper 0x5003d0 and child slot 0x2d0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fwd(c):
    e = c.emu
    # table T: [T] = inner, [T+4] = base, [T+8] = count; inner: [inner] = data pointer, [inner+8] = size
    data = _rnd(c, 0x1000)
    inner = _rnd(c, 0x200)
    e.w32(inner, data)
    e.w32(inner + 8, 0x100)
    table = _rnd(c, 0x40)
    e.w32(table, inner)
    e.w32(table + 4, c.rng.randrange(0, 0x80))
    e.w32(table + 8, 0x10)
    arg = _rnd(c, 0x40)
    e.w32(arg + 4, table)
    r = c.rng.getrandbits(32)
    vt = e.logging_vtable('child519', 0xb5, impl={0x2d0: lambda em, a: (r, None)}, argwords={0x2d0: 1})
    child = _rnd(c, 0x40)
    e.w32(child, vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x14, child)
    return [self_, arg]


S(0x519760, 'floatForward (GUESS)', 'thiscall', None, ret='eax', gen=_fwd, note='batch195; calls exe 0x5003d0; ret 4')
