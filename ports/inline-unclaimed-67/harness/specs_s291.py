"""specs_s291.py - unclaimed area 67: 0x5f49e0 (vslot 0x1c of the global at 0x724270 with [this+0x24]; the getter is original code)."""
from pilot import S


def _case(c):
    vt = c.emu.logging_vtable('G291', 0x140, impl={0x1c: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={0x1c: 1})
    g = c.emu.alloc(0x40, 4)
    c.emu.w32(g, vt)
    c.emu.w32(0x724270, g)
    self_ = c.emu.alloc(0x40, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x5f49e0, 'FUN_5f49e0 (callVslot1c)', 'thiscall', None, ret='eax', gen=_case, note='batch291; vslot 0x1c of the 0x724270 global')
