"""specs_s959.py - area 50 batch 959: 0x519bf0 (thiscall, one arg, ret 4, void). Stand-ins (logged): 0x5003d0 (thiscall,
one index arg, ECX = the argument's object at +4; returns a block drawn per index), and this's object at +0x14, slot +0x2cc (thiscall, four
floats; ret 0x10 assumed; logs the four floats)."""
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

    def h2cc(e, rr):
        floats = tuple(e.arg32(k) for k in range(4))
        e.calllog.append(('obj.2cc', floats))
        e.ret(eax=0, argbytes=0x10)

    obj = vt_object(c, 0x40, {0x2cc: h2cc}, nslots=0x400, name='obj')
    self = rnd(c, 0x40)
    e.w32(self + 0x14, obj)
    a = rnd(c, 0x40)
    e.w32(a + 4, rnd(c, 0x20))
    return [self, a]


S(0x519bf0, 'four accessor reads then slot 0x2cc (no name in map; 5003d0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch959 (claimed)')
