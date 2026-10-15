"""specs_s66024.py - cascade s4 batch 66024: 0x471540 (notify every entry of a list whose key matches a stream key)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab


def _g471540(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    key = r.choice([1, 2, 3])

    def wkey(em, rr):
        em.calllog.append(('key', em.arg32(0)))
        em.w32(em.arg32(1), key)
        em.ret(eax=0, argbytes=8)
    a = obj(c, 0x20, {0x88: e.stub_fn('key', wkey)})
    hook_rec(c, 0x4dc630, 2, this=True)
    objs = {}

    def mkobj():
        n = obj(c, 0x30, {0x5c: pystub(c, 3, this=True)}) if r.random() < 0.7 else 0
        ctx = e.alloc(0x60, 8)
        e.w32(ctx + 0x3c, r.getrandbits(32))
        o = obj(c, 0x20, {0x100: pystub(c, 1, this=True, ret=n)})
        e.w32(o + 8, ctx)
        return o
    elems = []
    for i in range(r.choice([0, 1, 2, 4])):
        rec = e.alloc(0x10, 4)
        e.w32(rec, r.choice([1, 2, 3, key]))
        idv = 0x100 + i
        e.w32(rec + 4, idv)
        if r.random() < 0.8:
            objs[idv] = mkobj()
        elems.append(rec)
    lst = reftab(c, elems) if r.random() < 0.9 else 0

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    t = e.alloc(0x90, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x90)))
    e.w32(t + 0x70, lst)
    return [t, a]


S(0x471540, 'GUESS notify list entries matching a stream key', 'thiscall', None, ret=None, gen=_g471540, note='batch66024')
