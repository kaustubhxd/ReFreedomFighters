"""specs_s855.py - area 50, batch 855: 0x5a29d0 (name GUESS), thiscall, one stack arg (the stream), ret 4, bool.
Stand-ins (hooked, logged): the base save 0x47ade0, the sub-object save 0x59d3f0 and the table lookup 0x589f70 (returns a
value from its argument). The stream's slots log their values (dword 0x3c / 0x44, word 0x48, float 0x4c, byte 0x60, the
12-byte vector 0x68 by pointer, and the 16-byte block 0x10 by pointer and count). The counted list at +0x7ce is 0..4 items.
The engine manager's +0x44 is subtracted from two fields and the table pointer comes from 0x7003b8."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object


def _gen(c):
    e, r = c.emu, c.rng
    fin = lambda x: x if x == x and abs(x) < 1e6 else 0.0

    def log(name, nargs):
        def h(e, rr):
            e.calllog.append((name,) + tuple(e.arg32(k) for k in range(nargs)))
            e.ret(eax=0, argbytes=4 * nargs)
        return h

    def lookup(e, rr):
        e.calllog.append(('lookup589f70', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=arg_ret, argbytes=4)

    def base(e, rr):
        e.calllog.append(('base.47ade0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    def sub(e, rr):
        e.calllog.append(('sub.59d3f0', e.reg('ecx'), e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    arg_ret = r.getrandbits(32)
    only_hooks(c, {0x47ade0: base, 0x59d3f0: sub, 0x589f70: lookup})
    stream = vt_object(c, 0x40, {0x3c: log('s.3c', 1), 0x44: log('s.44', 1), 0x48: log('s.48', 1),
                                 0x4c: log('s.4c', 1), 0x60: log('s.60', 1), 0x68: log('s.68', 1),
                                 0x10: log('s.10', 2)}, nslots=0x100, name='stream')
    mgr = vt_object(c, 0x80, {}, nslots=0x20, name='mgr')
    e.w32(mgr + 0x44, r.getrandbits(32))
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    table = rnd(c, 0x100)
    e.w32(0x7003b8, table)
    sub_obj = rnd(c, 0x100)
    self = rnd(c, 0x1000)
    e.w32(self + 0x54, sub_obj)
    e.w32(self + 0x7ce, r.randint(0, 4))
    e.w32(self + 0x921, r.getrandbits(32))
    return [self, stream]


S(0x5a29d0, 'Save5a29d0 (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch855')
