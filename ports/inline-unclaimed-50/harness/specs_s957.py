"""specs_s957.py - area 50 batch 957: 0x5197e0 (thiscall, one arg, ret 4, void). Stand-ins (logged): 0x5003d0 (thiscall, one index arg, ECX = the
argument's object at +4; returns a block drawn per index; the first dword of blocks 0 and 2 is drawn 0 about a third of the time), and this's object at
+0x14: slot +0x2fc (thiscall, a dword and a float, ret 8 assumed; returns a drawn float in st0) and slot +0x2f8 (thiscall, a float and a flag, ret 8
assumed)."""
import struct
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _f(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _gen(c):
    e, r = c.emu, c.rng
    blks = {}
    for idx in (0, 1, 2):
        b = rnd(c, 0x10)
        if idx != 1 and r.random() < 0.33:
            e.w32(b, 0)
        else:
            e.w32(b, _f(r.uniform(-100.0, 100.0)))
        blks[idx] = b
    rv = r.uniform(-50.0, 50.0)

    def h5003(e, rr):
        e.calllog.append(('5003d0', e.arg32(0), e.reg('ecx') != 0))
        e.ret(eax=blks[e.arg32(0)], argbytes=4)

    only_hooks(c, {0x5003d0: h5003})

    def h2fc(e, rr):
        e.calllog.append(('obj.2fc', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8, st0=rv)

    def h2f8(e, rr):
        e.calllog.append(('obj.2f8', e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    obj = vt_object(c, 0x40, {0x2fc: h2fc, 0x2f8: h2f8}, nslots=0x400, name='obj')
    self = rnd(c, 0x40)
    e.w32(self + 0x14, obj)
    a = rnd(c, 0x40)
    e.w32(a + 4, rnd(c, 0x20))
    return [self, a]


S(0x5197e0, 'guarded slot 0x2fc then slot 0x2f8 (no name in map; 5003d0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch957 (claimed)')
