"""specs_s1810.py - fresh-18 batch 10 (src/batch1810.cpp). 0x7003b0 is a logging stub where the code can assert."""
import os, sys, math
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from pilot import S, F
import h18 as h

R = lambda c: c.rng.getrandbits(32)


def logger(c, nargs):
    lg = h.obj(c, {0x2c: h.L(c, 'log2c', nargs, regs=(), pops=0)})
    c.emu.w32(0x700390, h.obj(c, {0x20: h.L(c, 'log20', 2, ret=lg)}))


def assert_stub(c):
    c.emu.w32(0x7003b0, h.L(c, 'assert', 0, regs=()))


def g4ca160(c):
    def fl(e, r):
        e.calllog.append(('dbfloat', (e.reg('ecx'),), ()))
        e.ret(eax=0, argbytes=0, st0=c.rng.choice([0.0, 1.0, -2.5, c.fv(-1000, 1000)]))
    c.emu.hook(0x4e5e80, fl)
    h.hk(c, 0x4e5e60, 'dbuint', 0, ret=lambda e, rv, a: c.rng.choice([0, 1, R(c)]))
    return [h.rnd(c, 0xb0), R(c)]
S(0x4ca160, 'ZDiscoMove::CopyEventDataBlock', 'thiscall', None, gen=g4ca160)


def g56c5a0(c):
    for a, n, k in ((0x565020, 'CFileWindow::OnWindowOpen', 2), (0x564600, 'AsynchronCommand', 1),
                    (0x565100, 'SetStatus', 1), (0x56c6a0, 'SetupProfiles', 0), (0x56b460, 'DisplayIndex', 1)):
        h.hk(c, a, n, k)
    lst = h.obj(c, {0x34: h.L(c, 'l34', 0, ret=R(c)), 0x3c: h.L(c, 'l3c', 0, ret=c.rng.choice([0, 1, 0x100, R(c)]))})
    s = h.obj(c, {0x104: h.L(c, 's104', 0)}, size=0xd00)
    c.emu.w32(s + 0xc5e, lst)
    c.emu.w32(s + 0xcee, c.rng.choice([0, 1, 2, 3, 3, 4, 5, 6, R(c)]))
    return [s, R(c), c.rng.choice([0, 1, 0x100, R(c)])]
S(0x56c5a0, 'CLoadMenu::OnWindowOpen', 'thiscall', None, ret='al', gen=g56c5a0)


def g47ff20(c):
    o0, o1 = c.rng.uniform(0.5, 10), c.rng.uniform(0.5, 10)
    def wr(e, rv, a):
        e.wf32(a[0], o0); e.wf32(a[0] + 4, o1)
    cam = h.obj(c, {0x274: h.L(c, 'cam274', 2, wr=wr)}, size=0x280)
    s = h.rnd(c, 0x30)
    k = c.rng.uniform(0, 5)
    near = c.rng.uniform(0, 2)
    # far == near with r == near makes t NaN: the CRT conversion then calls _except1 (import, no stub); not generated
    far = near + c.rng.choice([c.rng.uniform(0.1, 3), -1.0])
    c.emu.wf32(s + 0x1c, k); c.emu.wf32(s + 0x20, far); c.emu.wf32(s + 0x24, near)
    d = min(o0, o1) + k
    L = d * c.rng.choice([near * 0.5, c.rng.uniform(min(near, far), max(near, far)), far * 1.5, far, near])
    ang = c.rng.uniform(0, 6.283)
    p = h.rnd(c, 16)
    c.emu.wf32(p, L * math.cos(ang)); c.emu.wf32(p + 4, L * math.sin(ang)); c.emu.wf32(p + 8, c.fv())
    return [s, cam, p]
S(0x47ff20, 'ZLightOverlay::CalcTrans', 'thiscall', None, ret='eax', gen=g47ff20, stack_arg_bytes=12)


