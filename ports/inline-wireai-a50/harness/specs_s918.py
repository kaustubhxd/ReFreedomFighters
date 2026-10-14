"""specs_s918.py - batch 918: 0x440e10 (thiscall, one stack arg (stream), ret 4, returns al). Stand-ins (logged): 0x45f3c0 (thiscall; a drawn
bool; verified separately in batch917), and the stream's slots +0x40, +0x48, +0x50, +0x6c (each writes a drawn dword to the pointer; the
callee pops its one argument). The eight writes into this are compared."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.8

    def h45f(e, rr):
        e.calllog.append(('45f3c0', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=1 if ok else 0, argbytes=4)

    only_hooks(c, {0x45f3c0: h45f})

    def wr(name):
        def h(e, rr):
            v = r.getrandbits(32)
            e.w32(e.arg32(0), v)
            e.calllog.append(('stream.' + name, e.arg32(0) != 0))
            e.ret(eax=0, argbytes=4)
        return h

    stream = vt_object(c, 0x40, {0x40: wr('40'), 0x48: wr('48'), 0x50: wr('50'), 0x6c: wr('6c')}, nslots=0x40, name='stream')
    self = rnd(c, 0x100)
    return [self, stream]


S(0x440e10, 'read440e10 (no name in map; 45f3c0 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch918 (residue-9 slice)')
