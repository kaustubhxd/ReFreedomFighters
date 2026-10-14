"""specs_s36055.py - cascade s4 batch 36055: 0x4c7bb0 (look up a linked object and notify it)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g4c7bb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    xid = r.getrandbits(32) | 1
    x = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 1, 0x100])), 0x130: pystub(c, 2, this=True)})
    b3 = r.choice([0, xid, xid, 0x5555])

    def s28c(em, rr):
        em.calllog.append(('s28c', em.reg('ecx'), em.arg32(1), em.arg32(2), em.arg32(3)))
        em.w32(em.arg32(0) + 12, b3)
        em.ret(0, 16)
    oid = r.getrandbits(32) | 1
    o = obj(c, 0x20, {0x28c: e.stub_fn('s28c', s28c)})
    objs = {}
    if r.random() < 0.85:
        objs[oid] = o
    if r.random() < 0.5:
        objs[0] = o
    if r.random() < 0.9:
        objs[xid] = x

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    so = sysobj(c, table_slots={0x58: e.stub_fn('find', find),
                                0x114: pystub(c, 5, this=True, deref={4: 1}, ret=lambda em, k: 0x12345678 * (k + 1) & 0xffffffff)})
    mgr = obj(c, 0x20, {0xb4: pystub(c, 1, this=True, ret=oid if r.random() < 0.85 else 0)})
    e.w32(so + 0x190f, mgr)
    return []


S(0x4c7bb0, 'GUESS look up a linked object and notify it', 'cdecl', None, ret=None, gen=_g4c7bb0, note='batch36055')
