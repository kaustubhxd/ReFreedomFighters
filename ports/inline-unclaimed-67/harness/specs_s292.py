"""specs_s292.py - unclaimed area 67: 0x5fc260 (call chain on p with ext 0x5f49e0, slots 0x24/0x28 on p, slots 0x14/0x1c on the
getter object at 0x724270). Callee conventions: 0x24 none; 0x28 and 0x14 caller-cleaned; 0x1c callee-cleaned (4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _case(c):
    p_vt = c.emu.logging_vtable('P260', 0x140, impl={0x24: lambda e, a: (c.rng.getrandbits(32), None),
                                                     0x28: lambda e, a: (c.rng.getrandbits(32), None)},
                                argwords={0x24: 0, 0x28: 0})
    g_vt = c.emu.logging_vtable('G260', 0x140, impl={0x14: lambda e, a: (0, None),
                                                    0x1c: lambda e, a: (c.rng.getrandbits(32), None)},
                                argwords={0x14: 0, 0x1c: 1})
    g = c.emu.alloc(0x40, 4)
    c.emu.w32(g, g_vt)
    c.emu.w32(0x724270, g)
    tbl_base = c.emu.alloc(0x40, 4)
    c.emu.wbytes(tbl_base, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    for k in range(16):
        c.emu.w32(0x6efbe4 + 4 * k, c.rng.getrandbits(32)) if False else None
    p = c.emu.alloc(0x100, 4)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(p, p_vt)
    c.emu.w32(p + 0x16, c.rng.getrandbits(32))
    c.emu.w32(p + 0xac2, c.rng.getrandbits(32))
    c.emu.wbytes(p + 0xac, bytes([c.rng.choice([0, 1, 4, 5, 0x14, 0xff]), 0]))
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x5fc260, 'FUN_5fc260 (callChain5fc260)', 'stdcall', None, ret='eax', gen=_case, note='batch292; inline asm call chain')
