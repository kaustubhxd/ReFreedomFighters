"""specs_s4158.py - unclaimed-41 batch 50 (residue 0): 0x483b40 (dword at this+0x45d+4*i); thiscall."""
from pilot import S


def _a(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _pb(c):
    # p points to a dword index in 0..0x1f0 (the byte read stays inside a 0x200-byte region at [this+8])
    p = c.emu.alloc(4, 4)
    c.emu.w32(p, c.rng.randint(0, 0x1f0))
    return p


def _layout(c):
    return (lambda c: [_a(c,0x800), c.rng.randint(0,127)])(c)


S(0x483b40, 'FUN_483b40', 'thiscall', None, ret='eax', gen=_layout, note='unclaimed-41 batch 50; dword at this+0x45d+4*i')
