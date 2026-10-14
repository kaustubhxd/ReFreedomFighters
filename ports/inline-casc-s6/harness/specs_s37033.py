"""specs_s37033.py - cascade s6 batch 37033: 0x47f8d0. Engine object at 0x70038c (slot 0x20 known-pointer test, slot 0xac, range callback at +8 with bounds +0xc/+0x10),
lookup object [[0x70039c]+0x9b]+8 (slot 8, 4 args) returning a record whose +0x54 is the target object (slots 0x214, 0x74); this has slots 0x20 and 0; hooks:
0x610100, 0x4e1b30, 0x4db2c0, 0x4dcdf0, 0x4dc630."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g47f8d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    hook_rec(c, 0x610100, 1, pop=4)
    hook_rec(c, 0x4e1b30, 0, this=True)
    hook_rec(c, 0x4db2c0, 2, this=True, nullflag=(0, 1), pop=8)
    hook_rec(c, 0x4dcdf0, 1, this=True)
    hook_rec(c, 0x4dc630, 2, this=True)
    # target object (esi after lookup)
    tgt = obj(c, 0x80, {0x214: pystub(c, 1, this=True), 0x74: pystub(c, 2, this=True, nullflag=(0, 1))})
    e.w32(tgt + 8, rnd(c, 0x20))
    rec = rnd(c, 0x60)
    e.w32(rec + 0x54, tgt)
    so = sysobj(c, table_size=0x20)
    tab = e.r32(so + 0x9b)
    look = obj(c, 0x20, {0x8: pystub(c, 4, this=True, ret=rec)})
    e.w32(tab + 8, look)
    # this
    O = obj(c, 0x20, {0x288: pystub(c, 3, this=True)})
    me_base = rnd(c, 0x90)
    me = me_base + 8
    e.w32(me - 4, r.choice([0, 0, 0x77, r.getrandbits(32)]))
    e.w32(tgt - 4 if False else me - 4, e.r32(me - 4))
    vt = e.alloc(0x40, 4)
    e.w32(vt, pystub(c, 0, this=True))
    e.w32(vt + 0x20, pystub(c, 0, this=True, ret=O))
    e.w32(me, vt)
    M = rnd(c, 0x80)
    e.w32(me + 8, M)
    e.w32(me + 4, r.choice([0, rnd(c, 0x10)]))
    # engine allocator object
    def rangeobj(P, which):
        return P

    def make_eng():
        known = {me: r.random() < 0.3, tgt: r.random() < 0.3}
        eng = obj(c, 0x30, {0x20: pystub(c, 1, this=True, ret=lambda em, k: 1 if known.get(em.arg32(0), False) else 0),
                           0xac: pystub(c, 1, this=True, side=lambda em, k: None)})
        if r.random() < 0.6:
            e.w32(eng + 8, pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 5, 0x1234])))
        else:
            e.w32(eng + 8, 0)
        lo = min(me, tgt) - r.choice([0x10, 0, 0x10000])
        hi = max(me, tgt) + 0x100 + r.choice([0, -0x100000])
        if r.random() < 0.3:
            hi = r.choice([me, tgt])
            lo = min(me, tgt)
        e.w32(eng + 0xc, max(lo, 0))
        e.w32(eng + 0x10, max(hi, 0))
        return eng
    e.w32(tgt - 4, r.choice([0, 0, 0x55, r.getrandbits(32)]))
    e.w32(0x70038c, make_eng())
    a = rnd(c, 0x20)
    return [me, a]


S(0x47f8d0, 'GUESS bind entry to engine object', 'thiscall', None, ret=None, gen=_g47f8d0, note='batch37033')
