"""specs_s37120.py - cascade s6 batch 37120 (0x55c460, thiscall(a) ret 4). Hooked 0x5003d0 (three argument nodes) and 0x506040 (name); the table object slot 0x114 (4 args) gives
a 16-bit id (random high bits); listeners (count + pointers at [owner+0x921]) have slot 0x128 (id, &pair, 0) whose pair content is logged; the owner appears among the listeners
sometimes; the logger and assert hook handle type errors."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g55c460(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    sysobj(c, table_slots={0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x130)

    def pair(em, k):
        em.calllog.append(('pair', em.rbytes(em.arg32(1), 8)))
    owner = rnd(c, 0x940)
    nl = r.choice([0, 1, 2, 3])
    ls = e.alloc(4 * (nl + 2), 4)
    ws = []
    for i in range(nl):
        if r.random() < 0.25:
            ws.append(owner)
        else:
            ws.append(obj(c, 0x20, {0x128: pystub(c, 3, this=True, stackmark=(1,), side=pair)}))
    _w(c, ls, nl)
    for i, w in enumerate(ws):
        _w(c, ls + 4 + 4 * i, w)
    _w(c, owner + 0x921, ls if r.random() < 0.9 else 0)
    this = rnd(c, 0x40)
    _w(c, this + 0x1c, owner)
    nodes = [rnd(c, 0x10) for _ in range(3)]
    for n in nodes[1:]:
        _w(c, n + 4, r.choice([0, 1, 1, 0, 2, 5]), 1)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[em.arg32(0)])
    hook_rec(c, 0x506040, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    return [this, a]


S(0x55c460, 'GUESS broadcast_pair', 'thiscall', None, ret=None, gen=_g55c460, note='batch37120')
