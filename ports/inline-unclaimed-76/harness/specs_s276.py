"""specs_s276.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 small leaves: 0x483eb0, 0x4cf130, 0x4e7d70,
0x5a7530, 0x4442b0 (the last calls its own vtable slot 0x28c with three arguments)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _buf(c):
    return [_rnd(c, 0x20), _rnd(c, 0x20)]


def _ptr_only(c):
    return [_rnd(c, 0x40), _rnd(c, 0x40)]


def _gated(c):
    e = c.emu
    e.w8(0x7142f8, c.rng.choice([0, 1]))
    return [_rnd(c, 0x400), c.rng.getrandbits(32)]


def _fwd(c):
    e = c.emu
    r = c.rng.getrandbits(32)
    vt = e.logging_vtable('f4442', 0xa4, impl={0x28c: lambda em, a: (r, None)}, argwords={0x28c: 3})
    self_ = _rnd(c, 0x40)
    e.w32(self_, vt)
    A = _rnd(c, 0x40)
    e.w32(A + 8, c.rng.getrandbits(32))
    return [self_, A, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x483eb0, 'unitVec (GUESS)', 'thiscall', None, ret=None, gen=_buf, note='batch276; ret 4')
S(0x4cf130, 'initRec (GUESS)', 'thiscall', None, ret=None, gen=_buf, note='batch276; ret 4')
S(0x4e7d70, 'storeUnlessSelf (GUESS)', 'thiscall', None, ret=None, gen=_ptr_only, note='batch276; ret 4')
S(0x5a7530, 'gatedSet (GUESS)', 'thiscall', None, ret=None, gen=_gated, note='batch276; ret 4')
S(0x4442b0, 'forward3 (GUESS)', 'thiscall', None, ret='eax', gen=_fwd, note='batch276; ret 0xc')
