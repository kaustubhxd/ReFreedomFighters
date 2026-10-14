"""specs_s5731.py - unclaimed-57, band batch 31: 0x5c7ce0 (constructor shape, returns this) and 0x5ddad0 (two float reads from a DBREAD).
Hooks: 0x469870 (no args, logged); reader B 0x4e5e80 (float in st0), hooked with a per-call counter in the DBREAD object (heap)."""
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


def _ctor(c):
    def log(em, r):
        em.calllog.append(('469870', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x469870, log)
    return [_rnd(c, 0x200)]


def _reader(c):
    base = c.rng.choice([0.0, 1.0, -2.5, 0.75, 8.0])
    c.emu.hook(0x4e5e80, lambda em, r: em.ret(st0=base + _ctr(em, 0x30) * 0.5, argbytes=0))
    db = _rnd(c, 0x40)
    c.emu.w32(db + 0x30, 0)
    return [_rnd(c, 0x200), db]


S(0x5c7ce0, 'unnamed_5c7ce0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 31; calls 0x469870 (hooked, logged); vtable 0x6b4858; clears +0x4c')
S(0x5ddad0, 'unnamed_5ddad0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_reader,
  note='unclaimed-57 band batch 31; reader 0x4e5e80 hooked with a per-call counter')
