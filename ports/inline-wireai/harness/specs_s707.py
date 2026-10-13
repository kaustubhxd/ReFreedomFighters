"""specs_s707.py - soldier AI batch 707: ZActor::CheckSight/SetCheckSight, ZFFActor::ReducedSight, GetNextVisible,
RegisterVision, ZTargetManager::ObjectVisible/ObjectNotVisible.
Actors and geoms are fakes with one shared logging vtable per case; message ids come from a RegisterZMsg stub that logs
the name and line; data blocks passed by pointer are logged by content when they are on the stack."""
import struct
from pilot import S
from specs_s701 import _rnd
from specs_s705 import _bool, nostk


def _w(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    geoms = []

    def team(g):
        t = _rnd(c, 16)
        e.w32(t + 4, c.rng.choice([0, 1, 2, 3, 31, 33]))
        e.w32(t + 8, c.rng.choice([0, 4, 4, 1]))
        e.w32(t + 0xc, c.rng.getrandbits(32) & c.rng.choice([0xffffffff, 0xf, 0x5]))
        e.w32(g + 0x54, t if c.rng.random() < 0.9 else 0)

    def gslot(off, nargs, gen):
        def h(em, r):
            log('geom', off, tuple(em.arg32(k) for k in range(nargs)))
            em.ret(eax=gen(), argbytes=4 * nargs)
        return h

    def sendcmd(em, r):   # 0x130(target, id, data): data may point at a stack pair
        t, i, d = em.arg32(0), em.arg32(1), em.arg32(2)
        extra = tuple(struct.unpack('<2I', em.rbytes(d, 8))) if nostk(d) == 'stk' else ()
        log('geom', 0x130, (t, i, d) + extra)
        em.ret(eax=0, argbytes=12)

    def name_into(em, r):
        log('geom', 0x1d8, (em.arg32(1),))
        em.w32(em.arg32(0), em.reg('ecx'))
        em.ret(eax=em.arg32(0), argbytes=8)
    vt = e.fake_vtable('geom', 0x1b0, {
        0x678: gslot(0x678, 0, lambda: c.rng.getrandbits(32)),
        0x130: sendcmd,
        0x16c: gslot(0x16c, 2, lambda: 0),
        0x1e0: gslot(0x1e0, 1, lambda: _bool(c)),
        0x438: gslot(0x438, 0, lambda: _bool(c)),
        0x5b0: gslot(0x5b0, 0, lambda: c.rng.choice([0, 3, 4, 5, 0x103])),
        0x670: gslot(0x670, 0, lambda: _bool(c)),
        0x674: gslot(0x674, 0, lambda: c.rng.choice([0, 0, 1, 100, c.rng.getrandbits(32)])),
        0x1d8: name_into})

    def geom(size=0x960):
        g = _rnd(c, size)
        e.w32(g, vt)
        team(g)
        e.wbytes(g + 8, b'g%07x\0' % (g & 0xfffffff))
        n = c.rng.choice([0, 1, 2, 5])   # container of refs at +0x18 (used when the geom is an actor list)
        if c.rng.random() < 0.85:
            cont = _rnd(c, 16)
            items = [c.rng.getrandbits(32) for _ in range(n)]

            def first(em, r):
                log('cont', 0x4c, ())
                em.w32(em.arg32(0), 0)
                em._items = list(items)
                em.ret(eax=0, argbytes=4)

            def nxt(em, r):
                log('cont', 0x5c, ())
                it = em.arg32(0)
                if em._items:
                    em.w32(it, 1)
                    em.ret(eax=em._items.pop(0), argbytes=4)
                else:
                    em.w32(it, 0)
                    em.ret(eax=c.rng.getrandbits(32), argbytes=4)
            e.w32(cont, e.fake_vtable('cont', 0x20, {0x4c: first, 0x5c: nxt}))
            e.w32(g + 0x18, cont)
        else:
            e.w32(g + 0x18, 0)
        geoms.append(g)
        return g

    def lookup(em, r):
        log('db', 0x58, (em.arg32(0),))
        em.ret(eax=geom(), argbytes=4)

    def toref(em, r):
        log('db', 0x4c, (em.arg32(0),))
        em.ret(eax=c.rng.getrandbits(32), argbytes=4)

    def zmsg(em, r):
        log('db', 0x114, tuple(em.arg32(k) for k in range(4)))
        em.ret(eax=c.rng.getrandbits(32), argbytes=16)
    db = _rnd(c, 64)
    e.w32(db, e.fake_vtable('db', 0x60, {0x58: lookup, 0x4c: toref, 0x114: zmsg}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))
    logobj = _rnd(c, 16)

    def printf(em, r):
        em.calllog.append(('log.printf', 0x2c, None, tuple(em.arg32(k) for k in range(3))))
        em.ret(eax=0, argbytes=0)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: printf}))
    lg = _rnd(c, 16)
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    e.hook(0x4cc1d0, lambda em, r: em.ret(eax=em.r32(em.reg('ecx')) + 8))
    e.hook(0x4cbec0, lambda em, r: em.ret())
    return geom


