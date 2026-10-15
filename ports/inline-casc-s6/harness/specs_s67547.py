"""specs_s67547.py - cascade s6 batch 67547 (0x551fb0, stdcall(req) ret 4, return value unused). 0x5003d0 (hook) returns the id node, then the count node (byte +4 0 / 1 / other). The object
table slot 0x58 maps the first id to an object (or 0, then child ids to child objects whose slots 0x1e0 / 0x438 are bool recorders); the object's list obj[0x18] (sometimes 0) has slot 0x4c (writes the
first iterator value) and slot 0x5c (returns an id, writes the next iterator value; stack-marked pointer); logger at 0x700390; assert hook set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g551fb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg2c(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    x = obj(c, 0x20, {0x2c: e.stub_fn('recorder', lg2c)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=x)}))
    kids = [obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100])),
                          0x438: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100]))}) for _ in range(3)]
    its = [r.choice([1, 2, 3]) for _ in range(r.choice([0, 1, 2, 3, 4]))] + [0]

    def s4c(em, k):
        em.wbytes(em.arg32(0), its[0].to_bytes(4, 'little'))

    def s5c(em, k):
        em.wbytes(em.arg32(0), (its[k + 1] if k + 1 < len(its) else 0).to_bytes(4, 'little'))
    lst = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,), side=s4c),
                        0x5c: pystub(c, 1, this=True, stackmark=(0,), side=s5c, ret=lambda em, k: 0x100 + k)})
    o = rnd(c, 0x40)
    vt = obj(c, 0x40, {})
    e.wbytes(o + 0x18, (lst if r.random() < 0.85 else 0).to_bytes(4, 'little'))
    calls = {'n': 0}

    def t58(em, k):
        return None
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: (r.choice([o, o, o, 0]) if k == 0 else kids[k % 3]))})
    n1 = rnd(c, 0x10)
    n2 = rnd(c, 0x10)
    e.wbytes(n2 + 4, bytes([r.choice([0, 1, 1, 2, 0x80])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: [n1, n2][min(k, 1)])
    return [rnd(c, 0x20)]


S(0x551fb0, 'GUESS count_child_objects', 'stdcall', None, ret=None, gen=_g551fb0, note='batch67547')
