"""specs_f16b023.py - fresh slice 16 batch 23 (see src/f16b023.cpp)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, sysobj, except1
from f16help import phook, codeaddr, fval
import struct


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _45a(c):
    r = c.rng
    clear_hooks(c)
    me = rnd(c, 0x30)
    c.emu.w8(me + 0x2e, r.choice([0, 1, 0x80]))
    pitch = r.randrange(0, 16)
    x, y = r.randrange(0, 16), r.randrange(0, 8)
    buf = rnd(c, 16 * 10 + 20)
    outs = [rnd(c, 4) for _ in range(4)]
    return [me, buf, x, y, pitch] + outs


def _562(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    except1(c)
    rec = c.emu.alloc(12, 4)
    ca = codeaddr(c)

    def cp(e, a):
        if 0x0fe00000 <= a[0] < 0x0ff00000:
            e.wbytes(rec, bytes(e.rbytes(a[0], 12)))
    phook(c, seq, ca, 1, this=True, pop=True, act=cp)
    h = obj(c, 0x80, {0x70: ca}) if r.random() < 0.85 else 0
    me = obj(c, 0x100, {0xd4: stub(c, seq, 1)})
    c.emu.w32(me + 0x54, h)
    for o in (0x6c, 0x78, 0x7c, 0x80):
        c.emu.w32(me + o, fval(c) if r.random() < 0.2 else _f(r.uniform(-300, 300) if o != 0x6c else r.uniform(-2, 2)))
    t = fval(c) if r.random() < 0.2 else _f(r.uniform(-2, 2))
    return [me, t]


def _4cd(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    k = r.randrange(1, 4)
    n = r.randrange(0, 4)
    blk = rnd(c, 0x10 + 4 * k * n + 8)
    left = r.randrange(0, 2)
    cnt = [0]
    ent = rnd(c, 4 * k + 4)
    tgt = rnd(c, 0x10)
    c.emu.w32(ent + 4 * (k - 1), tgt)

    def nxt(e, a):
        cnt[0] += 1
        e.w32(a[0], 1 if cnt[0] <= left else 0)
        return ent
    ca4, ca5, ca44 = codeaddr(c), codeaddr(c), codeaddr(c)
    phook(c, seq, ca4, 1, this=True, pop=True, act=lambda e, a: e.w32(a[0], 0x77) and None)
    phook(c, seq, ca5, 1, this=True, pop=True, act=nxt)
    phook(c, seq, ca44, 1, this=True, pop=True)
    h = obj(c, 0x80, {0x14: stub(c, seq, 0, ret=r.choice([0, 0, 1, r.getrandbits(32)])), 4: stub(c, seq, 1),
                      0x4c: ca4, 0x5c: ca5, 0x44: ca44})
    me = obj(c, 0x100, {0x80: stub(c, seq, 0, ret=blk)})
    c.emu.w32(me + 0x1c, h)
    c.emu.w32(me + 0x18, k)
    c.emu.w32(me + 0xc, n | (r.getrandbits(1) << 31))
    c.emu.w32(me + 4, rnd(c, 8) if r.random() < 0.7 else 0)
    v = rnd(c, 4 * k + 4)
    c.emu.w32(v + 4 * (k - 1), rnd(c, 0x10))
    return [me, v]


S(0x45ac00, 'ZPICOBJ::ReadIndex4', 'thiscall', None, ret=None, gen=_45a, note='f16b023')
S(0x562080, 'FUN_562080 (fade colour + offset)', 'thiscall', None, ret=None, gen=_562, note='f16b023; 0x633910 runs as exe code (_except1 stubbed); cookie not reproduced')
S(0x4cd5c0, 'STATICREFTAB::Add', 'thiscall', None, ret='eax', gen=_4cd, note='f16b023')
