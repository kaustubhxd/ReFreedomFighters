"""specs_s244.py - ladder thread batch 244: ZFFHERO::AddToTargetList (find or make the enemy target list)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
import ladder_kit as K


def _att(c):
    e, r = c.emu, c.rng
    eng = K.engine(c)
    d = K.rnd(c, 0xb00)
    e.w32(eng + 0x9b, d)
    found = K.rnd(c, 0x20) if r.random() < 0.5 else 0
    made = K.rnd(c, 0x20)
    gb = K.rnd(c, 0x20)
    e.w32(made + 8, gb)
    e.w32(made, K.vt(c, 'newlist', {0x154: (0, lambda e2, a: (0, None, None)),
                                    0x124: (4, lambda e2, a: (0, None, K.nostack(a[0]) if False else None)),
                                    0x218: (1, lambda e2, a: (0, None, (K.nostack(a[0]),)))}, nslots=0x240))
    if found:
        e.w32(found, K.vt(c, 'foundlist', {0x218: (1, lambda e2, a: (0, None, (K.nostack(a[0]),)))}, nslots=0x240))
    lists = K.rnd(c, 0x10)
    e.w32(lists, K.vt(c, 'lists', {0x25c: (2, lambda e2, a: (found, None, None)),
                                   0x294: (4, lambda e2, a: (made, None, None))}, nslots=0xb0))
    e.w32(d + 0xadc, lists)

    def sc(e2, res):
        e2.calllog.append(('SetControl', tuple(e2.arg32(i) for i in range(2))))
        e2.ret(argbytes=8)
    e.hook(0x4dc630, sc)
    return [K.rnd(c, 0x200)]


S(0x58b930, 'ZFFHERO::AddToTargetList', 'thiscall', None, ret=None, gen=_att, note='batch244')
