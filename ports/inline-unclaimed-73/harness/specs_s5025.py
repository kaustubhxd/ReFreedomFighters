"""specs_s5025.py - area 73 batch 50 (gap band, GUESS name). FUN_4f00d0: index = this+0x1c. When index >= 7 it returns
the index. Otherwise it returns vtable slot +0x240 on this with (index, byte at this+0x8e), zero-extended."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    idx = c.rng.choice([c.rng.randint(0, 6), c.rng.randint(7, 0x20), c.rng.getrandbits(32)])
    e.w32(o + 0x1c, idx)
    e.wbytes(o + 0x8e, bytes([c.rng.getrandbits(8)]))
    rv = c.rng.getrandbits(32)
    vt = e.logging_vtable('f00d0', 0x92, impl={0x240: (lambda v: (lambda em, a: (v, None)))(rv)}, argwords={0x240: 2})
    e.w32(o, vt)
    return [o]


S(0x4f00d0, 'GUESS FUN_4f00d0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 73 batch 50; index = this+0x1c; index >= 7 returns it, else vt+0x240(index, byte +0x8e)')
