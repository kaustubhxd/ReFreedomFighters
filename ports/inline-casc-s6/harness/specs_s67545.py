"""specs_s67545.py - cascade s6 batch 67545 (0x61a520, stdcall(n, base, ctx) ret 0xc, return value unused). ctx[0x13f6] is the vertex ring (+0 buffer object with slot 0x30, +0xc lock flag), ctx[0x1377] the
device whose slot 0x11c is a custom 6-arg stdcall stub; 0x60ed80 (lock) is a hook returning a heap buffer (the count it receives is logged, the offset out dword is written); the corner offset
globals 0x6efd2c..0x6efd36 are random; the bound-buffer cache 0x7249f0 / 0x7249f4 and device 0x724a00 (slot 0x154, 3-arg stdcall stub) are set up per case."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g61a520(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x6efd2c, 0x6efd30, 0x6efd34):
        e.w32(a, r.getrandbits(32))
    for a in (0x6efd2e, 0x6efd32, 0x6efd36):
        e.wbytes(a, r.getrandbits(16).to_bytes(2, 'little'))
    buf = obj(c, 0x20, {0x30: pystub(c, 1, this=True)})
    ring = rnd(c, 0x20)
    rb = buf if r.random() < 0.8 else 0
    _w(c, ring, rb)
    _w(c, ring + 0xc, r.choice([0, 1, 1]), 1)

    def d3(em, res_):
        em.calllog.append(('d154', em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=12)
    dev2 = obj(c, 0x20, {0x154: e.stub_fn('recorder', d3)})
    e.w32(0x724a00, dev2)
    cur = r.choice([rb, rb, 1, 0])
    e.w32(0x7249f0, cur)
    e.w32(0x7249f4, r.choice([0, 0, 1]))

    def d6(em, res_):
        em.calllog.append(('d11c', tuple(em.arg32(i) for i in range(1, 6))))
        em.ret(eax=0, argbytes=24)
    dev = obj(c, 0x20, {0x11c: e.stub_fn('recorder', d6)})
    ctx = rnd(c, 0x1400)
    _w(c, ctx + 0x13f6, ring)
    _w(c, ctx + 0x1377, dev)
    out = e.alloc(0x400, 4)
    e.wbytes(out, bytes(0x400))

    def side(em, k):
        em.wbytes(em.arg32(1), (0x1000 + 8 * k).to_bytes(4, 'little'))
    hook_rec(c, 0x60ed80, 2, this=True, ret=out, deref={0: 1}, stackmark=(1,), side=side)
    return [r.choice([0, 1, 1, 2, 3, 5, 9]), r.getrandbits(32), ctx]


S(0x61a520, 'GUESS emit_quads', 'stdcall', None, ret=None, gen=_g61a520, note='batch67545')
