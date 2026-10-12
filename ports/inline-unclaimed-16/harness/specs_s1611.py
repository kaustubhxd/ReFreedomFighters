"""specs_s1611.py - unclaimed-16 batch 11 (docs/20-unclaimed-16.md): ZInputActions::DeActivateMap(const char*). Slot 0x58
of the object is a logging vtable that returns a chosen map object (or 0); the map object is 0x40 random bytes so the
dword at +0x29 and the bytes at +0x2e and +0x2f are inside it. The logged callee is NOT verified."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _deact(c):
    m = _rnd(c, 0x40)
    ptr = 0 if c.rng.random() < 0.2 else m
    self_ = _rnd(c, 0x1000)
    self_vt = c.emu.logging_vtable('zinput_deact', 0x100, impl={0x58: lambda e, a, p=ptr: (p, None)},
                                   argwords={0x58: 1})
    c.emu.w32(self_, self_vt)
    return [self_, c.rng.getrandbits(32)]


S(0x43abe0, 'ZInputActions::DeActivateMap (unknown) thiscall', 'thiscall', None, ret='eax', gen=_deact,
  note='unclaimed-16 b11; slot 0x58 gives map object; clears dword +0x29, ANDs bytes +0x2e and +0x2f')
