"""specs_s67569.py - cascade s6 batch 67569 (0x4ad3a0, thiscall(list) ret 4, no return value). The list (null sometimes) has slots 0x14 (0 args, bool), 0x4c (writes the first iterator) and 0x5c (returns the next
id, writes the following iterator; stack-marked); 0x4acf30 (hook) maps ids to objects (record at +8 with flags +0x3c, slots 0x158 / 0x2f0 / 0x2d0 / 0x2e8 / helper slot 0x300) or 0; this[0x44] has slot 0x548;
the table (sys[0x9b]) slot 0x4c is a custom 3-arg stub; 0x4dc630 (stdcall 2 args) is a hook."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4ad3a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def t4c(em, res_):
        em.calllog.append(('t4c', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0x9000 + len(em.calllog), argbytes=12)
    sysobj(c, table_slots={0x4c: e.stub_fn('recorder', t4c)})
    helpers = [obj(c, 0x20, {0x300: pystub(c, 0, this=True, ret=lambda em, k: r.choice([2, 2, 1, 0]))}) for _ in range(2)]
    objs = []
    for _ in range(3):
        rec = rnd(c, 0x60)
        _w(c, rec + 0x3c, r.choice([0, 0x400, 0x7ff, 0xffffffff, 0x3ff]))
        o = obj(c, 0x20, {0x158: pystub(c, 0, this=True), 0x2f0: pystub(c, 1, this=True), 0x2d0: pystub(c, 2, this=True),
                          0x2e8: pystub(c, 0, this=True, ret=lambda em, k: r.choice(helpers + [0]))})
        _w(c, o + 8, rec)
        objs.append(o)
    hook_rec(c, 0x4acf30, 1, this=True, ret=lambda em, k: r.choice(objs + [0]))
    hook_rec(c, 0x4dc630, 2)
    ids = [0x100 + i for i in range(r.choice([0, 1, 2, 3, 4]))]
    its = [1] * len(ids) + [0]

    def s4c(em, k):
        em.wbytes(em.arg32(0), its[0].to_bytes(4, 'little'))

    def s5c(em, k):
        em.wbytes(em.arg32(0), its[k + 1 if k + 1 < len(its) else len(its) - 1].to_bytes(4, 'little'))
    lst = obj(c, 0x20, {0x14: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 1, 1, 0x100])),
                        0x4c: pystub(c, 1, this=True, stackmark=(0,), side=s4c),
                        0x5c: pystub(c, 1, this=True, stackmark=(0,), side=s5c, ret=lambda em, k: ids[k] if k < len(ids) else 0)})
    t = rnd(c, 0x60)
    _w(c, t + 0x44, obj(c, 0x20, {0x548: pystub(c, 2, this=True)}))
    return [t, lst if r.random() < 0.92 else 0]


S(0x4ad3a0, 'GUESS activate_listed_objects', 'thiscall', None, ret=None, gen=_g4ad3a0, note='batch67569')
