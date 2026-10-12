"""specs_s6210.py - unclaimed-62 claim 4 (slice 1): ZGEOM::FindEvent (0x45e490). The gate (0x4da3a0, exe) reads this+8 -> +0x54 -> +0x10 -> +8
(built valid). The list (begin, next) and the element objects (slot 0x14, logged) are fake; the allocator's slot 0xcc returns its argument.
The wildcard matcher 0x4cc850 is patched to a logged stub (fastcall: ecx value, edx name) returning 0 (a match) about a third of the time.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, vtable


def _fe(c):
    e = c.emu
    r = c.rng
    n = r.randint(0, 4)
    elems = []
    for _ in range(n):
        el = rnd(c, 0x40)
        v = r.choice([0, r.getrandbits(32) | 1])
        e.w32(el, vtable(c, 'fe_el', 0x40, impl={0x14: (lambda vv: (lambda em, a: vv))(v)}, argwords={0x14: 0}))
        elems.append(el)
    match_pick = r.random() < 0.6

    def begin(em, rr):
        em.w32(em.arg32(0) + 4, 0)
        em.calllog.append(('fe_list', 0x4c))
        em.ret(argbytes=4)

    def nxt(em, rr):
        it = em.arg32(0)
        idx = em.r32(it + 4)
        valid = 1 if idx < n else 0
        em.w32(it, valid)
        em.w32(it + 4, idx + 1)
        em.calllog.append(('fe_list', 0x5c))
        em.ret(eax=elems[idx] if valid else 0, argbytes=4)
    ilist = e.alloc(0x20)
    e.w32(ilist, e.fake_vtable('fe_list', 0x20, {0x4c: begin, 0x5c: nxt}))
    a = e.alloc(0x10)

    def ident(em, rr):
        em.calllog.append(('alloc', 0xcc))
        em.ret(eax=em.arg32(0), argbytes=4)
    e.w32(a, e.fake_vtable('fe_alloc', 0x40, {0xcc: ident}))
    e.w32(0x70038c, a)

    def matcher(em, rr):
        em.calllog.append(('4cc850', em.reg('ecx'), em.reg('edx')))
        em.ret(eax=0 if (match_pick and r.random() < 0.5) else 1, argbytes=0)
    ss.patch(c, 0x4cc850, e.stub_fn('matcher4cc850', matcher))

    gate = e.alloc(0x80)
    z = e.alloc(0x20)
    e.w32(z + 8, 1)
    y = e.alloc(0x40)
    e.w32(y + 0x10, z)
    e.w32(gate + 0x54, y)
    holder = e.alloc(0x20)
    e.w32(holder + 8, ilist)
    geom = rnd(c, 0x100)
    e.w32(geom + 8, gate)
    e.w32(geom + 0x10, holder)
    name = e.alloc(16)
    e.wbytes(name, b'ev*\x00')
    return [geom, name]


S(0x45e490, 'ZGEOM::FindEvent', 'thiscall', None, ret='eax', gen=_fe, n=300)
