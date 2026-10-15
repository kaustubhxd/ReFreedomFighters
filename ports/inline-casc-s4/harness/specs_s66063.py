"""specs_s66063.py - cascade s4 batch 66063: 0x555430 (link two resolved objects)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g555430(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    ia, ib = 0x111, 0x222
    recs = []
    for v in (ia, ib):
        rec = e.alloc(0x10, 8)
        e.w32(rec, v)
        e.wbytes(rec + 4, bytes([r.choice([0, 1, 0, 1, 2, 5])]))
        recs.append(rec)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: recs[min(k, 1)])
    A = obj(c, 0x40, {0x3dc: pystub(c, 0, this=True)})
    B = obj(c, 0x40, {0x4dc: pystub(c, 2, this=True)})
    C = rnd(c, 8)
    mp = {ia: [A, B], ib: [C]}
    cnt = {}

    def find(em, rr):
        v = em.arg32(0)
        k = cnt.get(v, 0)
        cnt[v] = k + 1
        em.calllog.append(('tab.slot58', v, k))
        lst = mp[v]
        em.ret(lst[min(k, len(lst) - 1)], 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 8))
    return [p]


S(0x555430, 'GUESS link two resolved objects', 'stdcall', None, ret=None, gen=_g555430, note='batch66063')
