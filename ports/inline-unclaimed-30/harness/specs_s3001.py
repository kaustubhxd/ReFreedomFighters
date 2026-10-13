"""specs_s3001.py - unclaimed-30 batch 1 (docs/20-unclaimed-30.md, claim 1): ZGEOM bound distance (0x45ef10, float result in ST0)
and REFTAB::RemoveIfExists (0x4ced10). The REFTAB's iterator slots are logged stubs: begin (+0x4c) resets an index in the
iterator; next (+0x5c) returns the current element and advances; remove (+0x44) is logged. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, sf


def _bound(c):
    e = c.emu
    r = c.rng
    box = rnd(c, 0x60)
    for k in range(3):
        e.wf32(box + 0x30 + 4 * k, sf(c.fv(-200, 200)))
        e.wf32(box + 0x40 + 4 * k, sf(c.fv(0, 150)))
    self_ = rnd(c, 0x20)
    e.w32(self_ + 8, box)
    p = e.alloc(16)
    for k in range(3):
        e.wf32(p + 4 * k, sf(c.fv(-300, 300)))
    return [self_, p]


def _reftab(c):
    e = c.emu
    r = c.rng
    n = r.randint(0, 4)
    elems = [r.getrandbits(32) | 1 for _ in range(n)]

    def begin(em, a):
        em.w32(a[0] + 4, 0)
        em.w32(a[0], 1)
        return 0

    def nxt(em, a):
        idx = em.r32(a[0] + 4)
        valid = 1 if idx < n else 0
        em.w32(a[0], valid)
        em.w32(a[0] + 4, idx + 1)
        return elems[idx] if valid else 0

    def remove(em, rr):
        em.calllog.append(('remove',))
        em.ret(argbytes=0)

    def do_begin(em, rr):
        begin(em, [em.arg32(0)])
        em.calllog.append(('begin',))
        em.ret(argbytes=4)

    def do_next(em, rr):
        v = nxt(em, [em.arg32(0)])
        em.calllog.append(('next',))
        em.ret(eax=v, argbytes=4)
    vt = e.fake_vtable('reftab', 0x20, {0x44: remove, 0x4c: do_begin, 0x5c: do_next})
    tab = e.alloc(0x20)
    e.w32(tab, vt)
    e.w32(tab + 0xc, r.getrandbits(32))
    key = r.choice(elems) if elems and r.random() < 0.7 else r.getrandbits(32) | 1
    return [tab, key]


S(0x45ef10, 'ZGEOM bound distance', 'thiscall', None, ret='st0', gen=_bound, n=300)
S(0x4ced10, 'REFTAB::RemoveIfExists', 'thiscall', None, ret='al', gen=_reftab, n=300)
