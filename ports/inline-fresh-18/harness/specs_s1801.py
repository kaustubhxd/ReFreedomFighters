"""specs_s1801.py - fresh-18 batch 1 (src/batch1801.cpp). Every callee is a logging stub (h18.py): the call order,
ecx and all stack arguments are compared; objects are random bytes; returns are random where they feed later code."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)


def g54dce0(c):
    c.emu.w8(0x713e19, c.rng.randint(1, 255))   # nonzero first, so the clear is observed
    return [h.obj(c, {0x18: h.L(c, 'vt18', 0)})]
S(0x54dce0, 'GUESS clear 0x713e19,+4 then vt18', 'thiscall', None, gen=g54dce0)


def g601a60(c):
    o = h.obj(c, {0x118: h.L(c, 'vt118', 1, ret=R(c))})
    h.engine(c, 0x9b, o)
    return [R(c), R(c)]
S(0x601a60, 'CHostInterface::getNameForHostEvent', 'thiscall', None, ret='eax', gen=g601a60)


def g4cbe20(c):
    self = h.rnd(c, 0x40)
    c.emu.w32(self + 0x1f, h.L(c, 'factory', 2, ret=R(c), regs=('ecx', 'edx')))
    return [self, R(c), R(c), R(c)]
S(0x4cbe20, 'ZGEOMCLASSINFO::AllocOne', 'thiscall', None, ret='eax', gen=g4cbe20)


def g549820(c):
    o = h.obj(c, {0x9c: h.L(c, 'vt9c', 0)}, size=0xa280)
    c.emu.w8(o + 0xa26d, c.rng.choice([0, 0, 1, 0x80]))
    h.hk(c, 0x54cec0, 'f54cec0', 0)
    return [o]
S(0x549820, 'GUESS 0x54cec0 then vt9c if +0xa26d', 'thiscall', None, gen=g549820)


def g54c2a0(c):
    o = h.rnd(c, 0x60)
    c.emu.w32(o + 0x50, 0 if c.rng.random() < 0.3 else h.obj(c, {0x20: h.L(c, 'vt20', 1)}))
    h.hk(c, 0x650dc0, 'SetActiveAxis', 1)
    return [o, R(c)]
S(0x54c2a0, 'GUESS SetActiveAxis then +0x50 vt20', 'thiscall', None, gen=g54c2a0)


def g656f60(c):
    blk = h.rnd(c, 0x100)
    o = h.obj(c, {0xc: h.L(c, 'vtc', 1, ret=[blk, R(c)])})
    return [o, R(c)]
S(0x656f60, 'ZPrimControlGC::GetConvBones', 'thiscall', None, ret='eax', gen=g656f60)


def g57c360(c):
    o = h.obj(c, {0xf8: h.L(c, 'vtf8', 0)})
    h.hk(c, 0x563110, 'CBaseWindow::OnWindowOpen', 2, ret=R(c))
    return [o, R(c), R(c)]
S(0x57c360, 'ZFFAutoSave::OnWindowOpen', 'thiscall', None, ret='al', gen=g57c360)


def _dtor(base, size):
    def g(c):
        o = h.rnd(c, 0x40)
        h.hk(c, base, 'base_dtor', 0, ret=R(c))
        h.hk(c, 0x634273, 'delete', 2, pops=0, ret=R(c))
        return [o, R(c)]
    return g
S(0x42bf60, 'ZSysInterface scalar deleting dtor', 'thiscall', None, ret='eax', gen=_dtor(0x42bae0, 0x1b71))
S(0x6580e0, 'ZRenderGC scalar deleting dtor', 'thiscall', None, ret='eax', gen=_dtor(0x658020, 0x11e7))


def g656e20(c):
    o = h.rnd(c, 0x40)
    h.hk(c, 0x655a70, 'base', 0, ret=R(c), wr=lambda e, rv, a: e.calllog.append(('vt_at_call', e.r32(rv[0]))))
    h.hk(c, 0x634273, 'delete', 2, pops=0)
    return [o, R(c)]
S(0x656e20, 'ZPrimControlGC scalar deleting dtor', 'thiscall', None, ret='eax', gen=g656e20)


def g4e0e60(c):
    o = h.obj(c, {0x144: h.L(c, 'vt144', 2, ret=R(c))})
    c.emu.w32(0x70039c, o)
    return [R(c), R(c), R(c)]
S(0x4e0e60, 'DBLK::ConvertFileName', 'thiscall', None, ret='eax', gen=g4e0e60)


def g42c0a0(c):
    inner = h.obj(c, {0x20: h.L(c, 'inner20', 1, ret=R(c))})
    first = c.rng.choice([0, inner, inner])
    o = h.obj(c, {0x1b0: h.L(c, 'vt1b0', 0, ret=[first, inner])})
    return [o, R(c)]
S(0x42c0a0, 'ZSysInterface::Vsprintf', 'thiscall', None, ret='eax', gen=g42c0a0)


def _ctor(base):
    def g(c):
        o = h.rnd(c, 0x200)
        h.hk(c, base, 'base_ctor', 0, ret=R(c))
        return [o]
    return g
S(0x57baa0, 'GUESS ctor vt 0x6aa368', 'thiscall', None, ret='eax', gen=_ctor(0x564460))
S(0x4bb160, 'GUESS ctor vt 0x692c38', 'thiscall', None, ret='eax', gen=_ctor(0x469870))


def _chain(c, nxt_off, circular):
    k = c.rng.randint(0, 5)
    nodes = [h.rnd(c, 0x20) for _ in range(k)]
    for i, n in enumerate(nodes):
        c.emu.w32(n + nxt_off, nodes[i + 1] if i + 1 < k else (nodes[0] if circular and c.rng.random() < 0.5 else 0))
    return nodes[0] if nodes else 0


def g63cde0(c):
    o = h.obj(c, {0x34: h.L(c, 'remove', 1)}, size=0x20)
    c.emu.w32(o + 8, _chain(c, 8, True))
    return [o]
S(0x63cde0, 'ZDrawArray::Clear', 'thiscall', None, gen=g63cde0)


def g4cdc20(c):
    o = h.obj(c, {0x10: h.L(c, 'vt10', 0), 0x7c: h.L(c, 'vt7c', 1)}, size=0x20)
    c.emu.w32(o + 4, _chain(c, 4, False))
    return [o]
S(0x4cdc20, 'STRREFTAB::Clear', 'thiscall', None, gen=g4cdc20)


def g657820(c):
    p = h.rnd(c, 0x60)
    if c.rng.random() < 0.5:
        c.emu.w16(p + 2, 0)
    o = h.obj(c, {0xc: h.L(c, 'vtc', 1, ret=p)})
    return [o, R(c), h.rnd(c, 8), h.rnd(c, 8), h.rnd(c, 8)]
S(0x657820, 'ZPrimControlGC::GetPrimVertAnim', 'thiscall', None, ret='al', gen=g657820)


def g4dfe20(c):
    return [c.fbuf(2), c.fbuf(4)]
S(0x4dfe20, 'GUESS 2x2 transform in place', 'fastcall', None, gen=g4dfe20, nan_heap=True)


def g6567e0(c):
    pool = [h.rnd(c, 0x10) for _ in range(6)]
    ids = [0, 0x1111] + [c.rng.getrandbits(32) | 1 for _ in range(4)]
    for p in pool:
        c.emu.w32(p + 8, c.rng.choice(ids))
    def ret(e, rv, a):
        return pool[a[0] % 6]
    o = h.obj(c, {0xc: h.L(c, 'vtc', 1, ret=ret)})
    n = c.rng.choice([0, 1, 2, 3, 5, 8, 40])
    return [o, c.rng.choice(ids), n]
S(0x6567e0, 'ZPrimControlBase::GetSubPrim', 'thiscall', None, ret='eax', gen=g6567e0)


def g4c3220(c):
    nv = R(c)
    def wr(e, rv, a):
        if nv & 1:
            e.w32(a[0], nv)
    lg = h.obj(c, {0x40: h.L(c, 'lg40', 1, wr=wr)})
    eng = h.obj(c, {0x58: h.L(c, 'eng58', 1, ret=R(c))})
    h.engine(c, 0x9b, eng)
    o = h.rnd(c, 0x60)
    return [o, lg]
S(0x4c3220, 'ZWindElement::Load', 'thiscall', None, ret='al', gen=g4c3220)
