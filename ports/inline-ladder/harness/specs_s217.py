"""specs_s217.py - ladder thread batch 217: ZFFActionDropC4::CallBack."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _c4(c):
    e, r = c.emu, c.rng

    def h(e2, res):
        e2.calllog.append(('fn467410', e2.reg('ecx'), tuple(e2.arg32(i) for i in range(6))))
        e2.ret(argbytes=0x18)
    e.hook(0x467410, h)
    item = K.rnd(c, 0x40)
    e.w32(item, K.vt(c, 'item', {0x2d0: (2, lambda e2, a: (0, None, None)), 0x2f0: (3, lambda e2, a: (0, None, None))}, nslots=0x100))
    hero = K.rnd(c, 0x100)
    e.w32(hero, K.vt(c, 'hero', {0x4f4: (1, lambda e2, a: (0, None, None))}, nslots=0x180))
    hand = K.rnd(c, 0x40)
    e.w32(hand, K.vt(c, 'hand', {0x10: (0, lambda e2, a: (item, None, None)), 8: (2, lambda e2, a: (0, None, None))}, nslots=8))
    eng = K.engine(c)
    d = K.rnd(c, 0x10)
    e.w32(eng + 0x9b, d)
    e.w32(d, K.vt(c, 'database', {0x4c: (1, lambda e2, a: ((a[0] * 3 + 5) & 0xffffffff, None, None))}, nslots=0x40))
    s = K.rnd(c, 0x20)
    e.w32(s + 8, hero)
    e.w32(s + 0xc, hand)
    return [s]


S(0x5df8b0, 'ZFFActionDropC4::CallBack', 'thiscall', None, ret='al', gen=_c4, note='batch217')
