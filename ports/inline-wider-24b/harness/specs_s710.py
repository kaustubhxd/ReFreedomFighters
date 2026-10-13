"""specs_s710.py - soldier AI batch 710: CFFCoverList::CoverSpotQuality, CheckCover, TakeCover, FindCoverNoThreat.
Cover lists hold 0..6 spots of 0x48 bytes; facings are often longer than 1 so both quality results occur.
CCoverSpot::Reserve / CReservable::Release / FindCover are hooked and logged."""
import math
import struct
from pilot import S, F, f32
from specs_s701 import _rnd
from specs_s705 import nostk
from specs_s709 import _log_world


def _fl(c, lo=-50, hi=50):
    r = c.rng.random()
    if r < 0.06:
        return f32(c.rng.choice([0.0, -0.0, math.nan, math.inf, 1e-40, 1e-25]))
    if r < 0.15:
        return f32(float(c.rng.randint(-2, 2)))
    return f32(c.rng.uniform(lo, hi))


def _spots(c, n):
    e = c.emu
    base = _rnd(c, 0x48 * max(n, 1) + 16)
    for i in range(n):
        s = base + 0x48 * i
        e.wbytes(s + 0x10, b''.join(struct.pack('<f', _fl(c)) for _ in range(3)))
        k = c.rng.choice([1.0, 1.5, 2.0, 3.0])
        e.wbytes(s + 0x1c, b''.join(struct.pack('<f', f32(_fl(c, -1, 1) * k)) for _ in range(3)))
        e.w32(s + 4, c.rng.choice([0, 0, 7, c.rng.getrandbits(32)]))
    return base


def _list(c):
    e = c.emu
    n = c.rng.choice([0, 1, 3, 6])
    cl = _rnd(c, 0x80)
    base = _spots(c, n)
    e.wbytes(cl + 0x5f, struct.pack('<II', base, base + 0x48 * n))
    return cl, base, n


def _hooks(c):
    e = c.emu
    def h(name, nargs):
        def f(em, r):
            em.calllog.append((name, 0, em.reg('ecx'), tuple(nostk(em.arg32(k)) for k in range(nargs))))
            em.ret(eax=0x77, argbytes=4 * nargs)
        return f
    e.hook(0x5df400, h('CCoverSpot::Reserve', 4))
    e.hook(0x5de9c0, h('CReservable::Release', 0))


def _q(c):
    cl, base, n = _list(c)
    spot = _spots(c, 1)
    pos = c.emu.alloc(16, 4)
    c.emu.wbytes(pos, b''.join(struct.pack('<f', _fl(c)) for _ in range(3)))
    if c.rng.random() < 0.15:   # same x/z as the spot: the no-normalise path
        c.emu.wbytes(pos, c.emu.rbytes(spot + 0x10, 12))
    elif c.rng.random() < 0.4:  # facing along the flat direction, scaled near 1 or -0.5: dot lands on or next to 1
        sp = struct.unpack('<3f', c.emu.rbytes(spot + 0x10, 12))
        pp = struct.unpack('<3f', c.emu.rbytes(pos, 12))
        dx, dz = pp[0] - sp[0], pp[2] - sp[2]
        ln = math.sqrt(dx * dx + dz * dz)
        if ln > 0 and math.isfinite(ln):
            k = c.rng.choice([1.0, 1.0000001, 0.9999999, 1.0000002, -0.5, -0.50000006, -0.49999997])
            c.emu.wbytes(spot + 0x1c, struct.pack('<3f', f32(dx / ln * k), 0.0, f32(dz / ln * k)))
    return [cl, spot, pos, c.rng.choice([0, 1, 0x100, 0xff])]


S(0x585910, 'CFFCoverList::CoverSpotQuality', 'thiscall', None, ret='st0', gen=_q, note='b710 [high]; x87')


def _cc(c):
    e = c.emu
    _hooks(c)
    cl, base, n = _list(c)
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    def root(em, r):
        p = em.arg32(0)
        em.calllog.append(('geom', 0x84, em.reg('ecx'), tuple(struct.unpack('<3I', em.rbytes(p, 12)))))
        em.wbytes(p, b''.join(struct.pack('<f', _fl(c)) for _ in range(3)))
        em.ret(eax=0, argbytes=4)
    g = _rnd(c, 32)
    e.w32(g, e.fake_vtable('geom', 0x30, {0x84: root}))

    def lookup(em, r):
        em.calllog.append(('db', 0x58, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=g if c.rng.random() < 0.9 else 0, argbytes=4)
    db = _rnd(c, 32)
    e.w32(db, e.fake_vtable('db', 0x20, {0x58: lookup}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))
    actor = c.rng.choice([7, c.rng.getrandbits(32)])
    return [cl, actor, c.rng.getrandbits(32), c.rng.choice([-1, 0, 1, 2, 5, 6, 7]) & 0xffffffff,
            c.rng.choice([0, 1, 0x100])]


S(0x5857f0, 'CFFCoverList::CheckCover', 'thiscall', None, ret='eax', gen=_cc,
  note='b710 [high]; CoverSpotQuality runs as exe code, Reserve/Release hooked')


def _take(c):
    _hooks(c)
    _log_world(c)
    cl, base, n = _list(c)
    ev = c.emu.alloc(8, 4)
    c.emu.w32(ev, c.rng.getrandbits(32))
    c.emu.w32(ev + 4, c.rng.choice([0, 1, 2, 5, 6, 7, 100]))
    return [cl, ev]


S(0x588530, 'CFFCoverList::TakeCover', 'thiscall', None, ret='eax', gen=_take, note='b710 [high]')


def _fcnt(c):
    e = c.emu

    def fc(em, r):
        args = [em.arg32(k) for k in range(10)]
        m = args[2]
        args[2] = tuple(struct.unpack('<9I', em.rbytes(m, 36)))
        em.calllog.append(('FindCover', 0, em.reg('ecx'), tuple(nostk(a) if not isinstance(a, tuple) else a for a in args)))
        em.ret(eax=c.rng.getrandbits(32), argbytes=40)
    e.hook(0x586bc0, fc)
    cl = _rnd(c, 0x80)
    pos = _rnd(c, 16)
    return [cl, c.rng.getrandbits(32), pos, F(_fl(c, 0, 3000))]


S(0x5875c0, 'CFFCoverList::FindCoverNoThreat', 'thiscall', None, ret='eax', gen=_fcnt, note='b710 [high]; FindCover hooked')
