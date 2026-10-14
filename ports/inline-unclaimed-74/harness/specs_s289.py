"""specs_s289.py - unclaimed area 74 (docs/20-unclaimed-74.md), slice 13 leaf: 0x4d2e50 (copy with a flag byte). Stubs: this's
slot 0xb0 (returns a record or 0), the engine logger (slot 0x24, cdecl, three arguments), the memcpy import (Python copy)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _memcpy(em, rr):
    dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
    em.wbytes(dst, em.rbytes(src, n))
    em.ret(eax=dst, argbytes=0)


def _flag(c):
    e = c.emu
    e.stub_import('memcpy', _memcpy)
    logged = []

    def printf(em, rr):
        args = tuple(em.arg32(k) for k in range(3))
        em.calllog.append(('log4d2e', 0x24, None, args))
        em.ret(eax=0, argbytes=0)

    lg_vt = e.fake_vtable('log4d2e', 0x20, {0x24: printf})
    lg = _rnd(c, 0x40)
    e.w32(lg, lg_vt)
    e.w32(0x700390, lg)

    r = c.rng.random()
    obj = _rnd(c, 0x40)
    e.w8(obj + 0x10, c.rng.choice([0, 1, 2, 3]))
    rec = _rnd(c, 0x200)
    e.w32(rec, c.rng.randrange(0, 0x80))
    e.w32(rec + 4, obj)
    e.w32(rec + 8, c.rng.choice([0, 1, 2, 4]))     # the copy lands in the 4-byte local: keep size <= 4
    self_vt = e.logging_vtable('self4d2e', 0xb0 // 4 + 1, impl={0xb0: lambda em, a: (rec if r < 0.85 else 0, None)},
                               argwords={0xb0: 2})
    self_ = _rnd(c, 0x40)
    e.w32(self_, self_vt)
    bp = _rnd(c, 0x20)
    e.w8(bp, c.rng.choice([0, 1, 0x80, c.rng.getrandbits(8)]))
    return [self_, c.rng.getrandbits(32), bp]


S(0x4d2e50, 'copyFlag (GUESS)', 'thiscall', None, ret='eax', gen=_flag, note='batch289; ret 8')
