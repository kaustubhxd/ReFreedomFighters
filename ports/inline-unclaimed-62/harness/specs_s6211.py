"""specs_s6211.py - unclaimed-62 claim 5 (slice 1): 0x502590 (no name). The array at x+4 has four 8-byte elements (dword, tag byte +4); element
1's tag is 3, 4 (its dword is an object whose slot 0x34 returns a value) or another value (the error path, with the assert hook installed and
the reporter logging its three words). The message table's slot 0x114 (four words) returns a word; this+0xc's slot 0x12c (three words) is logged
with the two-dword array's contents peeked, so the array's values are compared. No faulting cases."""
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
    e.w32(rep, e.fake_vtable('rep6211', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('dbg6211', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6211', hook))


def _x(c):
    e = c.emu
    r = c.rng
    _rep(c)
    tag1 = r.choice([3, 4, 4, 7])
    data = e.alloc(8 * 4)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(32)))
    for k in range(4):
        e.w8(data + 8 * k + 4, tag1 if k == 1 else r.choice([0, 1, 2, 3]))
    if tag1 == 4:
        obj = rnd(c, 0x40)
        val = r.getrandbits(32)
        e.w32(obj, vtable(c, 'elem6211', 0x80, impl={0x34: lambda em, a: val}, argwords={0x34: 0}))
        e.w32(data + 8, obj)
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, 4)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, 4)
    x = e.alloc(16)
    e.w32(x + 4, arr)
    self_ = rnd(c, 0x100)
    o = rnd(c, 0x40)
    e.w32(o, vtable(c, 'r12c', 0x200, argwords={0x12c: 3}, opts={0x12c: {'peek': {2: 8}}}))
    e.w32(self_ + 0xc, o)
    wret = r.getrandbits(16)
    msg = e.alloc(0xb00)
    e.w32(msg, vtable(c, 'msg114', 0x80, impl={0x114: lambda em, a: wret}, argwords={0x114: 4}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    return [self_, x]


S(0x502590, 'unnamed 0x502590', 'thiscall', None, gen=_x, n=300)
