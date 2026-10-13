"""specs_s3011.py - unclaimed-30 batch 11 (docs/20-unclaimed-30.md, claim 1): ZGEOM::RemoveEventFromList (0x45f7d0). The gate
(0x4da3a0, exe code) reads this+8 -> +0x54 -> +0x10 -> +8, built valid as in DeactivateEvents. The list's begin / next / remove /
+0x14 slots and this's slot 0x140 are logged stubs. The allocator's slot 0xcc returns its argument (the element itself), so a match
with ev reads the element's flag byte +0x14 and dword +0x1c from real memory. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _obj(c, n):
    a = c.emu.alloc(n)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rm(c):
    e = c.emu
    r = c.rng
    n = r.randint(0, 4)
    elems = [_obj(c, 0x40) for _ in range(n)]
    for el in elems:
        e.w8(el + 0x14, r.getrandbits(8))
        e.w32(el + 0x1c, r.choice([0, r.getrandbits(32) | 1]))
    tail_val = r.choice([0, 1, 0x1234])

    def begin(em, rr):
        em.w32(em.arg32(0) + 4, 0)
        em.calllog.append(('list', 0x4c))
        em.ret(argbytes=4)

    def nxt(em, rr):
        it = em.arg32(0)
        idx = em.r32(it + 4)
        valid = 1 if idx < n else 0
        em.w32(it, valid)
        em.w32(it + 4, idx + 1)
        em.calllog.append(('list', 0x5c))
        em.ret(eax=elems[idx] if valid else 0, argbytes=4)

    def remove(em, rr):
        em.calllog.append(('list', 0x44))
        em.ret(argbytes=4)

    def tail(em, rr):
        em.calllog.append(('list', 0x14))
        em.ret(eax=tail_val, argbytes=0)

    ilist = _obj(c, 0x20)
    e.w32(ilist, e.fake_vtable('rm_list', 0x30, {0x14: tail, 0x44: remove, 0x4c: begin, 0x5c: nxt}))
    h2 = _obj(c, 0x20)
    h = _obj(c, 0x20)
    e.w32(h + 0x10, h2)
    e.w32(h + 8, ilist)

    # the allocator: slot 0xcc returns its argument (the element)
    def ident(em, rr):
        em.calllog.append(('alloc', 0xcc))
        em.ret(eax=em.arg32(0), argbytes=4)
    a = _obj(c, 0x10)
    e.w32(a, e.fake_vtable('rm_alloc', 0x40, {0xcc: ident}))
    e.w32(0x70038c, a)

    gate = _obj(c, 0x80)
    z = _obj(c, 0x20)
    e.w32(z + 8, 1)
    y = _obj(c, 0x40)
    e.w32(y + 0x10, z)
    e.w32(gate + 0x54, y)
    geom = _obj(c, 0x100)
    e.w32(geom + 8, gate)
    e.w32(geom + 0x10, h)

    def geom_140(em, rr):
        em.calllog.append(('geom', 0x140))
        em.ret(argbytes=0)
    e.w32(geom, e.fake_vtable('rm_geom', 0x60, {0x140: geom_140}))
    if n and r.random() < 0.7:
        ev = r.choice(elems)
    else:
        ev = r.getrandbits(32) | 1
    return [geom, ev]


S(0x45f7d0, 'ZGEOM::RemoveEventFromList', 'thiscall', None, gen=_rm, n=300)
