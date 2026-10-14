"""specs_s36076.py - cascade s4 batch 36076: 0x56cb20 (read nine values and resolve five objects), 0x5d3d90 (resolve named ids and one object)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g56cb20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x610100, 1)
    vals = [r.getrandbits(32) | 1 for _ in range(9)]
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k, _v=vals: _v[min(k, 8)])
    ids = {v: rnd(c, 0x10) for v in vals if r.random() < 0.7}

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(ids.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    w = obj(c, 0x20, {0xbc: pystub(c, 1, this=True)})
    s = rnd(c, 0x1b0)
    e.w32(s + 0x44, w)
    return [s, rnd(c, 0x10)]


def _g5d3d90(c):
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
    objs = {0x300 + k: rnd(c, 0x10) for k in range(1, 6) if r.random() < 0.7}

    def find(em, rr):
        em.calllog.append(('tab.slot58', em.arg32(0)))
        em.ret(objs.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x58: e.stub_fn('find', find)})
    return [rnd(c, 0x90)]


S(0x56cb20, 'GUESS read nine values and resolve five objects', 'thiscall', None, ret=None, gen=_g56cb20, note='batch36076')
S(0x5d3d90, 'GUESS resolve named ids and one object', 'thiscall', None, ret=None, gen=_g5d3d90, note='batch36076')
