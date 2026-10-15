"""specs_s219.py - ladder thread batch 219: ZFFActionSwingBat::Execute, ZFFActionUseKnife::Execute."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from pe_emu import f32
import ladder_kit as K


def _melee(c):
    e, r = c.emu, c.rng

    def hk(addr, name, n, ab, ret=0):
        def h(e2, res):
            e2.calllog.append((name, e2.reg('ecx'), tuple(e2.arg32(i) for i in range(n))))
            e2.ret(eax=ret, argbytes=ab)
        e.hook(addr, h)
    hk(0x4614d0, 'AddCallBack', 3, 0xc, 0x4444)
    hk(0x466f60, 'PlaySound', 1, 4, r.getrandbits(32))
    ba = r.getrandbits(32)
    hero = K.rnd(c, 0x100)
    e.w32(hero, K.vt(c, 'hero', {0x228: (5, lambda e2, a: (ba, None, None)),
                                 0x578: (1, lambda e2, a: (0x5a5a0000 | (a[0] & 0xffff), None, None))}, nslots=0x180))
    eng = K.engine(c)
    rnd = f32(r.choice([r.uniform(0, 1), r.uniform(-1, 1), 0.0, 1.0, r.uniform(-1e7, 1e7)]))
    e.w32(eng, K.vt(c, 'engine', {0x1c0: (2, lambda e2, a: (0, rnd, None))}, nslots=0x80))
    snd = K.rnd(c, 0x10)
    e.w32(eng + 0x1a9f, snd)
    e.w32(snd, K.vt(c, 'sound', {0x60: (1, lambda e2, a: (a[0] ^ 0x1111, None, None))}, nslots=0x20))
    obj = K.rnd(c, 0x100)
    d = K.rnd(c, 0x10)
    e.w32(eng + 0x9b, d)
    e.w32(d, K.vt(c, 'database', {0x60: (1, lambda e2, a: (obj if r.random() < 0.8 else 0, None, None))}, nslots=0x40))
    s = K.rnd(c, 0x20)
    cb = r.getrandbits(32)
    e.w32(s, K.vt(c, 'action', {0xc: (0, lambda e2, a: (cb, None, None))}, nslots=8))
    e.w32(s + 8, hero)
    knife = K.rnd(c, 8)
    if r.random() < 0.3:
        e.w32(knife, 0)
    return [s, knife]


def _swing(c):
    s, _ = _melee(c)
    return [s]


def _knife(c):
    s, knife = _melee(c)
    c.emu.w32(s + 0xc, knife)
    return [s]


S(0x5e0410, 'ZFFActionSwingBat::Execute', 'thiscall', None, ret='al', gen=_swing, note='batch219')
S(0x5e05a0, 'ZFFActionUseKnife::Execute', 'thiscall', None, ret='al', gen=_knife, note='batch219')
