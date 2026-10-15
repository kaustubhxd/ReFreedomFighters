"""specs_s66028.py - cascade s4 batch 66028: 0x50c360 (bind a resolved object's handle to a script slot)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g50c360(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def pr(em, rr):
        f = em.arg32(1)
        em.calllog.append(('print', f, em.arg32(2) if f == 0x69d650 else 0))
        em.ret(eax=0, argbytes=0)
    lo = obj(c, 0x20, {0x2c: e.stub_fn('print', pr)})
    lg = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=lo)})
    e.w32(0x700390, lg)
    s = obj(c, 0x40, {0x30: pystub(c, 1, this=True), 0x24: pystub(c, 0, this=True, ret=r.getrandbits(32)),
                      0x28: pystub(c, 0, this=True, ret=r.getrandbits(32))})
    m = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=s)})
    q = rnd(c, 8)
    ob = obj(c, 0x30, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x101])), 0x2e8: pystub(c, 0, this=True, ret=q)})
    oid = r.getrandbits(32) | 1
    rec1 = rnd(c, 8)
    e.w32(rec1, oid)
    tag = r.choice([0, 4, 4, 1, 7])
    rec2 = rnd(c, 8)
    e.wbytes(rec2 + 4, bytes([tag]))
    inner = obj(c, 0x30, {0x28: pystub(c, 0, this=True)})
    e.w32(rec2, inner if tag == 4 else r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: rec1 if k == 0 else rec2)

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(ob if (v == oid and found[0]) else 0, 4)
    found = [r.random() < 0.8]
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    p = rnd(c, 0x20)
    e.w32(p + 4, rnd(c, 8))
    e.w32(p + 8, rnd(c, 8))
    e.w32(p + 0xc, m)
    return [p]


S(0x50c360, 'GUESS bind a resolved object handle to a script slot', 'stdcall', None, ret='eax', gen=_g50c360, note='batch66028')
