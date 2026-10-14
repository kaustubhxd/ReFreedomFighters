"""specs_s37109.py - cascade s6 batch 37109 (0x63f0e0, thiscall(ctx, elem) ret 8, returns node or 0). Node table at +0x68 (idx & 0xfff), pool at +0x220 (slots 8 / 0xc), this slots
0x84 / 0x90 / 0x94, element sub object (+0x54, slot 0xec) and the seven callees as hooks (0x63f090 returns a fresh 16-bit id, 0x63f220 a target block or 0); ctx+0x3c object slot 0x358
and the table object's slot 0x358 at +0xadc supply the key."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g63f0e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    nodes = [rnd(c, 0x40) for _ in range(6)]
    for n in nodes:
        e.wbytes(n + 5, bytes([r.choice([0, 1, 0, 0x80, 0x1e])]))
    tbl = e.alloc(0x4000, 4)
    e.wbytes(tbl, bytes(0x4000))
    used = [1, 2, 3, 0x7ff, 0xfff]
    for i in used:
        _w(c, tbl + 4 * i, r.choice(nodes))
    pool = obj(c, 0x20, {0x8: pystub(c, 0, this=True, ret=lambda em, k: r.choice(nodes + [0])), 0xc: pystub(c, 1, this=True)})
    tg = [rnd(c, 0x50) for _ in range(3)]
    hook_rec(c, 0x63e850, 1, this=True)
    hook_rec(c, 0x4dd8d0, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101]))
    hook_rec(c, 0x4db6c0, 2, this=True)
    hook_rec(c, 0x63f090, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x658d30, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 5]))
    hook_rec(c, 0x658fb0, 1, this=True)
    hook_rec(c, 0x63f220, 1, this=True, ret=lambda em, k: r.choice(tg + [0]))
    so = sysobj(c, table_size=0xb00)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    tabo = obj(c, 0x20, {0x358: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 7]))})
    _w(c, tab + 0xadc, tabo)
    this = obj(c, 0x240, {0x84: pystub(c, 1, this=True), 0x90: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100])),
                          0x94: pystub(c, 1, this=True)})
    _w(c, this + 0x68, tbl)
    _w(c, this + 0x220, pool)
    elem = rnd(c, 0x60)
    idv = r.choice([0, 0, 0, 1, 2, 3, 0x7ff, 0x1fff, 0xf001])
    _w(c, elem + 0x5a, idv, 2)
    if r.random() < 0.6:
        sub = obj(c, 0x20, {0xec: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))})
        _w(c, elem + 0x54, sub)
    else:
        _w(c, elem + 0x54, 0)
    _w(c, elem + 0x3c, r.choice([0, 0x40000000, 0xffffffff, 1]))
    if r.random() < 0.85:
        c2 = obj(c, 0x20, {0x358: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 3, 9]))})
        ctx = rnd(c, 0x50)
        _w(c, ctx + 0x3c, c2 if r.random() < 0.85 else 0)
    else:
        ctx = 0
    return [this, ctx, elem]


S(0x63f0e0, 'GUESS find_or_create_node', 'thiscall', None, ret='eax', gen=_g63f0e0, note='batch37109')
