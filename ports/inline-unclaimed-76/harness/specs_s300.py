"""specs_s300.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue 15: 0x4ce9b0, a logged walk. Stubs: the engine logger
(0x700390: slot 0x20 returns one of two report objects by its second argument), the report objects (slot 0x2c, cdecl, logged
without the stack-address argument), and this's slots 0x14, 0x4c and 0x5c (the out flag is written; pointers not logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _walk(c):
    e = c.emu
    rep_a_vt = e.fake_vtable('repA4c', 0x2c // 4 + 1, {0x2c: lambda em, r: _report(em, 'repA', 4)})
    rep_b_vt = e.fake_vtable('repB4c', 0x2c // 4 + 1, {0x2c: lambda em, r: _report(em, 'repB', 3)})
    repA = _rnd(c, 0x40)
    e.w32(repA, rep_a_vt)
    repB = _rnd(c, 0x40)
    e.w32(repB, rep_b_vt)

    def lg_get(em, r):
        a0, a1 = em.arg32(0), em.arg32(1)
        em.calllog.append(('lg', 0x20, (a0, a1)))
        em.ret(eax=repA if a1 == 0x4c0 else repB, argbytes=8)

    lg_vt = e.fake_vtable('lg4ce', 0x20 // 4 + 1, {0x20: lg_get})
    lg = _rnd(c, 0x40)
    e.w32(lg, lg_vt)
    e.w32(0x700390, lg)

    seq = [c.rng.choice([0, 1]) for _ in range(c.rng.randrange(0, 4))] + [0]
    vals = [c.rng.getrandbits(32) for _ in range(len(seq) + 1)]
    k = [0]

    def get14(em, r):
        em.calllog.append(('this14', 0x14, ()))
        em.ret(eax=vals[-1], argbytes=0)

    def set4c(em, r):
        em.w32(em.arg32(0), 1)
        em.calllog.append(('this4c', 0x4c, ()))
        em.ret(eax=0, argbytes=4)

    def get5c(em, r):
        i = k[0]
        k[0] += 1
        flag = seq[min(i, len(seq) - 1)]
        em.w32(em.arg32(0), flag)
        em.calllog.append(('this5c', 0x5c, ()))
        em.ret(eax=vals[min(i, len(vals) - 2)], argbytes=4)

    this_vt = e.fake_vtable('this4ce', 0x60 // 4 + 1, {0x14: get14, 0x4c: set4c, 0x5c: get5c})
    self_ = _rnd(c, 0x40)
    e.w32(self_, this_vt)
    e.w32(self_ + 0x14, c.rng.getrandbits(32))
    return [self_]


def _report(em, name, n):
    args = tuple(em.arg32(k) for k in range(n))
    em.calllog.append((name, 0x2c, args))
    em.ret(eax=0, argbytes=0)


S(0x4ce9b0, 'logWalk (GUESS)', 'thiscall', None, ret=None, gen=_walk, note='batch300; logger and walk stubs; plain ret')
