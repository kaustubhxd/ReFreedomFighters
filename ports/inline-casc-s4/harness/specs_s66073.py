"""specs_s66073.py - cascade s4 batch 66073: 0x574280 (shut down a screen: hide its widgets and refresh)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g574280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x563750, 2, this=True)
    hook_rec(c, 0x562e90, 2, this=True)
    hook_rec(c, 0x5aa6e0, 0, this=True)
    hook_rec(c, 0x573d40, 0, this=True)
    hook_rec(c, 0x4f9680, 1, this=True)

    def mk():
        return obj(c, 0x40, {0xbc: pystub(c, 1, this=True)})
    objs = {}
    for k in (0x11, 0x12, 0x13, 0x14):
        objs[k] = obj(c, 0x300, {0x254: pystub(c, 0, this=True), 0x250: pystub(c, 0, this=True)})

    def find(em, rr):
        v = em.arg32(0)
        em.calllog.append(('tab.slot58', v))
        em.ret(objs[v], 4)
    sysobj(c, table_slots={0x58: e.stub_fn('find', find)})
    sub = e.alloc(0x700, 8)
    e.w32(sub + 0x676, 0x14)
    t = e.alloc(0x200, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x200)))
    e.w32(t + 0x4c, mk())
    e.w32(t + 0x50, mk())
    for off in (0x180, 0x184, 0x18c, 0x1c8):
        e.w32(t + off, 0 if r.random() < 0.4 else mk())
    e.w32(t + 0x1bc, 0x11)
    e.w32(t + 0x1c0, 0x12)
    e.w32(t + 0x1c4, 0x13)
    e.w32(t + 0x90, sub)
    cbuf = e.alloc(0x900, 8)
    e.wbytes(cbuf + 0x8cf, bytes([r.choice([0, 7])]))
    e.w32(t + 0xf8, cbuf)
    return [t, r.getrandbits(32), r.getrandbits(32)]


S(0x574280, 'GUESS shut down a screen hiding its widgets', 'thiscall', None, ret='al', gen=_g574280, note='batch66073')
