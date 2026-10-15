"""specs_s1803.py - fresh-18 batch 3 (src/batch1803.cpp)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)


def assert_stub(c, ret=0):
    c.emu.w32(0x7003b0, h.L(c, 'assert', 0, regs=(), ret=ret))


def g6057a0(c):
    h.hk(c, 0x5fa590, 'OpaqueType_t::toSerial', 2)
    si = h.obj(c, {0x2c: h.L(c, 'si2c', 1)})
    buf = h.obj(c, {0: h.L(c, 'buf0', 1, ret=R(c))})
    return [h.rnd(c, 0x20), si, buf]
S(0x6057a0, 'OpaqueString_t::toSerial', 'thiscall', None, gen=g6057a0)


def g656420(c):
    o = h.obj(c, {0x18: h.L(c, 'o18', 2)})
    m = h.obj(c, {0x20: h.L(c, 'm20', 0, ret=o)})
    blk = h.rnd(c, 0x1920)
    c.emu.w32(blk + 0x190f, m)
    c.emu.w32(0x70039c, blk)
    return [R(c), R(c), c.rng.choice([0, 1, 7, 0x20000000, 0x40000000, R(c)])]
S(0x656420, 'GUESS engine +0x190f slot20 -> slot18(p, n*8)', 'thiscall', None, gen=g656420)


def g6566a0(c):
    assert_stub(c, R(c))
    b = h.rnd(c, 0x30)
    c.emu.w32(b + 0x20, c.rng.choice([0, R(c)]))
    blk = h.rnd(c, 0x1ab0)
    c.emu.w32(blk + 0x1aa3, b)
    c.emu.w32(0x70039c, blk)
    return [R(c), R(c)]
S(0x6566a0, 'GUESS a + engine(+0x1aa3)+0x20', 'thiscall', None, ret='eax', gen=g6566a0)


def g551020(c):
    assert_stub(c, R(c))
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', 3, regs=(), pops=0)})
    o = h.obj(c, {0x20: h.L(c, 'o20', 2, ret=lg)})
    c.emu.w32(0x700390, o)
    return [R(c), R(c), R(c)]
S(0x551020, 'FFNIFFactory_t::typeInfoFromSerial', 'thiscall', None, ret='eax', gen=g551020)


def g490fa0(c):
    v = R(c)
    def wr(e, rv, a):
        if v & 1:
            e.w32(a[1], v)
    o = h.obj(c, {0x88: h.L(c, 'o88', 2, wr=wr)})
    h.engine(c, 0x9b, h.obj(c, {0x134: h.L(c, 'e134', 0, ret=o)}))
    return []
S(0x490fa0, 'ZEngineDataBase::GetStartupParam', 'cdecl', None, ret='eax', gen=g490fa0)


def g608d60(c):
    c.emu.w8(0x724b34, c.rng.choice([0, 0, 0, 1]))
    c.emu.w32(0x724a00, R(c))
    h.hk(c, 0x658140, 'BeginScene', 0)
    dev = h.obj(c, {0x88: h.L(c, 'dev88', 1, regs=(), ret=c.rng.choice([0, 1, 0x80004005, R(c)]))})
    self = h.rnd(c, 0x1400)
    c.emu.w32(self + 0x1377, dev)
    return [self]
S(0x608d60, 'GUESS BeginScene wrapper', 'thiscall', None, ret='al', gen=g608d60)


def g6549e0(c):
    o = h.obj(c, {0xc: h.L(c, 'oc', 0, ret=c.rng.choice([0, 1, 0x100, R(c)])), 0x18: h.L(c, 'o18', 2)})
    eng = h.obj(c, {0x1b0: h.L(c, 'e1b0', 0, ret=c.rng.choice([0, o, o]))})
    c.emu.w32(0x70039c, eng)
    self = h.rnd(c, 0x90)
    c.emu.w8(self + 0x80, c.rng.choice([0, 0, 1]))
    return [self, R(c), R(c)]
S(0x6549e0, 'GUESS engine 1b0 forward', 'thiscall', None, gen=g6549e0)


def g4d70e0(c):
    e = h.rnd(c, 0x30)
    h.hk(c, 0x4d8fc0, 'GetLowerCase', 1, ret=c.rng.choice([0, e, e]))
    return [h.rnd(c, 0x20), R(c), h.rnd(c, 0x30), h.rnd(c, 8)]
S(0x4d70e0, 'CFastLookupFileCache_t::lookup', 'thiscall', None, ret='al', gen=g4d70e0)


def g4f45a0(c):
    n = c.rng.randint(0, 30)
    s = c.emu.alloc(n + 8, 1)
    c.emu.wbytes(s, bytes(c.rng.randint(1, 255) for _ in range(n)) + b'\0' * 8)
    def wr(e, rv, a):
        p = e.r32(a[0])
        e.w32(a[0], p + 1 + (e.r8(p) % 3 if p < s + n else 0))
    def ret(e, rv, a):
        return e.r8(e.r32(a[0]) - 1) * 3 + 1
    o = h.obj(c, {0x298: h.L(c, 'glyph', 1, wr=wr, ret=lambda e, rv, a: R(c) & 0xff)}, size=0x10)
    return [o, s, c.rng.choice([0, 1, 2, 5, 100, 0xffffffff])]
S(0x4f45a0, 'ZLINEOBJ::GetStringWidth', 'thiscall', None, ret='eax', gen=g4f45a0)


def g54e0a0(c):
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=c.rng.choice([0, R(c)]))
    return [h.rnd(c, 0x60)]
S(0x54e0a0, 'GUESS ctor vt 0x6a3ea8', 'thiscall', None, ret='eax', gen=g54e0a0)


def g54a5e0(c):
    c.emu.w32(0x676148, h.L(c, 'CreateEventA', 4, regs=(), ret=R(c)))
    h.hk(c, 0x54dc10, 'f54dc10', 0, ret=c.rng.choice([0, 1, 0x100, R(c)]))
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', 2, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'o20', 2, ret=lg)}))
    return [h.obj(c, {0x90: h.L(c, 'self90', 0, ret=c.rng.choice([0, 1, 0x100, R(c)]))})]
S(0x54a5e0, 'GUESS init CreateEventA + 0x54dc10 + slot 0x90', 'thiscall', None, ret='al', gen=g54a5e0)


def g6238e0(c):
    ns = c.rng.randint(0, 12)
    src = h.rnd(c, ns + 4)
    for i in range(ns):
        if c.rng.random() < 0.2:
            c.emu.w8(src + i, 0xd8 | c.rng.randint(0, 7))
    nd = 2 * c.rng.randint(0, 8)
    dst = h.rnd(c, nd + 8)
    ps = c.emu.alloc(4, 4); c.emu.w32(ps, src)
    pd = c.emu.alloc(4, 4); c.emu.w32(pd, dst)
    # source end must be reachable in 2-byte steps unless the destination fills first
    return [R(c), ps, src + ns, pd, dst + nd]
S(0x6238e0, 'GUESS UTF-16 copy step', 'cdecl', None, gen=g6238e0)


def g422e60(c):
    h.hk(c, 0x4cc5f0, 'MYSTR::Length', 0, ret=[c.rng.choice([0, 0, 3]), c.rng.choice([0, 5])])
    h.hk(c, 0x4235b0, 'f4235b0', 5, ret=R(c))
    h.hk(c, 0x422ba0, 'f422ba0', 5, ret=R(c))
    return [h.rnd(c, 0x2600)] + [R(c) for _ in range(5)]
S(0x422e60, 'GUESS name dispatch', 'thiscall', None, ret='eax', gen=g422e60)


def g4f5860(c):
    h.hk(c, 0x4f05d0, 'ZWINOBJ::Load', 1, ret=c.rng.choice([0, 1, 0x100, R(c)]))
    lg = h.obj(c, {0x48: h.L(c, 'lg48', 1), 0x18: h.L(c, 'lg18', 2)})
    self = h.obj(c, {0x244: h.L(c, 's244', 0), 0x27c: h.L(c, 's27c', 0)}, size=0x100)
    return [self, lg]
S(0x4f5860, 'ZFRAME::Load', 'thiscall', None, ret='al', gen=g4f5860)


def g493020(c):
    eng = h.obj(c, {0x2c: h.L(c, 'e2c', 0, ret=c.rng.choice([0, 0, 1, 0x100])),
                    0x54: h.L(c, 'e54', 1, ret=lambda e, rv, a: (a[0] * 7) & 0xffffffff)})
    h.engine(c, 0x9b, eng)
    h.hk(c, 0x4dc440, 'SetAutoRoomAssign', 1)
    n = c.rng.randint(0, 5)
    lst = h.rnd(c, 4 + 8 * n)
    c.emu.w32(lst, n)
    return [R(c), lst]
S(0x493020, 'GUESS auto room assign list', 'thiscall', None, gen=g493020)


def g53b860(c):
    k = c.rng.randint(0, 6)
    paths = h.rnd(c, 0x89 * max(k, 1) + 8)
    t = h.rnd(c, 0x89)
    ln = c.rng.choice([0, 1, 2, 3, 5, -1])
    c.emu.w32(t + 0x25, ln & 0xffffffff)
    ids = [c.rng.choice([1, 2, 3]) for _ in range(max(ln, 0))]
    for j, v in enumerate(ids):
        c.emu.w32(t + 5 + 4 * j, v)
    for i in range(k):
        p = paths + 0x89 * i
        c.emu.w32(p + 0x25, (ln if c.rng.random() < 0.7 else c.rng.choice([0, 1, 4])) & 0xffffffff)
        for j, v in enumerate(ids):
            c.emu.w32(p + 5 + 4 * j, v if c.rng.random() < 0.85 else 9)
    return [R(c), paths, c.rng.choice([k, k, 0, -1 & 0xffffffff]), t]
S(0x53b860, 'ZSoundGraph::FindChain', 'thiscall', None, ret='eax', gen=g53b860)


def g6486e0(c):
    pool = h.rnd(c, 32 * 18)
    c.emu.w16(pool + 2, c.rng.choice([0xffff, c.rng.randint(0, 16), c.rng.randint(0, 16)]))
    return [pool]
S(0x6486e0, 'GUESS free-list alloc', 'thiscall', None, ret='eax', gen=g6486e0)


def g5518e0(c):
    h.hk(c, 0x5003d0, 'f5003d0', 1, ret=lambda e, rv, a: (rv[0] + 0x100 * a[0]) & 0xffffffff)
    h.hk(c, 0x5002f0, 'f5002f0', 1)
    ev = h.obj(c, {0x4c: h.L(c, 'ev4c', 0, ret=R(c))})
    fac = h.obj(c, {0x18: h.L(c, 'fac18', 1, ret=c.rng.choice([0, ev, ev]))})
    return [R(c), fac, R(c), h.rnd(c, 0x10)]
S(0x5518e0, 'Signature_iii_EventTranslator_t::handleEventTranslation', 'thiscall', None, ret='eax', gen=g5518e0)