S(0x477940, 'ZActor::CheckSight', 'thiscall', None, ret='al', gen=lambda c: [_rnd(c, 0x500)], note='b707 [high]')
S(0x47bd60, 'ZActor::SetCheckSight', 'thiscall', None, ret=None,
  gen=lambda c: [_rnd(c, 0x500), c.rng.getrandbits(32)], note='b707 [high]')


def _rs(c):
    geom = _w(c)
    a = geom()
    if c.rng.random() < 0.3:
        c.emu.w8(a + 0x8fa, 0)
    return [a, c.rng.getrandbits(32)]


S(0x5a2570, 'ZFFActor::ReducedSight', 'thiscall', None, ret='al', gen=_rs, note='b707 [high]')


def _gnv(c):
    e = c.emu
    _w(c)
    cv = _rnd(c, 0x16000)
    e.w32(cv, e.fake_vtable('cv', 0x40, {0x88: 0x4aab90, 0x8c: 0x4aaa30}))
    k = c.rng.randrange(200)
    words = [c.rng.choice([0, 0, 0, 0, 0x4000, 0x8000, 0xc000]) | c.rng.getrandbits(14) for _ in range(200)]
    if c.rng.random() < 0.2:
        words = [w & 0x7fff for w in words]
    e.wbytes(cv + 0x694 + k * 0x1b8 + 0x28, struct.pack('<200H', *words))
    a = _rnd(c, 0x960)
    e.w32(a + 0x8ee, cv)
    e.w32(a + 0x8f2, k)
    e.w32(a + 0x8f6, c.rng.choice([0xffffffff, c.rng.randrange(200), 0]))
    return [a]


S(0x59fed0, 'ZFFActor::GetNextVisible', 'thiscall', None, ret='eax', gen=_gnv,
  note='b707 [high]; CCheckVisible GetSeerData/GetObjectData run as exe code')


def _tm(c):
    geom = _w(c)
    return [_rnd(c, 16), geom(), geom()]


S(0x5a0e10, 'ZTargetManager::ObjectNotVisible', 'thiscall', None, ret=None, gen=_tm, note='b707 [medium]')
S(0x5a0e60, 'ZTargetManager::ObjectVisible', 'thiscall', None, ret=None, gen=_tm, note='b707 [high]')


def _rv(c):
    e = c.emu
    geom = _w(c)
    a = geom()
    cv = _rnd(c, 16)

    def gsi(em, r):
        em.calllog.append(('cv', 0x84, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=c.rng.getrandbits(32), argbytes=4)
    e.w32(cv, e.fake_vtable('cv', 0x40, {0x84: gsi}))
    e.w32(a + 0x8ee, cv)
    return [a, _bool(c), _bool(c)]


S(0x5a2600, 'ZFFActor::RegisterVision', 'thiscall', None, ret=None, gen=_rv, note='b707 [high]')
