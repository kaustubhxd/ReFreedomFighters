"""specs_s879.py - area 50, batch 879: 0x460f90 destructor (GUESS name), thiscall, no args, no result. The sub-object pointers at
+0x5c, +0x60, +0x72, +0x76 are fake objects with a deleting slot (vt +0) that logs its argument; some are equal (the exe skips
the duplicates). The base steps 0x461f00 and 0x43de70 are stood in (logged). SEH frame not reproduced."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng

    def logd(name):
        def h(e, rr):
            e.calllog.append((name, e.arg32(0)))
            e.ret(eax=0, argbytes=4)
        return h

    def base(name):
        def h(e, rr):
            e.calllog.append((name, e.reg('ecx')))
            e.ret(eax=0, argbytes=0)
        return h

    only_hooks(c, {0x461f00: base('base.461f00'), 0x43de70: base('base.43de70')})
    objs = [vt_object(c, 0x40, {0x0: logd('dtor.%d' % i)}, nslots=0x20, name='sub%d' % i) for i in range(3)]
    self = rnd(c, 0x100)
    pick = lambda: r.choice([0] + objs)
    a = pick()
    b = pick()
    cc = r.choice([0, a, objs[0]])
    d = r.choice([0, b, objs[1]])
    e.w32(self + 0x72, a)
    e.w32(self + 0x76, b)
    e.w32(self + 0x5c, cc)
    e.w32(self + 0x60, d)
    return [self]


S(0x460f90, 'destructor 0x460f90 (GUESS name; SEH frame not reproduced)', 'thiscall', None, gen=_gen, note='area50 batch879')
