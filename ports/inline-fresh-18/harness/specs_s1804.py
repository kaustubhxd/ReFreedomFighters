"""specs_s1804.py - fresh-18 batch 4 (src/batch1804.cpp)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)


def logger(c, nargs):
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', nargs, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'log20', 2, ret=lg)}))


def g64f8a0(c):
    h.hk(c, 0x634273, 'delete', 2, pops=0, regs=())
    s = h.rnd(c, 0x80)
    for off, slot in ((0x18, 0x160), (0x68, 0xc)):
        c.emu.w32(s + off, 0 if c.rng.random() < 0.3 else h.obj(c, {slot: h.L(c, 'o%x' % slot, 1)}))
    for off in (0x20, 0x2c):
        if c.rng.random() < 0.3:
            c.emu.w32(s + off, 0)
    return [s]
S(0x64f8a0, 'ZRenderBaseDll::Cleanup', 'thiscall', None, gen=g64f8a0)


def g44d520(c):
    g = h.obj(c, {0x294: h.L(c, 'g294', 2)})
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=c.rng.choice([0, g, g]))}))
    n = c.rng.randint(1, 6)
    arr = h.rnd(c, 4 * n + 8)
    for k in range(n):
        c.emu.w32(arr + 4 * k, h.rnd(c, 0x18))
    s = h.rnd(c, 0x30)
    c.emu.w32(s + 0x20, arr)
    c.emu.w32(s + 0x1c, n)
    return [s, c.rng.randint(0, n - 1)]
S(0x44d520, 'ZBoneParticle::RemoveParticles', 'thiscall', None, gen=g44d520)


def g615560(c):
    pool = h.rnd(c, 48 * 18)
    c.emu.w16(pool + 2, c.rng.choice([0xffff, c.rng.randint(0, 16), c.rng.randint(0, 16)]))
    return [pool]
S(0x615560, 'GUESS free-list alloc 48', 'thiscall', None, ret='eax', gen=g615560)


def g44ea60(c):
    s = h.rnd(c, 0x80)
    for i in range(6):
        c.emu.wf32(s + 0x5c + 4 * i, c.fv())
    v = c.fbuf(3)
    if c.rng.random() < 0.2:   # exact ties with the box faces
        for i in range(3):
            c.emu.w32(v + 4 * i, c.emu.r32(s + 0x5c + 4 * (i + c.rng.choice([0, 3]))))
    return [s, v]
S(0x44ea60, 'ZBOXGATEGROUP::CalcMaxMinBits', 'thiscall', None, ret='eax', gen=g44ea60)


def g4cec60(c):
    logger(c, 3)
    cnt = c.rng.randint(0, 4)
    def start(e, rv, a):
        e.w32(a[0], cnt); e.w32(a[0] + 4, 0x1234); e.w32(a[0] + 8, R(c))
    def step(e, rv, a):
        e.w32(a[0], max(e.r32(a[0]) - 1, 0))
    s = h.obj(c, {0x4c: h.L(c, 'start', 1, wr=start), 0x5c: h.L(c, 'step', 1, wr=step, ret=lambda e, rv, a: R(c))})
    return [c.rng.choice([s, s, s, 0])]
S(0x4cec60, 'STRREFTAB::PrintStatus', 'thiscall', None, gen=g4cec60, stack_arg_bytes=12)


def g4e8160(c):
    nil = h.rnd(c, 0x10)
    t = h.rnd(c, 0x10)
    c.emu.w32(t + 8, nil)
    nodes = []
    root = nil
    for _ in range(c.rng.randint(0, 6)):
        nd = h.rnd(c, 0x10)
        c.emu.w32(nd + 4, nil); c.emu.w32(nd + 8, nil)
        c.emu.w32(nd + 0xc, c.rng.choice([c.rng.randint(-5, 5), R(c)]) & 0xffffffff)
        if root == nil:
            root = nd
        else:
            cur = root
            k = c.emu.r32(nd + 0xc) - (1 << 32 if c.emu.r32(nd + 0xc) & 0x80000000 else 0)
            while True:
                ck = c.emu.r32(cur + 0xc); ck -= (1 << 32) if ck & 0x80000000 else 0
                side = 4 if k < ck else 8
                nx = c.emu.r32(cur + side)
                if nx == nil:
                    c.emu.w32(cur + side, nd); break
                cur = nx
        nodes.append(nd)
    c.emu.w32(t + 4, root)
    node = h.rnd(c, 0x10)
    c.emu.w32(node + 0xc, c.rng.choice([c.rng.randint(-5, 5), R(c)]) & 0xffffffff)
    return [t, node]
S(0x4e8160, 'GUESS tree insert', 'thiscall', None, gen=g4e8160)


def g5670a0(c):
    for a, n, k in ((0x5626c0, 'Load2', 0), (0x563510, 'SetBackGroundPicture', 1), (0x563610, 'f563610', 1),
                    (0x5672c0, 'SetCS', 1)):
        h.hk(c, a, n, k)
    h.hk(c, 0x566f10, 'GetCS', 0, ret=R(c))
    h.engine(c, 0x9b, h.obj(c, {0x58: h.L(c, 'e58', 1, ret=R(c)), 0x4c: h.L(c, 'e4c', 1, ret=R(c))}))
    o = h.rnd(c, 0x132c0)
    s = h.rnd(c, 0x200)
    c.emu.w32(s + 0x94, o)
    return [s]
S(0x5670a0, 'CController::Load2', 'thiscall', None, gen=g5670a0)


def g4b3460(c):
    s = h.obj(c, {0xa0: h.L(c, 'sa0', 0)}, size=0x190)
    a, b = R(c) & 0xffff, R(c) & 0xffff
    c.emu.w16(s + 0x72, a); c.emu.w16(s + 0x70, c.rng.choice([a, b]))
    c.emu.w8(s + 0x182, c.rng.choice([0, 1])); c.emu.w8(s + 0x184, c.rng.choice([0, 0, 1]))
    snd = h.rnd(c, 0x20)
    h.engine(c, 0x9b, h.obj(c, {0x60: h.L(c, 'e60', 1, ret=c.rng.choice([0, snd]))}))
    h.hk(c, 0x44b610, 'f44b610', 0)
    h.hk(c, 0x44b740, 'ZSoundObject::~', 1, pops=0, regs=())
    cmd = c.rng.choice([a, b, R(c)]) | (c.rng.choice([0, R(c) & 0xffff0000]))
    return [s, cmd, R(c)]
S(0x4b3460, 'CCutSequenceCharacterSound::Command', 'thiscall', None, ret='eax', gen=g4b3460)


def g4d61e0(c):
    logger(c, 2)
    n = c.rng.choice([0, 1, 2, 5, 9])
    old = h.rnd(c, 4 * n + 4)
    s = h.rnd(c, 0x10)
    c.emu.w32(s, n); c.emu.w32(s + 8, old)
    nb = h.rnd(c, 8 * n + 8)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=0 if (n == 0 and c.rng.random() < 0.5) else nb)
    h.hk(c, 0x41e2c0, 'free', 1, pops=0, regs=())
    def cp(e, rv, a):
        if a[2]:
            e.wbytes(a[0], e.rbytes(a[1], a[2]))
    h.hk(c, 0x634d22, 'memcpy', 3, pops=0, regs=(), wr=cp, ret=lambda e, rv, a: a[0])
    return [s]
S(0x4d61e0, 'GUESS array grow', 'thiscall', None, gen=g4d61e0)


def g42d360(c):
    buf = h.rnd(c, 0x40)
    k = c.rng.randint(1, 6)
    for i in range(k):
        c.emu.w32(buf + 4 * i, c.rng.choice([0, 1, R(c)]))
    vec = h.rnd(c, 0x10)
    c.emu.w32(vec + 4, buf + 4 * k)
    c.emu.w32(vec + 8, buf + 4 * k + c.rng.choice([0, 4, 8]))
    h.hk(c, 0x4301c0, 'grow_insert', 2)
    s = h.obj(c, {0x8c: h.L(c, 's8c', 1, ret=c.rng.choice([0, 1, 0x100, R(c)]))}, size=0x1b70)
    c.emu.w32(s + 0x1b61, vec)
    return [s, R(c)]
S(0x42d360, 'ZSysInterface::HandleIfNDef', 'thiscall', None, gen=g42d360)


def g4960e0(c):
    logger(c, 2)
    s = h.rnd(c, 0x60)
    n = c.rng.choice([0, 3, 0x1fd, 0x1fe, 0x1ff, R(c)])
    c.emu.w32(s + 0x59, n)
    if n < 0x1fe:
        idx = h.rnd(c, 2 * (n + 1))
        c.emu.w32(s + 0x55, idx - 0 if n < 8 else idx)
        c.emu.w16(idx + 2 * n, c.rng.randint(0, 7))
        c.emu.w32(s + 0x51, h.rnd(c, 32 * 8))
    m = h.obj(c, {0x2c: h.L(c, 'm2c', 3)})
    c.emu.w32(0x70038c, c.rng.choice([0, m]))
    return [s]
S(0x4960e0, 'ZGeomBuffer::AllocRoomList', 'thiscall', None, ret='eax', gen=g4960e0)


def g4f7520(c):
    wm = h.obj(c, {0xb8: h.L(c, 'wmb8', 1), 0xac: h.L(c, 'wmac', 2)})
    blk = h.rnd(c, 0x1920)
    c.emu.w32(blk + 0x190f, wm)
    c.emu.w32(0x70039c, blk)
    s = h.rnd(c, 0xb0)
    c.emu.w8(s + 0xa7, c.rng.choice([0, 1]))
    return [s, c.rng.choice([0, 1, 0x7fffffff, 0x80000000, 0xffffffff, 0x80000001, R(c), R(c) & 0xffff])]
S(0x4f7520, 'ZScrollArea::SetCameraPri', 'thiscall', None, gen=g4f7520)
