"""specs_s289.py - unclaimed area 67, gap band: 0x5f17b0 (tail call slot 0x28 with argument 1; a null argument returns)."""
from pilot import S


def _case(c):
    if c.rng.random() < 0.2:
        c.emu.mu.ctl_flush_tb()
        return [0]
    vt = c.emu.logging_vtable('Tail28', 0x140, impl={0x28: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={0x28: 1})
    o = c.emu.alloc(0x40, 4)
    c.emu.w32(o, vt)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x5f17b0, 'FUN_5f17b0 (tailSlot28)', 'stdcall', None, ret='eax', gen=_case, note='batch289; tail call slot 0x28 with 1; null returns')
