"""specs_s715.py - soldier AI batch 715: CFFCoverList::CreateSpot.
Pathfinder (db slot 0x138 gives the pathfinder-factory object, its slot 0x88 yields a reference, db slot 0x58 maps it to
the pathfinder), CheckPosition (0x220) and FindNearestPoint (0x218) are logged fakes with random answers; the scene
(0xadc: 0x218 line, 0x238 box), the engine config (0x5c) and the logger are fakes; atof is stubbed; CCoverSpot::Init (0x5def10)
is exe code, hooked so its output (spot fields) is logged and filled deterministically. The spot list is a struct at
self+0x6b (begin, end, cap) of 0..6 spots; insert (0x588750) runs as exe code."""
import math
import struct
from pilot import S, F, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk
from specs_s709 import _log_world


def _fl(c, lo=-60, hi=60):
    r = c.rng.random()
    if r < 0.05:
        return c.rng.choice([0.0, -0.0, math.nan, math.inf])
    return c.rng.uniform(lo, hi)


def _cs(c):
    e = c.emu
    tie = [None]
    _log_world(c)
    log = lambda name, off, args: e.calllog.append((name, off, nostk(e.reg('ecx')), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    pf = _rnd(c, 0x80)

    def pf_218(em, r):
        # FindNearestPoint fake: logs the query and (edge mode, 2026-10-11) moves the point in place, as the real one does
        v = em.arg32(0)
        log('pf', 0x218, (tuple(struct.unpack('<3I', em.rbytes(v, 12))), em.arg32(1), em.arg32(2), em.arg32(3)))
        if c.rng.random() < 0.7:
            q = struct.unpack('<3f', em.rbytes(v, 12))
            em.wbytes(v, struct.pack('<3f', *[f32(x + c.rng.uniform(-12, 12)) for x in q]))
        em.ret(eax=_bool(c), argbytes=16)
    e.w32(pf, e.fake_vtable('pf', 0x240, {
        0x220: lambda em, r: (log('pf', 0x220, (tuple(struct.unpack('<3I', em.rbytes(em.arg32(0), 12))),)),
                              em.ret(eax=_bool(c), argbytes=4)),
        0x218: pf_218}))

    ref = c.rng.getrandbits(32)
    fac = _rnd(c, 0x20)
    def fac_88(em, r):
        log('fac', 0x88, (em.arg32(0),))
        em.w32(em.arg32(1), ref)
        em.ret(eax=0, argbytes=8)
    e.w32(fac, e.fake_vtable('fac', 0x240, {0x88: fac_88}))

    def db58(em, r):
        log('db', 0x58, (em.arg32(0),))
        em.ret(eax=pf if (em.arg32(0) == ref and c.rng.random() < 0.95) else 0, argbytes=4)   # 5% missing pathfinder (2026-10-11)
    def db138(em, r):
        log('db', 0x138, ())
        em.ret(eax=fac, argbytes=0)
    db = _rnd(c, 0xae0)   # 0xadc holds the scene (was 0x100, 2026-10-11)
    e.w32(db, e.fake_vtable('db', 0x140, {0x58: db58, 0x138: db138}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    def line(em, r):
        log('scene', 0x218, tuple(struct.unpack('<3I', em.rbytes(em.arg32(0), 12))) + tuple(struct.unpack('<3I', em.rbytes(em.arg32(1), 12))) + (em.arg32(2),))
        em.ret(eax=0, argbytes=12)

    def box(em, r):
        log('scene', 0x238, (em.arg32(0),) + tuple(struct.unpack('<3I', em.rbytes(em.arg32(1), 12))) +
            tuple(struct.unpack('<3I', em.rbytes(em.arg32(2), 12))) + (em.arg32(3), em.arg32(4)))
        em.ret(eax=0, argbytes=20)
    sc = _rnd(c, 32)
    e.w32(sc, e.fake_vtable('scene', 0x240, {0x218: line, 0x238: box}))
    e.wbytes(db + 0xadc, struct.pack('<I', sc))

    cfg = [e.cstr(v) for v in ('0', '1', '0.5', '2.0')]
    def ecfg(em, r):
        log('eng', 0x5c, (em.arg32(0),))
        em.w32(em.arg32(1), c.rng.choice(cfg))
        em.ret(eax=_bool(c), argbytes=8)
    e.w32(eng, e.fake_vtable('engine', 0x80, {0x5c: ecfg}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))
    e.stub_import('atof', lambda em, r: (em.calllog.append(('atof', 0, None, (em.arg32(0),))),
                                         em.ret(st0=float(c.rng.choice([0.0, 1.0, -1.0, 0.5, 2.0])), argbytes=0)))

    def logger(em, r):
        log('logger', 0x2c, ())
    lg = _rnd(c, 16)
    logobj = _rnd(c, 16)
    e.w32(logobj, e.fake_vtable('log', 16, {0x2c: lambda em, r: (em.calllog.append(('log.printf', 0x2c, None, (em.arg32(1), em.arg32(2)))), em.ret(eax=0, argbytes=0)),
                                            0x30: lambda em, r: (em.calllog.append(('log.printf', 0x30, None, (em.arg32(1),))), em.ret(eax=0, argbytes=0))}))
    e.w32(lg, e.logging_vtable('logger', 16, impl={0x20: lambda em, a: (logobj, None)}, argwords={0x20: 2}))
    e.w32(0x700390, lg)
    e.hook(0x4cc1d0, lambda em, r: em.ret(eax=0, argbytes=0))

    def init(em, r):
        spot = em.reg('ecx')
        args = tuple(nostk(em.arg32(k)) for k in range(6))
        log('Init', 0, (nostk(spot), args))
        for off in range(0, 0x48, 4):
            em.w32(spot + off, c.rng.getrandbits(32))
        em.wbytes(spot + 0x10, struct.pack('<3f', *[f32(_fl(c)) for _ in range(3)]))
        if tie[0]:
            em.wbytes(spot + 0x10, em.rbytes(tie[0][0] + 0x48 * c.rng.randrange(tie[0][1]) + 0x10, 4))
        em.ret(eax=_bool(c), argbytes=24)
    e.hook(0x5def10, init)
    e.hook(0x588750, lambda em, r: (log('insert', 0, (em.arg32(0), em.arg32(1))), em.ret(eax=0, argbytes=8)))

    # the list: a struct at self+0x6b with begin, end, cap
    n = c.rng.choice([0, 1, 3, 6, 7])
    cap = c.rng.choice([6, 7, 8]) if n < 7 else 7
    base = _rnd(c, 0x48 * 8)
    for i in range(n):
        sp = base + 0x48 * i
        e.wbytes(sp + 0x10, struct.pack('<3f', *[f32(c.rng.uniform(-200, 200)) for _ in range(3)]))
        e.wbytes(sp + 0x14, struct.pack('<2f', *[f32(c.rng.uniform(-200, 200)) for _ in range(2)]))
    lst = _rnd(c, 16)
    e.wbytes(lst, struct.pack('<III', base, base + 0x48 * n, base + 0x48 * cap))
    if c.rng.random() < 0.1:   # full
        e.wbytes(lst, struct.pack('<III', base, base + 0x48 * n, base + 0x48 * n))
    self_ = _rnd(c, 0x100)
    e.wbytes(self_ + 0x6b, struct.pack('<I', lst))
    e.w8(self_ + 0x56, c.rng.choice([0, 0, 2, 0xff]))   # not always 0, so the 'mark' store is seen (2026-10-11)

    a = _rnd(c, 12); b = _rnd(c, 12); cc = _rnd(c, 12); d = _rnd(c, 12)
    bv = [f32(_fl(c)) for _ in range(3)]
    e.wbytes(b, struct.pack('<3f', *bv))
    # edge mode (2026-10-11): put some existing spots at a distance of about 15 from b (the too-close threshold),
    # and sometimes give Init's new spot the same x as an existing spot (the lower-bound tie)
    if n and all(math.isfinite(x) for x in bv) and c.rng.random() < 0.5:
        for i in range(n):
            if c.rng.random() < 0.5:
                dd = c.rng.choice([14.995, 15.0, 15.005, c.rng.uniform(0, 30)])
                ax = c.rng.randrange(3)
                q = list(bv); q[ax] = f32(q[ax] + dd * c.rng.choice([1, -1]))
                e.wbytes(base + 0x48 * i + 0x10, struct.pack('<3f', *q))
    tie[0] = (base, n) if n and c.rng.random() < 0.3 else None
    e.wbytes(d, struct.pack('<3f', *[f32(c.rng.choice([_fl(c, -2, 2), 0.0, 1.0])) for _ in range(3)]))
    return [self_, a, b, cc, d, c.rng.choice([0, 1, 1, 0xff]), c.rng.choice([0, 1, 2, 3]), c.rng.getrandbits(32) & 0xffff]


S(0x585a40, 'CFFCoverList::CreateSpot', 'thiscall', None, ret='al', gen=_cs,
  note='b715 [high]; Init and insert hooked; pathfinder and scene are fakes')
