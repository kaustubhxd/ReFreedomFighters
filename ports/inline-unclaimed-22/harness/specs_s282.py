"""specs_s282.py - area 22, batch282 (src/batch282.cpp): CExplodeMolotov::UpdateInAir. GetController 0x456b70, vrand
0x4e0a10 and vmul 0x4e0980 are GUESS hooks (vrand writes per-call floats, vmul logs the scale by content and writes
per-call floats); vmmul 0x4419f0 and PSVECAdd 0x441940 (inline-batch45) run as exe code. Objects are Python vtables;
buffers are logged by content, never by stack address."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g_584f90(c):
    e = c.emu

    def ctl(em, r):
        em.calllog.append(('getctl', 0x456b70, em.reg('ecx'), ()))
        em.w32(em.arg32(0), eid)
        em.w32(em.arg32(1), earg)
        em.ret(eax=_r(c), argbytes=8)

    def vrand(em, r):
        v = em.reg('ecx')
        em.calllog.append(('vrand', 0x4e0a10, None, ()))
        for k in range(3):
            em.w32(v + 4 * k, _fb(c.rng.uniform(-1, 1)))
        em.ret(eax=0, argbytes=0)

    def vmul(em, r):
        v, s = em.reg('ecx'), em.reg('edx')
        em.calllog.append(('vmul', 0x4e0980, None, tuple(em.r32(v + 4 * k) for k in range(3)) +
                           tuple(em.r32(s + 4 * k) for k in range(3))))
        for k in range(3):
            em.w32(v + 4 * k, _fb(c.rng.uniform(-10, 10)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x456b70, ctl)
    e.hook(0x4e0a10, vrand)
    e.hook(0x4e0980, vmul)
    eid, earg = _r(c), _r(c)
    bid, tid = _r(c), _r(c)
    bottle = 0
    if c.rng.random() < 0.8:
        bottle = _rnd(c, 0x10)

        def b78(em, r):
            p = em.arg32(0)
            em.calllog.append(('bottle.78', 0, None, tuple(em.r32(p + 4 * k) for k in range(3))))
            em.ret(eax=0, argbytes=4)
        e.w32(bottle, _pyvt(c, {0x78: b78}))
    emi = _rnd(c, 0x10)

    def e218(em, r):
        w, z = em.arg32(1), em.arg32(2)
        em.calllog.append(('emit', 0, None, (em.arg32(0),) + tuple(em.r32(w + 4 * k) for k in range(3)) +
                           tuple(em.r32(z + 4 * k) for k in range(3)) + (em.arg32(3),)))
        em.ret(eax=0, argbytes=16)
    e.w32(emi, _pyvt(c, {0x218: e218}))
    tpl = _rnd(c, 0x10) if c.rng.random() < 0.85 else 0
    objs = {bid: bottle, tid: tpl, eid: emi}

    def db58(em, r):
        a = em.arg32(0)
        em.calllog.append(('db.58', 0, None, (a,)))
        em.ret(eax=objs.get(a, 0), argbytes=4)
    db = _rnd(c, 0x10)
    e.w32(db, _pyvt(c, {0x58: db58}))
    rm = _rnd(c, 0xa0)
    e.w32(rm + 0x9b, db)
    e.w32(rm + 0x40, c.rng.randrange(0, 1 << 24))
    dt = c.rng.choice([1 / 30, 1 / 60, 0.1, 0.0005, c.rng.uniform(0.001, 0.08)])
    e.w32(rm + 0x48, _fb(dt))
    e.w32(0x70039c, rm)
    pp = [c.rng.uniform(-500, 500) for _ in range(3)]
    mm = [c.rng.uniform(-1.5, 1.5) for _ in range(12)]

    def c84(em, r):
        p = em.arg32(0)
        em.calllog.append(('car.84', 0, None, tuple(em.r32(p + 4 * k) for k in range(3))))
        for k in range(3):
            em.w32(p + 4 * k, _fb(pp[k] + 1))
        em.ret(eax=0, argbytes=4)

    def c80(em, r):
        m, p = em.arg32(0), em.arg32(1)
        em.calllog.append(('car.80', 0, None, ()))
        for k in range(12):
            em.w32(m + 4 * k, _fb(mm[k]))
        for k in range(3):
            em.w32(p + 4 * k, _fb(pp[k]))
        em.ret(eax=0, argbytes=8)
    car = _rnd(c, 0x10)
    e.w32(car, _pyvt(c, {0x80: c80, 0x84: c84}))
    self_ = _rnd(c, 0x370)
    e.w32(self_ + 0x44, car)
    e.w32(self_ + 0x362, bid if c.rng.random() < 0.9 else _r(c))
    e.w32(self_ + 0x4c, tid)
    t = c.rng.choice([c.rng.uniform(-0.05, 0.1), dt, dt - 0.0001, 0.0, c.rng.uniform(0, 0.03)])
    e.w32(self_ + 0x99, _fb(t))
    for k in range(3):
        e.w32(self_ + 0x8d + 4 * k, _fb(c.rng.uniform(-500, 500)))
    return [self_]


S(0x584f90, 'CExplodeMolotov::UpdateInAir', 'thiscall', None, ret=None, gen=_g_584f90, nan_heap=True,
  note='batch282; void; GetController, vrand, vmul GUESS hooks; vmmul and PSVECAdd as exe code; cookie not reproduced')
