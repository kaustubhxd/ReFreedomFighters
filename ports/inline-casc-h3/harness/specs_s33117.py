"""specs_s33117.py - h3 (Sonnet) batch 33117: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    if x != x:
        return 0x7fc00000
    try:
        return struct.unpack('<I', struct.pack('<f', x))[0]
    except OverflowError:
        return 0x7f800000 if x > 0 else 0xff800000


def _g4e0030(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = rnd(c, 0x10)
    b = rnd(c, 0x10)
    v = [c.fv(-5, 5, 0.1) for _ in range(3)]
    mode = r.random()
    if mode < 0.2:
        k = r.choice([2.0, 0.5, 3.0, -1.0, -2.0, 1.0, 0.1])
        w = [x * k for x in v]
    elif mode < 0.3:
        w = [0.0, 0.0, 0.0]
    elif mode < 0.4:
        v = [0.0, 0.0, 0.0]
        w = [c.fv(-5, 5, 0.1) for _ in range(3)]
    else:
        w = [c.fv(-5, 5, 0.1) for _ in range(3)]
    for i in range(3):
        for p, arr in ((a, v), (b, w)):
            x = arr[i]
            e.w32(p + 4 * i, 0x7fc00000 if x != x else _b(x))
    return [a, b]


def _g58aa40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 3, 4])
    arr = rnd(c, 4 + 48 * 5 + 8)
    e.w32(arr, n)
    shrink = r.random() < 0.4

    def side44(em, k):
        if shrink and k == 0:
            em.w32(arr, 1)
    stubs = {off: pystub(c, 1, this=True) for off in (0x3c, 0x64, 0x68, 0x4c)}
    stubs[0x44] = pystub(c, 1, this=True, side=side44)
    s = obj(c, 0x80, stubs)
    return [s, arr]


def _g449920(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    m = r.choice([0, 1, 2, 3])

    def s4c_side(em, k):
        em.w32(em.arg32(0), 1)

    def s5c_side(em, k):
        em.w32(em.arg32(0), 1 if k < m else 0)
    s4c = pystub(c, 1, this=True, stackmark=(0,), side=s4c_side)
    s5c = pystub(c, 1, this=True, stackmark=(0,), side=s5c_side, ret=lambda em, k: 0x2000 + k)
    kids = obj(c, 0x80, {0x4c: s4c, 0x5c: s5c})
    s230 = pystub(c, 1, this=True)
    pobj = obj(c, 0x240, {0x230: s230})
    sel = [r.random() < 0.7 for _ in range(4)]
    s58 = pystub(c, 1, this=True, ret=lambda em, k: pobj if sel[min(k, 3)] else 0)
    so = sysobj(c, table_slots={0x58: s58})

    def side84(em, k):
        p = em.arg32(1)
        for i in range(16):
            em.w32(p + 4 * i, _w(c))
    s84 = pystub(c, 2, this=True, stackmark=(1,), side=side84)
    sa0 = pystub(c, 2, this=True, deref={1: 16})
    h = obj(c, 0xb0, {0x84: s84, 0xa0: sa0})
    g = rnd(c, 0x40)
    e.w32(g + 0x18, h)
    e.w32(so + 0x1aa3, g)
    s238 = pystub(c, 0, this=True)
    s220 = pystub(c, 1, this=True)
    me = obj(c, 0x240, {0x238: s238, 0x220: s220})
    e.w32(me + 0x1c, kids if r.random() < 0.9 else 0)
    inner = rnd(c, 0x80)
    e.w32(me + 8, inner)
    return [me, _b(c.fv(-5, 5, 0.25))]


S(0x4e0030, 'GUESS angle between two vectors', 'fastcall', None, ret='st0', gen=_g4e0030, nan_heap=True, note='batch33117')
S(0x58aa40, 'GUESS write array of 48-byte records to stream', 'fastcall', None, ret='eax', gen=_g58aa40, note='batch33117')
S(0x449920, 'GUESS update children then store state via two slots', 'thiscall', None, ret=None, gen=_g449920, note='batch33117')
