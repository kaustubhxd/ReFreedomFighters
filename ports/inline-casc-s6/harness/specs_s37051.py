"""specs_s37051.py - cascade s6 batch 37051 (0x43fc30). Nine callees hooked (0x4daf20 runs as original code on spec tags); tag chains o+0x54 -> +0xc -> +0x23; table slots 0x178 / 0x50,
manager [table+8] slot 0x3c; this slots 0x280 / 0x26c; this+8 flags select the 0x4dc1a0 path."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

TAGS = [0x4000022, 0x200015, 0x20001c, 0x20001c, 0x200012, 0x100000, 0x800000, 0x0, 0x200002, 0x400000]


def _g43fc30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    blocks = [rnd(c, 0x80) for _ in range(3)]
    helper1 = obj(c, 0x20, {0x2f4: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0
    helper2 = obj(c, 0x20, {0x2fc: pystub(c, 1, this=True)}) if r.random() < 0.7 else 0
    hook_rec(c, 0x4da770, 1, this=True, pop=4)
    hook_rec(c, 0x4da720, 1, this=True, pop=4)
    hook_rec(c, 0x4dae60, 0, this=True)
    hook_rec(c, 0x4dc1a0, 0, this=True)
    hook_rec(c, 0x4daff0, 0, this=True, ret=helper1)
    hook_rec(c, 0x4db7e0, 0, this=True, ret=helper2)
    hook_rec(c, 0x4db520, 0, this=True, ret=lambda em, k: 0 if r.random() < 0.35 else blocks[k % 3])
    hook_rec(c, 0x4dcda0, 1, this=True, pop=4, side=lambda em, k: em.calllog.append(('o60', em.r32(em.reg('ecx') + 0x60))))
    hook_rec(c, 0x4dcd00, 1, this=True, pop=4)

    def mktag(tag):
        T = rnd(c, 0x40)
        e.w32(T + 0x23, tag)
        X = rnd(c, 0x20)
        e.w32(X + 0xc, T)
        return X
    mgr = obj(c, 0x20, {0x3c: pystub(c, 3, this=True, ret=lambda em, k: r.getrandbits(32))})
    so = sysobj(c, table_slots={0x178: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 1, 0x100])),
                                0x50: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x20)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 8, mgr)
    P = rnd(c, 0x60)
    e.w32(P + 0x3c, r.choice([0, 0x40000000, 0x40000, 0x1, r.getrandbits(32)]))
    me = obj(c, 0x80, {0x280: pystub(c, 0, this=True), 0x26c: pystub(c, 1, this=True)})
    e.w32(me + 8, P)
    for off in (0x48, 0x4c, 0x50, 0x54):
        e.w32(me + off, r.getrandbits(32))
    o = rnd(c, 0x80)
    e.w32(o + 0x3c, r.choice([0, 0x40000, 0x200000, 0x400, 0x40000 | 0x400, r.getrandbits(32), 0x800000, 0x40000000]))
    e.w32(o + 0x64, r.choice([0, 1]))
    e.w32(o + 0x60, r.choice([0, 0, blocks[1]]))
    e.w32(o + 0x54, mktag(r.choice(TAGS)) if r.random() < 0.85 else 0)
    return [me, o, r.choice([0, 1, 5])]


S(0x43fc30, 'GUESS detach object from owner', 'thiscall', None, ret=None, gen=_g43fc30, note='batch37051')
