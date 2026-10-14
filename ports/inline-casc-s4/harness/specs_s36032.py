"""specs_s36032.py - cascade s4 batch 36032: 0x4e6a80 (quicksort with LCG pivot), 0x553d00 (look up a record by name and read its first entry)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, reftab


def _g4e6a80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([1, 2, 3, 5, 8, 16, 40])
    pool = r.choice([[0, 1, 2], [0, 0xffffffff, 0x80000000, 0x7fffffff, 5], list(range(100))])
    arr = e.alloc(4 * (n + 4), 4)
    for i in range(n + 4):
        e.w32(arr + 4 * i, r.choice(pool) if r.random() < 0.8 else r.getrandbits(32))
    e.w32(0x6e7b9c, r.getrandbits(32))
    e._image_dirty = True
    lo = r.randint(0, n - 1)
    hi = r.randint(lo, n - 1)
    if r.random() < 0.3:
        lo, hi = 0, n - 1
    return [arr, lo, hi]


def _g553d00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    ident = r.getrandbits(32)

    def getname(em, rr):
        name, out = em.arg32(0), em.arg32(1)
        em.calllog.append(('o.slot88', 0x88, em.reg('ecx'), (name,)))
        em.w32(out, ident)
        em.ret(0, 8)
    o = obj(c, 0x20, {0x88: e.stub_fn('getname', getname)})
    elems = [r.getrandbits(32) for _ in range(r.choice([0, 1, 2]))]
    lst = reftab(c, elems) if r.random() < 0.8 else 0
    rec = rnd(c, 0x20)
    inner = rnd(c, 0x20)
    e.w32(rec + 0x10, inner)
    e.w32(inner + 8, lst)
    found = rec if r.random() < 0.75 else 0

    def find(em, rr):
        em.calllog.append(('tab.slot58', 0x58, em.reg('ecx'), (em.arg32(0) == ident,)))
        em.ret(found, 4)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x58: e.stub_fn('find', find)})
    g = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    e.w32(0x70038c, g)
    e._image_dirty = True
    s = rnd(c, 0x20)
    return [s]


S(0x4e6a80, 'GUESS quicksort u32 with LCG pivot', 'fastcall', None, ret=None, gen=_g4e6a80, note='batch36032')
S(0x553d00, 'GUESS look up a record and read its first entry', 'thiscall', None, ret='eax', gen=_g553d00, note='batch36032')
