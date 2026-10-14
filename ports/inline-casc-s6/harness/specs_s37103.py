"""specs_s37103.py - cascade s6 batch 37103 (0x5079c0, thiscall(a) ret 4). Hooked 0x5003d0 (nodes by call order: three argument nodes, then the result node), 0x4dbe30; the table
object (slots 0x58 / 0x4c), objects A and B (slots 0x288 / 0x80; 0x80 fills the 0x24 and 0xc byte stack records, logged through the owner's slot 0x370), owner slots 0x20 (X, then
X's slot 0x20 gives Y), 0x654, logger at 0x700390 and the assert hook."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5079c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(3))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    A = obj(c, 0x20, {0x288: pystub(c, 3, this=True)})

    def s80(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(0x24)))
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0xc)))
    B = obj(c, 0x20, {0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=s80)})

    def s370(em, k):
        em.calllog.append(('370', em.rbytes(em.arg32(0), 0x24), em.rbytes(em.arg32(1), 0xc)))
    inner = rnd(c, 0x20)
    Yv = r.getrandbits(32)
    Xo = obj(c, 0x20, {0x20: pystub(c, 0, this=True, ret=Yv)})
    _w(c, Xo + 8, inner)
    owner = obj(c, 0x720, {0x20: pystub(c, 0, this=True, ret=Xo), 0x654: pystub(c, 1, this=True),
                           0x370: pystub(c, 2, this=True, stackmark=(0, 1), side=s370)})
    _w(c, owner + 0x6fe, r.getrandbits(8), 1)
    this = rnd(c, 0x40)
    _w(c, this + 0x18, owner)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: [A, B][k % 2]),
                           0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    nodes = [rnd(c, 0x10) for _ in range(3)]
    _w(c, nodes[2], r.choice([0, 0, 1, 7]))
    res = rnd(c, 0x10)
    _w(c, res + 4, r.choice([0, 1, 1, 2, 5]), 1)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: nodes[em.arg32(0)] if k < 3 else res)
    hook_rec(c, 0x4dbe30, 1, this=True)
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    _w(c, a + 8, rnd(c, 0x10))
    return [this, a]


S(0x5079c0, 'GUESS attach_and_store_handle', 'thiscall', None, ret=None, gen=_g5079c0, note='batch37103')
