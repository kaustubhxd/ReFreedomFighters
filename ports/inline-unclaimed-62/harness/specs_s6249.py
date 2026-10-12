"""specs_s6249.py - ragdoll side (claim 42): four small ragdoll functions. The container and ragdoll records are 0x400 random bytes; the entries (0x1df
bytes each) at +0x25 and the flag words at +0x2d are allocated with a count of 0..6 and the single entry at +0x29. 0x641b60 is given pointers into the
entry array (in range, one past the end, or before it) and the single entry; out-of-range indices reach the debug report, which is a logged stub, and
the assert hook is installed. 0x642140 is called with the flag byte 0 and nonzero. No faulting cases."""
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
    e.w32(rep, e.fake_vtable('rep6249', 0x40, {0x2c: log}))
    dbg = e.alloc(16)

    def getrep(em, rr):
        em.calllog.append(('dbg20', em.arg32(0), em.arg32(1)))
        em.ret(eax=rep, argbytes=8)
    e.w32(dbg, e.fake_vtable('dbg6249', 0x40, {0x20: getrep}))
    e.w32(0x700390, dbg)

    def hook(em, rr):
        em.calllog.append(('assert-hook',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_6249', hook))


def _container(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x400)
    count = r.randint(0, 6)
    base = e.alloc(0x1df * 7 + 0x40)
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x1df * 7 + 0x40)))
    flags = e.alloc(4 * 8)
    for i in range(8):
        e.w32(flags + 4 * i, r.choice([0, 1]))
    single = e.alloc(0x1df + 0x20)
    e.wbytes(single, bytes(r.getrandbits(8) for _ in range(0x1df + 0x20)))
    e.w8(single + 0x15, r.choice([0, 1]))
    e.w32(rec + 0x21, count)
    e.w32(rec + 0x25, base)
    e.w32(rec + 0x29, single)
    e.w32(rec + 0x2d, flags)
    return rec, base, single, count


def _x640fe0(c):
    rec = rnd(c, 0x400)
    return [rec]


def _x641c50(c):
    rec = rnd(c, 0x400)
    e = c.emu
    e.w8(rec + 0x14, c.rng.choice([0, 1]))
    return [rec, c.rng.choice([0, 1, 7, 255])]


def _x641b60(c):
    _rep(c)
    rec, base, single, count = _container(c)
    r = c.rng
    choice = r.random()
    if choice < 0.2:
        p = single
    elif choice < 0.85:
        p = base + r.randint(-1, count + 1) * 0x1df
    else:
        p = base + r.randint(-3, 9) * 0x1df + r.randint(0, 0x1de)
    return [rec, p & 0xffffffff]


def _x642140(c):
    _rep(c)
    rec, base, single, count = _container(c)
    return [rec, c.rng.choice([0, 1, 5])]


S(0x640fe0, 'unnamed 0x640fe0', 'thiscall', None, gen=_x640fe0, n=300)
S(0x641c50, 'unnamed 0x641c50', 'thiscall', None, gen=_x641c50, n=300)
S(0x641b60, 'unnamed 0x641b60', 'thiscall', None, gen=_x641b60, n=300)
S(0x642140, 'unnamed 0x642140', 'thiscall', None, ret='eax', gen=_x642140, n=300)
