"""specs_f16b029.py - fresh slice 16 batch 29 (see src/f16b029.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj
from f16help import phook, codeaddr, fval, floorstub
import struct


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _vec(c, n, lo=-50, hi=50, nan=0.05):
    r = c.rng
    a = c.emu.alloc(4 * n + 4, 4)
    for i in range(n):
        c.emu.w32(a + 4 * i, fval(c) if r.random() < nan else _f(r.uniform(lo, hi)))
    return a


def _44c(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    rec = c.emu.alloc(0x40, 4)
    ca = codeaddr(c)

    def cp(e, a):
        e.wbytes(rec, bytes(e.rbytes(a[1], 36)))
        e.wbytes(rec + 36, bytes(e.rbytes(a[2], 12)))
    phook(c, seq, ca, 4, this=True, pop=True, act=cp)
    buf = obj(c, 0x80, {0x30: ca})
    geom = rnd(c, 0x40)
    for o in (0x24, 0x28, 0x2c):
        c.emu.w32(geom + o, _f(r.uniform(-100, 100)))
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, geom)
    c.emu.w8(me + 0x18, r.choice([0, 0, 1]))
    M = _vec(c, 16, -1.2, 1.2)
    if r.random() < 0.3:
        c.emu.w32(M + 0x14, _f(r.choice([0.99, -0.99, 0.9900001, 1.0, -1.0])))
    return [me, r.getrandbits(32), r.getrandbits(32), buf, r.getrandbits(32), M, _vec(c, 3), r.getrandbits(32)]


def _409(c):
    r = c.rng
    clear_hooks(c)
    floorstub(c)
    n = r.choice([0, 1, 2, 3, 5, 8, 16])
    a = _vec(c, max(n, 1), -20, 20)
    m = r.randrange(0, 12)
    tab = rnd(c, 0x514 + 0x400)
    for i in range(16):
        c.emu.w32(tab + 0x514 + 4 * i, _f(r.uniform(0, 150)) if r.random() < 0.95 else fval(c))
        c.emu.w32(tab + 0x514 + 0x100 + 4 * i, _f(r.uniform(0, 25)) if r.random() < 0.95 else fval(c))
        c.emu.w32(tab + 0x514 + 0x300 + 4 * i, r.randrange(-2, 6) & 0xffffffff)
    tp = c.emu.alloc(4, 4)
    c.emu.w32(tp, tab)
    return [a, n, tp, m, r.randrange(-1, 5) & 0xffffffff]


def _44b(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    rec = c.emu.alloc(0x20, 4)
    phook(c, seq, 0x4dc5d0, 3, this=True, pop=True)
    phook(c, seq, 0x4dce50, 1, this=True, pop=True)
    k = [0]

    def cp(e, a):
        e.wbytes(rec + 12 * (k[0] & 1), bytes(e.rbytes(a[0], 12)))
        k[0] += 1
    phook(c, seq, 0x4dd060, 1, this=True, pop=True, act=cp)
    phook(c, seq, 0x4dc600, 1, this=True, pop=True, act=cp)
    sysobj(c, extra={0x1a9f: r.choice([0, 1])})
    snd = rnd(c, 0x60)
    c.emu.w32(snd + 0x54, fval(c) if r.random() < 0.1 else _f(r.uniform(0, 500)))
    me = rnd(c, 0x20)
    c.emu.w32(me + 0x18, snd)
    return [me]


S(0x44c740, 'Z2DOBJ::OwnerDraw', 'thiscall', None, ret=None, gen=_44c, note='f16b029; vector helpers run as exe code; cookie not reproduced')
S(0x409300, 'FUN_409300 (quantiser pick, GUESS)', 'cdecl', None, ret='eax', gen=_409, note='f16b029; floor stubbed')
S(0x44b980, 'ZSNDOBJ::CalcCenSize', 'thiscall', None, ret=None, gen=_44b, note='f16b029; cookie not reproduced')
