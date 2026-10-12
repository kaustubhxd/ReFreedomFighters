"""specs_s267.py - area 22, batch267 (src/batch267.cpp): ZFFActor::_FireWeapon. Every object is a Python vtable; slots
that receive stack buffers write per-case floats into them and log only values (muzzle, matrix, position, barrel point,
direction), never stack addresses. GetPos, vmmul, PSVECAdd, PSVECSubtract, vnorm and vscalar run as original code
(inline-batch45). The log object has printf slots 0x2c and 0x30 (both used by this function)."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret(em) if callable(ret) else ret, argbytes=4 * nargs)
    return h


def _fill(name, ret, *counts):
    """Slot whose stack-buffer arguments get per-case floats (len(counts) arguments, counts[i] floats each)."""
    def h(em, r):
        em.calllog.append((name, 0, None, ()))
        for i, (n, vals) in enumerate(counts):
            a = em.arg32(i)
            for j in range(n):
                em.w32(a + 4 * j, vals[j])
        em.ret(eax=ret, argbytes=4 * len(counts))
    return h


def _namer(text):
    def h(em, r):
        buf = em.arg32(0)
        em.calllog.append(('name.1d8', 0x1d8, None, (em.arg32(1),)))
        em.w32(buf, buf + 4)
        em.wbytes(buf + 4, text + b'\0')
        em.ret(eax=buf, argbytes=8)
    return h


def _fl(c, n, lo, hi):
    return [_fb(c.rng.uniform(lo, hi)) for _ in range(n)]


def _g_5a31d0(c):
    e = c.emu
    _log_world(c, pslot=(0x2c, 0x30), deref=True)
    kind = c.rng.choice([7, 11, 12, 1, 3, 7, 11, 12, _r(c)])
    seq = {'k': [kind, kind, kind]}
    tm = _rnd(c, 0x120)
    bg = 0
    if c.rng.random() < 0.85:
        geom = _rnd(c, 0x30)
        for j, v in enumerate(_fl(c, 3, -2, 2)):
            e.w32(geom + 0x24 + 4 * j, v)
        bg = _rnd(c, 0x10)
        e.w32(bg + 8, geom)
    e.w32(tm + 0x11b, bg)
    e.w32(tm, _pyvt(c, {0x330: _slot('tmpl.330', 0, lambda em: seq['k'].pop(0) if seq['k'] else kind),
                        0x328: _slot('tmpl.328', 0, (_r(c) & ~0xff) | c.rng.choice([0, 1, 1]))}))
    scale = c.rng.choice([1.0, 100.0, 1000.0])
    edge = c.rng.random() < 0.2
    rng_ = 600.0 if kind == 7 else 400.0
    mat = [_fb(0.0)] * 9 if edge else _fl(c, 9, -1, 1)
    pos = [_fb(rng_ + c.rng.uniform(-1.5, 1.5)), _fb(0.0), _fb(0.0)] if edge else _fl(c, 3, -scale, scale)
    muz = [_fb(0.0)] * 3 if edge else _fl(c, 3, -scale, scale)
    w = _rnd(c, 0x10)
    e.w32(w, _pyvt(c, {0x350: _slot('w.350', 0, tm),
                       0x2c4: _fill('w.2c4', 0, (9, mat), (3, pos)),
                       0x32c: (lambda em, r: (em.calllog.append(('w.32c', 0, None, (em.rbytes(em.arg32(0), 12),))),
                                              em.ret(eax=0, argbytes=4))),
                       0x35c: _slot('w.35c', 0, c.rng.choice([0, 0, 5, _r(c)])),
                       0x354: _slot('w.354', 0, (_r(c) & ~0xff) | c.rng.choice([0, 1, 1])),
                       0x2d0: _slot('w.2d0', 2)}))
    wid = _r(c) | 1
    db = _rnd(c, 0x40)
    e.w32(db, _pyvt(c, {0x58: _slot('db.58', 1, lambda em: w if em.arg32(0) == wid else 0)}))

    def coli30(em, r):
        a = [em.arg32(i) for i in range(8)]
        em.calllog.append(('coli.30', 0, None, (em.r32(a[0]), a[1], em.rbytes(a[2], 12), em.rbytes(a[3], 12)) + tuple(a[4:])))
        em.ret(eax=(_r(c) & ~0xff) | c.rng.choice([0, 0, 1]), argbytes=32)
    coli = _rnd(c, 0x10)
    e.w32(coli, _pyvt(c, {0x30: coli30}))
    osd = _rnd(c, 0x20)
    e.w32(osd + 0x1c, coli)
    rm = _rnd(c, 0x1b00)
    e.w32(rm + 0x9b, db)
    e.w32(rm + 0x1aa3, osd)
    e.w32(0x70039c, rm)
    hands = [c.rng.choice([w, 0, _rnd(c, 4)]), c.rng.choice([w, 0, _rnd(c, 4)])]
    self_ = _rnd(c, 0x800)
    e.w32(self_, _pyvt(c, {0x1d8: _namer(b'actor'),
                           0x4cc: _fill('a.4cc', (_r(c) & ~0xff) | c.rng.choice([0, 1, 1, 1]), (3, muz)),
                           0x3f0: _slot('a.3f0', 0, c.rng.choice([0, 0, 1])),
                           0x4ec: _slot('a.4ec', 1), 0x4f0: _slot('a.4f0', 1),
                           0x504: _slot('a.504', 0, hands[0]), 0x500: _slot('a.500', 0, hands[1]),
                           0x3ec: _slot('a.3ec', 1, lambda em: em.arg32(0) ^ 0xabc00000), 0x3d8: _slot('a.3d8', 1)}))
    e.w32(self_ + 0x64c, c.rng.choice([0, 1, 10, 0, 3]))
    e.w32(self_ + 0x78a, c.rng.choice([wid, wid, 0]))
    e.w32(self_ + 0x78e, c.rng.choice([wid, wid, 0]))
    e.mu.ctl_flush_tb()
    return [self_, c.rng.choice([0, 1, _r(c)]), _r(c)]


S(0x5a31d0, 'ZFFActor::_FireWeapon', 'thiscall', None, ret=None, gen=_g_5a31d0, nan_heap=True,
  note='batch267; void; vector helpers as exe code; SEH frame and cookie not reproduced')
