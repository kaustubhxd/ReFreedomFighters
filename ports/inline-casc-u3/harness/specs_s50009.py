"""specs_s50009.py - u3 (Sonnet) batch 50009, tier H. 0x52e670: bounds A (this+6) / B (this+0x12) and grid sizes (this+0x3c/+0x40/+0x44) at unaligned offsets; point p inside, near and far outside the box;
0x43e920 runs as exe code; 0x530e80 hooked (records this, both pointers' contents via deref / marker, the two truncated shorts and the float; writes three result words that equal the input cell words
with probability, and returns 0 / 1 / random). Points p are random-filled blocks so the in-place rewrite and the 'same cell' corrections are observable."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _fb(v):
    return struct.pack('<f', v)


def _g52e670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cell(em, k):
        outp = em.arg32(0)
        inp = em.arg32(1)
        words = [em.r32(inp) & 0xffff, em.r32(inp) >> 16, em.r32(inp + 4) & 0xffff]
        res = []
        for w in words:
            res.append(w if r.random() < 0.5 else r.choice([0, 1, 5, 0xffff, r.getrandbits(16)]))
        em.wbytes(outp, struct.pack('<HHH', *res))
    ret = lambda em, k: r.choice([0, 1, 1, 1, 2, 0x100, r.getrandbits(32)])
    hook_rec(c, 0x530e80, 5, this=True, pop=0x14, ret=ret, side=cell, stackmark=(0, 1), deref={1: -6})
    me = rnd(c, 0x60)
    A = [r.uniform(-50, 50) for _ in range(3)]
    ext = [r.choice([r.uniform(1, 100), r.uniform(0.1, 5), 0.0, -r.uniform(1, 10)]) for _ in range(3)]
    B = [A[i] + ext[i] for i in range(3)]
    for off, vals in ((6, A), (0x12, B)):
        for j, v in enumerate(vals):
            e.wbytes(me + off + 4 * j, _fb(v))
    dims = [r.choice([1, 2, 4, 8, 16, 32, 64, 100, r.randrange(1, 300), 0, -3]) for _ in range(3)]
    for off, v in zip((0x3c, 0x40, 0x44), dims):
        e.w32(me + off, v & 0xffffffff)
    p = rnd(c, 0x20)
    for j in range(3):
        k = r.random()
        if k < 0.7:
            v = r.uniform(min(A[j], B[j]), max(A[j], B[j]) + 0.001)
        elif k < 0.9:
            v = r.uniform(-120, 120)
        elif k < 0.95:
            v = r.choice([x for x in EDGE_F if abs(x) < 1e30])
        else:
            v = A[j]
        e.wbytes(p + 4 * j, _fb(v))
    f = lambda: r.choice([r.uniform(-10, 10), r.uniform(0, 70000), 0.0, 65535.0, 65536.5, -1.0, r.uniform(-1e9, 1e9)])
    from pilot import F
    return [me, p, F(f()), F(f()), F(f())]


S(0x52e670, 'GUESS snap point to grid cell centre', 'thiscall', None, ret='al', gen=_g52e670, nan_heap=True, note='batch50009')
