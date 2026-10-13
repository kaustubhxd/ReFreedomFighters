"""specs_s6229.py - unclaimed-62 claim 22 (larger, 110 instructions): 0x5058a0 (thiscall, one argument). Element 0 of the first vector has tag 3
(its dword is a string buffer), tag 4 (its dword is an object whose slot 0x34 returns the buffer) or another tag (the error path). The buffer is
the exe's constant at 0x677b5c in about half the cases (read from the emulator) and a random string otherwise. The engine's helper object
(+0x1a9f) is null in about a fifth of the cases; its slot 0x5c (one argument) returns 0 or a word. The object at this+0x14 is a random block. The
second vector's element 0 is a state 0 or 1 element. No faulting cases."""
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
    e.w32(rep, e.fake_vtable('rep6229', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('dbg6229', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6229', hook))


def _vec(c, e, count, state0):
    r = c.rng
    data = e.alloc(8 * count)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(8 * count)))
    for k in range(count):
        e.w8(data + 8 * k + 4, r.choice([0, 1]))
    e.w8(data + 4, state0)
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, count)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, count)
    return arr, data


def _x(c):
    e = c.emu
    r = c.rng
    _rep(c)
    # the buffer the element value points to: the exe's constant string (in about half the cases) or a random short string
    if r.random() < 0.5:
        s = bytes(e.rbytes(0x677b5c, 40))
        s = s[:s.index(b'\x00') + 1] if b'\x00' in s else s + b'\x00'
    else:
        s = bytes(r.choice(b'abcdefgh') for _ in range(r.randint(0, 6))) + b'\x00'
    buf = e.alloc(64)
    e.wbytes(buf, s)
    tag = r.choice([3, 3, 4, 7])
    x = e.alloc(16)
    arr0, data0 = _vec(c, e, 2, tag)
    if tag == 3:
        e.w32(data0, buf)
    elif tag == 4:
        o = rnd(c, 0x40)
        e.w32(o, vtable(c, 'elem5058', 0x80, impl={0x34: lambda em, a: buf}, argwords={0x34: 0}))
        e.w32(data0, o)
    else:
        e.w32(data0, buf)
    e.w32(x + 4, arr0)
    arr1, _ = _vec(c, e, 2, r.choice([0, 1]))
    e.w32(x + 8, arr1)
    self_ = rnd(c, 0x100)
    sub = rnd(c, 0x200)
    e.w32(self_ + 0x14, sub)
    eng = e.alloc(0x2000)
    e.w32(0x70039c, eng)
    if r.random() < 0.8:
        ret5c = r.choice([0, r.getrandbits(32)])
        a = e.alloc(0x40)
        e.w32(a, vtable(c, 'helper5058', 0x100, impl={0x5c: lambda em, a_: ret5c}, argwords={0x5c: 1}))
        e.w32(eng + 0x1a9f, a)
    else:
        e.w32(eng + 0x1a9f, 0)
    return [self_, x]


S(0x5058a0, 'unnamed 0x5058a0', 'thiscall', None, gen=_x, n=1000)
