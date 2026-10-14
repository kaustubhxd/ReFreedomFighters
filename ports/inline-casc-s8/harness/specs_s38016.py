"""specs_s38016.py - cascade s8 batch 38016: 0x50bd00. Table object (engine +0x9b): slot 0x138 returns a helper whose slot 0x88 (name, &id) writes a pool id into the out local; slot 0x58 maps the
pool ids to two resolver objects (or 0); slot 0x4c returns a random handle (0 sometimes); field +0xadc random. Resolver slot 0x25c returns an object (or 0) whose slot 0x2c4 returns a random tag.
0x5003d0 / 0x5002f0 / 0x506040 / 0x50d7b0 hooked (the last one records the dword its pointer argument refers to); the logger stream has a 2-arg printer for line 0xd9 and a 3-arg printer otherwise."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g50bd00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st2 = obj(c, 0x20, {0x2c: pystub(c, 2, pop=0)})
    st3 = obj(c, 0x20, {0x2c: pystub(c, 3, pop=0)})

    def lg(em, res_):
        line = em.arg32(1)
        em.calllog.append(('logger', em.reg('ecx') != 0, em.arg32(0), line))
        em.ret(eax=st2 if line == 0xd9 else st3, argbytes=8)
    e.w32(0x700390, obj(c, 0x40, {0x20: e.stub_fn('logger', lg)}))
    tagobj = rnd(c, 0x20)
    pool = r.sample(range(1, 50), 3)

    def mk():
        if r.random() < 0.2:
            return 0
        o3 = 0 if r.random() < 0.25 else obj(c, 0x20, {0x2c4: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))})
        return obj(c, 0x20, {0x25c: pystub(c, 1, this=True, ret=o3)})
    A, B = mk(), mk()
    idmap = {pool[0]: A, pool[1]: B, pool[2]: 0}

    def s88(em, res_):
        out = em.arg32(1)
        v = r.choice(pool + [r.randrange(60, 99)])
        em.calllog.append(('s88', em.reg('ecx'), em.arg32(0)))
        em.w32(out, v)
        em.ret(eax=0, argbytes=8)
    X = obj(c, 0x20, {0x88: e.stub_fn('s88', s88)})

    def s58(em, res_):
        a = em.arg32(0)
        em.calllog.append(('s58', em.reg('ecx'), a))
        em.ret(eax=idmap.get(a, 0), argbytes=4)
    so = sysobj(c, {}, table_slots={0x138: pystub(c, 0, this=True, ret=X), 0x58: e.stub_fn('s58', s58),
                                    0x4c: pystub(c, 1, this=True, ret=lambda em, k: 0 if r.random() < 0.25 else r.getrandbits(32))})
    tb = e.r32(so + 0x9b)
    e.w32(tb + 0xadc, r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=rnd(c, 0x20))
    hook_rec(c, 0x5002f0, 1, this=True, pop=4)
    hook_rec(c, 0x506040, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x50d7b0, 1, this=True, pop=4, deref={0: 1})
    req = rnd(c, 0x20)
    e.w32(req + 4, rnd(c, 0x20))
    e.w32(req + 8, rnd(c, 0x20))
    return [req]


S(0x50bd00, 'GUESS resolve object by named ids and register handle', 'stdcall', None, ret=None, gen=_g50bd00, note='batch38016')
