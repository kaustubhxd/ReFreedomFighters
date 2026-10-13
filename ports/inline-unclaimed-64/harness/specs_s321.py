"""specs_s321.py - decomp area 64 (docs/20-unclaimed-64.md): 0x4d2ef0 calls self vtbl slot 0xb0, returns an offset of the result."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _lookup(c):
    e = c.emu
    r_obj = _rnd(c, 0x40)                      # the object the slot returns (its first word is read)
    r_val = 0 if c.rng.random() < 0.25 else r_obj
    vt = e.logging_vtable('self4d2e', 0x80, impl={0xb0: lambda em, a: (r_val, None)}, argwords={0xb0: 2})
    self_ = _rnd(c, 0x40)
    e.w32(self_, vt)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4d2ef0, 'lookup (GUESS)', 'thiscall', None, ret='eax', gen=_lookup,
  note='batch321; self vtbl slot 0xb0 with (x, 0); ret 8; result offset when nonzero')
