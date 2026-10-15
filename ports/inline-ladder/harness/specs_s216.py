"""specs_s216.py - ladder thread batch 216: ZFFActionGetBack / ZFFActionPutBack Execute and CallBack.
Direct callees (GetItemBack, DetachItemBack, AttachItemBack, ZBoneAnim::AddCallBack, 0x467410) are logging hooks."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _hook(c, addr, name, nargs, argbytes, ret=None):
    def h(e2, res):
        a = tuple(K.nostack(e2.arg32(i)) for i in range(nargs))
        e2.calllog.append((name, e2.reg('ecx'), a))
        e2.ret(eax=ret() if ret else 0x4444, argbytes=argbytes)
    c.emu.hook(addr, h)


def _act(c):
    e, r = c.emu, c.rng
    item = K.rnd(c, 0x40)
    e.w32(item, K.vt(c, 'item', {0x2e8: (0, lambda e2, a: (0, None, None)), 0x2d0: (2, lambda e2, a: (0, None, None))}, nslots=0x100))
    back = item if r.random() < 0.5 else 0
    _hook(c, 0x591f00, 'GetItemBack', 0, 0, lambda: back if back else 0)
    _hook(c, 0x591080, 'DetachItemBack', 0, 0, lambda: r.getrandbits(32))
    _hook(c, 0x58bc60, 'AttachItemBack', 1, 4)
    _hook(c, 0x4614d0, 'AddCallBack', 3, 0xc)
    _hook(c, 0x467410, 'fn467410', 6, 0x18)
    ba = r.getrandbits(32)
    hero = K.rnd(c, 0x100)
    e.w32(hero, K.vt(c, 'hero', {0x230: (2, lambda e2, a: (ba, None, None))}, nslots=0x100))
    hand = K.rnd(c, 0x40)
    e.w32(hand, K.vt(c, 'hand', {0x10: (0, lambda e2, a: (item, None, None)), 8: (2, lambda e2, a: (0, None, None))}, nslots=8))
    eng = K.engine(c)
    d = K.rnd(c, 0x10)
    e.w32(eng + 0x9b, d)
    e.w32(d, K.vt(c, 'database', {0x4c: (1, lambda e2, a: ((a[0] * 3 + 5) & 0xffffffff, None, None))}, nslots=0x40))
    s = K.rnd(c, 0x20)
    cbret = r.getrandbits(32)
    e.w32(s, K.vt(c, 'action', {0xc: (0, lambda e2, a: (cbret, None, None))}, nslots=8))
    e.w32(s + 8, hero)
    e.w32(s + 0xc, hand)
    e.w32(s + 0x10, 0 if r.random() < 0.3 else r.getrandbits(32))
    return [s]


S(0x5e02e0, 'ZFFActionGetBack::Execute', 'thiscall', None, ret='al', gen=_act, note='batch216')
S(0x5df970, 'ZFFActionGetBack::CallBack', 'thiscall', None, ret='al', gen=_act, note='batch216')
S(0x5e03c0, 'ZFFActionPutBack::Execute', 'thiscall', None, ret='al', gen=_act, note='batch216')
S(0x5df9f0, 'ZFFActionPutBack::CallBack', 'thiscall', None, ret='al', gen=_act, note='batch216')
