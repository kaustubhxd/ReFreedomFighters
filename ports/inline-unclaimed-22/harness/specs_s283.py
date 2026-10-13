"""specs_s283.py - area 22, batch283 (src/batch283.cpp): CMAINCAMERACONTROL::FreeCam. KeyControlGeom1 0x4fca70 and
MouseConVect1 0x4fd2a0 are GUESS hooks (the mouse hook logs its inputs by content and writes a per-case vector);
createmat 0x4de040, vdist2 0x4e0830, COLI::COLI 0x4e1b60 and vector add 0x43e8e0 (inline-batch45) run as exe code.
Objects are Python vtables; stack buffers are logged by content."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _slot(name, nargs, ret=0):
    def h(em, r):
        em.calllog.append((name, 0, None, tuple(em.arg32(i) for i in range(nargs))))
        em.ret(eax=ret() if callable(ret) else ret, argbytes=4 * nargs)
    return h


def _g_4fc190(c):
    e = c.emu

    def key(em, r):
        em.calllog.append(('keygeom', 0x4fca70, em.reg('ecx'), ()))
        em.ret(eax=_r(c), argbytes=0)

    def mouse(em, r):
        v = em.reg('ecx')
        em.calllog.append(('mouse', 0x4fd2a0, None, tuple(em.r32(v + 4 * k) for k in range(3)) +
                           (em.reg('edx'), em.arg32(0), em.arg32(1), em.arg32(2))))
        for k in range(3):
            em.w32(v + 4 * k, _fb(c.rng.uniform(-1, 1)))
        em.ret(eax=0, argbytes=12)
    e.hook(0x4fca70, key)
    e.hook(0x4fd2a0, mouse)
    rm = _rnd(c, 0x1910)
    db = _rnd(c, 0xae0)
    e.w32(rm + 0x9b, db)
    inp = _rnd(c, 0x10)
    e.w32(inp, _pyvt(c, {0x38: _slot('in.38', 2, lambda: (_r(c) & ~0xff) | c.rng.choice([0, 1, 0x40]))}))
    e.w32(rm + 0x1907, inp)
    e.w32(rm, _pyvt(c, {0xe8: _slot('rm.e8', 1, lambda: (_r(c) & ~0xff) | c.rng.choice([0, 1]))}))
    cam = [c.rng.uniform(-500, 500) for _ in range(3)]
    edge = c.rng.random() < 0.15
    if edge:
        cam = [float(c.rng.randrange(-400, 400)) for _ in range(3)]
    for k in range(3):
        e.w32(rm + 0x9e7 + 4 * k, _fb(cam[k]))
    e.w32(0x70039c, rm)
    near = c.rng.random() < 0.4
    for k in range(3):
        e.w32(0x700e40 + 4 * k, _fb(cam[k] + (c.rng.uniform(-0.01, 0.01) if near else c.rng.uniform(-50, 50))))
    if edge:
        # squared distance exactly 2^-14 + 0 + 2^-14 = 1/8192, the threshold (or one step either side)
        dz = c.rng.choice([2.0 ** -7, 2.0 ** -7, 2.0 ** -6, 2.0 ** -8])
        e.w32(0x700e40, _fb(cam[0] + 2.0 ** -7))
        e.w32(0x700e44, _fb(cam[1]))
        e.w32(0x700e48, _fb(cam[2] - dz))
    e.w32(0x700e64, _r(c))
    oid = _r(c)
    obj = 0
    if c.rng.random() < 0.7:
        obj = _rnd(c, 0x10)
        e.w32(obj, _pyvt(c, {0x128: _slot('obj.128', 3)}))

    def db58(em, r):
        a = em.arg32(0)
        em.calllog.append(('db.58', 0, None, (a,)))
        em.ret(eax=obj if a == oid else 0, argbytes=4)
    e.w32(db, _pyvt(c, {0x58: db58}))
    col = _rnd(c, 0x10)
    hitv = [_fb(c.rng.uniform(-500, 500)) for _ in range(3)]

    def c2e0(em, r):
        co = em.arg32(0)
        em.calllog.append(('col.2e0', 0, None, tuple(em.r32(co + 4 * k) for k in range(6)) +
                           tuple(em.arg32(i) for i in range(1, 6))))
        hit = c.rng.choice([0, 1, 0x100])
        if hit & 0xff:
            for k in range(3):
                em.w32(co + 0x28 + 4 * k, hitv[k])
        em.ret(eax=(_r(c) & ~0xff) | hit, argbytes=24)

    def c218(em, r):
        co, h = em.arg32(0), em.arg32(1)
        em.calllog.append(('col.218', 0, None, tuple(em.r32(co + 4 * k) for k in range(6)) +
                           tuple(em.r32(h + 4 * k) for k in range(3)) + (em.arg32(2),)))
        em.ret(eax=0, argbytes=12)
    e.w32(col, _pyvt(c, {0x2e0: c2e0, 0x218: c218}))
    e.w32(db + 0xadc, col)
    mm = [_fb(c.rng.uniform(-1.5, 1.5)) for _ in range(12)]
    pp = [_fb(c.rng.uniform(-500, 500)) for _ in range(3)]

    def g80(em, r):
        m, p = em.arg32(0), em.arg32(1)
        em.calllog.append(('geom.80', 0, None, ()))
        for k in range(12):
            em.w32(m + 4 * k, mm[k])
        for k in range(3):
            em.w32(p + 4 * k, pp[k])
        em.ret(eax=0, argbytes=8)

    def g7c(em, r):
        m, p = em.arg32(0), em.arg32(1)
        em.calllog.append(('geom.7c', 0, None, tuple(em.r32(m + 4 * k) for k in range(12)) +
                           tuple(em.r32(p + 4 * k) for k in range(3))))
        em.ret(eax=0, argbytes=8)
    geom = _rnd(c, 0x10)
    e.w32(geom, _pyvt(c, {0x80: g80, 0x7c: g7c}))
    self_ = _rnd(c, 0x80)
    e.w32(self_, _pyvt(c, {0x84: _slot('self.84', 2)}))
    e.w32(self_ + 0x44, geom)
    e.w8(self_ + 0x68, c.rng.choice([0, 1, 0, 2]))
    e.w8(self_ + 0x69, c.rng.choice([0, 1]))
    e.w16(self_ + 0x64, _r(c))
    e.w32(self_ + 0x6a, _r(c))
    e.w32(self_ + 0x74, oid if c.rng.random() < 0.8 else _r(c))
    return [self_]


S(0x4fc190, 'CMAINCAMERACONTROL::FreeCam', 'thiscall', None, ret='al', gen=_g_4fc190, nan_heap=True,
  note='batch283; returns bool; key/mouse control GUESS hooks; createmat, vdist2, COLI ctor, vector add as exe code')
