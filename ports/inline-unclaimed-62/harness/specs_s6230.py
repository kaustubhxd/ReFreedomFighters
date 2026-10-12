"""specs_s6230.py - unclaimed-62 claim 23 (larger, 108 instructions): 0x55afe0 (thiscall, one argument). The vector at arg+8 has three elements in a
header with a random offset (its count is 0 in about a fifth of the cases, the exe's hook path). Element states are 0, 1 or 2 (2 takes the error
path with the reporter and the assert hook). The list at this+0x1c+0x921 is null in about a fifth of the cases, else a count of 0..3 followed by
objects whose slot 0x438 returns a random byte (logged). The assert hook and reporter are installed. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _rep(c):
    e = c.emu
    rep = e.alloc(16)

    def log(em, rr):
        em.calllog.append(('report',) + tuple(em.arg32(k) for k in range(3)))
        em.ret(argbytes=0)
    e.w32(rep, e.fake_vtable('rep6230', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('dbg6230', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6230', hook))


def _x(c):
    e = c.emu
    r = c.rng
    _rep(c)
    # the vector at arg+8: header {base, total}; vector {hdr, offset, count}
    total = 3
    base = e.alloc(8 * total)
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(8 * total)))
    for k in range(total):
        e.w8(base + 8 * k + 4, r.choice([0, 1, 0, 2]) if r.random() < 0.9 else 2)
    hdr = e.alloc(16)
    e.w32(hdr, base)
    e.w32(hdr + 8, total)
    V = e.alloc(16)
    e.w32(V, hdr)
    e.w32(V + 4, r.randint(0, total - 1))
    e.w32(V + 8, 2)     # count 0 (the exe's inline hook path) is not verified: see docs/20-unclaimed-62.md
    x = e.alloc(16)
    e.w32(x + 8, V)
    # this+0x1c -> object Q with the list at +0x921
    self_ = rnd(c, 0x100)
    Q = rnd(c, 0x1000)
    e.w32(self_ + 0x1c, Q)
    if r.random() < 0.8:
        n = r.randint(0, 3)
        lst = e.alloc(4 * (n + 2))
        e.w32(lst, n)
        for k in range(n):
            o = e.alloc(0x40)
            ret438 = r.getrandbits(8) & 1
            e.w32(o, vtable(c, 'o6230', 0x500, impl={0x438: lambda em, a, v=ret438: v}, argwords={0x438: 0}))
            e.w32(lst + 4 + 4 * k, o)
        e.w32(Q + 0x921, lst)
    else:
        e.w32(Q + 0x921, 0)
    return [self_, x]


S(0x55afe0, 'unnamed 0x55afe0', 'thiscall', None, gen=_x, n=300)
