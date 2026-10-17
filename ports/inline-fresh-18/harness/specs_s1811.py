"""specs_s1811.py - fresh-18 batch 11 (src/batch1811.cpp)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)


def cstr(c, n=None, hi=False):
    n = c.rng.randint(0, 20) if n is None else n
    a = h.rnd(c, n + 8)
    lo, top = (1, 255) if hi else (0x20, 0x7e)
    c.emu.wbytes(a, bytes(c.rng.randint(lo, top) for _ in range(n)) + b'\0')
    return a


def g600f20(c):
    n = h.rnd(c, 0x20)
    q = h.rnd(c, 0x10)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=lambda e, rv, a: n if a[0] == 0x18 else c.rng.choice([0, q, q]))
    h.hk(c, 0x6014a0, 'alloc', 1, ret=h.rnd(c, 0x10))
    h.hk(c, 0x5f2d60, 'assign', 2, ret=R(c))
    h.hk(c, 0x42b390, 'string', 2, ret=R(c))
    return [h.rnd(c, 8), cstr(c), R(c), R(c)]
S(0x600f20, 'GUESS record ctor (name, b, c)', 'thiscall', None, ret='eax', gen=g600f20, stack_arg_bytes=1)


def g565f20(c):
    s = h.rnd(c, 0xa20)
    vals = c.rng.sample(range(0x10000), 5)
    for o, v in zip((0x184, 0x186, 0x188, 0x18a, 0x196), vals):
        c.emu.w16(s + o, v)
    for o in (0xa0a, 0xa0b, 0xa0d):
        c.emu.w8(s + o, c.rng.choice([0, 0, 1, R(c) & 0xff]))
    c.emu.w32(s + 0xa17, R(c))
    db = h.rnd(c, 0xaf0)
    c.emu.w32(db + 0xae4, h.obj(c, {0: h.L(c, 'text', 2, ret=R(c))}))
    h.engine(c, 0x9b, db)
    for a, nm, k in ((0x59a5b0, 'MessageDialog', 3), (0x566820, 'MusicLow', 0), (0x566a10, 'StopBriefing', 0)):
        h.hk(c, a, nm, k)
    h.hk(c, 0x4f1520, 'GroupCommand', 2, ret=R(c))
    cmd = c.rng.choice(vals + [c.rng.randint(0, 0xffff)])
    return [s, cmd | (c.rng.choice([0, R(c)]) & 0xffff0000), h.rnd(c, 0x10)]
S(0x565f20, 'CBriefing::Command', 'thiscall', None, ret='eax', gen=g565f20)


def g411169(c):
    return [h.rnd(c, 0x48), c.fbuf(3), c.fbuf(3), c.fbuf(3)]
S(0x411169, 'GUESS look-at matrix', 'stdcall', None, gen=g411169, nan_heap=True)


def g61bd20(c):
    s = h.rnd(c, 0x120)
    if c.rng.random() < 0.15:
        base, cap, back, off = 0, 0, 0, 0
    else:
        cap = c.rng.choice([0x10, 0x100, 0x400, 0x800, c.rng.randint(1, 0x2000)])
        base = h.rnd(c, cap + 0x10)
        back = c.rng.choice([0, cap, c.rng.randint(0, cap)])
        off = c.rng.randint(0, cap - back)
    c.emu.w32(s + 8, base); c.emu.w32(s + 0x18, base + back); c.emu.w32(s + 0x1c, base + back + off)
    c.emu.w32(s + 0x20, base + cap)
    def mm(e, rv, a):
        if a[2]:
            e.wbytes(a[0], e.rbytes(a[1], a[2]))
    c.emu.w32(0x676278, h.L(c, 'memmove', 3, pops=0, regs=(), wr=mm, ret=lambda e, rv, a: a[0]))
    def cp(e, rv, a):
        if a[2]:
            e.wbytes(a[0], e.rbytes(a[1], a[2]))
    h.hk(c, 0x634d22, 'memcpy', 3, pops=0, regs=(), wr=cp, ret=lambda e, rv, a: a[0])
    fail = c.rng.random() < 0.15
    c.emu.w32(s + 0xc, h.L(c, 'allocCb', 1, pops=0, regs=(), ret=lambda e, rv, a: 0 if fail else h.rnd(c, a[0] + 8)))
    c.emu.w32(s + 0x14, h.L(c, 'freeCb', 1, pops=0, regs=()))
    free = cap - back - off
    n = c.rng.choice([0, free, free + 1, c.rng.randint(0, cap + 1), c.rng.randint(0, 3 * cap + 0x900),
                      c.rng.randint(1, 0x10000), -c.rng.randint(0, 100), -1])
    if n == -1:  # grow boundary: need exactly a doubled size
        sz0 = (cap - back) or 0x400
        n = sz0 * (1 << c.rng.randint(1, 3)) - off - min(back, 0x400)
    return [s, n & 0xffffffff]
S(0x61bd20, 'GUESS buffer make-room', 'cdecl', None, ret='eax', gen=g61bd20)


def g5fb660(c):
    hd = h.rnd(c, 0x20)
    k = c.rng.choice([0, 1, 2, 3, 5, 8])
    nodes = [h.rnd(c, 0x20) for _ in range(k)]
    def build(lo, hi, parent):
        if lo >= hi:
            return 0
        m = c.rng.randint(lo, hi - 1)
        nd = nodes[m]
        c.emu.w32(nd + 1, parent)
        c.emu.w32(nd + 5, build(lo, m, nd))
        c.emu.w32(nd + 9, build(m + 1, hi, nd))
        return nd
    root = build(0, k, hd)
    c.emu.w32(hd + 1, root)
    c.emu.w32(hd + 5, nodes[0] if k else hd)
    c.emu.w32(hd + 9, nodes[-1] if k else hd)
    for nd in nodes:
        o = 0
        if c.rng.random() < 0.8:
            o = h.rnd(c, 0x190)
            b = c.rng.choice([0, R(c)])
            c.emu.w32(o + 0x172, b)
            c.emu.w32(o + 0x17a, (b + c.rng.choice([0, 0, 0x10, R(c)])) & 0xffffffff)
        c.emu.w32(nd + 0x19, o)
    for a, nm, n in ((0x54f870, 'dealloc', 2), (0x5fdb70, 'm3c', 0), (0x5fae50, 'dtor', 0), (0x5fb370, 'erase', 1)):
        h.hk(c, a, nm, n)
    h.hk(c, 0x634273, 'delete', 2, pops=0, regs=())
    s = h.rnd(c, 0x10)
    c.emu.w32(s + 1, hd)
    c.emu.w32(s + 5, c.rng.choice([k, k, 0, R(c)]))
    return [s]
S(0x5fb660, 'GUESS map clear', 'thiscall', None, gen=g5fb660)


def g4f8e20(c):
    pa = h.obj(c, {0x2f4: h.L(c, 'p2f4', 2)})
    s = h.obj(c, {0x2c4: h.L(c, 's2c4', 0, ret=pa), 0x358: h.L(c, 's358', 1), 0x360: h.L(c, 's360', 1)}, size=0x200)
    f = h.obj(c, {0x14: h.L(c, 'focus14', 0, ret=c.rng.choice([0, 1, 1, 1, R(c)]))})
    c.emu.w32(s + 0x10f, c.emu.r32(f))
    if c.rng.random() < 0.2:  # only UTF-8 continuation bytes, one more just before the text
        n = c.rng.randint(1, 4)
        a = h.rnd(c, n + 8)
        c.emu.wbytes(a, bytes(c.rng.randint(0x80, 0xbf) for _ in range(n + 1)) + b'\0')
        c.emu.w32(s + 0x8f, a + 1)
    else:
        c.emu.w32(s + 0x8f, cstr(c, c.rng.choice([0, 1, 2, 5, 8]), hi=c.rng.random() < 0.6))
    key = c.rng.choice([8, 8, 8, 9, 13, 27, 37, 38, 39, 40, c.rng.randint(0, 60), R(c)])
    return [s, key]
S(0x4f8e20, 'ZEditControl::KeyPress', 'thiscall', None, ret='al', gen=g4f8e20)


def g4b2060(c):
    g = h.obj(c, {0x40: h.L(c, 'g40', 1), 0x14: h.L(c, 'g14', 0, ret=c.rng.choice([0, 1, R(c)])), 0: h.L(c, 'gdel', 1)})
    c.emu.w32(0x700334, c.rng.choice([0, g, g]))
    db = h.obj(c, {0x4c: h.L(c, 'db4c', 1, ret=R(c)), 0x34: h.L(c, 'db34', 1)}, size=0x60)
    eng = h.rnd(c, 0x1920)
    c.emu.w32(eng + 0x9b, db)
    t = h.rnd(c, 0x110)
    c.emu.w32(t + 0xfd, c.rng.choice([0, 1, R(c)]))
    c.emu.w32(eng + 0x190f, t)
    c.emu.w32(0x70039c, eng)
    h.hk(c, 0x4ccfe0, '~REFTAB', 0)
    h.hk(c, 0x4ccee0, 'mAA', 0)
    s = h.rnd(c, 0x120)
    for o in (0x98, 0x9e):
        c.emu.w8(s + o, c.rng.choice([0, 1, 1, R(c) & 0xff]))
    return [s]
S(0x4b2060, 'GUESS window dtor (vt 0x691cfc)', 'thiscall', None, gen=g4b2060)
