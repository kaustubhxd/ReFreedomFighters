"""specs_s36002.py - cascade s4 batch 36002: 0x49da90 (array compaction via engine slot 0xcc), 0x4a7f20 (read fields via stream slots 0x58/0x68), 0x4ceda0 (find by name with _stricmp, log if missing)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger


def _g49da90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([0, 1, 2, 5, r.randint(0, 10)])
    me = rnd(c, 0x40)
    arr = rnd(c, 0x40)
    e.w32(me + 4, arr)
    e.w32(me + 0x10, n)
    objs = []
    for i in range(n):
        if r.random() < 0.2:
            objs.append(0)
        else:
            o = rnd(c, 0x50)
            f18 = o_f18 = r.getrandbits(8) & ~0x10 if r.random() < 0.5 else r.getrandbits(8) | 0x10
            e.wbytes(o + 0x18, bytes([f18]))
            f3c = r.getrandbits(32) | (0x10 if r.random() < 0.5 else 0)
            e.w32(o + 0x3c, f3c)
            objs.append(o)
    eng = obj(c, 0x40, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, len(objs) - 1)]),
                        0x30: pystub(c, 3, this=True)})
    e.w32(0x70038c, eng)
    return [me]


def _g4a7f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    hook_rec(c, 0x4a7fb0, 1, this=True)

    def w4(em, k):
        em.w32(em.arg32(0), r.getrandbits(32))

    def w1(em, k):
        em.wbytes(em.arg32(0), bytes([r.getrandbits(8)]))
    s = obj(c, 0x20, {0x58: pystub(c, 1, this=True, side=w4), 0x68: pystub(c, 1, this=True, side=w1)})
    me = rnd(c, 0x90)
    return [me, s]


def _g4ceda0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 3)
    steps = r.randint(0, 4)
    found = r.choice([-1, -1, 0, 1, 2, 3])
    locs = [1 if i < steps or r.random() < 0.2 else 0 for i in range(8)]
    if steps:
        locs = [1] * steps + [0] * 8
    elif r.random() < 0.5:
        locs = [0] * 8
    rets = [r.getrandbits(32) for _ in range(9)]

    def side5c(em, k):
        em.w32(em.arg32(0), locs[min(k, len(locs) - 1)])

    def sidr(em, k):
        pass
    cmpn = [0]

    def sc(em, res):
        k = cmpn[0]
        cmpn[0] += 1
        em.calllog.append(('cmp', em.arg32(0), em.arg32(1)))
        em.ret(eax=(0 if k == found else r.choice([-1, 1])), argbytes=0)
    e.stub_import('_stricmp', sc)
    me = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, stackmark=(0,)),
                       0x5c: pystub(c, 1, this=True, ret=lambda em, k: rets[min(k, 8)], side=side5c, stackmark=(0,)),
                       0x44: pystub(c, 1, this=True, stackmark=(0,))})
    name = rnd(c, 0x10)
    return [0 if r.random() < 0.1 else me, name]


S(0x49da90, 'GUESS compact array dropping dead entries', 'thiscall', None, ret=None, gen=_g49da90, note='batch36002')
S(0x4a7f20, 'GUESS read fields from stream', 'thiscall', None, ret='al', gen=_g4a7f20, note='batch36002')
S(0x4ceda0, 'GUESS select entry by name, log if missing', 'thiscall', None, ret=None, gen=_g4ceda0, note='batch36002')
