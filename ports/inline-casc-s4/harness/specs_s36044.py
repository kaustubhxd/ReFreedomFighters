"""specs_s36044.py - cascade s4 batch 36044: 0x4d8c30 (detach an object from a manager list), 0x502ad0 (typed value to a callback), 0x5b7ad0 (notify an object or its list)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab, logger


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g4d8c30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    key = rnd(c, 8)
    x = obj(c, 0x20, {4: pystub(c, 0, this=True, ret=key)})
    elems = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 3]))]
    if r.random() < 0.6 and elems:
        elems[r.randint(0, len(elems) - 1)] = x
        if r.random() < 0.5:
            elems.append(x)
    rtv = reftab(c, elems, count=r.choice([0, 0, 1, 3]))
    ob = obj(c, 0x20, {})
    e.w32(ob + 4, rtv)
    mgr = obj(c, 0x20, {0x84: pystub(c, 1, this=True, ret=ob if r.random() < 0.88 else 0), 0x90: pystub(c, 1, this=True)})
    s = rnd(c, 0x20)
    e.w32(s + 4, mgr)
    return [s, x]


def _g502ad0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    _assert_hook(c)
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec0 = rnd(c, 0x10)
    rec1 = rnd(c, 0x10)
    rec2 = rnd(c, 0x10)
    e.wbytes(rec1 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec1, inner if typ == 4 else r.getrandbits(32))
    recs = [rec0, rec1, rec2]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 2)])
    w = obj(c, 0x20, {0x134: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, deref={4: 1}, ret=lambda em, k: 0x12345678 * (k + 3) & 0xffffffff)})
    s = rnd(c, 0x20)
    e.w32(s + 0xc, w)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [s, p]


def _g5b7ad0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ids = [r.getrandbits(32) | 1 for _ in range(r.choice([0, 1, 2, 3]))]
    xs = {}
    for i in ids:
        xs[i] = obj(c, 0x20, {0x128: pystub(c, 3, this=True)})
    oid = r.getrandbits(32) | 1
    lst = 0 if r.random() < 0.15 else reftab(c, ids)
    o = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100])), 0x128: pystub(c, 3, this=True)})
    e.w32(o + 0x18, lst)
    objs = dict(xs)
    if r.random() < 0.9:
        objs[oid] = o

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    d = rnd(c, 0x60)
    e.w32(d + 0x4e, oid)
    return [d]


S(0x4d8c30, 'GUESS detach an object from a manager list', 'thiscall', None, ret=None, gen=_g4d8c30, note='batch36044')
S(0x502ad0, 'GUESS typed value to a callback', 'thiscall', None, ret=None, gen=_g502ad0, note='batch36044')
S(0x5b7ad0, 'GUESS notify an object or its list', 'thiscall', None, ret=None, gen=_g5b7ad0, note='batch36044')
