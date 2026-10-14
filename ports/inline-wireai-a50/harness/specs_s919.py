"""specs_s919.py - batch 919: 0x4fa230 (thiscall, one stack arg (stream), ret 4, returns al). Stand-ins (logged): 0x440e10 (thiscall, a drawn
bool; verified in batch918) and the stream's slots +0x40, +0x48, +0x68 (each writes a drawn dword to the pointer; the callee pops one
argument). The writes into this, including this+0x8b, are compared."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    ok = r.random() < 0.8

    def h440(e, rr):
        e.calllog.append(('440e10', e.reg('ecx') != 0, e.arg32(0) != 0))
        e.ret(eax=1 if ok else 0, argbytes=4)

    only_hooks(c, {0x440e10: h440})

    def wr(name):
        def h(e, rr):
            v = r.getrandbits(32)
            e.w32(e.arg32(0), v)
            e.calllog.append(('stream.' + name, e.arg32(0) != 0))
            e.ret(eax=0, argbytes=4)
        return h

    stream = vt_object(c, 0x40, {0x40: wr('40'), 0x48: wr('48'), 0x68: wr('68')}, nslots=0x40, name='stream')
    self = rnd(c, 0x100)
    return [self, stream]


S(0x4fa230, 'read4fa230 (no name in map; 440e10 stood in)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch919 (residue-9 slice)')
