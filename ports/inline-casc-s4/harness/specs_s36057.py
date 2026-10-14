"""specs_s36057.py - cascade s4 batch 36057: 0x50fa90 (typed value to a callback with a flag)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g50fa90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True
    typ = r.choice([3, 4, 3, 4, 0, 1, 0xff])
    rec1 = rnd(c, 0x10)
    e.w32(rec1, r.choice([0, 1, 0x100, r.getrandbits(32)]))
    rec0 = rnd(c, 0x10)
    e.wbytes(rec0 + 4, bytes([typ]))
    inner = obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    e.w32(rec0, inner if typ == 4 else r.getrandbits(32))
    recs = [rec1, rec0]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k, _r=recs: _r[min(k, 1)])
    o = obj(c, 0x20, {0x68: pystub(c, 3, this=True)})
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o)})
    p = rnd(c, 0x10)
    e.w32(p + 4, rnd(c, 0x10))
    return [p]


S(0x50fa90, 'GUESS typed value to a callback with a flag', 'stdcall', None, ret=None, gen=_g50fa90, note='batch36057')
