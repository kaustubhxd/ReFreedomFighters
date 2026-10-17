"""specs_s244031.py - hand-written spec for 0x535ea0 (batch 244031)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g535ea0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    sr = seh_record(c, 1)
    pkf = lambda v: struct.pack('<f', v)
    FV = [0.0, -0.0, 1.0, 0.5, 100.0, 10.0, -1.0, 1e-3, 25.0, float('nan'), r.uniform(0, 200)]
    NARGS = {0x6a224c: 6, 0x6a2254: 5, 0x6a2288: 4, 0x6a2328: 23}

    def xprint(emu, k):
        n = 4
        s = emu.arg32(3)
        n = NARGS.get(s, 4)
        row = []
        for i in range(n):
            v = emu.arg32(i)
            if n == 23 and i == 5:   # &[ebp-0x24]: stack buffer, log what it holds
                v = ('buf', bytes(emu.rbytes(v, 8)))
            row.append(v)
        emu.calllog.append(('print', n, tuple(row)))
        sr(emu, k)
    X = obj(c, 0x40, {0x184: pystub(c, 4, ret=r.getrandbits(32), pop=0, side=xprint)})
    strp = lambda: r.choice([0, 0, rnd(c, 8)])
    Y = rnd(c, 0x20)
    em.w32(Y + 4, strp())
    W = rnd(c, 0x20)
    pool = []
    for _ in range(3):
        o = rnd(c, 0x100)
        em.w32(o + 8, r.choice([0, 1, 1] + list(range(0, 15))))   # indexes the string table at ebp-0x64 (slot 0 is the local [ebp-0x64])
        em.w32(o + 0x2c, r.randrange(-12, 4) & 0xffffffff)   # table at ebp-0x34 + 4*k reaches back to the first entries
        em.wbytes(o + 0x40, bytes([r.choice([0, 8, 0x18, 0xf7, 1])]))
        for fo in (0x84, 0x88, 0xd4, 0xd8, 0xdc, 0x54, 0x70):
            em.wbytes(o + fo, pkf(r.choice(FV) if fo in (0x84, 0x88, 0x54) else r.uniform(-5, 5)))
        em.w32(o + 0x68, r.getrandbits(32))
        em.w32(o + 4, strp())
        pool.append(o)

    def pick60(emu, k):
        return 0 if r.random() < 0.2 else r.choice(pool)
    em.w32(0x7003b0, 0)
    H = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda emu, k: 0 if r.random() < 0.3 else W, pop=4, this=True, side=lambda emu, k: (emu.calllog.append(('h58', emu.arg32(0))), sr(emu, k))),
                      0x60: pystub(c, 1, ret=pick60, pop=4, this=True, side=lambda emu, k: (emu.calllog.append(('h60', emu.arg32(0))), sr(emu, k)))})
    G = rnd(c, 0x100)
    em.w32(G + 0x9b, H)
    GV = obj(c, 0x200, {0x190: pystub(c, 0, ret=X, pop=0, this=True, side=sr)})
    em.w32(0x70039c, GV)
    em.w32(GV + 0x9b, H)
    hook_rec(c, 0x4db3b0, 0, ret=Y, pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('db3b0',)), sr(emu, k)))
    em.w32(W + 8, r.getrandbits(32))
    # the loop object a0
    kit = r.choice([0, 1, 2, 3])
    ctr = [0]

    def s6c(emu, k):
        n = ctr[0]
        ctr[0] += 1
        emu.w32(emu.arg32(0), 1 if n < kit else 0)
        emu.calllog.append(('a6c', n))
        sr(emu, k)
    A = obj(c, 0x100, {0x14: pystub(c, 2, ret=r.getrandbits(32), pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('a14', emu.arg32(0), emu.arg32(1))), sr(emu, k))),
                       0x54: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=lambda emu, k: (emu.calllog.append(('a54',)), sr(emu, k))),
                       0x6c: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s6c)})
    R3 = rnd(c, 0x20)
    E = 0 if r.random() < 0.2 else rnd(c, 0x20)
    if E:
        em.w32(E + 4, strp())
    R2 = rnd(c, 0x20)
    em.w32(R2 + 4, strp())
    off = r.getrandbits(32)
    if r.random() < 0.3:
        off = (-em.r32(R3 + 4)) & 0xffffffff
    me = obj(c, 0x5400, {0xc0: pystub(c, 0, ret=E, pop=0, this=True, side=sr),
                         0x220: pystub(c, 1, ret=R2, pop=4, this=True, side=lambda emu, k: (emu.calllog.append(('v220', emu.arg32(0))), sr(emu, k))),
                         0x40: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lambda emu, k: (emu.calllog.append(('v40', emu.arg32(0))), sr(emu, k))),
                         0x1dc: pystub(c, 1, ret=lambda emu, k: 0 if r.random() < 0.25 else R3, pop=4, this=True, side=lambda emu, k: (emu.calllog.append(('v1dc', emu.arg32(0))), sr(emu, k)))})
    em.w32(me + 0x5155, r.choice([-1, 0, 1, 2, 3, 3]) & 0xffffffff)
    for i in range(4):
        em.wbytes(me + 0x5159 + 9 * i, pkf(r.choice(FV)))
    em.w32(me + 0x5302, off)
    return [me, A]


S(0x535ea0, 'GUESS audio debug text overlay (voice list + volume dB per emitter)', 'thiscall', 1, ret='eax', gen=g535ea0, note='batch244031')
