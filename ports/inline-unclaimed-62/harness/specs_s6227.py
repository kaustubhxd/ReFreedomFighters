"""specs_s6227.py - unclaimed-62 claim 20 (larger, 111 instructions): 0x501860 (thiscall, one argument). The object at this+0xc has a logged
slot 0x84 (one argument) that writes three words through its pointer; the vector at arg+8 has three 8-byte elements with states from
{0, 2, 1}; a state of 1 takes the error path (reporter and assert hook installed). Writes to the globals and the elements are compared.
No faulting cases."""
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
    e.w32(rep, e.fake_vtable('rep6227', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('dbg6227', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6227', hook))


def _x(c):
    e = c.emu
    r = c.rng
    _rep(c)
    vals = [r.getrandbits(32) for _ in range(3)]

    def fill(em, a):
        for k in range(3):
            em.w32(a[0] + 4 * k, vals[k])
        return 0

    obj = e.alloc(0x40)
    e.w32(obj, vtable(c, 'o6227', 0x100, impl={0x84: fill}, argwords={0x84: 1}))
    self_ = rnd(c, 0x100)
    e.w32(self_ + 0xc, obj)
    data = e.alloc(8 * 3)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(24)))
    for k in range(3):
        e.w8(data + 8 * k + 4, r.choice([0, 2, 2, 0, 1]))
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, 3)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, 3)
    x = e.alloc(16)
    e.w32(x + 8, arr)
    return [self_, x]


S(0x501860, 'unnamed 0x501860', 'thiscall', None, gen=_x, n=300)
