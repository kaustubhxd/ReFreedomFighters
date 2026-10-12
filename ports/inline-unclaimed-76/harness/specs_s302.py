"""specs_s302.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4b91f0 (SEH frame not reproduced). Stubs: the
frees 0x634273 and 0x4690b0 (cdecl, logged), the dispatch callback 0x7003b0 (always set; the exe asserts when null), and the
engine-object slot 0x34 (logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dtor(c):
    e = c.emu

    def free2(em, r):
        em.calllog.append(('free634', 0x634273, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    def h4690(em, r):
        em.calllog.append(('h4690b0', 0x4690b0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    def cbh(em, r):
        em.calllog.append(('cb7003', 0x7003b0, ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x634273, free2)
    e.hook(0x4690b0, h4690)
    cb = e._new_stub('cb4b9', cbh)
    e.w32(0x7003b0, cb)

    o_vt = e.logging_vtable('eng9b4b', 0x0e, impl={}, argwords={0x34: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    self_ = _rnd(c, 0x100)
    e.w32(self_ + 0x8d, c.rng.getrandbits(32))
    e.w32(self_ + 0x6d, c.rng.getrandbits(32))
    flags = c.rng.choice([0, 1, 2, 4, 5, 3, 7, c.rng.getrandbits(32)])
    return [self_, flags]


S(0x4b91f0, 'dtorC (GUESS)', 'thiscall', None, ret='eax', gen=_dtor, note='batch302; ret 4; SEH frame not reproduced')
