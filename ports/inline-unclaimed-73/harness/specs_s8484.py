"""specs_s8484.py - residue 6 batch 84 (GUESS names).
FUN_004e4fe0 (thiscall, one stack argument, ret 4): the argument (a 32-bit float pattern) is stored at this+0x1d.
FUN_004d1c60 (thiscall, one stack argument, ret 4): p = vtable +0x3c on this with the argument; returns the byte at p (al)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_store(c):
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


def _gen_byte(c):
    e = c.emu
    buf = _rnd(c, 0x20)
    o = _rnd(c, 0x40)
    e.w32(o, e.logging_vtable('d1c60', 0x80 // 4, impl={0x3c: (lambda v: (lambda em, a: (v, None)))(buf)},
                              argwords={0x3c: 1}))
    return [o, c.rng.getrandbits(32)]


S(0x4e4fe0, 'GUESS FUN_004e4fe0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_store,
  note='residue 6 batch 84; [this+0x1d] = arg (float bits); ret 4')
S(0x4d1c60, 'GUESS FUN_004d1c60 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_byte,
  note='residue 6 batch 84; p = vt+0x3c(arg); returns byte at p')
