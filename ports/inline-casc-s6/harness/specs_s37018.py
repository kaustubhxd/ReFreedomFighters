"""specs_s37018.py - cascade s6 batch 37018: 0x509e50. Hooked 0x5003d0 (node by index), table slot 0x114 (4 args), logger at 0x700390, assert hook always set;
[this+0xc] is an object with slot 0x12c (3 args, third recorded as the dword it points at) and a list at +0x18 (slots 0x4c, 0x5c)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g509e50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    A = rnd(c, 0x10)
    A1 = rnd(c, 0x10)
    e.w32(A + 4, A1)
    nodes = [rnd(c, 0x10) for _ in range(3)]
    ty0 = r.choice([3, 3, 4, 4, 0, 1, 2, 7])
    e.wbytes(nodes[0] + 4, bytes([ty0]))
    words = [r.getrandbits(32) for _ in range(3)]
    if ty0 == 3:
        e.w32(nodes[0], r.choice(words))
    else:
        e.w32(nodes[0], obj(c, 0x10, {0x34: pystub(c, 0, this=True, ret=r.choice(words))}))
    for n in nodes[1:]:
        e.wbytes(n + 4, bytes([r.choice([0, 1, 1, 2, 5, r.getrandbits(8)])]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[em.arg32(0)])

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(3))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    so = sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x130)
    lst = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, nullflag=(0,), side=lambda em, k: em.w32(em.arg32(0), 1)),
                        0x5c: pystub(c, 1, this=True, nullflag=(0,), ret=lambda em, k: r.getrandbits(32),
                                     side=lambda em, k: em.w32(em.arg32(0), 0 if (k >= 4 or r.random() < 0.3) else 1))})
    M = obj(c, 0x40, {0x12c: pystub(c, 3, this=True, deref={2: 1})})
    e.w32(M + 0x18, lst if r.random() < 0.85 else 0)
    me = rnd(c, 0x20)
    e.w32(me + 0xc, M)
    return [me, A]


S(0x509e50, 'GUESS dispatch id to list items', 'thiscall', None, ret=None, gen=_g509e50, note='batch37018')
