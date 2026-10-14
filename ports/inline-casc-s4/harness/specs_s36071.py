"""specs_s36071.py - cascade s4 batch 36071: 0x502f00 (typed value pair to a callback), 0x498be0 (mark and write selected nodes to a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g502f00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec1 = rnd(c, 0x10)
    e.wbytes(rec1 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec1, inner if typ == 4 else r.getrandbits(32))
    recs = [rnd(c, 0x10), rec1, rnd(c, 0x10), rnd(c, 0x10)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 3)])
    w = obj(c, 0x20, {0x12c: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, deref={4: 2}, ret=lambda em, k: 0x12345678 * (k + 3) & 0xffffffff)})
    s = rnd(c, 0x20)
    e.w32(s + 0xc, w)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [s, p]


def _g498be0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pats = [bytes(r.choice([0, 0xff, 0x01, 0x80, 0x55, 0xaa, r.getrandbits(8)]) for _ in range(4)) for _ in range(4)]
    holder = {}
    hook_rec(c, 0x498f00, 2, this=True, ret=0, side=lambda em, k: em.wbytes(holder['b'], pats[(k + 1) % 4]) if k > 0 else None)
    ncols = r.choice([0, 1, 2, 3])
    base = e.alloc(0x380 * 3 + 0x80, 16)
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x380 * 3 + 0x80)))
    chains = []
    for i in range(ncols):
        for k in range(8):
            node = base + 0x380 * i + 0x70 * k
            fl = r.choice([0, 0, 0x4000000, 0x4000000 | 0x10])
            e.w32(node + 0x3c, fl)
            depth = r.choice([0, 0, 1, 2])
            nxt = 0
            for _ in range(depth):
                ch = rnd(c, 0x60)
                e.w32(ch + 0x50, nxt)
                nxt = ch
            e.w32(node + 0x50, nxt)
    bits_arr = e.alloc(8, 4)
    holder['b'] = bits_arr
    e.wbytes(bits_arr, bytes(r.choice([0, 0xff, 0x01, 0x80, 0x55, r.getrandbits(8)]) for _ in range(4)) + bytes(4))
    x = obj(c, 0x20, {8: pystub(c, 1, this=True), 0x10: pystub(c, 2, this=True, deref={0: 1})})
    a = rnd(c, 0x20)
    e.w32(a, x)
    e.w32(a + 8, bits_arr)
    e.w32(a + 0xc, ncols)
    Z = rnd(c, 0x20)
    e.w32(Z + 4, base)
    so = sysobj(c, table_size=0xb00)
    tab = e.r32(so + 0x9b)
    Y = rnd(c, 0x20)
    e.w32(tab + 0xadc, Y)
    s = rnd(c, 0x40)
    e.w32(s + 0x14, Z)
    return [s, a]


S(0x502f00, 'GUESS typed value pair to a callback (2)', 'thiscall', None, ret=None, gen=_g502f00, note='batch36071')
S(0x498be0, 'GUESS mark and write selected nodes to a stream', 'thiscall', None, ret=None, gen=_g498be0, note='batch36071')
