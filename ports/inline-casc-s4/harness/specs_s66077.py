"""specs_s66077.py - cascade s4 batch 66077: 0x590140 (switch the active controller of a screen)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _g590140(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cobj = obj(c, 0x30, {0x308: pystub(c, 0, this=True, ret=r.choice([0, 1, 1, 2]))})
    X = obj(c, 0x40, {0x2d0: pystub(c, 2, this=True), 0x2e8: pystub(c, 0, this=True, ret=cobj)})
    A = obj(c, 0x40, {})
    B = obj(c, 0x40, {})
    aid, bid = 0x901, 0x902
    pickA = r.choice(['A', 'A', 'X', 'none', 'B'])
    objs = {aid: {'A': A, 'X': X, 'none': 0, 'B': B}[pickA], bid: B}
    xr = r.choice([X, X, 0])

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs.get(v, 0), 4)

    def mk4c(em, rr):
        em.calllog.append(('tab.slot4c', em.arg32(0)))
        em.ret(eax=(em.arg32(0) * 5 + 3) & 0xffffffff, argbytes=4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find), 0x4c: e.stub_fn('mk4c', mk4c)})
    t = obj(c, 0x900, {0x504: pystub(c, 0, this=True, ret=xr), 0x45c: pystub(c, 2, this=True),
                       0x3ec: pystub(c, 1, this=True, ret=lambda em, k: 0x40 + k), 0x3d8: pystub(c, 1, this=True)})
    e.w32(t + 0x842, bid)
    return [t, aid]


S(0x590140, 'GUESS switch the active controller of a screen', 'thiscall', None, ret=None, gen=_g590140, note='batch66077')
