"""specs_s37017.py - cascade s6 batch 37017: 0x50cbc0 (stdcall(a)). Hooked: 0x5003d0 (node by (owner, index)), 0x5002f0, 0x4db2f0 (returns an object with slot 0x288);
table slot 0x58 by id; object slots 0x1e0/0x2f4/0x80/0x7c/0x2f0, name object slot 0x20; logger line object with cdecl slot 0x2c recorded by its argument count."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g50cbc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    A = rnd(c, 0x10)
    A1 = rnd(c, 0x10)
    A2 = rnd(c, 0x10)
    e.w32(A + 4, A1)
    e.w32(A + 8, A2)
    id0, id1 = r.randint(1, 0xffff), r.randint(1, 0xffff)
    nodes = {}
    for owner in (A1, A2):
        for i in range(2):
            n = rnd(c, 0x10)
            nodes[(owner, i)] = n
    e.w32(nodes[(A1, 0)], id0 if r.random() < 0.5 else 0)
    e.w32(nodes[(A1, 1)], id1)
    node0 = nodes[(A1, 0)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[(em.reg('ecx'), em.arg32(0))])
    hook_rec(c, 0x5002f0, 1, this=True)
    Own = obj(c, 0x20, {0x288: pystub(c, 3, this=True)})
    hook_rec(c, 0x4db2f0, 1, this=True, ret=Own)

    def lg(em, res_):
        n = {0x69d728: 2, 0x69d5fc: 3}.get(em.arg32(1), 2)
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(n))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    R = rnd(c, 0x10)
    ebx = rnd(c, 0x20) if r.random() < 0.7 else 0
    e.w32(ebx + 8 if ebx else 0x0, e.r32(ebx + 8)) if ebx else None
    O = obj(c, 0x300, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x1ff])),
                       0x2f4: pystub(c, 0, this=True, ret=ebx),
                       0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=lambda em, k: [em.w32(em.arg32(0), 7), em.w32(em.arg32(1), 9)]),
                       0x7c: pystub(c, 2, this=True, nullflag=(0, 1)),
                       0x2f0: pystub(c, 3, this=True)})
    e.w32(O + 4, r.getrandbits(32))
    N = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=R)}) if r.random() < 0.8 else 0
    table = {id1: O if r.random() < 0.85 else 0, id0: N}
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: table.get(em.arg32(0), 0))}, table_size=0x20)
    return [A]


S(0x50cbc0, 'GUESS command handler for node ids', 'stdcall', None, ret=None, gen=_g50cbc0, note='batch37017')
