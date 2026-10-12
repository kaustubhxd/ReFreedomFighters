"""specs_s194.py - unclaimed area 19 (docs/20-unclaimed-19.md): 0x5a76a0, call slot 8 then tail-jump slot 4 of a child."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fwd(c):
    e = c.emu
    r = c.rng.getrandbits(32)
    vt = e.logging_vtable('child5a76', 3, impl={4: lambda em, a: (r, None), 8: lambda em, a: (0, None)})
    child = _rnd(c, 0x40)
    e.w32(child, vt)
    self_ = _rnd(c, 0x800)
    e.w32(self_ + 0x644, child)
    return [self_]


S(0x5a76a0, 'forward2 (GUESS)', 'thiscall', None, ret='eax', gen=_fwd, note='batch194; slot 8 call then slot 4 tail jump')
