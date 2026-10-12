"""specs_s6242.py - unclaimed-62 claim 35 (gap band): 0x56b430 and 0x572580 (thiscall, one stack argument, ret 4). The helpers 0x57f350 (one argument),
0x4e5e60 (ecx = the argument, returns eax) are recording stubs by address (GUESS: bodies not part of this batch). 0x572580 gets an object whose
vtable slot 0x78 (no argument) is a logged stub; this+0x44 is zero, equal to the argument, or another value. Records are 0x200 random bytes.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _stubs(c):
    e = c.emu
    ret4e = e.alloc(16)

    def h57f(em, rr):
        em.calllog.append(('57f350', em.reg('ecx'), em.arg32(0)))
        em.ret(eax=0, argbytes=4)

    def h4e5(em, rr):
        em.calllog.append(('4e5e60', em.reg('ecx')))
        em.ret(eax=ret4e, argbytes=0)
    e.hook(0x57f350, h57f)
    e.hook(0x4e5e60, h4e5)


def _x56b(c):
    r = c.rng
    _stubs(c)
    return [rnd(c, 0xd00), r.getrandbits(32)]   # the store is at this+0xcee: the record must cover it


def _x572(c):
    e = c.emu
    r = c.rng
    _stubs(c)
    rec = rnd(c, 0x200)
    a = r.getrandbits(32)
    cur = r.choice([0, a, r.getrandbits(32)])
    e.w32(rec + 0x44, cur)
    # this[0] is the vtable itself (the exe loads it as eax and calls [eax+0x78])
    e.w32(rec, vtable(c, 'o572580', 0x100, impl={0x78: lambda em, aa: 0}, argwords={0x78: 0}))
    return [rec, a]


S(0x56b430, 'unnamed 0x56b430', 'thiscall', None, gen=_x56b, n=300)
S(0x572580, 'unnamed 0x572580', 'thiscall', None, gen=_x572, n=300)
