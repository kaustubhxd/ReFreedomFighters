"""specs_s36053.py - cascade s4 batch 36053: 0x4b48c0 (find a selectable child), 0x4c61c0 (bind a model to a manager object)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g4b48c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    nn = r.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x70) for _ in range(nn)]
    for n in nodes:
        if r.random() < 0.15:
            e.w32(n + 0x54, 0)
            continue
        x = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k, _a=r.choice([0, 0, 1, 0x100]), _b=r.choice([0, 1, 1]): _a if k == 0 else _b)})
        y = rnd(c, 0x40)
        e.w32(y + 0x23, r.choice([0, 0x100000, 0x800000, 0x900000, 0x200002, 0x1, r.getrandbits(32)]))
        e.w32(x + 0xc, y)
        e.w32(n + 0x54, x)
    seq = nodes[1:] + [0]
    hook_rec(c, 0x4db520, 0, this=True, ret=lambda em, k, _s=seq: _s[min(k, len(_s) - 1)])
    p = obj(c, 0x80, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 1, 0x100]))})
    e.w32(p + 0x54, nodes[0] if nodes else 0)
    return [0 if r.random() < 0.1 else p]


def _g4c61c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4db500, 1, this=True, stackmark=(0,), side=lambda em, k: em.wbytes(em.arg32(0), bytes((i * 29 + 5) & 0xff for i in range(12))))
    o = obj(c, 0x20, {0x218: pystub(c, 1, this=True)})
    mg = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, ret=o if r.random() < 0.6 else 0),
                       0x294: pystub(c, 4, this=True, ret=o)})
    tobj = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)})
    so = sysobj(c, table_size=0xb00, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: 0x12345678 * (k + 1) & 0xffffffff),
                                                  0x58: pystub(c, 1, this=True, ret=tobj if r.random() < 0.7 else 0)})
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, mg)
    sub = rnd(c, 0x20)
    w = obj(c, 0x20, {0x70: pystub(c, 1, this=True, deref={0: 3}), 0xbc: pystub(c, 1, this=True)})
    e.w32(w + 8, sub)
    s = rnd(c, 0x60)
    e.w32(s + 0x44, w)
    return [s]


S(0x4b48c0, 'GUESS find a selectable child', 'stdcall', None, ret='eax', gen=_g4b48c0, note='batch36053')
S(0x4c61c0, 'GUESS bind a model to a manager object', 'thiscall', None, ret=None, gen=_g4c61c0, note='batch36053')
