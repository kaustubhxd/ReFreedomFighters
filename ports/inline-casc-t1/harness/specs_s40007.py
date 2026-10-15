"""specs_s40007. 0x4c1e30: hooked 0x4e5e60 (values 0/1/2/other for the first, random later; call order logged by the recorder) and 0x4e5e80 (st0), stream [s] -> kind byte (0xff, 2, 0x42, others). 0x5517a0: stdcall, object slots 0x18/0x4c, hooked 0x5003d0 (cells), 0x5002f0 and 0x500360, record of 4 dwords at c.
0x4e1e30: fastcall (this, d, a, b, c); the real 0x43e920/0x4e0d40/0x441940 run on random vectors; dot product exactly 0 or K in a share of cases; ret st0. 0x610250: six floats F(), block prefilled with random bytes. 0x4e2bb0: fastcall (arr, n), n 0..6, real 0x446ee0/0x441940, ret st0."""
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


def _fl(r, v):
    return struct.unpack('<f', struct.pack('<I', v))[0]


def _g4c1e30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    first = r.choice([0, 1, 2, 3, 7, 0xffffffff])
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: first if k == 0 else r.choice([0, 1, 5, r.getrandbits(32)]))
    fv = [0.0, 1.5, -3.25, 100.0, r.uniform(-50, 50)]
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: r.choice(fv))
    buf = rnd(c, 0x10)
    e.wbytes(buf, bytes([r.choice([0xff, 2, 0x42, 0x82, 0xc2, 0x3f, 0, r.getrandbits(8)])]))
    s = rnd(c, 0x20)
    e.w32(s, buf)
    me = rnd(c, 0x80)
    return [me, r.getrandbits(32), s]


def _g5517a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cells = [rnd(c, 0x10) for _ in range(4)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: cells[em.arg32(0) & 3])
    hook_rec(c, 0x5002f0, 1, this=True)
    hook_rec(c, 0x500360, 1, this=True)
    p = obj(c, 0x20, {}, nslots=2)
    o = obj(c, 0x20, {0x4c: pystub(c, 0, ret=p, this=True)}, nslots=0x50 // 4)
    a = obj(c, 0x20, {0x18: pystub(c, 1, ret=r.choice([o, o, o, 0]), this=True)}, nslots=0x1c // 4)
    cc = rnd(c, 0x20)
    for i in range(1, 4):
        e.w32(cc + 4 * i, _rf(r))
    return [a, r.getrandbits(32), cc]


def _g4e1e30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x20)
    d, a, b, cc = rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)
    for blk in (d, a, b, cc):
        for i in range(3):
            e.w32(blk + 4 * i, _fb(r.uniform(-5, 5)))
    k = r.random()
    if k < 0.25:
        for i in range(3):   # dot product zero
            e.w32(cc + 4 * i, 0)
    elif k < 0.3:
        e.w32(cc + 4, 0x7fc00000)
    return [me, d, a, b, cc]


def _g610250(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x40)
    vals = [r.uniform(-10, 10) for _ in range(6)]
    if r.random() < 0.15:
        vals[5] = vals[4]
    if r.random() < 0.1:
        vals[1] = vals[0]
    return [me] + [F(v) for v in vals]


def _g4e2bb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4, 6])
    arr = c.emu.alloc(12 * 8, 4)
    for i in range(24):
        e.w32(arr + 4 * i, _fb(r.uniform(-20, 20)))
    return [arr, n]


S(0x4c1e30, 'GUESS read playback flags', 'thiscall', None, ret=None, gen=_g4c1e30, note='batch40007')
S(0x5517a0, 'GUESS fill cells from a record', 'stdcall', None, ret='eax', gen=_g5517a0, note='batch40007')
S(0x4e1e30, 'GUESS ray plane intersect', 'fastcall', None, ret='st0', gen=_g4e1e30, note='batch40007')
S(0x610250, 'GUESS build frustum block', 'thiscall', None, ret=None, gen=_g610250, note='batch40007')
S(0x4e2bb0, 'GUESS polygon vector length', 'fastcall', None, ret='st0', gen=_g4e2bb0, note='batch40007')
