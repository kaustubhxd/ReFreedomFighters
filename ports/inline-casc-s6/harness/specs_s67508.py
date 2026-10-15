"""specs_s67508.py - cascade s6 batch 67508 (0x5591b0, thiscall(a) ret 4). Hooked 0x5003d0 (argument nodes 0 / 1), 0x58b780 and 0x594460 (this = the resolved object or 0); the table
object's slot 0x58 (object or none per call, the three lookups may differ), slot 0x154 (record whose dword at +0x23 is random) and the objects' slot 0x1e0; logger and assert hook for
node type errors."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5591b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    objs = [obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100]))}) for _ in range(3)]
    rec = rnd(c, 0x40)
    first = r.choice(objs + [0, 0])
    third = r.choice(objs + [0])
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: first if k < 2 else third), 0x154: pystub(c, 2, this=True, ret=rec)}, table_size=0x160)
    nodes = [rnd(c, 0x10), rnd(c, 0x10)]
    for n in nodes:
        _w(c, n + 4, r.choice([0, 1, 1, 0, 2, 5]), 1)
    _w(c, nodes[1], r.choice([0, 1, 7]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[min(k, 1)])
    hook_rec(c, 0x58b780, 1, this=True)
    hook_rec(c, 0x594460, 1, this=True)
    t = rnd(c, 0x40)
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    return [t, a]


S(0x5591b0, 'GUESS dispatch_by_flag', 'thiscall', None, ret=None, gen=_g5591b0, note='batch67508')
