"""specs_s227.py - ladder thread batch 227: ZIKLNKOBJ::UpdateFacing (quick turn clip choice)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _uf(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    e.w32(s + 0x136, r.getrandbits(32) | (0x200000 if r.random() < 0.85 else 0))
    if r.random() < 0.1:
        e.w32(s + 0x1a6, 0)
    tgt = K.rnd(c, 0x10)
    toff = [f32(r.uniform(-300, 300)) for _ in range(3)]
    if r.random() < 0.1:
        toff = [0.0, f32(r.uniform(-10, 10)), 0.0]

    def w(e2, a):
        before = K.bits3(e2, a[0])
        K.wv3(e2, a[0], [f32(x + y) for x, y in zip(K.rv3(e2, a[0]), toff)])
        return 0, None, before
    e.w32(tgt, K.vt(c, 'target', {0x84: (1, w)}, nslots=0x40))
    eng = K.engine(c)
    d = K.rnd(c, 0x100)
    e.w32(eng + 0x9b, d)
    tp = tgt if r.random() < 0.9 else 0
    e.w32(d, K.vt(c, 'database', {0x58: (1, lambda e2, a: (tp, None, None))}, nslots=0x40))
    soff = [f32(r.uniform(-50, 50)) for _ in range(3)]
    if r.random() < 0.15:          # target straight ahead/behind: local x exactly 0 (the Left/Right tie)
        soff[0] = toff[0]

    def tolocal(e2, a):
        before = K.bits3(e2, a[0])
        K.wv3(e2, a[0], [f32(x - y) for x, y in zip(K.rv3(e2, a[0]), soff)])
        return 0, None, before
    busy = r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff)
    flags = r.getrandbits(32)
    anim = r.getrandbits(32) if r.random() < 0.8 else 0
    nameobj = K.rnd(c, 0x10)
    if r.random() < 0.3:
        e.w32(nameobj + 4, 0)
    else:
        e.w32(nameobj + 4, e.cstr('Hero') if hasattr(e, 'cstr') else 0)
    slots = {0x324: (1, lambda e2, a: (busy, None, None)), 0x320: (1, lambda e2, a: (flags, None, None)),
             0x8c: (1, tolocal), 0x21c: (1, lambda e2, a: (anim, None, None)), 0x230: (2, lambda e2, a: (0, None, None)),
             0x20: (0, lambda e2, a: (nameobj, None, None))}
    e.w32(s, K.vt(c, 'self', slots, nslots=0x100))
    pr = K.rnd(c, 0x10)

    def prn(e2, res):
        e2.calllog.append(('printf', tuple(e2.arg32(i) for i in range(4))))
        e2.ret()
    prvt = e.fake_vtable('printer', 0x10, {0x30: prn})
    e.w32(pr, prvt)
    lg = K.rnd(c, 0x10)
    e.w32(lg, K.vt(c, 'logger', {0x20: (2, lambda e2, a: (pr, None, None))}, nslots=0x10))
    e.w32(0x700390, lg)
    return [s]


S(0x467d00, 'ZIKLNKOBJ::UpdateFacing', 'thiscall', None, ret=None, gen=_uf, note='batch227')
