"""specs_s4161.py - unclaimed-41 batch 50 (residue 0): 0x4e5480 (indexed byte); thiscall."""
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
    self_ = _a(c, 0x800)
    base = _a(c, 0x200)          # [this+8] is the base of the byte table
    c.emu.w32(self_ + 8, base)
    return [self_, _pb(c)]


S(0x4e5480, 'FUN_4e5480', 'thiscall', None, ret='al', gen=_layout, note='unclaimed-41 batch 50; indexed byte')
