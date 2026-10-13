"""specs_s712.py - soldier AI batch 712: FindCoverThreat, FindCoverNearLeader. FindCover is hooked and logs every
argument (contents of the stack matrix and points); geoms give random root points at distances around the 1000/2100
thresholds; lookups sometimes return null."""
import math
import struct
from pilot import S, F, f32
from specs_s701 import _rnd
from specs_s705 import nostk
from specs_s709 import _log_world


def _w(c):
    e = c.emu
    _log_world(c)
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    base = [float(c.rng.randint(-3000, 3000)) for _ in range(3)]

    def root(em, r):
        p = em.arg32(0)
        em.calllog.append(('geom', 0x84, em.reg('ecx'), tuple(struct.unpack('<3I', em.rbytes(p, 12)))))
        d = c.rng.choice([500.0, 999.0, 1000.0, 1500.0, 2100.0, 2200.0, c.rng.uniform(0, 4000)])
        a = c.rng.uniform(-math.pi, math.pi)
        v = [base[0] + d * math.cos(a), base[1] + c.rng.choice([0.0, c.rng.uniform(-800, 800)]), base[2] + d * math.sin(a)]
        if d in (1000.0, 2100.0) and c.rng.random() < 0.6:   # exactly on the threshold: distance computes to d
            v = [base[0] + d, base[1], base[2]]
        if c.rng.random() < 0.05:
            v = list(base)
        em.wbytes(p, struct.pack('<3f', *[f32(x) for x in v]))
        em.ret(eax=0, argbytes=4)
    vt = e.fake_vtable('geom', 0x30, {0x84: root})

    def lookup(em, r):
        em.calllog.append(('db', 0x58, em.reg('ecx'), (em.arg32(0),)))
        if c.rng.random() < 0.08:
            em.ret(eax=0, argbytes=4)
            return
        g = _rnd(c, 32)
        e.w32(g, vt)
        em.ret(eax=g, argbytes=4)
    db = _rnd(c, 32)
    e.w32(db, e.fake_vtable('db', 0x20, {0x58: lookup}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    def fc(em, r):
        a = [em.arg32(k) for k in range(10)]
        rec = (a[0], a[1], struct.unpack('<9I', em.rbytes(a[2], 36)), struct.unpack('<3I', em.rbytes(a[3], 12)),
               a[4], a[5], a[6], a[7], struct.unpack('<3I', em.rbytes(a[8], 12)), a[9])
        em.calllog.append(('FindCover', 0, em.reg('ecx'), rec))
        em.ret(eax=c.rng.getrandbits(32), argbytes=40)
    e.hook(0x586bc0, fc)
    return _rnd(c, 0x80)


def _fct(c):
    cl = _w(c)
    fl = lambda: F(f32(c.rng.choice([c.rng.uniform(-1000, 1000), 0.0, 300.0])))
    return [cl, c.rng.getrandbits(32), c.rng.getrandbits(32), fl(), fl(), fl(), fl(), c.rng.choice([0, 1, 0x100])]


S(0x587640, 'CFFCoverList::FindCoverThreat', 'thiscall', None, ret='eax', gen=_fct, note='b712 [high]; FindCover hooked')
S(0x5873a0, 'CFFCoverList::FindCoverNearLeader', 'thiscall', None, ret='eax',
  gen=lambda c: [_w(c), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)],
  note='b712 [high]; FindCover hooked')
