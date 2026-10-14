"""specs_s37029.py - cascade s6 batch 37029: 0x4d7f70 (zlib wrapper). deflateInit_ (0x62f120), deflate (0x62ebc0) and deflateEnd (0x62ee40) are hooks working on the
caller's z_stream: deflate writes a random number of random bytes through next_out/avail_out (at least 2 on the first call) and returns Z_STREAM_END (1) after a few calls;
0x634273 / 0x634d22 / 0x41e290 hooked; logger at 0x700390; assert hook set."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4d7f70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    ln = r.choice([0, 1, 5, 20, 40, 100])
    src = rnd(c, ln + 8)
    ext = r.random() < 0.4
    cap = ln + 9 + r.choice([-2, 0, 0, 5])
    extbuf = rnd(c, ln + 0x20) if ext else 0
    allocbuf = rnd(c, ln + 0x20)
    dest = {}
    hook_rec(c, 0x41e290, 1, pop=0, ret=allocbuf)
    hook_rec(c, 0x634273, 2, pop=0)

    def cp(em, k):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        if n < 0x200:
            em.wbytes(d, em.rbytes(s, n))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp, stackmark=(1,))
    fail = r.random() < 0.08

    def init_side(em, k):
        z = em.arg32(0)
        em.calllog.append(('z', em.r32(z), em.r32(z + 4), em.r32(z + 0x20), em.r32(z + 0x24)))
    hook_rec(c, 0x62f120, 4, nullflag=(0,), pop=0x10, ret=(1 if fail else 0), side=init_side)
    state = {'k': 0}
    ncalls = r.choice([1, 1, 2, 3])

    def defl(em, k):
        z = em.arg32(0)
        nxt, avail = em.r32(z + 0xc), em.r32(z + 0x10)
        n = r.choice([2, 3, 6, 15, 30, 60, 200]) if k == 0 else r.choice([0, 1, 5, 30])
        n = min(n, avail)
        em.wbytes(nxt, bytes(r.getrandbits(8) for _ in range(n)))
        em.w32(z + 0x10, avail - n)
        em.calllog.append(('defl', em.r32(z), em.r32(z + 4), em.arg32(1)))

    def defl_ret(em, k):
        return 1 if k >= ncalls - 1 else 0
    hook_rec(c, 0x62ebc0, 2, nullflag=(0,), pop=8, side=defl, ret=defl_ret)
    hook_rec(c, 0x62ee40, 1, nullflag=(0,), pop=4)

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(2))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    me = rnd(c, 0x20)
    e.wbytes(me, bytes([r.choice([0, 1])]))
    if r.random() < 0.4:
        e.w32(me + 1, rnd(c, 0x20))
    else:
        e.w32(me + 1, 0)
    e.w32(me + 0xd, r.choice([1, 6, 9]))
    return [me, src, ln, extbuf, cap]


S(0x4d7f70, 'GUESS zlib compress to buffer', 'thiscall', None, ret='al', gen=_g4d7f70, note='batch37029')
