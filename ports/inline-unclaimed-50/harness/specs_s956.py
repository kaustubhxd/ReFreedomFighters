"""specs_s956.py - area 50 batch 956: 0x519ab0 (thiscall, one arg, ret 4, void). The stack cookie is not reproduced (tagged). Stand-ins (logged): 0x5003d0 (thiscall,
one index arg, ECX = the argument's object at +4; returns a block drawn per index), and this's object at +0x14, slot +0x32c (thiscall, a float and a
pointer; ret 8 assumed; logs the float and the three floats behind the pointer)."""
import struct
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _f(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _gen(c):
    e, r = c.emu, c.rng
    blks = {}
    for idx in (0, 1, 2, 3):
        b = rnd(c, 0x10)
        e.w32(b, _f(r.uniform(-100.0, 100.0)))
        blks[idx] = b

    def h5003(e, rr):
        e.calllog.append(('5003d0', e.arg32(0), e.reg('ecx') != 0))
        e.ret(eax=blks[e.arg32(0)], argbytes=4)

    only_hooks(c, {0x5003d0: h5003})

    def h32c(e, rr):
        p = e.arg32(1)
        e.calllog.append(('obj.32c', e.arg32(0), tuple(e.r32(p + 4 * k) for k in range(3))))
        e.ret(eax=0, argbytes=8)

    obj = vt_object(c, 0x40, {0x32c: h32c}, nslots=0x400, name='obj')
    self = rnd(c, 0x40)
    e.w32(self + 0x14, obj)
    a = rnd(c, 0x40)
    e.w32(a + 4, rnd(c, 0x20))
    return [self, a]


S(0x519ab0, 'four accessor reads then slot 0x32c (no name in map; 5003d0 stood in; cookie not reproduced)', 'thiscall', None, gen=_gen, note='area50 batch956 (claimed)')