def g509c20(c):
    assert_stub(c)
    logger(c, 3)
    p = h.rnd(c, 8)
    t = c.rng.choice([3, 4, 4, 0, c.rng.randint(5, 255)])
    c.emu.w8(p + 4, t)
    if t == 4:
        c.emu.w32(p, h.obj(c, {0x34: h.L(c, 'str34', 0, ret=R(c))}))
    h.hk(c, 0x5003d0, 'param', 1, ret=p)
    h.engine(c, 0x9b, h.obj(c, {0x114: h.L(c, 'RegisterZMsg', 4, ret=R(c))}, size=0x120))
    cnt = c.rng.randint(0, 4)
    def start(e, rv, a):
        e.w32(a[0], cnt); e.w32(a[0] + 4, 0x1234); e.w32(a[0] + 8, R(c))
    def step(e, rv, a):
        e.w32(a[0], max(e.r32(a[0]) - 1, 0))
    it = h.obj(c, {0x4c: h.L(c, 'start', 1, wr=start), 0x5c: h.L(c, 'step', 1, wr=step, ret=lambda e, rv, a: R(c))})
    grp = h.obj(c, {0x12c: h.L(c, 'SendCommand', 3)}, size=0x140)
    c.emu.w32(grp + 0x18, c.rng.choice([0, it, it]))
    s = h.rnd(c, 0x20)
    c.emu.w32(s + 0xc, grp)
    return [s, h.rnd(c, 0x10)]
S(0x509c20, 'GUESS script call: send registered message to group', 'thiscall', None, gen=g509c20, stack_arg_bytes=12)


def g45a720(c):
    def draw(e, r):
        e.calllog.append(('buf30', (e.reg('ecx'),), (e.arg32(0), e.rbytes(e.arg32(1), 0x30).hex(), e.arg32(2), e.arg32(3))))
        e.ret(eax=0, argbytes=16)
    buf = h.obj(c, {0x30: c.emu.stub_fn('buf30', draw)})
    p = h.rnd(c, 0x40)
    for i in range(3):
        c.emu.wf32(p + 0x30 + 4 * i, c.fv())
    s = h.rnd(c, 0x30)
    for o in (0x18, 0x1c, 0x20):
        c.emu.wf32(s + o, c.fv())
    c.emu.w32(s + 8, p)
    return [s, buf, R(c), c.fbuf(9), R(c)]
S(0x45a720, 'ZPICOBJ::Draw', 'thiscall', None, gen=g45a720)


def mystr(c):
    pat = c.rng.randbytes(0x80)
    h.hk(c, 0x4cbe80, 'MYSTR', 1, wr=lambda e, rv, a: e.wbytes(rv[0], pat))
    h.hk(c, 0x4cbec0, '~MYSTR', 0)


def g4266a0(c):
    mystr(c)
    h.hk(c, 0x4cbe50, 'MYSTR(copy)', 1)
    h.hk(c, 0x4cc2c0, 'MYSTR+=', 1)
    h.engine(c, 0x123, R(c))
    return [h.rnd(c, 0x80), R(c)]
S(0x4266a0, 'ZSysFileGC::ConvertFileNameFromZipToHD', 'stdcall', None, ret='eax', gen=g4266a0)


def g572360(c):
    h.hk(c, 0x469870, 'geombase', 0)
    h.engine(c, 0x9b, h.obj(c, {0x114: h.L(c, 'RegisterZMsg', 4, ret=lambda e, rv, a: R(c))}, size=0x120))
    return [h.rnd(c, 0x60)]
S(0x572360, 'CSubtitle::CSubtitle', 'thiscall', None, ret='eax', gen=g572360)


def g5378a0(c):
    logger(c, 1)
    db = h.obj(c, {0x114: h.L(c, 'RegisterZMsg', 4, ret=R(c))}, size=0x120)
    o = h.obj(c, {0x7c: h.L(c, 'o7c', 1, ret=R(c)), 0x84: h.L(c, 'o84', 1, ret=R(c)),
                  0x8c: h.L(c, 'o8c', 1, ret=R(c)), 0x5c: h.L(c, 'o5c', 2, ret=c.rng.choice([0, 1, 2, 0xffffffff, R(c)]))})
    eng = h.obj(c, {0xbc: h.L(c, 'ebc', 0, ret=c.rng.choice([0, o, o]))}, size=0xc0)
    c.emu.w32(eng + 0x9b, db)
    c.emu.w32(0x70039c, eng)
    s = h.obj(c, {0x104: h.L(c, 's104', 2), 0x1f8: h.L(c, 's1f8', 0, ret=c.rng.choice([0, 1, 0x100, R(c)]))}, size=0x50c0)
    return [s]
S(0x5378a0, 'ZDllSound::Initialize', 'thiscall', None, gen=g5378a0)
