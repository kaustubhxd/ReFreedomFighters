"""specs_s717.py - soldier AI batch 717: ZActor::OnSound. Same fakes as batch 716 (event list, db lookup with self,
geoms with IsDerivedFrom, logger, RegisterZMsg and SendCommand logged). The MYSTR helpers run as exe code; operator new
and delete (0x41e290 / 0x634273) are hooked in case SetString allocates. Self has its flag byte at +0x145, sources
have bit 0x100 at +0x417 at random. Distances sit on 700, 1000, 1200 and 1500 thresholds."""
import math
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world
from specs_s716 import _team


def _as(c):
    e = c.emu
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    # MYSTR allocation hooks (only used if the string does not fit inline)
    heap = {'next': 0}
    def newop(em, r):
        log('new', 0, (em.arg32(0),))
        em.ret(eax=_rnd(c, max(em.arg32(0), 16)), argbytes=4)
    def delop(em, r):
        log('delete', 0, (em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=8)
    e.hook(0x41e290, newop)
    e.hook(0x634273, delop)

    selfteam = _team(c, e, idx=c.rng.choice([0, 1, 2]))
    self_ = _rnd(c, 0x200)
    e.w32(self_ + 0x54, selfteam)
    e.w8(self_ + 0x145, c.rng.choice([0, 0, 1, 1]))

    def sendcmd(em, r):
        log('self', 0x128, (em.arg32(0), nostk(em.arg32(1)), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    self_vt = e.fake_vtable('self', 0x200, {0x128: sendcmd, 0x1e0: lambda em, r: (log('self', 0x1e0, (em.arg32(0),)), em.ret(eax=1, argbytes=4))})
    e.w32(self_, self_vt)

    selfref = c.rng.getrandbits(32)
    geoms = {}

    def geom(ref):
        if ref in geoms:
            return geoms[ref]
        g = _rnd(c, 0x500)
        def isd(em, r):
            log('geom', 0x1e0, (em.arg32(0),))
            em.ret(eax=_bool(c) if c.rng.random() < 0.8 else 1, argbytes=4)
        gvt = e.fake_vtable('geom', 0x1f0, {0x1e0: isd})
        e.w32(g, gvt)
        e.w32(g + 0x54, _team(c, e))
        e.w32(g + 0x417, c.rng.choice([0, 0x100, 0x200, c.rng.getrandbits(32)]))
        geoms[ref] = g
        return g

    def dblookup(em, r):
        ref = em.arg32(0)
        log('db', 0x58, (ref,))
        if ref == selfref:
            em.ret(eax=self_, argbytes=4)
        elif ref == 0:
            em.ret(eax=0, argbytes=4)
        else:
            em.ret(eax=geom(ref), argbytes=4)

    def regmsg(em, r):
        name = em.arg32(0)
        log('db', 0x114, (name, em.arg32(1), em.arg32(2), em.arg32(3)))
        em.ret(eax=c.rng.getrandbits(32), argbytes=16)
    db = _rnd(c, 0x100)
    e.w32(db, e.fake_vtable('db', 0x120, {0x58: dblookup, 0x114: regmsg}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    logobj = _rnd(c, 16)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: lambda em, r: (em.calllog.append(('log.printf', 0x2c, None, (em.arg32(1),))), em.ret(eax=0, argbytes=0))}))

    n = c.rng.choice([0, 1, 2, 4, 6])
    evs = []
    for _ in range(n):
        ev = _rnd(c, 0x20)
        e.wbytes(ev, struct.pack('<3f', *[f32(c.rng.uniform(-300, 300)) for _ in range(3)]))
        e.wbytes(ev + 0xc, struct.pack('<I', c.rng.choice([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 0, 11])))
        e.wbytes(ev + 0x10, struct.pack('<f', f32(c.rng.choice([c.rng.uniform(0, 2000), 699.0, 700.0, 700.5, 999.0, 1000.0,
                                                               1199.0, 1200.0, 1500.0, 1500.001]))))
        e.wbytes(ev + 0x14, struct.pack('<I', c.rng.choice([selfref, 0, c.rng.getrandbits(32), 77, 78])))
        e.wbytes(ev + 0x1c, struct.pack('<I', c.rng.getrandbits(32)))
        evs.append(ev)

    def lst_begin(em, r):
        em.w32(em.arg32(0), 0)
        em.ret(eax=0, argbytes=4)

    def lst_next(em, r):
        it = em.arg32(0)
        i = em.r32(it)
        if i < len(evs):
            em.w32(it, i + 1)
            em.ret(eax=evs[i], argbytes=4)
        else:
            em.ret(eax=0, argbytes=4)
    lst = _rnd(c, 16)
    e.w32(lst, e.fake_vtable('list', 0x80, {0x4c: lst_begin, 0x64: lst_next}))
    if c.rng.random() < 0.05:
        return [self_, 0]
    return [self_, lst]


S(0x47a620, 'ZActor::OnSound', 'thiscall', None, ret=None, gen=_as,
  note='b717 [high]; MYSTR helpers run as exe code; new/delete hooked')
