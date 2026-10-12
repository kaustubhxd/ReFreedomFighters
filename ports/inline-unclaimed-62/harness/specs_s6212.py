"""specs_s6212.py - unclaimed-62 claim 5 (slice 1): 0x5dbed0 (no name). The list at +0x48 has 0..4 entries (fake begin / next, logged). The
message table's slot 0x58 maps an entry to an object with logged slots 0x8c (vector) and 0x180 (vector, 0) returning a per-entry flag. The
vector arguments are stack pointers and are peeked (12 bytes) so their contents are compared. Returns al. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, sf


def _x(c):
    e = c.emu
    r = c.rng
    n = r.randint(0, 4)
    elems = [r.getrandbits(32) | 1 for _ in range(n)]
    flags = [r.random() < 0.3 for _ in range(4)]
    objs = {}
    for el in elems:
        o = rnd(c, 0x40)
        objs[el] = o
    def begin(em, rr):
        em.w32(em.arg32(0) + 4, 0)
        em.calllog.append(('dlist', 0x4c))
        em.ret(argbytes=4)

    def nxt(em, rr):
        it = em.arg32(0)
        idx = em.r32(it + 4)
        valid = 1 if idx < n else 0
        em.w32(it, valid)
        em.w32(it + 4, idx + 1)
        em.calllog.append(('dlist', 0x5c))
        em.ret(eax=elems[idx] if valid else 0, argbytes=4)
    lst = e.alloc(0x20)
    e.w32(lst, e.fake_vtable('dlist', 0x20, {0x4c: begin, 0x5c: nxt}))
    for el in elems:
        o = objs[el]
        idx = elems.index(el)
        flag = flags[idx]
        e.w32(o, vtable(c, 'dm', 0x200, argwords={0x8c: 1, 0x180: 2},
                        impl={0x180: (lambda f: (lambda em, a: 1 if f else 0))(flag)},
                        opts={0x8c: {'peek': {0: 12}}, 0x180: {'peek': {0: 12}}}))
    msg = e.alloc(0xb00)
    e.w32(msg, vtable(c, 'dmsg', 0x80, impl={0x58: lambda em, a: objs.get(a[0], 0)}, argwords={0x58: 1}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    self_ = rnd(c, 0x100)
    e.w32(self_ + 0x48, lst if r.random() < 0.9 else 0)
    arg = e.alloc(16)
    for k in range(3):
        e.wf32(arg + 4 * k, sf(c.fv(-100, 100)))
    return [self_, arg]


S(0x5dbed0, 'unnamed 0x5dbed0', 'thiscall', None, ret='al', gen=_x, n=300)
