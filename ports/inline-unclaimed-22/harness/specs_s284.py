"""specs_s284.py - area 22, batch284 (src/batch284.cpp): ZBoneModifyBase::CalcShadowProjectPlane. mmmul 0x4de440 is a
GUESS hook (logs both matrices by content and writes a per-call matrix); vmmul 0x441970 (inline-collision), PSVECAdd
0x441940, vneg 0x4e09e0 and in-place vmmul 0x4419f0 (inline-batch45) run as exe code. The bone data object and the
bone matrices are Python vtables over per-case tables."""
import struct
from pilot import S
from helpers22 import _rnd, _pyvt


def _r(c):
    return c.rng.getrandbits(32)


def _fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g_645790(c):
    e = c.emu

    # case kinds: 'rnd'; 'zero' (signed-zero matrices so projected points land on +0 and -0 ties); 'nan' (a NaN in the
    # rotation or translation of some bone matrices: NaN coordinates, and a positive-bit NaN z that the int test accepts)
    kind = c.rng.choice(['rnd'] * 6 + ['zero'] * 3 + ['nan'] * 2)

    def mmmul(em, r):
        o, a = em.reg('ecx'), em.reg('edx')
        b = em.arg32(0)
        em.calllog.append(('mmmul', 0x4de440, None, tuple(em.r32(a + 4 * k) for k in range(12)) +
                           tuple(em.r32(b + 4 * k) for k in range(12))))
        sc = c.rng.choice([1.0, 0.01, 2.0])
        for k in range(12):
            if kind == 'zero':
                v = c.rng.choice([0.0, -0.0]) if k != 11 else c.rng.uniform(50, 500)
            else:
                v = c.rng.uniform(-1, 1) * (sc if k < 9 else 300)
            em.w32(o + 4 * k, _fb(v))
        if kind == 'nan' and c.rng.random() < 0.4:
            em.w32(o + 4 * c.rng.choice([2, 5, 8, 0, 4, 9, 10, 11]), c.rng.choice([0x7fc00000, 0x7fc00000, 0xffc00000]))
        em.ret(eax=0, argbytes=4)
    e.hook(0x4de440, mmmul)
    n = c.rng.choice([1, 3, 8, 24])
    mats = _rnd(c, 48 * n)
    boxes = _rnd(c, 48 * n)
    for s in range(n):
        for k in range(12):
            if kind == 'zero':
                v = c.rng.uniform(-0.1, 0.1) if k < 9 else c.rng.uniform(1000, 2000)   # bone centre all positive
            else:
                v = c.rng.uniform(-1.2, 1.2) if k < 9 else c.rng.uniform(-100, 100)
            e.w32(mats + 48 * s + 4 * k, _fb(v))
        for k in range(12):
            v = c.rng.uniform(-20, 20) if k < 3 else (c.rng.uniform(0, 30) if k < 7 else c.rng.uniform(-1, 1))
            e.w32(boxes + 48 * s + 4 * k, _fb(v))
    tab = _rnd(c, 0x20)
    e.wbytes(tab, bytes(c.rng.randrange(n) for _ in range(0x20)))
    shape = _r(c)
    known = c.rng.random() < 0.9

    def bd_c0(em, r):
        em.calllog.append(('bd.c0', 0, None, (em.arg32(0),)))
        em.ret(eax=c.rng.choice([1, 0x100, _r(c) | 1]) if known else 0, argbytes=4)

    def bd_c8(em, r):
        em.calllog.append(('bd.c8', 0, None, (em.arg32(0),)))
        em.ret(eax=tab, argbytes=4)

    def bd_c4(em, r):
        em.calllog.append(('bd.c4', 0, None, (em.arg32(0),)))
        em.ret(eax=boxes, argbytes=4)
    bd = _rnd(c, 0x10)
    e.w32(bd, _pyvt(c, {0xc0: bd_c0, 0xc4: bd_c4, 0xc8: bd_c8}))
    holder = _rnd(c, 0x20)
    e.w32(holder + 0x18, bd)
    rm = _rnd(c, 0x1ab0)
    e.w32(rm + 0x1aa3, holder)
    e.w32(0x70039c, rm)
    geo = _rnd(c, 0x70)
    e.w32(geo + 0x6c, shape)
    obj = _rnd(c, 0x10)
    e.w32(obj + 8, geo)

    def s58(em, r):
        em.calllog.append(('self.58', 0, None, ()))
        em.ret(eax=mats, argbytes=4)
    self_ = _rnd(c, 0x10)
    e.w32(self_, _pyvt(c, {0x58: s58}))
    out = _rnd(c, 0x10)
    for k in range(4):
        e.w32(out + 4 * k, _r(c))
    P = _rnd(c, 0x30)
    for k in range(12):
        e.w32(P + 4 * k, _fb(c.rng.uniform(-1, 1) if k < 9 else c.rng.uniform(-50, 50)))
    if kind == 'zero':
        for k in range(12):
            e.w32(P + 4 * k, _fb(c.rng.choice([-0.0, -0.0, 0.0])))
    T = _rnd(c, 0x10)
    zoff = c.rng.choice([0.0, 200.0, 600.0, -200.0])
    for k, v in enumerate((c.rng.uniform(-50, 50), c.rng.uniform(-50, 50), zoff + c.rng.uniform(-50, 50))):
        e.w32(T + 4 * k, _fb(v))
    if kind == 'zero':
        for k, v in enumerate((c.rng.choice([0.0, -0.0]), c.rng.choice([0.0, -0.0, -0.0]), 300.0)):
            e.w32(T + 4 * k, _fb(v))
    return [self_, obj, out, P, T]


S(0x645790, 'ZBoneModifyBase::CalcShadowProjectPlane', 'thiscall', None, ret='al', gen=_g_645790, nan_heap=True,
  note='batch284; returns bool; mmmul GUESS hook; vector helpers as exe code; cookie not reproduced')
