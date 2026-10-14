"""specs_s36073.py - cascade s4 batch 36073: 0x50a770 (store a looked-up value into a value record), 0x50ae00 (send a typed id and value to an engine object)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _common(c, r):
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec0 = rnd(c, 0x10)
    e.wbytes(rec0 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec0, inner if typ == 4 else r.getrandbits(32))
    return rec0


def _g50a770(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec0 = _common(c, r)
    q = rnd(c, 0x10)
    e.wbytes(q + 4, bytes([r.choice([0, 1, 1, 2, 5, 0xff])]))
    recs = [rec0, q]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 1)])
    val = r.getrandbits(32)

    def s88(em, rr):
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        em.w32(em.arg32(1), val)
        em.ret(0, 8)
    o = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=o)})
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [p]


def _g50ae00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rec0 = _common(c, r)
    rec1 = rnd(c, 0x10)
    recs = [rec1, rec0]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 1)])
    o = obj(c, 0x20, {0x5c: pystub(c, 3, this=True)})
    sysobj(c, table_slots={0x134: pystub(c, 0, this=True, ret=o)})
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [p]


S(0x50a770, 'GUESS store a looked-up value into a value record', 'stdcall', None, ret=None, gen=_g50a770, note='batch36073')
S(0x50ae00, 'GUESS send a typed id and value to an engine object', 'stdcall', None, ret=None, gen=_g50ae00, note='batch36073')
