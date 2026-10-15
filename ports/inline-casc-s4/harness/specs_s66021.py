"""specs_s66021.py - cascade s4 batch 66021: 0x5cbe30 (gather the objects of a list and a default into an array)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub, reftab


def _g5cbe30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    g = e.alloc(0x500, 8)
    n = r.choice([0, 1, 3, 8, 0x10, 0x11, 0x12])
    e.w32(g + 0x41c, n)
    for i in range(0x10):
        e.w32(g + 0x420 + 4 * i, r.getrandbits(32))
    e.w32(0x7003b8, g)
    ids = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 4]))]
    objs = {i: rnd(c, 8) for i in ids if r.random() < 0.7}
    dflt = r.getrandbits(32) | 1
    if r.random() < 0.7:
        objs[dflt] = rnd(c, 8)

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)
    lst = reftab(c, ids)
    s = obj(c, 0x30, {})
    e.w32(s + 0x18, lst if r.random() < 0.85 else 0)
    m = obj(c, 0x30, {0x25c: pystub(c, 2, this=True, ret=(s if r.random() < 0.9 else 0))})
    so = sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    tab = int.from_bytes(bytes(e.rbytes(so + 0x9b, 4)), 'little')
    e.w32(tab + 0xadc, m)
    t = e.alloc(0x7c0, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x7c0)))
    e.w32(t + 0x368, dflt)
    return [t]


S(0x5cbe30, 'GUESS gather list objects and a default into an array', 'thiscall', None, ret=None, gen=_g5cbe30, note='batch66021')
