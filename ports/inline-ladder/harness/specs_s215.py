"""specs_s215.py - ladder thread batch 215: three shared action destructors, FFCommand::Execute, PickupItem::Execute."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _del(c):
    def dl(e2, res):
        e2.calllog.append(('delete', e2.arg32(0), e2.arg32(1)))
        e2.ret()
    c.emu.hook(0x634273, dl)
    return [K.rnd(c, 0x20), c.rng.getrandbits(32)]


for a in (0x5df7f0, 0x5df820, 0x485f30):
    S(a, 'action deleting dtor %x' % a, 'thiscall', None, ret='eax', gen=_del, note='batch215')


def _obj(c, name, slots, n=0x200):
    o = K.rnd(c, 0x1000 if name == 'hero' else 0x40)
    c.emu.w32(o, K.vt(c, name, slots, nslots=n))
    return o


def _ffc(c):
    r = c.rng
    kind = r.randint(0, 10)
    t = _obj(c, 'kind', {0x330: (0, lambda e2, a: (kind, None, None))})
    isw = r.getrandbits(32) & (0xffffff00 if r.random() < 0.3 else 0xffffffff)
    w = _obj(c, 'item', {0x1e0: (1, lambda e2, a: (isw, None, None)), 0x350: (0, lambda e2, a: (t, None, None))})
    held = w if r.random() < 0.8 else 0
    hero = _obj(c, 'hero', {0x504: (0, lambda e2, a: (held, None, None)), 0x228: (5, lambda e2, a: (0, None, None))})
    s = K.rnd(c, 0x20)
    c.emu.w32(s + 8, hero)
    return [s]


def _pick(c):
    r = c.rng
    e = c.emu
    rb = r.getrandbits(32) & (0xffffff00 if r.random() < 0.5 else 0xffffffff)
    item = _obj(c, 'item', {0x144: (1, lambda e2, a: (0, None, None)), 0x1e0: (1, lambda e2, a: (rb, None, None)),
                            0x2d0: (2, lambda e2, a: (0, None, None)), 0x2f0: (3, lambda e2, a: (0, None, None))})
    hand = _obj(c, 'hand', {8: (2, lambda e2, a: (0, None, None))}, n=8)
    eng = K.engine(c)
    d = K.rnd(c, 0x10)
    e.w32(eng + 0x9b, d)
    e.w32(d, K.vt(c, 'database', {0x4c: (1, lambda e2, a: ((a[0] * 7 + 1) & 0xffffffff, None, None))}, nslots=0x40))
    s = K.rnd(c, 0x20)
    e.w32(s + 8, item)
    e.w32(s + 0xc, r.getrandbits(32))
    e.w32(s + 0x10, hand)
    return [s]


S(0x5e0250, 'ZFFActionFFCommand::Execute', 'thiscall', None, ret='al', gen=_ffc, note='batch215')
S(0x5e0330, 'ZFFActionPickupItem::Execute', 'thiscall', None, ret='al', gen=_pick, note='batch215')
