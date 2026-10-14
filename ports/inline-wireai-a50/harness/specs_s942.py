"""specs_s942.py - area 50 batch 942: 0x5eeab0 (thiscall, one float arg, ret 4, void). Stand-ins (logged): 0x5ac5b0 (thiscall: the object, one float)
and 0x5ec2b0 (thiscall: the child at this+0x15, a float and -1). The list at this+5..this+9 holds 0 to 3 element pointers; each element points to a
cell that holds the object pointer."""
import struct
from pilot import S, F
from anim_common import only_hooks, rnd


def _gen(c):
    e, r = c.emu, c.rng

    def h5ac(e, rr):
        e.calllog.append(('5ac5b0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def h5ec(e, rr):
        e.calllog.append(('5ec2b0', e.reg('ecx'), e.arg32(0), e.arg32(1)))
        e.ret(eax=0, argbytes=8)

    only_hooks(c, {0x5ac5b0: h5ac, 0x5ec2b0: h5ec})
    self = rnd(c, 0x40)
    cnt = r.randint(0, 3)
    arr = rnd(c, 0x40)
    e.w32(self + 5, arr)
    e.w32(self + 9, arr + 4 * cnt)
    for i in range(cnt):
        cell = rnd(c, 0x10)
        obj = rnd(c, 0x20)
        e.w32(cell, obj)
        e.w32(arr + 4 * i, cell)
    e.w32(self + 0x15, rnd(c, 0x20))
    return [self, F(r.uniform(-4.0, 4.0))]


S(0x5eeab0, 'loop over list then child call (no name in map; 5ac5b0 and 5ec2b0 stood in)', 'thiscall', None, gen=_gen, note='area50 batch942 (label D)')
