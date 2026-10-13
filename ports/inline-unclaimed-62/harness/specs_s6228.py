"""specs_s6228.py - unclaimed-62 claim 21 (larger, 115 instructions): 0x502cc0 (thiscall, one argument). The array at arg+4 has ten 8-byte
elements; element 1's tag is 3, 4 (its dword is an object whose slot 0x34 returns a value) or another value (the error path with the reporter and
assert hook). The message table's slot 0x114 (five arguments, the last a pointer to eight words, peeked) returns a word; this+0xc's slot 0x12c
(two words) is logged. No faulting cases."""
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
    e.w32(rep, e.fake_vtable('rep6228', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('dbg6228', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6228', hook))


def _x(c):
    e = c.emu
    r = c.rng
    _rep(c)
    data = e.alloc(8 * 10)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(80)))
    for k in range(10):
        e.w8(data + 8 * k + 4, r.choice([0, 1, 2, 3]))
    tag1 = r.choice([3, 4, 4, 7])
    e.w8(data + 8 + 4, tag1)
    if tag1 == 4:
        obj = rnd(c, 0x40)
        val = r.getrandbits(32)
        e.w32(obj, vtable(c, 'elem6228', 0x80, impl={0x34: lambda em, a: val}, argwords={0x34: 0}))
        e.w32(data + 8, obj)
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, 10)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, 10)
    x = e.alloc(16)
    e.w32(x + 4, arr)
    self_ = rnd(c, 0x100)
    o = rnd(c, 0x40)
    e.w32(o, vtable(c, 'r12c', 0x200, argwords={0x12c: 2}))
    e.w32(self_ + 0xc, o)
    wret = r.getrandbits(16)
    msg = e.alloc(0xb00)
    e.w32(msg, vtable(c, 'msg114', 0x80, impl={0x114: lambda em, a: wret},
                      argwords={0x114: 5}, opts={0x114: {'peek': {4: 32}}}))
    eng = e.alloc(0xa0)
    e.w32(eng + 0x9b, msg)
    e.w32(0x70039c, eng)
    return [self_, x]


S(0x502cc0, 'unnamed 0x502cc0', 'thiscall', None, gen=_x, n=1000)
