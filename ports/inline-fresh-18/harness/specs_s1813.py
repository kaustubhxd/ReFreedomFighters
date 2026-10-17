"""specs_s1813.py - fresh-18 batch 13 (src/batch1813.cpp). Ld() stubs also log the bytes behind stack-pointer
arguments at call time (per-argument sizes, instead of one stack_arg_bytes for the whole spec)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)
FC = ('ecx', 'edx')


def Ld(c, name, nargs, dumps=None, ret=0, wr=None, regs=(), pops=None):
    st = {'i': 0}
    pops = 4 * nargs if pops is None else pops
    def hd(e, r):
        args = tuple(e.arg32(k) for k in range(nargs))
        extra = tuple(e.rbytes(args[k], n).hex() for k, n in sorted((dumps or {}).items()))
        e.calllog.append((name, tuple(e.reg(x) for x in regs), args, extra))
        if wr:
            wr(e, args)
        v = ret(e, args) if callable(ret) else ret
        e.ret(eax=v, argbytes=pops)
    return c.emu.stub_fn(name, hd)


def logger(c, nargs):
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', nargs, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'log20', 2, ret=lg)}))


def g606ce0(c):
    h.hk(c, 0x5fb600, 'mapclear', 0)
    h.hk(c, 0x54f870, 'dealloc', 2)
    s = h.rnd(c, 0x20)
    b = c.rng.choice([0, R(c) & ~3])
    c.emu.w32(s + 3, b)
    c.emu.w32(s + 11, (b + c.rng.choice([0, 4, 0x40, 3, R(c)])) & 0xffffffff)
    return [s]
S(0x606ce0, 'GUESS map holder dtor', 'thiscall', None, gen=g606ce0)


def g547520(c):
    logger(c, 7)
    sg = h.obj(c, {0x44: h.L(c, 'u32', 1), 0x68: h.L(c, 'vec3', 1), 0x4c: h.L(c, 'float', 1)})
    s = h.rnd(c, 0x40)
    for off, cnt_off, stride in ((0xf, 0x28, 0x34), (0x13, 0x2c, 0xc), (0x17, 0x30, 0xc)):
        n = c.rng.choice([0, 1, 2, 4, -1])
        c.emu.w32(s + cnt_off, n & 0xffffffff)
        c.emu.w32(s + off, h.rnd(c, max(n, 0) * stride + 8))
    return [s, sg]
S(0x547520, 'ConstrainedParticleSystem::Save', 'thiscall', None, ret='al', gen=g547520)


def g54c7a0(c):
    eff = h.obj(c, {0x30: Ld(c, 'effSet', 3, dumps={1: 0x40}, ret=R(c))})
    dev = h.obj(c, {0x40: Ld(c, 'devGain', 2, ret=c.rng.choice([0, 1, 0x80004005]))})
    s = h.obj(c, {0x7c: h.L(c, 'level', 1, ret=c.rng.choice([0, 5, 0xffffffff, 20000, (-20000) & 0xffffffff, 10000,
                                                              (-10000) & 0xffffffff, 10001, (-10001) & 0xffffffff, R(c)]))}, size=0x6400)
    c.emu.w32(s + 0x63f0, c.rng.choice([0, eff, eff]))
    c.emu.w32(s + 0x63ec, dev)
    h.hk(c, 0x54f2b0, 'dxerr', 0, regs=FC)
    ev = h.rnd(c, 0xc0)
    c.emu.w32(ev + 0x24, c.rng.choice([1, 1, 10, 10, 0, 2, R(c)]))
    for o in (0xb4, 0xb8):
        c.emu.wf32(ev + o, c.rng.choice([c.rng.uniform(0, 1e6), float(c.rng.randint(0, 5000)), 0.0]))
    c.emu.wf32(ev + 0xbc, c.rng.choice([c.rng.uniform(0, 1e6), -c.rng.uniform(0, 1e4), 3e9, 0.0]))
    return [s, ev]
S(0x54c7a0, 'GUESS force feedback event', 'thiscall', None, gen=g54c7a0)


def g4045a0(c):
    n = c.rng.choice([0, 1, 2, 3, 8, 20, 40])
    lp = c.rng.randint(1, 8)
    sg = lambda c: c.rng.choice([-9999.0, c.fv(-100, 100), c.rng.uniform(-100, 0), float(c.rng.randint(-3, 3)),
                                 float('nan')])
    return [c.fbuf(n, sg), lp, n]
S(0x4045a0, 'vorbis psy seed_chase', 'cdecl', None, gen=g4045a0)


def g4ee2e0(c):
    c.emu.w32(0x7003b0, h.L(c, 'assert', 0, regs=()))
    logger(c, 4)
    h.hk(c, 0x449d40, 'base', 3)
    s = h.rnd(c, 0x40)
    c.emu.w32(s + 4, c.rng.choice([0, R(c)]))
    other = h.rnd(c, 0x10)
    c.emu.w32(other + 4, c.rng.choice([0, R(c)]))
    hv = R(c)
    names = h.obj(c, {0x88: h.L(c, 'find', 2, wr=lambda e, rv, a: e.w32(a[1], hv)), 0x60: h.L(c, 'add', 3)})
    db = h.obj(c, {0x138: h.L(c, 'names', 0, ret=names), 0x58: h.L(c, 'db58', 1, ret=c.rng.choice([0, s, other])),
                   0x4c: h.L(c, 'db4c', 1, ret=R(c))}, size=0x140)
    h.engine(c, 0x9b, db)
    n = h.rnd(c, 0xb0)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=c.rng.choice([0, n, n]))
    h.hk(c, 0x4ccba0, 'REFTAB32', 0, ret=lambda e, rv, a: rv[0])
    return [s, R(c), R(c), R(c)]
S(0x4ee2e0, 'GUESS named object ctor (vt 0x6978c4)', 'thiscall', None, ret='eax', gen=g4ee2e0)


def g62f1e0(c):
    ws = c.rng.choice([0x200, 0x400])
    s = h.rnd(c, 0x70)
    win = h.rnd(c, 2 * ws + 0x10)
    hs = c.rng.choice([0x40, 0x100])
    head, prev = h.rnd(c, 2 * hs), h.rnd(c, 2 * ws)
    for a, n in ((head, hs), (prev, ws)):  # chain entries around w_size (rebased or cleared)
        for i in range(n):
            if c.rng.random() < 0.3:
                c.emu.w16(a + 2 * i, c.rng.choice([ws, ws - 1, ws + 1, 0]))
    look = c.rng.choice([0, 1, 2, 3, c.rng.randint(0, 0x105), c.rng.randint(0x106, 0x200)])
    ss = c.rng.randint(0, 2 * ws - look)
    k = c.rng.random()
    if k < 0.3:
        ss = 2 * ws - look - c.rng.randint(0, 4)  # near the end: slide
        ss = max(ss, 0)
    elif k < 0.45:
        ss = 2 * ws - 0x106 + c.rng.choice([-1, 0])  # slide threshold exactly
        look = min(look, 2 * ws - ss)
    for o, v in ((0x24, ws), (0x30, win), (0x34, 2 * ws), (0x38, prev), (0x3c, head), (0x44, hs),
                 (0x4c, hs - 1), (0x50, c.rng.randint(0, 40)), (0x54, R(c)), (0x64, ss), (0x68, R(c)), (0x6c, look)):
        c.emu.w32(s + o, v)
    strm = h.rnd(c, 0x40)
    avail = c.rng.choice([0, 1, 5, 0x100, c.rng.randint(0, 0x900)])
    nin = h.rnd(c, avail + 8)
    stt = h.rnd(c, 0x20)
    c.emu.w32(stt + 0x18, c.rng.choice([0, 1]))
    c.emu.w32(strm, nin); c.emu.w32(strm + 4, avail); c.emu.w32(strm + 0x1c, stt)
    c.emu.w32(s, strm)
    def cp(e, rv, a):
        if a[2]:
            e.wbytes(a[0], e.rbytes(a[1], a[2]))
    h.hk(c, 0x634d22, 'memcpy', 3, pops=0, regs=(), wr=cp, ret=lambda e, rv, a: a[0])
    h.hk(c, 0x6316e0, 'adler32', 3, regs=(), ret=lambda e, rv, a: R(c))
    return [s]
S(0x62f1e0, 'zlib fill_window', 'cdecl', None, gen=g62f1e0)


def g6526e0(c):
    h.setg(c, 0x725824, R(c))
    def adj(e, a):
        e.wbytes(a[0], c.rng.randbytes(16))
    c.emu.w32(0x676218, Ld(c, 'AdjustWindowRectEx', 4, dumps={0: 16}, wr=adj, ret=1))
    c.emu.w32(0x67618c, Ld(c, 'GetClassInfoExA', 3, wr=lambda e, a: e.wbytes(a[2], c.rng.randbytes(0x30)),
                           ret=c.rng.choice([0, 0, 1])))
    c.emu.w32(0x676248, Ld(c, 'LoadIconA', 2, ret=R(c)))
    c.emu.w32(0x6761cc, Ld(c, 'LoadCursorA', 2, ret=R(c)))
    c.emu.w32(0x676034, Ld(c, 'GetStockObject', 1, ret=R(c)))
    c.emu.w32(0x676188, Ld(c, 'RegisterClassExA', 1, dumps={0: 0x30}, ret=c.rng.choice([0, 0x10000, 1, 0xc001])))
    c.emu.w32(0x676190, Ld(c, 'CreateWindowExA', 12, ret=R(c)))
    c.emu.w32(0x6761fc, Ld(c, 'SetWindowLongA', 3, ret=R(c)))
    s = h.rnd(c, 0x140)
    return [s, c.rng.choice([0, 0, R(c)]), R(c), R(c), R(c), h.rnd(c, 0x10), R(c), R(c)]
S(0x6526e0, 'GUESS game window creation', 'thiscall', None, ret='al', gen=g6526e0)


def g43b820(c):
    logger(c, 3)
    k = c.rng.randint(0, 10)
    st = {'i': 0}
    def cmp(e, a):
        st['i'] += 1
        return 0 if st['i'] - 1 == k else c.rng.choice([1, 0xffffffff])
    c.emu.w32(0x676414, Ld(c, '_stricmp', 2, ret=cmp, pops=0))
    return [h.rnd(c, 0xc0), R(c)]
S(0x43b820, 'CConfigReader::ExtractMappingActivation', 'thiscall', None, gen=g43b820)
