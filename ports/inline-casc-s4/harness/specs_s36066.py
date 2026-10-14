"""specs_s36066.py - cascade s4 batch 36066: 0x50a940 (store a typed id's text into a value record), 0x5359f0 (check a record's linked lists against an object)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g50a940(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    _assert_hook(c)
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec0 = rnd(c, 0x10)
    e.wbytes(rec0 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec0, inner if typ == 4 else r.getrandbits(32))
    q = rnd(c, 0x10)
    e.wbytes(q + 4, bytes([r.choice([0, 1, 1, 2, 5, 0xff])]))
    recs = [rec0, q]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 1)])
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: 0x12345678 * (k + 3) & 0xffffffff)})
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [p]


def _g5359f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    N = 6
    d = e.alloc(0x10a7 + 8 * (N + 2), 4)
    e.wbytes(d, bytes(r.getrandbits(8) for _ in range(0x10a7 + 8 * (N + 2))))
    target = rnd(c, 0x20)
    objs = {}

    def chain():
        k = r.choice([0, 0, 1, 2, 3, 0x80000000])
        if k in (0, 0x80000000):
            return k
        idxs = r.sample(range(1, N + 1), r.randint(1, 3))
        for j, ix in enumerate(idxs):
            nxt = idxs[j + 1] if j + 1 < len(idxs) else 0x80000000
            ident = r.getrandbits(32) | 1
            e.w32(d + 0x10a7 + ix * 8, ident)
            e.w32(d + 0x10a7 + ix * 8 + 4, nxt)
            objs[ident] = target if r.random() < 0.25 else rnd(c, 0x10)
        return idxs[0]
    a = rnd(c, 0x40)
    e.w32(a + 0x30, chain())
    e.w32(a + 0x34, chain())

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    return [d, a, target]


S(0x50a940, "GUESS store a typed id's text into a value record", 'stdcall', None, ret=None, gen=_g50a940, note='batch36066')
S(0x5359f0, "GUESS check a record's linked lists against an object", 'thiscall', None, ret='al', gen=_g5359f0, note='batch36066')
