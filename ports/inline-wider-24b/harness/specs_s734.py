"""specs_s734.py - residue 11: ZMovementGuide::Load. The guide has a fake vtable with slot 0x20 (logs). The load object has
slot 0x50 (logs the pointer it gets) and slot 0x40 (writes a random id into its pointer argument). The engine db has slot 0x58
(logs the id, returns a random reference)."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _gl(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0xb00)
    e.w32(eng + 0x9b, db)
    ref = c.rng.getrandbits(32)
    cid = c.rng.getrandbits(32)

    def db58(em, r):
        log('db', 0x58, (em.arg32(0),))
        em.ret(eax=ref, argbytes=4)
    e.w32(db, e.fake_vtable('db', 0x100, {0x58: db58}))

    def l50(em, r):
        log('load', 0x50, (em.arg32(0),))
        em.ret(eax=0, argbytes=4)

    def l40(em, r):
        log('load', 0x40, ())
        e.w32(em.arg32(0), cid)
        em.ret(eax=0, argbytes=4)
    load = _rnd(c, 0x40)
    e.w32(load, e.fake_vtable('load', 0x100, {0x50: l50, 0x40: l40}))

    def g20(em, r):
        log('guide', 0x20, ())
        em.ret(eax=0, argbytes=0)
    self_ = _rnd(c, 0x400)
    e.w32(self_, e.fake_vtable('guide', 0x100, {0x20: g20}))
    return [self_, load]


S(0x489370, 'ZMovementGuide::Load', 'thiscall', None, ret='al', gen=_gl, note='b734 [medium]; residue 11')
