"""specs_s36001.py - cascade s4 batch 36001: 0x436260 (delete three child lists), 0x444fe0 (child update + parent walk), 0x4531e0 (read fields from a stream).
Slot stubs record this/args; 0x4dc630 and the stream readers are hooked recorders that write random values through their out pointers."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g436260(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x80)
    for off, mx in ((4, 2), (0x10, 3), (0x20, 16)):
        for i in range(mx):
            cell = me + off + 4 * i
            clr = r.random() < 0.3

            def side(em, k, cell=cell, clr=clr):
                if clr:
                    em.w32(cell, 0)
            o = obj(c, 0x10, {0: pystub(c, 1, this=True), 8: pystub(c, 0, this=True, side=side)})
            e.w32(cell, o)
    for off, mx in ((0xc, 2), (0x1c, 3), (0x60, 16)):
        e.w32(me + off, r.choice([0, 1, mx, r.randint(0, mx)]))
    return [me]


def _mkself(c, depth):
    r = c.rng
    e = c.emu
    nxt = _mkself(c, depth - 1) if depth > 0 and r.random() < 0.7 else 0
    o = obj(c, 0x100, {0x1e0: pystub(c, 1, this=True, ret=(1 if r.random() < 0.8 else 0)),
                       0x20: pystub(c, 0, this=True, ret=nxt)})
    e.w32(o + 0xa4, 0 if r.random() < 0.7 else r.getrandbits(32) | 1)
    return o


def _g444fe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc630, 2, this=True)
    me = _mkself(c, 3)
    # first object always carries the child at 0xa4 (or none)
    if r.random() < 0.85:
        p = obj(c, 0x20, {0x3c: pystub(c, 1, this=True), 0x14: pystub(c, 0, this=True, ret=(0 if r.random() < 0.75 else r.getrandbits(32))),
                          0: pystub(c, 1, this=True)})
        e.w32(me + 0xa4, p)
    else:
        e.w32(me + 0xa4, 0)
    prev = 0
    for i in range(r.choice([0, 1, 2, 3, 4])):
        node = rnd(c, 0x70)
        if r.random() < 0.8:
            blk = rnd(c, 0x40)
            fl = r.getrandbits(32) | (0x100000 if r.random() < 0.7 else 0)
            if r.random() < 0.3:
                fl &= ~0x100000
            e.wbytes(blk + 0x23, fl.to_bytes(4, 'little'))
            w = rnd(c, 0x20)
            e.w32(w + 0xc, blk)
            e.w32(node + 0x54, w)
        else:
            e.w32(node + 0x54, 0)
        e.w32(node + 0x3c, r.getrandbits(32) & (~0x400000 if r.random() < 0.6 else 0xffffffff))
        e.w32(node + 0x60, prev)
        prev = node
    e.w32(me + 0x50, prev)
    return [me, r.getrandbits(32)]


def _g4531e0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x610100, 1)
    hook_rec(c, 0x4e13c0, 2, this=True, nullflag=(0,))

    def dw(em, k):
        em.w32(em.arg32(0), 0 if r.random() < 0.4 else r.getrandbits(32))

    def blk(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
    hook_rec(c, 0x4e11e0, 2, this=True, nullflag=(0,), side=dw)
    hook_rec(c, 0x4e12f0, 2, this=True, side=blk)
    hook_rec(c, 0x4e12e0, 2, this=True, side=dw)
    hook_rec(c, 0x4e1b30, 0, this=True)
    hook_rec(c, 0x4dc630, 2, this=True)
    me = rnd(c, 0x80)
    s = rnd(c, 0x40)
    return [me, s]


S(0x436260, 'GUESS delete three child lists', 'thiscall', None, ret=None, gen=_g436260, note='batch36001')
S(0x444fe0, 'GUESS drop finished child, walk parents', 'thiscall', None, ret=None, gen=_g444fe0, note='batch36001')
S(0x4531e0, 'GUESS read flags and name from stream', 'thiscall', None, ret=None, gen=_g4531e0, note='batch36001')
