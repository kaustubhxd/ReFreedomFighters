"""specs_s66016.py - cascade s4 batch 66016: 0x509c20 (broadcast a resolved id to every entry of a list)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, reftab


def _g509c20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    typ = r.choice([3, 4, 3, 4, 0, 1, 5, 0xff])
    rec = rnd(c, 0x10)
    e.wbytes(rec + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec, inner if typ == 4 else r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, this=True, ret=rec)
    n = r.choice([0, 0, 1, 2, 4])
    lst = reftab(c, [rnd(c, 8) for _ in range(n)]) if r.random() < 0.85 else 0
    w = obj(c, 0x30, {0x12c: pystub(c, 3, this=True)})
    e.w32(w + 0x18, lst)
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: r.choice([0x12345678, 0xffff, 0x10000, 0x7fff8001]))})
    s = rnd(c, 0x20)
    e.w32(s + 0xc, w)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [s, p]


S(0x509c20, 'GUESS broadcast a resolved id to every list entry', 'thiscall', None, ret=None, gen=_g509c20, note='batch66016')
