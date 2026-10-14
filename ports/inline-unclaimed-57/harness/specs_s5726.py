"""specs_s5726.py - unclaimed-57, band batch 26: 0x5dd690 (thiscall, one DBREAD arg) and 0x5c7c80 (thiscall, two args, ret 8). Hooks:
reader A 0x4e5e60 (dword, per-call counter in the DBREAD object), reader B 0x4e5e40 (word, counter), reader S 0x4e5ea0 (returns a fixed
pointer chosen in gen), and the helper 0x47bde0 (thiscall, one argument, logged: (ECX, argument)). Recording stubs only."""
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


def _hooks(c):
    base60 = c.rng.getrandbits(32)
    base40 = c.rng.getrandbits(32)
    ptr = _rnd(c, 0x40)
    c.emu.hook(0x4e5e60, lambda em, r: em.ret(eax=(base60 + _ctr(em, 0x34) * 0x9e3779b9) & 0xffffffff, argbytes=0))
    c.emu.hook(0x4e5e40, lambda em, r: em.ret(eax=(base40 ^ (_ctr(em, 0x38) * 3)) & 0xffffffff, argbytes=0))
    c.emu.hook(0x4e5ea0, lambda em, r: em.ret(eax=ptr, argbytes=0))
    def helper(em, r):
        em.calllog.append(('47bde0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    c.emu.hook(0x47bde0, helper)


def _db(c):
    _hooks(c)
    db = _rnd(c, 0x40)
    c.emu.w32(db + 0x34, 0)
    c.emu.w32(db + 0x38, 0)
    return db


def _g1(c):
    return [_rnd(c, 0x200), _db(c)]


def _g2(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32), _db(c)]


S(0x5dd690, 'unnamed_5dd690 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g1,
  note='unclaimed-57 band batch 26; readers 0x4e5e60 hooked; helper 0x47bde0 hooked and logged')
S(0x5c7c80, 'unnamed_5c7c80 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g2,
  note='unclaimed-57 band batch 26; readers 0x4e5ea0 and 0x4e5e40 hooked')
