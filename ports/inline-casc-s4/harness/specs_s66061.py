"""specs_s66061.py - cascade s4 batch 66061: 0x502fe0 (resolve an id and three values of a call record, then forward a 16-bit handle)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g502fe0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    recs = []
    for _ in range(5):
        rec = e.alloc(0x10, 8)
        e.w32(rec, r.getrandbits(32))
        recs.append(rec)
    typ = r.choice([3, 4, 3, 4, 0, 1, 7])
    e.wbytes(recs[1] + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    if typ == 4:
        e.w32(recs[1], inner)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: recs[min(k, 4)])
    sysobj(c, table_slots={0x114: pystub(c, 5, this=True, deref={4: 3}, ret=lambda em, k: r.choice([0x12345678, 0xffff, 0x10000]))})
    w = obj(c, 0x30, {0x12c: pystub(c, 2, this=True)})
    t = rnd(c, 0x20)
    e.w32(t + 0xc, w)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 8))
    return [t, p]


S(0x502fe0, 'GUESS resolve an id and three values then forward a handle', 'thiscall', None, ret=None, gen=_g502fe0, note='batch66061')
