"""specs_s37010.py - cascade s6 batch 37010: 0x50cfd0. Hooked: 0x5003d0 (node by (owner, index): returns a node whose first dword is an id), 0x5002f0, table slot 0x58
(id -> object), logger at 0x700390 (slot 0x20 -> logger line object with cdecl slot 0x2c, recorded by argument count). Objects 0/1/2 carry the slots the function calls."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g50cfd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    A = rnd(c, 0x10)
    A1 = rnd(c, 0x10)
    A2 = rnd(c, 0x10)
    e.w32(A + 4, A1)
    e.w32(A + 8, A2)
    ids = [r.getrandbits(32) for _ in range(3)]
    nodes = {}
    for owner in (A1, A2):
        for i in range(3):
            n = rnd(c, 0x10)
            e.w32(n, ids[i] if owner == A1 else r.getrandbits(32))
            nodes[(owner, i)] = n
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[(em.reg('ecx'), em.arg32(0))])
    hook_rec(c, 0x5002f0, 1, this=True)
    # logger line object
    def lg(em, res_):
        ret_args = [em.arg32(i) for i in range(5 if em.arg32(1) == 0x69d9e0 else 2)]
        em.calllog.append(('log', tuple(ret_args)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    lgr = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)})
    e.w32(0x700390, lgr)

    def name_obj():
        R = rnd(c, 0x10)
        return R

    def slot20(Rr):
        def h(em, res_):
            k = em.calllog.count(('s20', Rr))
            if k == 0:
                em.calllog.append(('s20', Rr, em.reg('ecx')))
                em.calllog.append(('s20', Rr))
                em.ret(eax=Rr, argbytes=0)
            else:
                em.calllog.append(('s20b', Rr, em.reg('ecx'), em.arg32(0)))
                em.ret(eax=Rr, argbytes=4)
        return e.stub_fn('s20', h)
    # objects
    R0, R1, R2 = name_obj(), name_obj(), name_obj()
    O0 = obj(c, 0x10, {0x20: pystub(c, 0, this=True, ret=R0)}) if r.random() < 0.9 else 0
    # o1 slot 0x20: called with no argument first, then with one: a custom stub
    cnt = [0]

    def h1(em, res_):
        k = cnt[0]
        cnt[0] += 1
        if k == 0:
            em.calllog.append(('o1s20', em.reg('ecx')))
            em.ret(eax=R1, argbytes=0)
        else:
            em.calllog.append(('o1s20b', em.reg('ecx'), em.arg32(0)))
            em.ret(eax=R1, argbytes=4)
    O1 = obj(c, 0x10, {0x20: e.stub_fn('o1s20', h1)}) if r.random() < 0.9 else 0
    O2 = obj(c, 0x10, {0x2e8: pystub(c, 0, this=True, ret=R2),
                       0x2f0: pystub(c, 2, this=True)}) if r.random() < 0.85 else 0
    table = {ids[0]: O0, ids[1]: O1, ids[2]: O2}
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: table.get(em.arg32(0), 0))}, table_size=0x20)
    ent = 0
    if r.random() < 0.85:
        t2 = O2 if O2 else rnd(c, 0x10)
        ent = obj(c, 0x20, {0x504: pystub(c, 0, this=True, ret=(t2 if r.random() < 0.5 else 0x1234)),
                            0x500: pystub(c, 0, this=True, ret=(t2 if r.random() < 0.5 else 0x4321)),
                            0x54c: pystub(c, 2, this=True), 0x548: pystub(c, 2, this=True)})
    me = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, ret=ent)})
    return [me, A]


S(0x50cfd0, 'GUESS link objects by node ids', 'thiscall', None, ret=None, gen=_g50cfd0, note='batch37010')
