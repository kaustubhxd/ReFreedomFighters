"""specs_s37028.py - cascade s6 batch 37028: 0x556e80 (stdcall(a)). Hooked: 0x5003d0 (nodes 0..4 of one owner), 0x591820; table slots 0x58 (id -> object) and 0x114 (5 args,
the last recorded as the dword it points at); logger line object with cdecl slot 0x2c recorded by argument count; assert hook always set."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g556e80(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    A = rnd(c, 0x10)
    A1 = rnd(c, 0x10)
    e.w32(A + 4, A1)
    nodes = [rnd(c, 0x10) for _ in range(5)]
    oid = r.randint(1, 0xffff)
    e.w32(nodes[0], oid)
    e.wbytes(nodes[0] + 4, bytes([r.choice([0, 1, 1, 2, 5])]))
    ty2 = r.choice([3, 3, 4, 4, 0, 7])
    e.wbytes(nodes[2] + 4, bytes([ty2]))
    names = [r.getrandbits(32) for _ in range(3)]
    if ty2 == 3:
        e.w32(nodes[2], r.choice(names))
    else:
        e.w32(nodes[2], obj(c, 0x10, {0x34: pystub(c, 0, this=True, ret=r.choice(names))}))
    e.w32(nodes[1], r.choice([0, 0, 5]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[em.arg32(0)])
    hook_rec(c, 0x591820, 1, this=True)

    def lg(em, res_):
        n = 3 if em.arg32(1) == 0x69c6b0 else 2
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(n))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    O = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100, 0x1ff]))}) if r.random() < 0.9 else 0
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: O if em.arg32(0) == oid else 0),
                                0x114: pystub(c, 5, this=True, deref={4: 1}, ret=lambda em, k: r.getrandbits(32))}, table_size=0x130)
    return [A]


S(0x556e80, 'GUESS command resolving object and name', 'stdcall', None, ret=None, gen=_g556e80, note='batch37028')
