"""specs_s303.py - decomp area 39 (docs/20-unclaimed-39.md): 0x4db460 gated copy; calls exe 0x4e2c60, 0x4419f0, 0x441940."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gate(c):
    e = c.emu
    # Global system object at 0x70039c; its child at +0x9b has a vtable whose slot 0x70 returns al (the gate).
    flag = c.rng.getrandbits(8) & 1
    vt = e.logging_vtable('child4db4', 0x40, impl={0x70: lambda em, a: (flag if c.rng.random() < 0.8 else 0, None)})
    child = _rnd(c, 0x40)
    e.w32(child, vt)
    sys_ = _rnd(c, 0x100)
    e.w32(sys_ + 0x9b, child)
    e.w32(0x70039c, sys_)

    self_ = _rnd(c, 0x80)
    r = c.rng.random()
    if r < 0.3:
        e.w32(self_ + 0x3c, c.rng.getrandbits(32) | 0x40000)
    else:
        e.w32(self_ + 0x3c, c.rng.getrandbits(32) & ~0x40000 & 0xffffffff)
    if c.rng.random() < 0.2:
        e.w32(self_ + 0x4c, 0)               # 0.0 ordered: returns false
    else:
        e.wf32(self_ + 0x4c, c.rng.uniform(-100.0, 100.0)) if c.rng.random() < 0.9 else e.w32(self_ + 0x4c, c.rng.getrandbits(32))
    e.w32(self_ + 0x50, c.rng.getrandbits(32) if c.rng.random() < 0.8 else 0)

    a = 0 if c.rng.random() < 0.2 else _rnd(c, 0x40)
    b = _rnd(c, 0x40)
    return [self_, a, b]


S(0x4db460, 'gateCopy (GUESS)', 'thiscall', None, ret='al', gen=_gate,
  note='batch303; a, b stack args; ret 8; vtbl slot 0x70 on the global child at sys+0x9b; exe 0x4e2c60/0x4419f0/0x441940')
