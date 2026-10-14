"""specs_s882.py - area 50, batch 882: 0x4abf90 (GUESS name Walk4abf90), thiscall, two stack args (record, name), ret 8, bool.
Stand-ins (hooked, logged): the predicate 0x4db9a0 (thiscall, one arg, ret 4; answers drawn per (entry, flag) at generation time),
the SEH-framed routine 0x4acf30 (thiscall, one arg, ret 4, result unused), and the CRT _stricmp import (install_crt_str).
The record's list head is +0x50, next +0x60; each entry's T object (+0x54) has info at +0xc (flag dword at info+0x23), a name
at +4. T's slots: 0x340 (returns the shared object R), 0x1e0 (bool), 0x2e8 (R or not). The manager (g+0x9b): 0x4c (a value)
and 0x58 (key -> T). The Z sub-object at this+0x11a: 0x4c and 0x5c write the loop flag; 0x5c returns a key. Slot 0x88 (this and
R) logs its two args. The loop is bounded by a counter so it always ends."""
from pilot import S
from anim_common import only_hooks, rnd, vt_object, install_crt_str


def _gen(c):
    e, r = c.emu, c.rng
    names = ['FF', 'ff.wav', 'abc', 'x']
    predmap, eqmap, okmap, tkey = {}, {}, {}, {}
    FLAGS = (0x1007d3, 0x1007d4, 0x100001)

    def h88(name):
        def h(e, rr):
            e.calllog.append((name + '.88', e.arg32(0), e.arg32(1)))
            e.ret(eax=0, argbytes=8)
        return h

    R = e.fake_object('R', 0x40, nslots=0x100, slots={0x88: h88('R')})

    def t340(e, rr):
        e.calllog.append(('T.340',))
        e.ret(eax=R, argbytes=4)

    def t1e0(e, rr):
        e.calllog.append(('T.1e0', e.arg32(0)))
        e.ret(eax=1 if okmap.get(e.reg('ecx'), 0) else 0, argbytes=4)

    def t2e8(e, rr):
        e.calllog.append(('T.2e8',))
        e.ret(eax=R if eqmap.get(e.reg('ecx'), 0) else 0x1234, argbytes=0)

    Tvt = e.fake_vtable('T', 0x100, {0x340: t340, 0x1e0: t1e0, 0x2e8: t2e8})

    def pred(e, rr):
        node, flag = e.reg('ecx'), e.arg32(0)
        e.calllog.append(('pred', flag))
        e.ret(eax=1 if predmap.get((node, flag), 0) else 0, argbytes=4)

    def sef(e, rr):
        e.calllog.append(('sef.4acf30', e.reg('ecx') == 0, e.arg32(0)))
        e.ret(eax=0, argbytes=4)

    M4 = r.getrandbits(32)
    mgr_map = {}

    def m4c(e, rr):
        e.calllog.append(('mgr.4c', e.arg32(0)))
        e.ret(eax=M4, argbytes=4)

    def m58(e, rr):
        k = e.arg32(0)
        e.calllog.append(('mgr.58', k))
        e.ret(eax=mgr_map.get(k, 0), argbytes=4)

    mgr = e.fake_object('mgr', 0x40, nslots=0x100, slots={0x4c: m4c, 0x58: m58})
    loopctr = [r.randint(0, 2)]
    loc4c = r.randint(0, 1)

    def z4c(e, rr):
        out = e.arg32(0)
        e.calllog.append(('Z.4c',))
        e.w32(out, loc4c)
        e.ret(eax=0, argbytes=4)

    keys = [r.getrandbits(32) for _ in range(3)]

    def z5c(e, rr):
        out = e.arg32(0)
        nxt = 1 if loopctr[0] > 0 else 0
        loopctr[0] -= 1
        e.w32(out, nxt)
        k = r.choice(keys + [r.getrandbits(32)])
        e.calllog.append(('Z.5c', k))
        e.ret(eax=k, argbytes=4)

    Zvt = e.fake_vtable('Z', 0x100, {0x4c: z4c, 0x5c: z5c})
    selfvt = e.fake_vtable('self', 0x100, {0x88: h88('self')})

    only_hooks(c, {0x4db9a0: pred, 0x4acf30: sef})
    install_crt_str(c)

    # list entries (built back to front)
    head = 0
    nodes = []
    for i in range(r.randint(1, 3)):
        T = rnd(c, 0x40)
        e.w32(T, Tvt)
        info = rnd(c, 0x40)
        flag = r.getrandbits(32) & ~0x100000
        if r.random() < 0.7:
            flag |= 0x100000
        e.w32(info + 0x23, flag)
        e.w32(T + 0xc, info)
        nm = r.choice(names)
        e.w32(T + 4, 0 if r.random() < 0.5 else e.cstr(nm))
        eqmap[T] = r.random() < 0.5
        okmap[T] = r.random() < 0.7
        k = keys[i % len(keys)]
        tkey[T] = k
        mgr_map[k] = T
        node = rnd(c, 0x80)
        e.w32(node + 0x54, T)
        e.w32(node + 0x60, head)
        for f in FLAGS:
            predmap[(node, f)] = r.random() < 0.6
        head = node
        nodes.append(node)

    p = rnd(c, 0x80)
    e.w32(p + 0x50, head)
    self = rnd(c, 0x200)
    e.w32(self, selfvt)
    e.w32(self + 0x11a, Zvt)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x9b, mgr)
    e.w32(0x70039c, g)
    a2 = e.cstr(r.choice(names))
    return [self, p, a2]


S(0x4abf90, 'Walk4abf90 (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch882')
