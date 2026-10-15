"""specs_s67516.py - cascade s6 batch 67516 (0x502670, thiscall(a) ret 4). Hooked 0x5003d0 (call order: arguments 2, 3, 4, 1, 0); argument 4 / 1 nodes have type 3 (int), 4 (object with
slot 0x34) or other (error 0x111 + assert hook); table slot 0x114 (4 args) gives an id with random high bits; the target (+0xc) has slot 0x12c whose stack triple content is logged."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g502670(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x130)
    nodes = [rnd(c, 0x10) for _ in range(5)]   # indexed by argument number

    def setnode(i):
        ty = r.choice([3, 3, 4, 4, 0, 1, 7])
        _w(c, nodes[i] + 4, ty, 1)
        if ty == 4:
            _w(c, nodes[i], obj(c, 0x20, {0x34: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))}))
    setnode(1)
    setnode(4)
    order = [2, 3, 4, 1, 0]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[order[k]])
    tgt = obj(c, 0x20, {0x12c: pystub(c, 3, this=True, stackmark=(2,), side=lambda em, k: em.calllog.append(('trip', em.rbytes(em.arg32(2), 12))))})
    t = rnd(c, 0x20)
    _w(c, t + 0xc, tgt)
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    return [t, a]


S(0x502670, 'GUESS forward_record', 'thiscall', None, ret=None, gen=_g502670, note='batch67516')
