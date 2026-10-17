"""specs_f1106.py - fresh-11 batch 6: slice-11 functions of 126 to 137 bytes."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from h11 import L, obj, rbuf, fbuf, patch


def r32(c): return c.rng.getrandbits(32)


def set_eng9b(c, o9b):
    eng = rbuf(c, 0x200)
    c.emu.w32(eng + 0x9b, o9b)
    c.emu.w32(0x70039c, eng)


def g_57f130(c):
    patch(c, 0x57d500, L('57d500', 2, ret=r32(c)))
    patch(c, 0x57ee90, L('57ee90', 0, ret=r32(c)))
    n = c.rng.choice([0, 1, 2, 3, 0xffffffff])
    objs = [c.rng.choice([0, rbuf(c, 0x100), rbuf(c, 0x100)]) for _ in range(4)]
    mgr = obj(c, 'mgr', {0xcc: L('mgr_cc', 1, retf=lambda e, a: objs[a[0] & 3])})
    c.emu.w32(0x70038c, mgr)
    o = rbuf(c, 0x300)
    c.emu.w32(o + 0x23c, c.emu.fake_vtable('list', 13, {0x14: L('count', 0, ret=n), 0x30: L('at', 1, retf=lambda e, a: (a[0] * 0x101 + 7) & 0xffffffff if c.rng.random() < 0.0 else a[0])}))
    return [o, c.rng.choice([0, 1, 0x100, r32(c)])]
S(0x57f130, 'GUESS refresh entries (+0x23c list)', 'thiscall', None, ret='eax', gen=g_57f130)


def g_42d6b0(c):
    patch(c, 0x41e290, L('new', 1, pop=0, ret=c.rng.choice([0, rbuf(c, 0x20)]), ecx=False))
    patch(c, 0x436bd0, L('ctor_436bd0', 0, ret=r32(c)))
    o = obj(c, 'self', {0xc8: L('vtc8', 0, ret=r32(c))}, size=0x1910)
    return [o]
S(0x42d6b0, 'GUESS create sub-object (+0x1907)', 'thiscall', None, ret='eax', gen=g_42d6b0)


def g_45c5f0(c):
    patch(c, 0x45c3e0, L('body', 0, ret=r32(c)))
    patch(c, 0x4690b0, L('lort', 2, pop=0, ret=r32(c), ecx=False))
    pool = obj(c, 'pool', {0x14: L('free', 1, ret=r32(c))})
    e = rbuf(c, 0x20)
    c.emu.w32(e + 8, pool)
    set_eng9b(c, e)
    return [rbuf(c, 0x40), c.rng.choice([0, 1, 4, 5, r32(c)])]
S(0x45c5f0, 'ZGEOM::~ZGEOM (deleting)', 'thiscall', None, ret='eax', gen=g_45c5f0)


def g_4c96f0(c):
    ld = obj(c, 'ld', {k: L('ld%x' % k, 1, ret=r32(c)) for k in (0x44, 0x58, 0x68, 0x6c)})
    return [rbuf(c, 0x100), ld]
S(0x4c96f0, 'ZSpin::Load', 'thiscall', None, ret='al', gen=g_4c96f0)


def g_5538f0(c):
    els = [rbuf(c, 8), rbuf(c, 8)]
    k = [0]
    def h3d0(e, r):
        e.calllog.append(('5003d0', e.reg('ecx'), (e.arg32(0),)))
        k[0] += 1
        e.ret(eax=els[k[0] & 1], argbytes=4)
    patch(c, 0x5003d0, h3d0)
    patch(c, 0x5002f0, L('5002f0', 1, ret=r32(c)))
    patch(c, 0x596cf0, L('CharismaGetRecruitable', 0, ret=r32(c)))
    idv = r32(c)
    def h88(e, r):
        e.calllog.append(('o88', e.reg('ecx'), (e.arg32(0), e.r32(e.arg32(1)))))
        if c.rng.random() < 0.8:
            e.w32(e.arg32(1), idv)
        e.ret(eax=r32(c), argbytes=8)
    o = obj(c, 'o', {0x88: h88})
    g = rbuf(c, 0x900)
    if c.rng.random() < 0.3:
        c.emu.w32(g + 0x852, 0)
    set_eng9b(c, obj(c, 'eng9b', {0x138: L('e138', 0, ret=o), 0x58: L('e58', 1, ret=c.rng.choice([0, g, g]))}))
    p = rbuf(c, 0x20)
    return [p]
S(0x5538f0, 'GUESS native: recruitable count', 'stdcall', None, ret='eax', gen=g_5538f0)


def g_4b6d70(c):
    patch(c, 0x41e290, L('new', 1, pop=0, ret=c.rng.choice([0, rbuf(c, 0x28)]), ecx=False))
    patch(c, 0x4cca60, L('LINKREFTAB', 2, ret=r32(c)))
    c.emu.w32(0x7003b0, c.emu.stub_fn('cb', L('cb7003b0', 0, ret=r32(c), ecx=False)))
    c.emu.w32(0x700334, c.rng.choice([0, r32(c)]))
    return [rbuf(c, 0x60), c.rng.choice([0, 0, r32(c)])]
S(0x4b6d70, 'CCutSequenceList::RegisterInstance', 'thiscall', None, ret=None, gen=g_4b6d70)


def g_509430(c):
    c.emu.w32(0x701048, c.rng.choice([0, 0, r32(c)]))
    def h9b0(e, r):
        p = e.reg('ecx')
        e.calllog.append(('reserve', e.rbytes(p, 13).hex(), (e.arg32(0),)))
        e.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(12)))
        e.ret(eax=r32(c), argbytes=4)
    def h1c(e, r):
        p = e.arg32(0)
        e.calllog.append(('vt1c', e.reg('ecx'), (e.rbytes(p, 13).hex(),)))
        e.ret(eax=r32(c), argbytes=4)
    def h9d0(e, r):
        p = e.reg('ecx')
        e.calllog.append(('dtor', e.rbytes(p, 13).hex(), ()))
        e.ret(eax=r32(c))
    patch(c, 0x59a9b0, h9b0)
    patch(c, 0x4ff9d0, h9d0)
    return [obj(c, 'self', {0x1c: h1c})]
S(0x509430, 'GUESS one-time registration (0x701048)', 'thiscall', None, ret=None, gen=g_509430)


def g_5fb370(c):
    patch(c, 0x54f870, L('free', 2, ret=r32(c)))
    def tree(d):
        if d == 0 or c.rng.random() < 0.35:
            return 0
        first = 0
        prev = None
        for _ in range(c.rng.randint(1, 3)):
            n = rbuf(c, 0x20)
            c.emu.w32(n + 9, tree(d - 1))
            c.emu.w32(n + 5, 0)
            if c.rng.random() < 0.3:
                c.emu.w32(n + 0xd, 0)
            if c.rng.random() < 0.2:
                c.emu.w32(n + 0x15, c.emu.r32(n + 0xd))
            if prev:
                c.emu.w32(prev + 5, n)
            else:
                first = n
            prev = n
        return first
    return [rbuf(c, 0x10), tree(3)]
S(0x5fb370, 'GUESS free a tree (0x54f870)', 'thiscall', None, ret=None, gen=g_5fb370)


def g_57dfb0(c):
    patch(c, 0x4db500, L('GetPos', 1, ret=r32(c)))
    g = rbuf(c, 0x20)
    set_eng9b(c, obj(c, 'eng9b', {0x58: L('e58', 1, ret=g)}))
    o = rbuf(c, 0x400)
    c.emu.w32(o + 0x264, c.emu.fake_vtable('lst', 12, {0x2c: L('has', 1, ret=c.rng.choice([0, 0x100, r32(c)]))}))
    return [o, r32(c), r32(c)]
S(0x57dfb0, 'GUESS select target (+0x340/+0x344)', 'thiscall', None, ret='eax', gen=g_57dfb0, stack_arg_bytes=12)
