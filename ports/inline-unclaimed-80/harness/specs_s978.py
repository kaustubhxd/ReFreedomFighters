"""specs_s978.py - unclaimed-80 residue-19 batch 56 (docs/20-unclaimed-80.md), see src/batch978.cpp. self is a 0xa280-byte zeroed block whose first dword
is a logging vtable with slot +0xa8 (no arguments) returning a per-case block R; R+0xc8 is a random byte (zero half the time). The argument
is 0 or 1 at random. The flag at self+0xa273 is random before the call (it must be overwritten)."""
from pilot import S


def _gen(c):
    R = c.emu.alloc(0xd0, 4)
    c.emu.wbytes(R, bytes(0xd0))
    c.emu.wbytes(R + 0xc8, bytes([0 if c.rng.random() < 0.5 else 1]))
    self_o = c.emu.alloc(0xa280, 4)
    c.emu.wbytes(self_o, bytes(0xa280))
    c.emu.w32(self_o, c.emu.logging_vtable('ZGroupA8', 0x2c, impl={0xa8: (lambda e, a, r=R: (r, None))}))
    c.emu.wbytes(self_o + 0xa273, bytes([c.rng.randint(0, 255)]))
    return [self_o, c.rng.choice([0, 1, 2, 0x100])]


S(0x54aaf0, 'vtable result then flag (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 residue-19; slot +0xa8 on self; one stack argument, ret 4; flag at +0xa273')
