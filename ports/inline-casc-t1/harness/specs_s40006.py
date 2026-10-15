"""specs_s40006. 0x5c78e0: sys time +0x40 / unaligned flag +0x1a9f, engine table slot 0x58 -> object slots 0x20 and block [o+8], hooked 0x43ec00 (6 args), float at +0x6d unaligned. 0x5138f0: table slot 0x58 returning an object or 0, slot 0x1e0 al, floats at +0x30/+0x34.
0x4a5f20: hooked 0x4e7930 fills the stack matrix/vector (deterministic words) and returns on st0; the real fastcall helpers run; [this+0x44] slot 0x74 records both blocks; ret st0. 0x523470: float c edge cases (negative, 0, 1, >1, NaN), unaligned pointer at +0x4b, hooked 0x460af0 / 0x44c840 (st0), real 0x4e0d00, slots 0x84/0x88.
0x40cc20: cdecl, count n in [obj], hooked 0x405800 returns a small index into the table at [obj+0xc], float arrays with large/small magnitudes."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, hook_rec


def _fb(v):
    try:
        return struct.unpack('<I', struct.pack('<f', v))[0]
    except OverflowError:
        return 0x7f800000 if v > 0 else 0xff800000


def _rf(r):
    k = r.random()
    if k < 0.15:
        return _fb(r.choice(EDGE_F))
    if k < 0.2:
        return r.getrandbits(32)
    return _fb(r.uniform(-1000, 1000))


def _g5c78e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x60)
    o = obj(c, 0x30, {0x20: pystub(c, 0, ret=rnd(c, 0x20), this=True)}, nslots=0x24 // 4)
    e.w32(o + 8, blk)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.choice([o, o, o, 0]), this=True)})
    e.w32(so + 0x40, r.choice([0, 1000, 123456, r.getrandbits(32), r.randrange(0, 5000)]))
    e.wbytes(so + 0x1a9f, r.choice([0, 1, 0x01000000, r.getrandbits(32)]).to_bytes(4, 'little'))
    hook_rec(c, 0x43ec00, 6, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x80)
    e.wbytes(me + 0x6d, struct.pack('<f', r.choice([0.0, 1.0, -3.5, 0.5, r.uniform(-4, 4), r.uniform(-1000, 1000)])))
    if r.random() < 0.25:
        e.w32(me + 0x4c, 0)
    p = rnd(c, 0x40)
    if r.random() < 0.7:
        e.w32(p + 0x20, 0)
    return [me, p]


def _g5138f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x30, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100, 0xffffff00, r.getrandbits(32)]), this=True)}, nslots=0x1e4 // 4)
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=r.choice([o, o, 0]), this=True)})
    e.w32(so + 0x40, r.choice([0, 1000, r.getrandbits(32), r.randrange(0, 5000)]))
    me = rnd(c, 0x60)
    for off in (0x30, 0x34):
        e.w32(me + off, _fb(r.choice([0.0, 1.0, -2.5, 0.001, r.uniform(-5, 5), r.uniform(-1e6, 1e6)])) if r.random() < 0.9 else _rf(r))
    return [me, r.getrandbits(32)]


def _g4a5f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    words = [_fb(r.uniform(-3, 3)) for _ in range(12)]
    rv = [0.0, 1.5, -2.25, r.uniform(-10, 10)]

    def fill(em, k):
        em.wbytes(em.arg32(1), b''.join(w.to_bytes(4, 'little') for w in words[:9]))
        em.wbytes(em.arg32(2), b''.join(w.to_bytes(4, 'little') for w in words[9:12]))
    hook_rec(c, 0x4e7930, 4, this=True, stackmark=(1, 2), st0=lambda em, k: r.choice(rv), side=fill)
    tgt = obj(c, 0x20, {0x74: pystub(c, 2, this=True, deref={0: 9, 1: 3})}, nslots=0x78 // 4)
    me = rnd(c, 0x100)
    e.w32(me + 0x44, tgt)
    for off in (0x5f, 0x6b, 0x93):
        n = 3 if off == 0x5f else 9
        e.wbytes(me + off, b''.join(_fb(r.uniform(-3, 3)).to_bytes(4, 'little') for _ in range(n)))
    e.wbytes(me + 0xc0, struct.pack('<f', r.choice([0.0, 1.0, 2.5, r.uniform(-5, 5)])))
    return [me, F(struct.unpack('<f', struct.pack('<I', _rf(r)))[0])]


def _g523470(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x460af0, 3, this=True)
    hook_rec(c, 0x44c840, 0, this=True, st0=lambda em, k: r.choice([0.0, 1.0, -2.0]))
    ee = obj(c, 0x40, {0x84: pystub(c, 1, this=True), 0x88: pystub(c, 1, this=True)}, nslots=0x8c // 4) if r.random() < 0.8 else 0
    me = rnd(c, 0x80)
    e.wbytes(me + 0x4b, ee.to_bytes(4, 'little'))
    e.w32(me + 0x20, _fb(r.uniform(-3, 3)))
    a, b = rnd(c, 0x20), rnd(c, 0x20)
    for off in range(0, 12, 4):
        e.w32(b + off, _fb(r.uniform(-5, 5)))
    cv = r.choice([-1.0, -0.0, 0.0, 0.5, 1.0, 2.0, 1e30, float('nan'), r.uniform(-2, 2)])
    return [me, a, b, F(cv)]


def _g40cc20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, 8])
    ret = r.randrange(0, 3)
    hook_rec(c, 0x405800, 3, pop=0, ret=ret)
    tbl = c.emu.alloc(4 * 8 * 4, 4)
    for i in range(8 * 4):
        e.w32(tbl + 4 * i, _fb(r.choice([r.uniform(-100, 100), 1e-3, 1e8, -1e8, 0.0])))
    o = rnd(c, 0x20)
    e.w32(o, n)
    e.w32(o + 0xc, tbl)
    src = c.emu.alloc(4 * 24, 4)
    dst = c.emu.alloc(4 * 24, 4)
    for i in range(24):
        e.w32(src + 4 * i, _fb(r.choice([r.uniform(-100, 100), 1e-3, 1e8, -1e8, 0.0, 16777217.0])))
        e.w32(dst + 4 * i, _fb(r.choice([r.uniform(-100, 100), 1e8, 3.0])))
    idx = r.choice([0, 0, 1, 3, 7, r.randrange(0, 10)])
    return [o, src, dst, idx]


S(0x5c78e0, 'GUESS stamp time and bind', 'thiscall', None, ret=None, gen=_g5c78e0, note='batch40006')
S(0x5138f0, 'GUESS init time window', 'thiscall', None, ret=None, gen=_g5138f0, note='batch40006')
S(0x4a5f20, 'GUESS place transformed point', 'thiscall', None, ret='st0', gen=_g4a5f20, note='batch40006')
S(0x523470, 'GUESS blend pair', 'thiscall', None, ret=None, gen=_g523470, note='batch40006')
S(0x40cc20, 'GUESS delta decode channel', 'cdecl', None, ret=None, gen=_g40cc20, note='batch40006')
