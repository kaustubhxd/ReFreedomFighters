"""specs_f1103.py - fresh-11 batch 3: slice-11 functions of 93 to 106 bytes."""
import os, sys, struct
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S
from h11 import L, obj, rbuf, fbuf, patch, iat


def r32(c): return c.rng.getrandbits(32)


def eng9b(c, slots, size=0x100):
    o = obj(c, 'eng9b', slots, size=size)
    eng = rbuf(c, 0x200)
    c.emu.w32(eng + 0x9b, o)
    c.emu.w32(0x70039c, eng)
    return o


def g_45b970(c):
    o = obj(c, 'o138', {0x60: L('o60', 3, ret=r32(c))})
    eng9b(c, {0x138: L('e138', 0, ret=o), 0x4c: L('e4c', 1, ret=r32(c))})
    patch(c, 0x43e0f0, L('ZSTDOBJ::ClassInit', 0, ret=r32(c)))
    s = obj(c, 'self', {0x110: L('vt110', 2, ret=r32(c)), 0x214: L('vt214', 0, ret=r32(c))})
    return [s]
S(0x45b970, 'ZBloodStains::ClassInit', 'thiscall', None, ret='eax', gen=g_45b970)


def g_53b7f0(c):
    dst, src = rbuf(c, 0xa0), rbuf(c, 0xa0)
    c.emu.w32(src + 0x25, c.rng.choice([0, 1, 2, 3, 5, 8, 0xffffffff, 0x80000000]))
    return [dst, src]
S(0x53b7f0, 'ZSoundGraph::CopyChain', 'stdcall', None, ret=None, gen=g_53b7f0)


def g_dtor(body, n=0x100):
    def g(c):
        patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
        patch(c, body, L('body_%x' % body, 0, ret=r32(c)))
        return [rbuf(c, n), r32(c)]
    return g
S(0x616b70, 'GUESS deleting dtor (0x6bdcf4, 0x659c00(+8), 0x14)', 'thiscall', None, ret='eax', gen=g_dtor(0x659c00))


def g_620670(c):
    fr = rbuf(c, 0x10)                     # allocator: +8 is a free function pointer (cdecl), not a vtable slot
    c.emu.w32(fr + 8, c.emu.stub_fn('free', L('free', 1, pop=0, ret=r32(c), ecx=False)))
    p = rbuf(c, 0x20)
    c.emu.w32(p + 0x14, fr)
    for k in (0, 4):
        n = c.rng.randint(0, 4)
        nodes = [rbuf(c, 0x10) for _ in range(n)]
        for i, nd in enumerate(nodes):
            c.emu.w32(nd, nodes[i + 1] if i + 1 < n else 0)
        c.emu.w32(p + k, nodes[0] if nodes else 0)
    return [p]
S(0x620670, 'GUESS clear two node lists', 'cdecl', None, ret=None, gen=g_620670)

S(0x636330, 'GUESS ctor (vt 0x6c2080, OLAP)', 'thiscall', None, ret='eax', gen=lambda c: [rbuf(c, 0x60)])


def g_factory(ctor):
    def g(c):
        p = rbuf(c, 0x40)
        pool = obj(c, 'pool', {0x44: L('alloc', 1, ret=c.rng.choice([0, p]))})
        e = rbuf(c, 0x20)
        c.emu.w32(e + 8, pool)
        eng = rbuf(c, 0x200)
        c.emu.w32(eng + 0x9b, e)
        c.emu.w32(0x70039c, eng)
        patch(c, ctor, L('ctor_%x' % ctor, 0, ret=r32(c)))
        return [r32(c)]
    return g
S(0x53d0f0, 'GUESS new CRigidBody (pool +0x44)', 'thiscall', None, ret='eax', gen=g_factory(0x53ccd0))
S(0x565eb0, 'GUESS new CBriefing (pool +0x44)', 'thiscall', None, ret='eax', gen=g_factory(0x565b90))


def g_424e70(c):
    patch(c, 0x634273, L('delete', 2, pop=0, ecx=False))
    patch(c, 0x42ace0, L('42ace0', 0, ret=r32(c)))
    iat(c, 0x6761d4, 'iat_6761d4', 4, ret=r32(c))
    iat(c, 0x6762ac, 'iat_6762ac', 0, ret=r32(c))
    o = rbuf(c, 0x40)
    if c.rng.random() < 0.3:
        c.emu.w32(o + 0x24, 0)
    return [o, r32(c)]
S(0x424e70, 'ZSysComGC::Free', 'thiscall', None, ret='eax', gen=g_424e70)


def g_5060f0(c):
    patch(c, 0x41e290, L('new', 1, pop=0, ret=c.rng.choice([0, rbuf(c, 0x18)]), ecx=False))
    patch(c, 0x5047c0, L('ZLinkIf::ZLinkIf', 1, ret=r32(c)))
    return [rbuf(c, 0x20)]
S(0x5060f0, 'GUESS new ZLinkIf', 'thiscall', None, ret='eax', gen=g_5060f0)


def g_565870(c):
    eng9b(c, {0x34: L('e34', 1, ret=r32(c))})
    return [rbuf(c, 0x200)]
S(0x565870, 'GUESS ctor tail (0x686874, eng9b +0x34)', 'thiscall', None, ret='eax', gen=g_565870)


def g_4f6ab0(c):
    patch(c, 0x4f97f0, L('base', 3, ret=r32(c)))
    return [rbuf(c, 0xc0), r32(c), r32(c), r32(c)]
S(0x4f6ab0, 'GUESS ctor (0x4f97f0, vt 0x69aaf0)', 'thiscall', None, ret='eax', gen=g_4f6ab0)


def g_64dcb0(c):
    o = fbuf(c, 0x10100)
    def ents(n):
        for i in range(n):
            e = rbuf(c, 0x80)
            inner = rbuf(c, 0x10)
            c.emu.w32(e + 0xc, inner)
            c.emu.w32(o + 0x1008d + 4 * i, e)
        c.emu.w32(o + 0x10089, n)
    ents(c.rng.randint(0, 3))
    def hc(e, r):
        e.calllog.append(('vtc', e.reg('ecx'), (e.arg32(0),)))
        cnt = e.r32(o + 0x10089)
        e.w32(o + 0x10089, cnt - 1)
        e.ret(eax=r32(c), argbytes=4)
    m = c.rng.randint(0, 4)
    def h64(e, r):
        e.calllog.append(('r64', e.reg('ecx'), ()))
        ents(m)
        e.ret(eax=r32(c))
    rr = obj(c, 'r', {0x60: L('r60', 0, ret=r32(c)), 0x64: h64})
    c.emu.w32(o + 0x1005d, rr)
    c.emu.w32(o, c.emu.fake_vtable('self', 4, {0xc: hc}))
    return [o]
S(0x64dcb0, 'GUESS reset (count +0x10089)', 'thiscall', None, ret=None, gen=g_64dcb0)
