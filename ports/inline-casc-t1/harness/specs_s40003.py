"""specs_s40003. 0x57edf0: two object tables (+0xc, +0x1c) with slots 0x284 (1 arg) and 0x26c (3 args, float bits recorded); n includes negatives (table 0x680aa0 adds 2^32). 0x459f40: hooked 0x4e0a10 fills the stack vector (deterministic words),
the real 0x4e0d00/0x451890/0x443ef0 run on random blocks; /GS check real. 0x640c10: ret al, flag words, [this+0x68] table of objects with byte +0x3f / dword +0x48 (real 0x658d30), slot 0x24c object with an unaligned float, hooked 0x63eb90 (st0).
0x524f50: counts at +0x8c/+0x90 (negative too), hooked 0x516070 sets flag bytes through side effects. 0x5072f0: hooked 0x5003d0 (three cells), [this+0x18] slot 0x39c records the 3 floats, /GS check real. 0x5a0b80: slot 0x48 writes n through the pointer, slot 0x18 fills the block, real 0x5eade0."""
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


def _g57edf0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x60)
    for off in (0xc, 0x1c):
        for i in range(4):
            e.w32(me + off + 4 * i, obj(c, 0x20, {0x284: pystub(c, 1, this=True), 0x26c: pystub(c, 3, this=True)}, nslots=0x290 // 4))
    n = r.choice([0, 1, 100, 0x7fffffff, 0x80000000, 0xffffffff, -5 & 0xffffffff, 123456789, r.getrandbits(32)])
    return [me, r.getrandbits(32), r.randrange(0, 4), n]


def _g459f40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    words = [_rf(r) for _ in range(3)]

    def fill(em, k):
        buf = em.reg('ecx')
        em.wbytes(buf, b''.join(w.to_bytes(4, 'little') for w in words))
    hook_rec(c, 0x4e0a10, 0, this='mark', pop=0, side=fill)
    me = rnd(c, 0x100)
    p = rnd(c, 0x20)
    for off in (0xa0, 0xac):
        for j in range(3):
            if r.random() < 0.8:
                e.w32(me + off + 4 * j, _fb(r.uniform(-100, 100)))
    return [me, p, F(struct.unpack('<f', struct.pack('<I', _rf(r)))[0])]


def _g640c10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    arr = rnd(c, 0x40)
    for i in range(8):
        o = rnd(c, 0x60)
        e.wbytes(o + 0x3f, bytes([r.choice([0, 1, 1, 5])]))
        e.w32(o + 0x48, rnd(c, 0x20))
        e.w32(arr + 4 * i, o)
    q = rnd(c, 0x300)
    e.wbytes(q + 0x271, struct.pack('<I', _fb(r.choice([0.0, 999.0, 1000.0, 1001.0, 1e9, -5.0, r.uniform(0, 2000)])) if r.random() < 0.92 else 0x7fc00001))
    po = obj(c, 0x20, {0x24c: pystub(c, 0, ret=q, this=True)}, nslots=0x250 // 4)
    p = rnd(c, 0x80)
    w = r.choice([0, 1, 2, 7, 0x1003, 0x2004, 0xf005, r.randrange(1, 8)])
    e.wbytes(p + 0x5a, struct.pack('<H', w))
    fl = r.choice([0, 0, 0x2000, 0x2001, r.getrandbits(32)])
    e.w32(p + 0x3c, fl)
    e.w32(p + 0x54, po)
    vals = [999.0, 1000.0, 1000.5, 1.0, -1.0, 2000.0, float('nan'), r.uniform(0, 2000)]
    hook_rec(c, 0x63eb90, 1, this=True, st0=lambda em, k: r.choice(vals))
    me = rnd(c, 0x100)
    e.w32(me + 0x68, arr)
    return [me, p]


def _g524f50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    flags = [r.random() < 0.4 for _ in range(16)]

    def side(em, k):
        em.wbytes(em.reg('ecx') + 0x10, bytes([1 if flags[min(k, 15)] else r.choice([0, 0])]))
    hook_rec(c, 0x516070, 1, this=True, side=side)
    n1 = r.choice([0, 1, 2, 3, -1 & 0xffffffff, 0x80000000])
    n2 = r.choice([0, 1, 2, 3, -2 & 0xffffffff])
    me = rnd(c, 0x445 + 4 * 0xde + 0x40)
    e.w32(me + 0x8c, n1)
    e.w32(me + 0x90, n2)
    e.w32(me + 0x80, r.getrandbits(32))
    e.w32(me + 0x9c, _rf(r))
    return [me]


def _g5072f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cells = [rnd(c, 0x10) for _ in range(3)]
    for cc in cells:
        e.w32(cc, _rf(r))
    seq = cells
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: seq[min(k, 2)])
    tgt = obj(c, 0x20, {0x39c: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x3a0 // 4)
    me = rnd(c, 0x40)
    e.w32(me + 0x18, tgt)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [me, p]


def _g5a0b80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 5, -1 & 0xffffffff, 0x80000000])

    def put_n(em, k):
        em.w32(em.arg32(0), n)

    def fill(em, k):
        em.wbytes(em.arg32(0), bytes((k * 29 + i * 7 + 3) & 0xff for i in range(16)))
    o = obj(c, 0x20, {0x48: pystub(c, 1, this=True, stackmark=(0,), side=put_n), 0x18: pystub(c, 2, this=True, stackmark=(0,), side=fill)}, nslots=0x4c // 4)
    me = rnd(c, 4 + 16 * 8)
    e.w32(me, r.randrange(0, 3))
    return [me, o]


S(0x57edf0, 'GUESS set two animation values', 'thiscall', None, ret=None, gen=_g57edf0, note='batch40003')
S(0x459f40, 'GUESS advance a position', 'thiscall', None, ret=None, gen=_g459f40, note='batch40003')
S(0x640c10, 'GUESS entry usable check', 'thiscall', None, ret='al', gen=_g640c10, note='batch40003')
S(0x524f50, 'GUESS refresh child flags', 'thiscall', None, ret=None, gen=_g524f50, note='batch40003')
S(0x5072f0, 'GUESS forward three cells', 'thiscall', None, ret=None, gen=_g5072f0, note='batch40003')
S(0x5a0b80, 'GUESS collect records', 'thiscall', None, ret=None, gen=_g5a0b80, note='batch40003')
