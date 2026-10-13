"""specs_s9001.py - wire-ai batch 9001: ZFastBoxColi1::AddFace (0x6354a0). Triangles of every shape (ordinary, thin, collinear,
repeated vertices, tiny, huge, NaN-free), the back-face cull byte +0x59 with a random direction, the geom flag 0x400000 with the
+0x54 byte, the geom database slot 0x50 (logs the geom, returns a random ref) and the face list (slot 4 logs its argument and
returns a fresh buffer + 4; the 0x7c bytes written there are part of the compared heap). Byte +0x6e is always set (FindFaces sets
it; with it clear the exe copies 0x3c bytes of uninitialised stack, which no port can match). 0x53d160, vector helpers, vnorm and
vscalar run as exe code."""
import struct
from pilot import S, f32
from specs_s701 import _rnd
from specs_s705 import nostk


def _v(c, scale):
    return [c.rng.uniform(-scale, scale) for _ in range(3)]


def _tri(c):
    k = c.rng.random()
    s = c.rng.choice([1.0, 50.0, 1000.0, 20000.0])
    a = _v(c, s)
    if k < 0.45:
        return a, [a[i] + x for i, x in enumerate(_v(c, s))], [a[i] + x for i, x in enumerate(_v(c, s))]
    if k < 0.55:                                    # collinear
        d = _v(c, s)
        return a, [a[i] + d[i] for i in range(3)], [a[i] + d[i] * c.rng.choice([2.0, -1.0, 0.5]) for i in range(3)]
    if k < 0.62:                                    # repeated vertex
        b = [a[i] + x for i, x in enumerate(_v(c, s))]
        return (a, a[:], b) if c.rng.random() < 0.5 else (a, b, b[:])
    if k < 0.75:                                    # tiny (determinant near the 1e-6 band)
        e = c.rng.choice([1e-4, 1e-3, 3e-3, 1e-2])
        return a, [a[i] + x for i, x in enumerate(_v(c, e))], [a[i] + x for i, x in enumerate(_v(c, e))]
    if k < 0.82:                                    # thin sliver
        d = _v(c, s)
        return a, [a[i] + d[i] for i in range(3)], [a[i] + d[i] * 0.5 + x for i, x in enumerate(_v(c, 1e-3))]
    if k < 0.92:                                    # one edge shorter than ~3e-5 (its edge normal is degenerate), the other long
        d = c.rng.choice([1e-6, 5e-6, 2e-5, 4e-5])
        b = [a[i] + x for i, x in enumerate(_v(c, d))]
        far = [a[i] + x for i, x in enumerate(_v(c, s))]
        return (a, b, far) if c.rng.random() < 0.5 else (a, far, b)
    # axis-aligned floor / wall pieces, either winding
    w = c.rng.uniform(1, 500)
    t = [a, [a[0] + w, a[1], a[2]], [a[0], a[1], a[2] + w]] if c.rng.random() < 0.5 else [a, [a[0], a[1] + w, a[2]], [a[0] + w, a[1], a[2]]]
    if c.rng.random() < 0.5:
        t[1], t[2] = t[2], t[1]
    return t


def _af(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(x) for x in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)

    def ref_of(em, r):
        log('db', 0x50, (em.arg32(0),))
        em.ret(eax=c.rng.getrandbits(32), argbytes=4)
    db = _rnd(c, 32)
    e.w32(db, e.fake_vtable('db', 0x20, {0x50: ref_of}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    def add(em, r):
        log('list', 4, (em.arg32(0),))
        buf = _rnd(c, 0x84)
        em.ret(eax=buf + 4, argbytes=4)
    lst = _rnd(c, 16)
    e.w32(lst, e.fake_vtable('list', 0x10, {4: add}))
    self_ = _rnd(c, 0x80)
    e.w32(self_ + 0x14, lst)
    e.wbytes(self_ + 0x59, bytes([c.rng.choice([0, 0, 1, 0x80])]))
    e.wbytes(self_ + 0x5a, struct.pack('<3f', *[f32(x) for x in c.rng.choice([_v(c, 1.0), [0.0, -1.0, 0.0], [0.0, 1.0, 0.0], [0.0, 0.0, 0.0]])]))
    e.wbytes(self_ + 0x6e, bytes([c.rng.choice([1, 0x40])]))
    g = _rnd(c, 0x60)
    fl = e.r32(g + 0x3c) & ~0x400000
    if c.rng.random() < 0.3:
        fl |= 0x400000
    e.w32(g + 0x3c, fl)
    t = _rnd(c, 0x60)
    e.wbytes(t + 0x5b, bytes([c.rng.choice([0, 1, 0x20])]))
    e.w32(g + 0x54, t)
    pts = []
    for v in _tri(c):
        p = e.alloc(16, 4)
        e.wbytes(p, struct.pack('<3f', *[f32(x) for x in v]))
        pts.append(p)
    return [self_, g] + pts


S(0x6354a0, 'ZFastBoxColi1::AddFace', 'thiscall', None, ret=None, gen=_af, note='b9001; helpers as exe code')
