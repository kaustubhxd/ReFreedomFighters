"""specs_s34138.py - 0x555350 (stdcall p): hooked 0x5003d0 (returns a cell, the second call a pointer), 0x5002f0 (returns random); table [0x70039c]+0x9b slot 0x58 returns an object (slots 0x1e0, 0x64c) or 0; logger 0x700390 slot 0x20 returns a printer whose slot 0x30 is a cdecl recorder.
0x569f80: hooked 0x562260 and 0x56ac30 (plain ret); state +0x1c5 in {5, 1, 6, other}; slots 0x84 (returns obj with 0x2fc), 0xd8 (low byte random), 0xd0; +0x1c9 object (slot 0x20) or 0; [0x70039c]+0x1907 object (slot 0x14) or 0.
0x574bc0: as 0x5f0380 plus hooked 0x589c20 / 0x59a5b0 and a data pointer at 0x7003b8."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _g555350(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cell = rnd(c, 0x10)
    cell2 = rnd(c, 0x10)
    seq = [cell, cell2]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: seq[min(k, 1)])
    hook_rec(c, 0x5002f0, 1, this=True, ret=r.getrandbits(32))
    s = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101])),
                      0x64c: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0xff, 0x1ff, r.getrandbits(32)]))}, nslots=0x650 // 4)
    sel = r.choice([0, s, s, s])
    tbl = obj(c, 0x20, {0x58: pystub(c, 1, this=True, ret=sel)}, nslots=0x5c // 4)
    so = rnd(c, 0xa0)
    e.w32(so + 0x9b, tbl)
    e.w32(0x70039c, so)
    pr = obj(c, 0x20, {0x30: pystub(c, 2, pop=0)}, nslots=0x34 // 4)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=pr, this=True)}, nslots=0x24 // 4)
    e.w32(0x700390, lg)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [p]


def _g569f80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x562260, 0, this=True, pop=0)
    hook_rec(c, 0x56ac30, 0, this=True, pop=0)
    o = obj(c, 0x20, {0x2fc: pystub(c, 1, this=True)}, nslots=0x300 // 4)
    p = obj(c, 0x20, {0x20: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))}, nslots=0x24 // 4)
    q = r.choice([0, obj(c, 0x20, {0x14: pystub(c, 1, this=True)}, nslots=0x18 // 4)])
    so = rnd(c, 0x1920)
    e.w32(0x70039c, so)
    e.wbytes(so + 0x1907, q.to_bytes(4, 'little'))
    me = obj(c, 0x200, {0x84: pystub(c, 0, ret=o, this=True), 0xd8: pystub(c, 0, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]), this=True),
                        0xd0: pystub(c, 1, this=True)}, nslots=0xdc // 4)
    st = r.choice([5, 5, 1, 1, 6, 6, 0, 2, r.getrandbits(32)])
    e.wbytes(me + 0x1c5, st.to_bytes(4, 'little'))
    e.wbytes(me + 0x1c9, r.choice([0, p, p]).to_bytes(4, 'little'))
    return [me]


def _g574bc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x589c20, 1, this=True, ret=rnd(c, 0x10))
    hook_rec(c, 0x59a5b0, 3, this=True)
    e.w32(0x7003b8, rnd(c, 0x10))

    def w4(em, k):
        em.w32(em.arg32(1), r.getrandbits(32))
    x = obj(c, 0x20, {0x88: pystub(c, 2, this=True, side=w4, deref={1: 1})}, nslots=0x8c // 4)
    tbl = obj(c, 0x20, {0x138: pystub(c, 0, ret=x, this=True),
                        0x114: pystub(c, 5, ret=lambda em, k: r.choice([0, 1, 0x12345, 0xabcd0000 | r.getrandbits(16)]), this=True)}, nslots=0x118 // 4)
    so = rnd(c, 0xa0)
    e.w32(so + 0x9b, tbl)
    e.w32(0x70039c, so)
    tgt = obj(c, 0x20, {0x12c: pystub(c, 2, this=True)}, nslots=0x130 // 4)
    me = rnd(c, 0x60)
    e.w32(me + 0x44, tgt)
    return [me]


S(0x555350, 'GUESS look up and toggle', 'stdcall', None, ret='eax', gen=_g555350, note='batch34138')
S(0x569f80, 'GUESS per-frame state step', 'thiscall', None, ret=None, gen=_g569f80, note='batch34138')
S(0x574bc0, 'GUESS query engine values and apply them D', 'thiscall', None, ret=None, gen=_g574bc0, note='batch34138')
