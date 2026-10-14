"""specs_s36067.py - cascade s4 batch 36067: 0x5d3520 (resolve four named objects, variant), 0x605010 (store a registry comparison result)."""
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


def _g5d3520(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = [0]

    def s88(em, rr):
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        cnt[0] += 1
        em.w32(em.arg32(1), 0x300 + cnt[0])
        em.ret(0, 8)
    o = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x58: pystub(c, 1, this=True, ret=lambda em, k: 0x7000 + 0x10 * k)})
    return [rnd(c, 0x80)]


def _g605010(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    _assert_hook(c)
    v = rnd(c, 0x20)
    rec0 = rnd(c, 0x10)
    e.w32(rec0, v)
    q = rnd(c, 0x10)
    e.wbytes(q + 4, bytes([r.choice([0, 1, 1, 2, 5, 0xff])]))
    recs = [rec0, q]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 1)])
    reg = obj(c, 0x20, {0x18: pystub(c, 2, this=True, ret=r.choice([0, 1, 0x100, 0x7]))})
    e.w32(0x724270, reg)
    e._image_dirty = True
    d = rnd(c, 0x20)
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    e.w32(p + 8, rnd(c, 0x10))
    return [d, p]


S(0x5d3520, 'GUESS resolve four named objects (variant)', 'thiscall', None, ret=None, gen=_g5d3520, note='batch36067')
S(0x605010, 'GUESS store a registry comparison result', 'thiscall', None, ret=None, gen=_g605010, note='batch36067')
