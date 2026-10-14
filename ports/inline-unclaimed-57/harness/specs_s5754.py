"""specs_s5754.py - unclaimed-57, band batch 54 (GUESS): 0x5c65e0 and 0x5d6240 (thiscall, one DBREAD argument, ret 4). Readers: 0x4e5e60 (dword,
a per-call counter at db+0x34 makes repeated calls differ) and 0x4e5ea0 (a fixed pointer chosen in gen). The DBREAD is a heap block."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ctr(em, off):
    p = em.reg('ecx')
    n = em.r32(p + off)
    em.w32(p + off, (n + 1) & 0xffffffff)
    return n


def _rd(c):
    base = c.rng.getrandbits(32)
    ptr = _rnd(c, 0x40)
    c.emu.hook(0x4e5e60, lambda em, r: em.ret(eax=(base + _ctr(em, 0x34) * 0x9e3779b9) & 0xffffffff, argbytes=0))
    c.emu.hook(0x4e5ea0, lambda em, r: em.ret(eax=ptr, argbytes=0))
    db = _rnd(c, 0x40)
    c.emu.w32(db + 0x34, 0)
    return [_rnd(c, 0x200), db]


S(0x5c65e0, 'unnamed_5c65e0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_rd,
  note='unclaimed-57 band batch 54; readers 0x4e5e60 (counter) and 0x4e5ea0 (fixed pointer) hooked')
S(0x5d6240, 'unnamed_5d6240 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_rd,
  note='unclaimed-57 band batch 54; reader 0x4e5e60 hooked (counter); flag byte at +0x7a')
