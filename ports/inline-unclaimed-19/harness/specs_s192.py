"""specs_s192.py - unclaimed area 19 (docs/20-unclaimed-19.md): 0x5059e0 forwarder to a child's vtable slot 0x220."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fwd(c):
    e = c.emu
    val = c.rng.getrandbits(32)
    vt = e.logging_vtable('child5059', 0x89, impl={0x220: lambda em, a: (val, None)}, argwords={0x220: 1})
    child = _rnd(c, 0x40)
    e.w32(child, vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x14, child)
    return [self_, c.rng.getrandbits(32)]


S(0x5059e0, 'forward (GUESS)', 'thiscall', None, ret='eax', gen=_fwd, note='batch192; child vtable slot 0x220; stack arg unused')
