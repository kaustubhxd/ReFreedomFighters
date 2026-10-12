"""specs_s258.py - area 22, batch258 (src/batch258.cpp): CMoveAlongPath::SetNextPath. Geom name via vt[0x1d8] writing a
self-pointing inline string (as specs_s251); c_str 0x4cc1d0 and the string destructor 0x4cbec0 run as original code; the
logger logs the %s text; the assert hook at 0x7003b0 is always set and logged (with no hook the exe breaks on int3)."""
from pilot import S
from helpers22 import _rnd, _multi_vt, _pyvt, _log_world


def _r(c):
    return c.rng.getrandbits(32)


def _namer(text):
    def h(em, r):
        buf = em.arg32(0)
        em.calllog.append(('name.1d8', 0x1d8, None, (em.arg32(1),)))
        em.w32(buf, buf + 4)
        em.wbytes(buf + 4, text + b'\0')
        em.ret(eax=buf, argbytes=8)
    return h


def _g_523b90(c):
    e = c.emu
    _log_world(c, deref=True)
    g = _rnd(c, 0x10)
    v = (_r(c) & ~0xff) | c.rng.choice([1, 1, 0, 0x20])
    e.w32(g, _pyvt(c, {0x1d8: _namer(b'path%d' % c.rng.randint(0, 99)),
                       0x1e0: lambda em, r, v=v: (em.calllog.append(('geom.1e0', 0x1e0, None, (em.arg32(0),))),
                                                  em.ret(eax=v, argbytes=4))}))
    path = c.rng.choice([_r(c) | 1] * 5 + [0])
    db = _rnd(c, 0x40)
    e.w32(db, _multi_vt(c, {0x58: (lambda em, a, p=path, g=g: (g if a[0] == p else 0, None), 1)}))
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    self_ = _rnd(c, 0x60)
    e.mu.ctl_flush_tb()
    return [self_, path, _r(c)]


S(0x523b90, 'CMoveAlongPath::SetNextPath', 'thiscall', None, ret=None, gen=_g_523b90,
  note='batch258; void; float stored as a bit copy; SEH frame and cookie not reproduced')
