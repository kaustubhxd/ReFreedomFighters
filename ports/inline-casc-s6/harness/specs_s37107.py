"""specs_s37107.py - cascade s6 batch 37107 (0x604e10, thiscall(a) ret 4). Hooked 0x5003d0 (argument nodes 0 / 1 of the pair, then the result node), 0x41e290 (alloc) and
0x634273 (release); the two string objects carry C strings at +0xc; the object's capacity word (+0x10) is chosen around the joined length; the logger at 0x700390 and the assert hook
are set. The result node type is 0, 4 or something else."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g604e10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))

    def mkstr():
        n = r.choice([0, 1, 3, 5, 8])
        txt = bytes(r.randrange(1, 0x7f) for _ in range(n))
        a = e.alloc(0x20, 4)
        e.wbytes(a, txt + b'\x00' + bytes(r.randrange(1, 255) for _ in range(0x1f - n)))
        so = rnd(c, 0x20)
        _w(c, so + 0xc, a)
        return so, n
    s1, n1 = mkstr()
    s2, n2 = mkstr()
    total = n1 + 1 + n2
    cap = r.choice([0, total - 1, total, total + 1, 0x30, 2])
    cap = max(cap, 0)
    buf = e.alloc(0x100, 4)
    e.wbytes(buf, bytes(r.getrandbits(8) for _ in range(0x100)))
    pool = [e.alloc(0x40, 4) for _ in range(2)]
    for p in pool:
        e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x40)))
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: pool[k % 2])
    hook_rec(c, 0x634273, 2, pop=0)
    clone = r.getrandbits(32)
    this = obj(c, 0x40, {0x24: pystub(c, 0, this=True, ret=clone)})
    _w(c, this + 0xc, buf)
    _w(c, this + 0x10, cap, 2)
    ty = r.choice([0, 0, 4, 4, 1, 2])
    res = rnd(c, 0x10)
    _w(c, res + 4, ty, 1)
    _w(c, res, obj(c, 0x20, {0x28: pystub(c, 0, this=True)}))
    nodes = [rnd(c, 0x10), rnd(c, 0x10)]
    _w(c, nodes[0], s1)
    _w(c, nodes[1], s2)
    pair = rnd(c, 0x20)
    _w(c, pair + 8, 2 if r.random() < 0.85 else r.choice([0, 1, 3]))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[k] if k < 2 else res)
    a = rnd(c, 0x10)
    _w(c, a + 4, pair)
    _w(c, a + 8, rnd(c, 0x10))
    return [this, a]


S(0x604e10, 'GUESS concat_strings', 'thiscall', None, ret=None, gen=_g604e10, note='batch37107')
