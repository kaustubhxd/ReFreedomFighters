"""specs_s3202.py - area 45 batch 3202: ZFFHeroMovementCloseCombat::TerminateControl (0x5e71c0) and ZActor::OnViewEnter
(0x47aa80). The virtual targets are stubs (their classes are GUESS): a fake object at +0x36d whose slot 0x220 logs its
argument and returns 0, and a fake self vtable whose slot 0xbc logs its argument."""
from pilot import S, F


def _vt(c, name, slots, nslots):
    """fake vtable; slots maps byte offset to (number of stack args, handler(emu, args) -> (eax, logged))"""
    e = c.emu
    hs = {}
    for off, (nargs, fn) in slots.items():
        def h(em, rr, off=off, nargs=nargs, fn=fn):
            args = [em.arg32(k) for k in range(nargs)]
            eax, logged = fn(em, args)
            em.calllog.append((name, off, em.reg('ecx'), logged))
            em.ret(eax=eax, argbytes=4 * nargs)
        hs[off] = h
    return e.fake_vtable(name, nslots, hs)


def _term(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x800, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x800)))
    sub = e.alloc(0x800, 4)
    e.wbytes(sub, bytes(r.getrandbits(8) for _ in range(0x800)))
    def s220(em, a):
        em.calllog.append(('s220', a[0]))
        return 0, ()
    e.w32(sub, _vt(c, 'sub220', {0x220: (1, s220)}, 0x224 // 4))
    e.w32(self_ + 0x36d, sub)
    return [self_, r.getrandbits(8) & 1]


def _view(c):
    e, r = c.emu, c.rng
    self_ = e.alloc(0x800, 4)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x800)))
    g = e.alloc(0x80, 4)
    e.wbytes(g, bytes(r.getrandbits(8) for _ in range(0x80)))
    e.w32(g + 0x3c, r.getrandbits(32) & (0xfffff7ff if r.random() < 0.6 else 0xffffffff))
    e.w32(self_ + 8, g)
    e.w32(self_ + 0x640, r.choice([0, 0, 1, 5]))
    def s_bc(em, a):
        em.calllog.append(('sbc', a[0]))
        return 0, ()
    e.w32(self_, _vt(c, 'view', {0xbc: (1, s_bc)}, 0xc0 // 4))
    return [self_]


S(0x5e71c0, 'ZFFHeroMovementCloseCombat::TerminateControl', 'thiscall', None, ret='al', gen=_term, note='batch3202')
S(0x47aa80, 'ZActor::OnViewEnter', 'thiscall', None, gen=_view, note='batch3202')
