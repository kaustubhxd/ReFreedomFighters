"""specs_s925.py - batch 925: 0x44a650 (thiscall, one stream arg, ret 4, returns al). Stand-ins (logged): 0x45f960 (thiscall, a drawn bool;
verified in batch924), the stream's slots +0xc, +0x10, +0x20 (each pops its argument), and the object's slots +0x18 and +0x1c (return drawn
dwords). The sub-objects at this+0x18 and this+0x1c are drawn null and non-null in all combinations."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.8
    v18, v1c = r.getrandbits(32), r.getrandbits(32)

    def h45f(e, rr):
        e.calllog.append(('45f960', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=1 if ok else 0, argbytes=4)

    only_hooks(c, {0x45f960: h45f})

    def sw(name):
        def h(e, rr):
            # slot +0x10 gets a pointer into the port's and the exe's own stack: log the value it points to, not the address
            v = e.r32(e.arg32(0)) if name == '10' else e.arg32(0)
            e.calllog.append(('stream.' + name, v))
            e.ret(eax=0, argbytes=8 if name == '10' else 4)     # slot +0x10 takes (pointer, 4)
        return h

    stream = vt_object(c, 0x40, {0xc: sw('c'), 0x10: sw('10'), 0x20: sw('20')}, nslots=0x40, name='stream')

    def o18(e, rr):
        e.calllog.append(('obj.18',))
        e.ret(eax=v18, argbytes=0)

    def o1c(e, rr):
        e.calllog.append(('obj.1c',))
        e.ret(eax=v1c, argbytes=0)

    obj = vt_object(c, 0x40, {0x18: o18, 0x1c: o1c}, nslots=0x40, name='obj')
    self = rnd(c, 0x40)
    e.w32(self + 0x18, obj if r.random() < 0.7 else 0)
    e.w32(self + 0x1c, obj if r.random() < 0.6 else 0)
    return [self, stream]


S(0x44a650, 'read44a650 (no name in map; 45f960 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch925 (dependency slice)')
