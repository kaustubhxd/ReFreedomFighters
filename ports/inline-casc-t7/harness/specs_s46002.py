"""specs_s46002.py - cascade t7 batch 46002: 0x549840 stream refill step. Callees hooked: 0x54d470 (fastcall: ecx=this, edx=out, 6 stack args, pops 24; edx logged),
0x54e1f0 (thiscall, 4 args), 0x634d10/0x634d22 (cdecl); self vtable slots 0x0 (writes [L18]), 0x74, 0x78 (writes the four output locals); object at +8 slot 0x98;
the embedded sub-object at +0x40b1 has slots 0x8 (al) and 0xc (writes the byte count through its out pointer)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _rv(r):
    return r.choice([0, 0, 1, 2, 3, 5, 8, 0x40, r.getrandbits(8), r.getrandbits(32)])


def g549840(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    N = 8

    def lst(f):
        return [f() for _ in range(N)]
    r54d = lst(lambda: r.choice([0, 0, 1, 2, 3, 7, 20, r.getrandbits(5)]))
    r54e = lst(lambda: r.choice([0, 1, 2, 3, 3, 2, 4]))
    w54e = lst(lambda: r.choice([0, 1, 5, r.getrandbits(8), r.getrandbits(32)]))
    outs = [[_rv(r) for _ in range(4)] for _ in range(N)]
    w0 = lst(lambda: r.getrandbits(32))
    ok0 = lst(lambda: r.choice([0, 1, 1, 1, 0x100, 0xff00]))
    r98 = lst(lambda: r.getrandbits(32))
    r8 = lst(lambda: r.choice([0, 1, 1, 1, 0x100, 0x100]))
    w0c = lst(lambda: r.choice([0, 1, 3, r.getrandbits(8), r.getrandbits(32)]))

    hook_rec(c, 0x54d470, 6, this=True, ret=lambda em, k: r54d[min(k, N - 1)],
             side=lambda em, k: em.calllog.append(('edx', em.reg('edx'))))
    hook_rec(c, 0x54e1f0, 4, this=True, stackmark=(2,), ret=lambda em, k: r54e[min(k, N - 1)],
             side=lambda em, k: em.w32(em.arg32(2), w54e[min(k, N - 1)]))
    hook_rec(c, 0x634d10, 3, pop=0)
    hook_rec(c, 0x634d22, 3, pop=0)

    def s78(em, k):
        for i in range(4):
            em.w32(em.arg32(2 + i), outs[min(k, N - 1)][i])

    def s0(em, k):
        em.w32(em.arg32(0), w0[min(k, N - 1)])

    def s0c(em, k):
        em.w32(em.arg32(1), w0c[min(k, N - 1)] if r.random() < 2 else 0)
    # sub-object embedded in self at +0x40b1: its vtable pointer sits at self+0x40b1
    me = obj(c, 0x6400, {0x0: pystub(c, 1, this=True, stackmark=(0,), side=s0, ret=lambda em, k: ok0[min(k, N - 1)]),
                         0x74: pystub(c, 4, this=True),
                         0x78: pystub(c, 6, this=True, stackmark=(2, 3, 4, 5), side=s78)})
    svt = c.emu.alloc(0x40, 4)
    e.w32(svt + 8, pystub(c, 0, this=True, ret=lambda em, k: r8[min(k, N - 1)]))
    e.w32(svt + 0xc, pystub(c, 2, this=True, stackmark=(1,), side=s0c))
    e.w32(me + 0x40b1, svt)
    ob = obj(c, 0x40, {0x98: pystub(c, 1, this=True, ret=lambda em, k: r98[min(k, N - 1)])})
    e.w32(me + 8, ob)
    rc = rnd(c, 0x40)
    typ = r.choice([0x11, 0x11, 0x1000, 0x1000, 1, 1, 2, 0x12, 0x11 | 0x80000000, 0x1000 | 0x80000000, 1 | 0x80000000, r.getrandbits(32)])
    e.w32(rc + 8, typ)
    if r.random() < 0.1:
        e.w32(rc + 0x14, 0)
    e.w32(rc + 0x28, r.choice([0, 4, 0x100, r.getrandbits(12), r.getrandbits(32)]))
    e.w32(rc + 0x1c, r.choice([0, 1, 4, 8, r.getrandbits(6)]))
    e.w32(me + 0x5d, rc)
    e.wbytes(me + 0x75, r.choice([1, 1, 3, 3, 3, 0, 2, 5, r.getrandbits(32)]).to_bytes(4, 'little'))
    e.wbytes(me + 0x7c, bytes([r.choice([0, 1, 1, 7])]))
    e.w32(me + 0x10, r.choice([0, r.getrandbits(8), r.getrandbits(32)]))
    e.w32(me + 0x29, rnd(c, 0x60))
    ee = r.getrandbits(32)
    e.wbytes(me + 0x40ad, ee.to_bytes(4, 'little'))
    e.wbytes(me + 0x40a9, r.choice([0, 100, r.getrandbits(32)]).to_bytes(4, 'little'))
    return [me]


S(0x549840, 'GUESS stream refill/decode step', 'thiscall', None, ret='eax', gen=g549840, note='batch46002')
