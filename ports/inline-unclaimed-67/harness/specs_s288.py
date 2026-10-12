"""specs_s288.py - unclaimed area 67, gap band: 0x5f1780 (optional link through [this+0xc], then a store at +0x30 of the second object)."""
from pilot import S


def _case(c):
    o2 = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o2, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    o1 = c.emu.alloc(0x20, 4)
    c.emu.wbytes(o1, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    c.emu.w32(o1 + 4, o2)
    self_ = c.emu.alloc(0x20, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    c.emu.w32(self_ + 0xc, o1)
    a = c.emu.alloc(0x20, 4) if c.rng.random() < 0.7 else 0
    if a:
        c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
    c.emu.mu.ctl_flush_tb()
    return [self_, a]


S(0x5f1780, 'FUN_5f1780 (linkThenStore1780)', 'thiscall', None, ret=None, gen=_case, note='batch288; optional link, then store at +0x30 of the second object')
