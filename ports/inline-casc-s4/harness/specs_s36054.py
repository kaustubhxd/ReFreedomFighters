"""specs_s36054.py - cascade s4 batch 36054: 0x4d1060 (best-fit allocation from a free table)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _g4d1060(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    arena = e.alloc(0x2000, 16)
    e.wbytes(arena, bytes([0x66]) * 0x2000)
    n = r.choice([0, 1, 2, 3, 5, 8])
    tab = e.alloc(8 * 10, 4)
    e.wbytes(tab, bytes([0x77]) * 80)
    need_hint = r.choice([0x10, 0x18, 0x20, 0x28])
    for i in range(n):
        addr = arena + 0x200 * i + 0x10 * r.randint(0, 3)
        size = r.choice([0, 4, 8, 0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x28, 0x2c, 0x30, 0x40, 0x100, 0xffffffff & 0x500, r.randint(0, 0x200)])
        e.w32(tab + 8 * i, addr)
        e.w32(tab + 8 * i + 4, size)
    a = rnd(c, 0x20)
    e.w32(a, tab)
    e.w32(a + 8, n)
    size = r.choice([0, 1, 4, 5, 8, 9, 0x10, 0x11, 0x14, 0x18, 0x1d, 0x20, 0x21, 0x40, 0x80, r.randint(0, 0x100)])
    return [a, size]


S(0x4d1060, 'GUESS best-fit allocation from a free table', 'thiscall', None, ret='eax', gen=_g4d1060, note='batch36054')
