"""specs_s5725.py - unclaimed-57, band batch 25: 0x5d3ac0 and 0x5d6e60 (thiscall, one DBREAD argument, ret 4). Readers: 0x4e5e60 (dword)
and 0x4e5e80 (float in st0), hooked. Each returns a value that depends on a per-reader counter in the DBREAD object (heap), so repeated
calls differ and the order matters. Leaves otherwise."""
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


def _readers(c):
    base60 = c.rng.getrandbits(32)
    base80 = c.rng.choice([0.0, 1.0, -2.5, 0.75, 8.0])
    c.emu.hook(0x4e5e60, lambda em, r: em.ret(eax=(base60 + _ctr(em, 0x34) * 0x9e3779b9) & 0xffffffff, argbytes=0))
    c.emu.hook(0x4e5e80, lambda em, r: em.ret(st0=base80 + _ctr(em, 0x30) * 0.5, argbytes=0))


def _gen(c):
    _readers(c)
    db = _rnd(c, 0x40)
    c.emu.w32(db + 0x30, 0)
    c.emu.w32(db + 0x34, 0)
    return [_rnd(c, 0x200), db]


S(0x5d3ac0, 'unnamed_5d3ac0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-57 band batch 25; readers 0x4e5e60/0x4e5e80 hooked with per-call counters')
S(0x5d6e60, 'unnamed_5d6e60 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-57 band batch 25; reader 0x4e5e80 hooked with a per-call counter')
