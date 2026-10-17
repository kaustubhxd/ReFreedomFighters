"""specs_s738.py - ZFFItemBomb::Load. The load object has slot 0x40 (writes a random dword into its pointer argument, logs
the call), slot 0x50 and 0x68 (log their pointer). The engine db has slot 0x58 (id -> reference, logs the id) and slot 0x138
(returns a fake object whose slot 0x4c logs the string pointer and this). The item's flag dword at +4 is random."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _bl(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0xb00)
    e.w32(eng + 0x9b, db)
    ids = [c.rng.getrandbits(32) for _ in range(3)]
    refs = {}

    def db58(em, r):
        ident = em.arg32(0)
        log('db', 0x58, (ident,))
        em.ret(eax=refs.setdefault(ident, c.rng.getrandbits(32)), argbytes=4)

    def db138(em, r):
        log('db', 0x138, ())
        em.ret(eax=obj, argbytes=0)
    e.w32(db, e.fake_vtable('db', 0x200, {0x58: db58, 0x138: db138}))

    def o4c(em, r):
        log('obj', 0x4c, (em.arg32(0), nostk(em.arg32(1))))
        em.ret(eax=0, argbytes=8)
    obj = _rnd(c, 0x40)
    e.w32(obj, e.fake_vtable('obj', 0x100, {0x4c: o4c}))

    k = [0]

    def l40(em, r):
        p = em.arg32(0)
        log('load', 0x40, ())
        em.w32(p, ids[k[0] % 3])
        k[0] += 1
        em.ret(eax=0, argbytes=4)

    def l50(em, r):
        log('load', 0x50, (nostk(em.arg32(0)),))
        em.ret(eax=0, argbytes=4)

    def l68(em, r):
        log('load', 0x68, (nostk(em.arg32(0)),))
        em.ret(eax=0, argbytes=4)
    load = _rnd(c, 0x40)
    e.w32(load, e.fake_vtable('load', 0x100, {0x40: l40, 0x50: l50, 0x68: l68}))

    self_ = _rnd(c, 0x100)
    e.w32(self_ + 4, c.rng.getrandbits(32))
    return [self_, load]


S(0x5d4770, 'ZFFItemBomb::Load', 'thiscall', None, ret='al', gen=_bl, note='b738 residue 11 [high]; load and db slots fake')
