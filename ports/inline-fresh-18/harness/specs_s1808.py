"""specs_s1808.py - fresh-18 batch 8 (src/batch1808.cpp). 0x7003b0 is a logging stub where the code can assert."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)
FC = ('ecx', 'edx')


def assert_stub(c):
    c.emu.w32(0x7003b0, h.L(c, 'assert', 0, regs=()))


def wdtor(pre):
    def g(c):
        assert_stub(c)
        if pre:
            h.hk(c, pre, 'member_dtor', 0)
        h.hk(c, 0x4690b0, 'SetState', 2, pops=0, regs=())
        h.engine(c, 0x9b, h.obj(c, {0x34: h.L(c, 'e34', 1)}))
        return [h.rnd(c, 0x190), c.rng.choice([0, 1, 4, 5, 7, R(c)])]
    return g
S(0x4f69e0, 'CAutoLayout::~CAutoLayout', 'thiscall', None, ret='eax', gen=wdtor(0x4ccf60))
S(0x5658e0, 'CBootMenu::~CBootMenu', 'thiscall', None, ret='eax', gen=wdtor(None))


def g506160(c):
    buf = h.rnd(c, 0x20)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=c.rng.choice([0, buf, buf]))
    h.hk(c, 0x500900, 'base', 2)
    h.hk(c, 0x505d50, 'f505d50', 0)
    c.emu.w32(0x700f7c, c.rng.choice([0, 1]))
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=R(c))}))
    a = h.rnd(c, 0x20)
    c.emu.w32(a + 0x15, h.obj(c, {0x40: h.L(c, 'a40', 1, wr=lambda e, rv, x: e.w32(x[0], R(c)))}))
    return [a, R(c)]
S(0x506160, 'GUESS factory (fastcall, vtable 0x69cc88)', 'fastcall', None, ret='eax', gen=g506160)


def g64f760(c):
    c.emu.w32(0x70038c, h.obj(c, {0x48: h.L(c, 'm48', 1, ret=R(c))}))
    h.hk(c, 0x64f6a0, 'AddCameraToView', 1)
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=lambda e, rv, a: c.rng.choice([0, R(c)]))}))
    cnt = c.rng.randint(0, 4)
    def start(e, rv, a):
        e.w32(a[0], cnt); e.w32(a[0] + 4, 0x1234); e.w32(a[0] + 8, R(c))
    def step(e, rv, a):
        e.w32(a[0], max(e.r32(a[0]) - 1, 0))
    t = h.obj(c, {0x4c: h.L(c, 'start', 1, wr=start), 0x5c: h.L(c, 'step', 1, wr=step, ret=lambda e, rv, a: R(c))})
    dev = h.obj(c, {8: h.L(c, 'dev8', 0)})
    c.emu.w8(dev + 5, c.rng.choice([0, 0, 1]))
    s = h.obj(c, {0x3c: h.L(c, 's3c', 0), 0xa4: h.L(c, 'sa4', 1, ret=c.rng.choice([0, 0, 1]))}, size=0xc8)
    c.emu.w32(s + 0xbd, dev)
    c.emu.w32(s + 0x8c, c.rng.choice([0, t, t]))
    return [s]
S(0x64f760, 'ZRender::AllocateDrawBuffers', 'thiscall', None, gen=g64f760, stack_arg_bytes=12)


def g51f3e0(c):
    h.hk(c, 0x517050, 'base', 3)
    h.hk(c, 0x5273b0, 'f5273b0', 0)
    h.hk(c, 0x511c60, 'f511c60', 0)
    s = h.rnd(c, 0x1700)
    vt = c.emu.fake_vtable('m', 1, {0: h.L(c, 'm0', 3)})
    c.emu.w32(s + 0x1684, vt)
    return [s, R(c), R(c), R(c)]
S(0x51f3e0, 'GUESS constructor (vtable 0x69fb3c)', 'thiscall', None, ret='eax', gen=g51f3e0)


def g631620(c):
    p = h.rnd(c, 0x490)
    mode = c.rng.random()
    if mode < 0.5:   # small words so both sides of the compare are close
        for o in range(0x8c, 0x490, 2):
            c.emu.w16(p + o, c.rng.randint(0, 40))
        c.emu.w16(p + 0x288, c.rng.randint(0, 20000))
        if c.rng.random() < 0.6:   # put t>>2 on or next to the left sum (the <= boundary)
            w = lambda o: c.emu.r32(p + o) & 0xffff
            a = sum(w(o) for o in range(0x8c, 0xa8, 4)) + sum(w(0x28c + 4 * i) for i in range(128))
            sm = sum(w(0xa8 + 4 * i) for i in range(120))
            v = 4 * a - sm + c.rng.choice([-4, -1, 0, 0, 3, 4])
            if 0 <= v <= 0xffff:
                c.emu.w16(p + 0x288, v)
    return [p]
S(0x631620, 'GUESS word sums compare', 'cdecl', None, gen=g631620)


def fwd_or_build(fwd, size, ctor, extra=None):
    def g(c):
        h.hk(c, fwd, 'fwd', 2, regs=FC, ret=R(c))
        buf = h.rnd(c, size + 8)
        h.hk(c, 0x45c4b0, 'alloc', 1, pops=0, regs=(), ret=c.rng.choice([0, buf, buf]))
        h.hk(c, ctor, 'ctor', 3, ret=R(c))
        if extra:
            extra(c)
        return [R(c), R(c), R(c), c.rng.choice([0, R(c)])]
    return g


def bad(c):
    db = h.rnd(c, 0xc00)
    c.emu.w8(db + 0xbad, c.rng.choice([0, 1]))
    h.engine(c, 0x9b, db)
S(0x448160, 'GUESS forward or build (fastcall)', 'fastcall', None, ret='eax', gen=fwd_or_build(0x4471f0, 0x1c, 0x45c3a0, bad))
S(0x47fde0, 'GUESS forward or build (fastcall)', 'fastcall', None, ret='eax', gen=fwd_or_build(0x47fc30, 0x90, 0x43de40))


def g4f7f20(c):
    h.hk(c, 0x4fa230, 'ZCONTROL::Load', 1, ret=c.rng.choice([0, 1, 1, 0x100, R(c)]))
    lg = h.obj(c, {k: h.L(c, 'l%x' % k, 1) for k in (0x40, 0x48, 0x50, 0x70)})
    return [h.rnd(c, 0xe0), lg]
S(0x4f7f20, 'ZSlider::Load', 'thiscall', None, ret='al', gen=g4f7f20)


def g5ddde0(c):
    cmd = R(c) & 0xffff
    c.emu.w16(0x71439c, cmd)
    h.hk(c, 0x5de090, 'AddFogImpact', 1)
    ld = h.rnd(c, 0x2c60)
    c.emu.w32(ld + 0x2c4d, c.rng.choice([0, R(c), R(c)]))
    c.emu.w32(0x7003b8, ld)
    h.engine(c, 0x40, R(c))
    s = h.rnd(c, 0x60)
    c.emu.w32(s + 0x44, h.obj(c, {0x84: h.L(c, 'o84', 1, wr=lambda e, rv, a: e.w32(a[0] + 4, R(c)))}))
    return [s, c.rng.choice([cmd, cmd | (R(c) & 0xffff0000), R(c)]), R(c)]
S(0x5ddde0, 'ZImpactFog::Command', 'thiscall', None, ret='eax', gen=g5ddde0, stack_arg_bytes=0x28)


def g493f20(c):
    tag = R(c)
    def wrtag(e, rv, a):
        e.w32(a[0] - 4, tag)
    blk = h.rnd(c, 0x20) + 8
    c.emu.w32(blk - 4, c.rng.choice([0, R(c)]))
    fn = h.L(c, 'rangefn', 0, ret=R(c))
    m = h.obj(c, {0x20: h.L(c, 'm20', 1, ret=c.rng.choice([0, 0, 1])), 0xac: h.L(c, 'mac', 1, wr=wrtag)})
    c.emu.w32(m + 8, c.rng.choice([0, fn]))
    lo = blk - c.rng.choice([0, 4, 0x100])
    c.emu.w32(m + 0xc, c.rng.choice([lo, blk, blk + 1]))
    c.emu.w32(m + 0x10, c.rng.choice([blk, blk + 1, blk + 0x100]))
    c.emu.w32(0x70038c, m)
    s = h.rnd(c, 0xd0)
    c.emu.w32(s + 0xc8, h.obj(c, {4: h.L(c, 'c8_4', 1)}))
    ent = h.rnd(c, 8)
    vt = c.emu.fake_vtable('cc', 2, {4: h.L(c, 'cc4', 1, ret=c.rng.choice([0, ent]))})
    c.emu.w32(s + 0xcc, vt)
    for i in range(7):
        c.emu.w32(s + 0x48 + 4 * i, h.obj(c, {0x3c: h.L(c, 'lst%d' % i, 1)}))
    return [s, c.rng.choice([0, blk, blk, blk]), c.rng.choice([0, 0x10, 8, 0x40, 0x58, 0xff, R(c)])]
S(0x493f20, 'GUESS owner tag dispatch', 'thiscall', None, gen=g493f20)


def g61cd60(c):
    n = c.rng.choice([0, 0, 1, 3, 8])
    cap = c.rng.choice([n, n, n + 2])
    arr = h.rnd(c, 12 * max(cap, 1) + 12)
    items = [h.rnd(c, 0x10) for _ in range(n)]
    for i, it in enumerate(items):
        c.emu.w32(arr + 12 * i, it)
    newarr = h.rnd(c, 12 * 2 * max(cap, 8) + 12)
    al = h.rnd(c, 0x20)
    c.emu.w32(al + 0xc, h.L(c, 'alloc', 1, regs=(), pops=0, ret=c.rng.choice([0, newarr, newarr])))
    def cp(e, rv, a):
        if a[1] and newarr:
            e.wbytes(newarr, e.rbytes(a[0], min(a[1], 12 * n)))
    c.emu.w32(al + 0x10, h.L(c, 'realloc', 2, regs=(), pops=0, wr=cp, ret=c.rng.choice([0, newarr, newarr])))
    s = h.rnd(c, 0x18)
    c.emu.w32(s + 8, c.rng.choice([0, R(c)]))
    c.emu.w32(s + 0xc, n)
    c.emu.w32(s + 0x10, cap)
    c.emu.w32(s + 0x14, arr)
    e = c.rng.choice(items + [h.rnd(c, 0x10)] * 2) if items else h.rnd(c, 0x10)
    c.emu.w8(e + 9, c.rng.choice([0, 1]))
    return [s, e, c.rng.choice([0, 1, 0x100]), c.rng.choice([0, 1]), c.rng.choice([0, R(c)]), al]
S(0x61cd60, 'GUESS item table add', 'cdecl', None, ret='eax', gen=g61cd60)
