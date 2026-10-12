"""specs_s6207.py - unclaimed-62 claim 4 (slice 1): 0x507e50 and 0x523650 (0x4c4f10 is blocked, see docs/20-unclaimed-62.md). The
array 0x5003d0 (exe) is built valid; the element's tag byte is 3, 4, or other (the error path, with a logged assert hook). The slot
objects are logged; the reporter logs all five stack words (own copy of the reporter, see specs_s6201)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S, F
from pfspec import rnd, vtable


def reporter_all(c, nwords=5):
    e = c.emu
    rep = e.alloc(16)

    def log(em, rr):
        em.calllog.append(('report',) + tuple(em.arg32(k) for k in range(nwords)))
        em.ret(argbytes=0)
    e.w32(rep, e.fake_vtable('reporter_all', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('g_pDebug_all', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)
    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_hook_6207', hook))


def _x507(c):
    e = c.emu
    r = c.rng
    reporter_all(c, 3)   # printf(report, fmt, one word): only three stack words are passed
    data = e.alloc(8 * 4)
    e.wbytes(data, bytes(r.getrandbits(8) for _ in range(32)))
    tag = r.choice([3, 4, 3, 4, 9])
    e.w8(data + 4, tag)
    if tag == 4:
        obj = rnd(c, 0x40)
        e.w32(obj, vtable(c, 'elemobj', 0x80, impl={0x34: lambda em, a: r.getrandbits(32)}, argwords={0x34: 0}))
        e.w32(data, obj)
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, 4)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, 1)
    x = e.alloc(16)
    e.w32(x + 4, arr)
    self_ = rnd(c, 0x100)
    sub = rnd(c, 0x40)
    e.w32(sub, vtable(c, 'sub18', 0x200, impl={0x5c0: lambda em, a: 0x5000 + (len(em.calllog) & 0xff)},
                      argwords={0x5c0: 2, 0x5ac: 1}))
    e.w32(self_ + 0x18, sub)
    return [self_, x]


def _f523(c):
    e = c.emu
    r = c.rng
    reporter_all(c, 4)   # printf(report, fmt, double): four stack words
    self_ = rnd(c, 0x100)
    e.w32(self_, vtable(c, 'mover', 0x200, argwords={0x20: 1}))
    val = r.choice([0.0, 1.0, -0.0, 2.5, r.uniform(-4, 4)])
    return [self_, F(val)]


S(0x507e50, 'unnamed 0x507e50', 'thiscall', None, gen=_x507, n=300)
S(0x523650, 'CMoveAlongPath::InitSplineVal (unconfirmed name)', 'thiscall', None, gen=_f523, n=300)
