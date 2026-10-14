"""specs_s1203.py - pathfinding batch 1203: GetNearest visitor, Init, AddPoint."""
from pilot import S
from pfspec import rnd, hooks, reporter, RET


def _near(c):
    r = c.rng
    e = c.emu
    f = rnd(c, 0x24)
    for k in range(1, 7):
        e.w32(f + 4 * k, r.randint(-300, 300) if r.random() < 0.9 else r.getrandbits(32))
    e.wf32(f + 0x1c, c.fv(0, 400))
    e.wf32(f + 0x20, c.fv(0, 4))
    elem = rnd(c, 4)
    if r.random() < 0.2:
        e.w32(elem, 0)
    cc = rnd(c, 12)
    for k in range(3):
        e.w32(cc + 4 * k, r.randint(-300, 300) if r.random() < 0.9 else r.getrandbits(32))
    return [f, rnd(c, 0x40), elem, r.getrandbits(32), cc, rnd(c, 12), r.getrandbits(32), r.getrandbits(32)]


S(0x52d3f0, 'ZPFOctreeElementFuncGetNearest_packed::Apply', 'thiscall', None, ret='eax', gen=_near)


def _init(c):
    e = c.emu
    r = c.rng
    reporter(c)
    sizes = []

    def new(em, rr):
        n = em.arg32(0)
        sizes.append(n)
        em.calllog.append(('alloc', em.reg('ecx'), n))
        em.ret(eax=em.alloc(min(n, 0x200000), 16, 0x5a) if n < 0x200000 else 0, argbytes=4)
    alloc = e.alloc(16)
    e.w32(alloc, e.fake_vtable('allocator', 4, {8: new}))
    e.w32(0x70038c, alloc)
    o = rnd(c, 0xa0)
    k = r.random()
    n = r.randint(0, 40) if k < 0.7 else r.choice([0xffff, 0x10000, 0x7fffffff, -1, -5, 0x12345])
    return [o, n]


S(0x530fd0, 'ZPFOctree_packed::Init', 'thiscall', None, gen=_init, n=300)


def _addpt(c):
    e = c.emu
    r = c.rng
    lst = rnd(c, 0x20)
    cnt = r.randint(0, 6)
    e.w32(lst + 0xc, rnd(c, 16 * 8))
    e.w32(lst + 0x10, rnd(c, 4 * 8))
    e.w32(lst + 0x14, rnd(c, 4 * 8))
    n = rnd(c, 4)
    e.w32(n, cnt if r.random() < 0.8 else 0)
    ln = rnd(c, 4)
    e.wf32(ln, c.fv(0, 1000))
    prev = c.fbuf(3)
    p = c.fbuf(3)
    if r.random() < 0.1:
        p = prev
    return [rnd(c, 16), lst, n, ln, prev, p, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x52d1c0, 'ZPFOctree_packed::AddPoint', 'thiscall', None, gen=_addpt)
