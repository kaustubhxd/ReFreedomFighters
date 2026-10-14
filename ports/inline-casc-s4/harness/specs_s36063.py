"""specs_s36063.py - cascade s4 batch 36063: 0x5ffa20 (read table entries from a stream recursively), 0x57ec10 (write an object's state to a stream)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab_vt


def _mk_this(c, depth, r):
    e = c.emu
    s = rnd(c, 0xa8)
    off = r.choice([0, 0, 4, 8])
    e.w32(s + 0x98, off)
    for fld in (0x84, 0x80):
        n = r.choice([0, 1, 2, 3])
        blk = e.alloc(4 + 6 * 4 + off + 8, 4)
        e.wbytes(blk, bytes([0x33]) * (4 + 6 * 4 + off + 8))
        e.w32(blk + off, n)
        for i in range(n):
            e.w32(blk + off + 4 + 6 * i, rnd(c, 0x40))
        e.w32(s + fld, blk)
    e.w32(s + 0x9c, _mk_this(c, depth + 1, r) if (depth < 1 and r.random() < 0.5) else 0)
    return s


def _g5ffa20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5fa1e0, 1, this=True, ret=lambda em, k: 0xb000 + k)
    cnt = [0]

    def s5c(em, rr):
        cnt[0] += 1
        em.calllog.append(('s5c', em.reg('ecx'), cnt[0]))
        em.w32(em.arg32(0), 0x100 + cnt[0] * 5)
        em.ret(0, 4)
    a = obj(c, 0x20, {0x5c: e.stub_fn('s5c', s5c)})
    b = rnd(c, 0xb0)
    e.w32(b + 0x9e, r.choice([0, 4, 8, 0x10]))
    cc = rnd(c, 0x10)
    s = _mk_this(c, 0, r)
    return [s, a, b, cc]


def _g57ec10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x563490, 1, this=True, ret=r.choice([0, 1, 1, 1, 0x100]))
    hook_rec(c, 0x57ebb0, 1, this=True)
    sv = obj(c, 0x20, {0x6c: pystub(c, 1, this=True), 0x3c: pystub(c, 1, this=True)})
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: 0x2100 + k)})
    ids = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3]))]
    objs = {i: rnd(c, 0x20) for i in ids}

    def cc(em, rr):
        em.calllog.append(('slot0xcc', em.arg32(0)))
        em.ret(objs[em.arg32(0)], 4)
    g = obj(c, 0x20, {0xcc: e.stub_fn('cc', cc)})
    e.w32(0x70038c, g)
    e._image_dirty = True
    d = rnd(c, 0x330)
    e.w32(d + 0x23c, reftab_vt(c, ids))
    e.w32(d + 0x310, r.getrandbits(32))
    e.w32(d + 0x314, r.getrandbits(32))
    return [d, sv]


S(0x5ffa20, 'GUESS read table entries from a stream recursively', 'thiscall', None, ret=None, gen=_g5ffa20, note='batch36063')
S(0x57ec10, "GUESS write an object's state to a stream", 'thiscall', None, ret='al', gen=_g57ec10, note='batch36063')
