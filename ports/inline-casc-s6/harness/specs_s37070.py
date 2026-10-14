"""specs_s37070.py - cascade s6 batch 37070 (0x552290, stdcall(a) ret 4). Hooked: 0x5003d0 (node by index; the final call returns the result node), 0x5002f0 (store, 1 arg),
0x5857f0 (4 args, random result), logger at 0x700390 and the assert hook. The object at [0x7003b8]+0x2c1d is set or cleared."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g552290(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(3))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    g = e.alloc(0x2c40, 4)
    e.wbytes(g, bytes(r.getrandbits(8) for _ in range(0x2c40)))
    on = r.random() < 0.8
    e.wbytes(g + 0x2c1d, (r.getrandbits(32) | 1 if on else 0).to_bytes(4, 'little'))
    e.w32(0x7003b8, g)
    nodes = []
    for i in range(4):
        n = rnd(c, 0x10)
        e.wbytes(n + 4, bytes([r.choice([0, 1, 1, 0, 2, 3, r.getrandbits(8)])]))
        if i == 3:
            e.w32(n, r.choice([0, 1, r.getrandbits(32)]))
        nodes.append(n)
    outn = rnd(c, 0x10)

    def nd(em, k):
        if not on:
            return outn
        return outn if k == 4 else nodes[em.arg32(0)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=nd)
    hook_rec(c, 0x5002f0, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5857f0, 4, this=True, ret=lambda em, k: r.getrandbits(32))
    a = rnd(c, 0x10)
    e.w32(a + 4, rnd(c, 0x10))
    e.w32(a + 8, rnd(c, 0x10))
    return [a]


S(0x552290, 'GUESS push call result', 'stdcall', None, ret=None, gen=_g552290, note='batch37070')
