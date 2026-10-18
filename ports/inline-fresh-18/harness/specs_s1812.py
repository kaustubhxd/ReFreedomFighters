"""specs_s1812.py - fresh-18 batch 12 (src/batch1812.cpp)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)
FC = ('ecx', 'edx')


def g4f28e0(c):
    cnt = c.rng.choice([0, 1, 2, 3, 5])
    def begin(e, rv, a):
        e.w32(a[0], cnt)
    def nxt(e, rv, a):
        e.w32(a[0], max(e.r32(a[0]) - 1, 0))
    s = h.obj(c, {0x2dc: h.L(c, 's2dc', 4)}, size=0x640)
    l = h.obj(c, {0x54: h.L(c, 'begin', 1, wr=begin), 0x44: h.L(c, 'next', 1, wr=nxt),
                  0x6c: h.L(c, 'get', 1, ret=lambda e, rv, a: c.rng.choice([0, R(c)]))})
    c.emu.w32(s + 0xcb, c.emu.r32(l))
    db = h.obj(c, {0x58: h.L(c, 'db58', 1, ret=lambda e, rv, a: c.rng.choice([0, 0, R(c)])),
                   0x4c: h.L(c, 'db4c', 1, ret=lambda e, rv, a: R(c))}, size=0x60)
    h.engine(c, 0x9b, db)
    return [s]
S(0x4f28e0, 'ZWINDOWS::PopWindow', 'thiscall', None, gen=g4f28e0)


def g4d7220(c):
    n, z = h.rnd(c, 0x440), h.rnd(c, 0x40)
    h.hk(c, 0x41e290, 'new', 1, pops=0, regs=(), ret=lambda e, rv, a: n if a[0] == 0x432 else z)
    h.hk(c, 0x634273, 'delete', 2, pops=0, regs=())
    h.hk(c, 0x4d6520, 'findFile', 3, ret=c.rng.choice([0, 1, 1, 0x100]))
    h.hk(c, 0x62f9d0, 'inflateInit2_', 4, regs=(), ret=c.rng.choice([0, 0, 0xfffffffe, R(c)]))
    s = h.rnd(c, 0x80)
    c.emu.w32(s + 0x15, h.obj(c, {0xc: h.L(c, 'pos', 1, ret=R(c))}))
    return [s, R(c), c.rng.choice([3, 3, 3, 0, 1, R(c)])]
S(0x4d7220, 'FsZip_t::open', 'thiscall', None, ret='eax', gen=g4d7220)


def g572720(c):
    s = h.rnd(c, 0x880)
    cnt = c.rng.randint(0, 12)
    c.emu.w32(s + 0x85c, cnt)
    c.emu.w32(s + 0x860, c.rng.choice([-1, 0, c.rng.randint(0, cnt + 1), cnt, cnt + 2]) & 0xffffffff)
    for i in range(0x20):
        c.emu.w8(s + 0x5b + i, c.rng.choice([0, 0, c.rng.randint(1, 255)]))
    c.emu.w32(s + 0x872, h.obj(c, {0xbc: h.L(c, 'w1bc', 1), 0x284: h.L(c, 'w1text', 1)}, size=0x290))
    c.emu.w32(s + 0x876, c.rng.choice([0, h.obj(c, {0xbc: h.L(c, 'w2bc', 1), 0x284: h.L(c, 'w2text', 1)}, size=0x290)]))
    c.emu.w32(s + 0x86e, c.rng.choice([0, R(c)]))
    c.emu.w32(s + 0x44, h.obj(c, {0x12c: h.L(c, 'SendCommand', 3)}, size=0x140))
    c.emu.wf32(s + 0x54, c.fv(-100, 100))
    h.engine(c, 0x40, c.rng.choice([R(c), c.rng.randint(0, 100000)]))
    return [s]
S(0x572720, 'CSubtitle::DisplayNextLines', 'thiscall', None, gen=g572720)


def g4dbbe0(c):
    def rd(e, rv, a):
        if a[1] == 2:
            e.w16(a[0], c.rng.choice([0xffff, c.rng.randint(0, 7)]))
        else:
            e.wbytes(a[0], c.rng.randbytes(a[1]))
    st = h.obj(c, {0x18: h.L(c, 'read', 2, wr=rd)})
    tab = h.rnd(c, 8 * 0x70 + 0x60)
    o = h.obj(c, {0x5c: h.L(c, 'release', 1), 0x4c: h.L(c, 'table', 0, ret=tab)}, size=0x60)
    db = h.rnd(c, 0x20)
    c.emu.w32(db + 8, o)
    h.engine(c, 0x9b, db)
    h.hk(c, 0x4dc9c0, 'set4dc9c0', 1)
    h.hk(c, 0x4dc630, 'SetControl', 2)
    s = h.rnd(c, 0x80)
    c.emu.w32(s + 0x54, c.rng.choice([0, h.obj(c, {0x14: h.L(c, 'load', 1, ret=c.rng.choice([0, 1, 0x100]))})]))
    c.emu.w16(s + 0x5c, c.rng.choice([0, R(c)]))
    return [s, st]
S(0x4dbbe0, 'GUESS ZBaseGeom load from stream', 'thiscall', None, ret='al', gen=g4dbbe0)


def g4bfee0(c):
    snd = h.obj(c, {0x228: h.L(c, 'getpitch', 0, ret=c.rng.randint(-100, 100) & 0xffffffff), 0x218: h.L(c, 'setpitch', 1)},
                size=0x230)
    s = h.obj(c, {0x68: h.L(c, 'stop', 2)}, size=0x70)
    c.emu.w32(s + 0x44, snd)
    c.emu.w8(s + 0x4c, c.rng.choice([0, 1, 1]))
    c.emu.w8(s + 0x4d, c.rng.choice([0, 1]))
    r52 = c.rng.uniform(0, 10)
    c.emu.wf32(s + 0x4e, c.rng.choice([0.0, c.rng.uniform(0, 100)]))
    c.emu.wf32(s + 0x52, r52)
    c.emu.wf32(s + 0x56, c.rng.choice([r52, r52 + c.rng.uniform(0, 20), c.rng.uniform(0, 20)]))
    c.emu.wf32(s + 0x5a, c.fv(-100, 100))
    c.emu.w32(s + 0x5e, c.rng.randint(-100, 100) & 0xffffffff)
    c.emu.wf32(s + 0x62, c.fv())
    eng = h.rnd(c, 0x50)
    c.emu.w32(eng + 0x40, c.rng.choice([c.rng.randint(0, 0x30000), R(c)]))
    c.emu.wf32(eng + 0x48, c.rng.choice([c.rng.uniform(0, 1), c.fv()]))
    c.emu.w32(0x70039c, eng)
    k = c.rng.random()
    if k < 0.15:  # pitch lands exactly on the target (x == tg) while rising
        c.emu.w8(s + 0x4d, 1); c.emu.wf32(eng + 0x48, 0.0); c.emu.wf32(s + 0x62, c.rng.uniform(0.1, 2))
        c.emu.wf32(s + 0x5a, float(c.emu.r32(s + 0x5e) - (1 << 32) if c.emu.r32(s + 0x5e) >> 31 else c.emu.r32(s + 0x5e)))
    elif k < 0.3:  # now == start time exactly
        r4e = c.rng.uniform(1, 100)
        c.emu.wf32(s + 0x4e, r4e)
        t = F(F(F(r52) + F(r4e)) * 1024.0)
        c.emu.w32(eng + 0x40, int(t))
    return [s]
S(0x4bfee0, 'ZSoundSegmentPitch::FrameUpdate', 'thiscall', None, gen=g4bfee0)


def g63f0e0(c):
    ent2 = h.rnd(c, 0x40)
    pool = h.obj(c, {8: h.L(c, 'take', 0, ret=c.rng.choice([0, ent2, ent2, ent2])), 0xc: h.L(c, 'give', 1)})
    s = h.obj(c, {0x84: h.L(c, 's84', 1), 0x90: h.L(c, 's90', 1, ret=c.rng.choice([0, 1, 1, 0x100])),
                  0x94: h.L(c, 's94', 1)}, size=0x230)
    c.emu.w32(s + 0x220, pool)
    tab = h.rnd(c, 0x4000)
    c.emu.w32(s + 0x68, tab)
    g = h.rnd(c, 0x60)
    gid = c.rng.choice([0, 0, R(c) & 0xffff])
    c.emu.w16(g + 0x5a, gid)
    c.emu.w32(tab + 4 * (gid & 0xfff), h.rnd(c, 0x10))
    c.emu.w32(g + 0x54, c.rng.choice([0, h.obj(c, {0xec: h.L(c, 'mec', 0, ret=c.rng.choice([0, 1, 0x100]))})]))
    room = c.rng.choice([0, h.rnd(c, 0x40), h.rnd(c, 0x40)])
    if room:
        c.emu.w32(room + 0x3c, c.rng.choice([0, h.obj(c, {0x358: h.L(c, 'rl', 0, ret=c.rng.choice([0, R(c)]))}, size=0x360)]))
    db = h.rnd(c, 0xae8)
    c.emu.w32(db + 0xadc, h.obj(c, {0x358: h.L(c, 'dl', 0, ret=c.rng.choice([0, R(c)]))}, size=0x360))
    h.engine(c, 0x9b, db)
    lt = h.rnd(c, 0x60)
    c.emu.w16(lt + 0x3e, c.rng.choice([0xffff, R(c)]))
    for a, nm, n, rt in ((0x63e850, 'GeomEnter', 1, 0), (0x4dd8d0, 'WantCameraMsg', 0, lambda e, rv, a: c.rng.choice([0, 1, 0x100])),
                         (0x4db6c0, 'GetRootTM', 2, 0), (0x63f090, 'NewDrawId', 1, lambda e, rv, a: R(c)),
                         (0x658d30, 'Bones', 0, lambda e, rv, a: c.rng.choice([0, 0, 1])),
                         (0x63f220, 'OnLightNotify', 1, lambda e, rv, a: c.rng.choice([0, lt, lt])), (0x658fb0, 'SetEnvironment', 1, 0)):
        h.hk(c, a, nm, n, ret=rt)
    return [s, room, g]
S(0x63f0e0, 'ZDrawBase::OnGeomNotify', 'thiscall', None, ret='eax', gen=g63f0e0)


def g404460(c):
    n = c.rng.choice([0, 1, 2, 3, 5, 8])
    fo = c.rng.randint(0, 4)
    lp = c.rng.randint(1, 8)
    o = fo + lp // 2 + c.rng.randint(0, 3)
    octs = []
    for i in range(max(n, 1) + 1):
        octs.append(o)
        o += c.rng.randint(0, 5)
    tot = o - fo + c.rng.randint(1, 4)
    oa = h.rnd(c, 4 * len(octs) + 8)
    for i, v in enumerate(octs):
        c.emu.w32(oa + 4 * i, v)
    vi = h.rnd(c, 0x80)
    c.emu.wf32(vi + 0x7c, c.rng.choice([c.fv(-100, 100), -9999.0, 1e30]))
    p = h.rnd(c, 0x30)
    c.emu.w32(p, n); c.emu.w32(p + 4, vi); c.emu.w32(p + 0x18, oa); c.emu.w32(p + 0x20, fo)
    c.emu.w32(p + 0x28, lp); c.emu.w32(p + 0x2c, tot)
    sg = lambda c: c.rng.choice([-9999.0, c.fv(-100, 100), c.rng.uniform(-100, 0)])
    sd = c.fbuf(tot + 2, sg)
    # no signalling NaN seeds: the band store goes through fld/fstp, which quiets an SNaN on hardware but not in
    # Unicorn's x87 (checked: case 4 of seed 3 kept 0xff800123); vorbis never produces SNaNs, so they are left out.
    return [p, sd, c.fbuf(max(n, 1), lambda c: c.rng.choice([-9999.0, c.fv(-100, 100)]))]
S(0x404460, 'vorbis psy max_seeds', 'cdecl', None, gen=g404460)


def g42be20(c):
    node = h.rnd(c, 0x30)
    head = h.rnd(c, 0x30)
    s = h.rnd(c, 0x10)
    c.emu.w32(s, head)
    h.hk(c, 0x431110, 'lower_bound', 2, wr=lambda e, rv, a: e.w32(a[0], c.rng.choice([head, node, node])))
    h.hk(c, 0x42feb0, 'compare', 2, regs=FC, ret=lambda e, rv, a: c.rng.choice([0, 1, 0xffffffff]))
    h.hk(c, 0x6014a0, 'alloc', 1, ret=h.rnd(c, 0x10))
    def cp(e, rv, a):
        b = c.rng.choice([0, R(c)])
        e.w32(rv[0], b); e.w32(rv[0] + 4, b); e.w32(rv[0] + 8, (b + c.rng.choice([0, 0x10, R(c)])) & 0xffffffff)
    h.hk(c, 0x5f10c0, 'strcopy', 1, wr=cp)
    h.hk(c, 0x430eb0, 'insert', 3, wr=lambda e, rv, a: e.w32(a[0], R(c)))
    h.hk(c, 0x54f870, 'dealloc', 2)
    return [s, h.rnd(c, 0x10)]
S(0x42be20, 'GUESS map<string,string>::operator[]', 'thiscall', None, ret='eax', gen=g42be20)
