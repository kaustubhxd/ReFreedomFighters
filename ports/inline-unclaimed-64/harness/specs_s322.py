"""specs_s322.py - decomp area 64 (docs/20-unclaimed-64.md): 0x514670 countdown; tail call to child vtbl slot 0x28 (no args)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c):
    r = c.rng.random()
    if r < 0.2:
        return c.rng.choice([0.0, 1.0, -1.0, 0.5, 2.0])
    return c.rng.uniform(-3.0, 3.0)


def _count(c):
    e = c.emu
    # Global system object at 0x70039c: its float at +0x48 is the decrement.
    sys_ = _rnd(c, 0x60)
    e.wf32(sys_ + 0x48, _fl(c))
    e.w32(0x70039c, sys_)

    self_ = _rnd(c, 0x200)
    e.wf32(self_ + 0x1c9, _fl(c))
    if c.rng.random() < 0.7:
        # Child with slot 0x28 taking no stack words (the exe tail call leaves the caller's frame as it is).
        vt = e.logging_vtable('child514_', 0x40)
        child = _rnd(c, 0x40)
        e.w32(child, vt)
        e.w32(self_ + 0x134, child)
    else:
        e.w32(self_ + 0x134, 0)
    return [self_]


S(0x514670, 'countdown (GUESS)', 'thiscall', None, ret=None, gen=_count,
  note='batch322; no stack args; tail jump to child vtbl slot 0x28 when child is non-null')
