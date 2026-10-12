"""specs_s733.py - soldier AI batch 733: ZFFActor::ClassInit2. The object has a fake vtable with the slots it calls (0x110, 0x678,
0x6f4, 0x6cc; all log their arguments, 0x678 returns a random id). The engine's db (0x9b) has slot 0x58 returning a fake geom
whose slot 0x100 (the name) returns a random id. ZActor::ClassInit2 (0x477de0) and ZFFActor::InitSounds (0x5a04f0) are hooked
(logged only) so the port's calls into them are checked for order and arguments, not their bodies."""
from pilot import S
from specs_s701 import _rnd
from specs_s705 import nostk


def _cci(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))

    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    db = _rnd(c, 0xb00)
    e.w32(eng + 0x9b, db)

    id0 = c.rng.getrandbits(32)
    id1 = c.rng.getrandbits(32)

    def f110(em, r):
        log('obj', 0x110, (em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)

    def f678(em, r):
        log('obj', 0x678, ())
        em.ret(eax=id0, argbytes=0)

    def f6f4(em, r):
        log('obj', 0x6f4, (em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)

    def f6cc(em, r):
        log('obj', 0x6cc, ())
        em.ret(eax=0, argbytes=0)

    self_ = _rnd(c, 0x940)
    e.w32(self_, e.fake_vtable('obj', 0x8000, {0x110: f110, 0x678: f678, 0x6f4: f6f4, 0x6cc: f6cc}))

    def db58(em, r):
        log('db', 0x58, (em.arg32(0),))
        em.ret(eax=geom, argbytes=4)

    def g100(em, r):
        log('geom', 0x100, (em.arg32(0),))
        em.ret(eax=id1, argbytes=4)

    geom = _rnd(c, 0x40)
    e.w32(geom, e.fake_vtable('geom', 0x200, {0x100: g100}))
    e.w32(db, e.fake_vtable('db', 0x100, {0x58: db58}))

    def h_cia(em, r):
        log('base', 0x477de0, ())
        em.ret(eax=0, argbytes=0)

    def h_snd(em, r):
        log('base', 0x5a04f0, ())
        em.ret(eax=0, argbytes=0)

    e.hook(0x477de0, h_cia)
    e.hook(0x5a04f0, h_snd)
    return [self_]


S(0x59e350, 'ZFFActor::ClassInit2', 'thiscall', None, ret=None, gen=_cci,
  note='b733 [medium]; base init and InitSounds hooked; CheckVisible id stored at +0x8ee')
