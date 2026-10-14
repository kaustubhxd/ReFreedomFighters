"""specs_s224.py - ladder thread batch 224: ZIKLNKOBJ CalcShadowProjectPlane, ForceFacing."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _self(c):
    e, r = c.emu, c.rng
    s = K.rnd(c, 0x200)
    off = [f32(r.uniform(-300, 300)) for _ in range(3)]

    def w(e2, a):
        before = K.bits3(e2, a[0])
        K.wv3(e2, a[0], [f32(x + y) for x, y in zip(K.rv3(e2, a[0]), off)])
        return 0, None, before

    def setm(e2, a):
        return 0, None, tuple(e2.r32(a[0] + 4 * i) for i in range(9)) + K.bits3(e2, a[1])
    e.w32(s, K.vt(c, 'self', {0x84: (1, w), 0x370: (2, setm)}, nslots=0x100))
    ik = K.rnd(c, 0x10)
    rv = r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff)
    e.w32(ik, K.vt(c, 'ik', {0x54: (4, lambda e2, a: (rv, None, None))}, nslots=0x20))
    e.w32(s + 0x6c, ik)

    def h(e2, res):
        e2.calllog.append(('ZLNKOBJ::CalcShadowProjectPlane', e2.reg('ecx'), tuple(e2.arg32(i) for i in range(3))))
        e2.ret(eax=0x3131, argbytes=0xc)
    e.hook(0x461760, h)
    return s


S(0x465890, 'ZIKLNKOBJ::CalcShadowProjectPlane', 'thiscall', None, ret='eax',
  gen=lambda c: [_self(c)] + [c.rng.getrandbits(32) for _ in range(3)], note='batch224')
S(0x466640, 'ZIKLNKOBJ::ForceFacing', 'thiscall', None, ret=None,
  gen=lambda c: [_self(c), c.fbuf(3, lambda cc: cc.fv(-400.0, 400.0))], note='batch224')
