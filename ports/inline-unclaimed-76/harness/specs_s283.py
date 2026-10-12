"""specs_s283.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 logger-using leaf: 0x4d2d30. Stubs: this's slot
0xb0 (returns a record), the engine logger at 0x700390 (slot 0x24, cdecl, three arguments), exe copy 0x634d22 (runs)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _memcpy(em, rr):                       # the exe's import: cdecl (dst, src, n), stubbed with a Python copy
    dst, src, n = em.arg32(0), em.arg32(1), em.arg32(2)
    em.wbytes(dst, em.rbytes(src, n))
    em.ret(eax=dst, argbytes=0)


def _copy(c):
    e = c.emu
    e.stub_import('memcpy', _memcpy)

    def printf(em, r):                      # cdecl: (logger, fmt, a); the caller pops
        args = tuple(em.arg32(k) for k in range(3))
        em.calllog.append(('log4d2d', 0x24, None, args))
        em.ret(eax=0, argbytes=0)

    lg_vt = e.fake_vtable('log4d2d', 0x20, {0x24: printf})
    lg = _rnd(c, 0x40)
    e.w32(lg, lg_vt)
    e.w32(0x700390, lg)

    rec = c.rng.random()
    obj = _rnd(c, 0x40)
    e.w8(obj + 0x10, c.rng.choice([0, 8, 1, 9]))
    r = _rnd(c, 0x200)
    e.w32(r, c.rng.randrange(0, 0x80))           # base offset; dst = base + 0xc + r
    e.w32(r + 4, obj)
    e.w32(r + 8, c.rng.randrange(0, 0x40))       # size
    vt = e.logging_vtable('self4d2d', 0xb0 // 4 + 1, impl={0xb0: lambda em, a: (r if rec < 0.9 else 0, None)},
                          argwords={0xb0: 2})
    self_ = _rnd(c, 0x40)
    e.w32(self_, vt)
    b = _rnd(c, 0x100)
    a = c.rng.getrandbits(32)
    return [self_, a, b]


S(0x4d2d30, 'copyRec (GUESS)', 'thiscall', None, ret='eax', gen=_copy, note='batch283; logger slot 0x24 cdecl; ret 8')
