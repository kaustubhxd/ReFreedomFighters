"""specs_s3024.py - unclaimed-30 claim 2 (residue 10): ZRepositionCharacter::CopyData (0x5c40e0). Source and destination lists are logged
fake lists (begin +0x4c, next +0x5c, add +4 on the destination). The source's list is null in about a quarter of the cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, log_args


def _lst(c, elems, tag):
    e = c.emu
    n = len(elems)

    def begin(em, rr):
        em.w32(em.arg32(0) + 4, 0)
        em.calllog.append((tag, 0x4c))
        em.ret(argbytes=4)

    def nxt(em, rr):
        it = em.arg32(0)
        idx = em.r32(it + 4)
        valid = 1 if idx < n else 0
        em.w32(it, valid)
        em.w32(it + 4, idx + 1)
        em.calllog.append((tag, 0x5c))
        em.ret(eax=elems[idx] if valid else 0, argbytes=4)

    def add(em, rr):
        em.calllog.append((tag, 0x4, em.arg32(0)))
        em.ret(argbytes=4)
    lst = e.alloc(0x20)
    e.w32(lst, e.fake_vtable(tag, 0x20, {0x4: add, 0x4c: begin, 0x5c: nxt}))
    return lst


def _rc(c):
    e = c.emu
    r = c.rng
    elems = [r.getrandbits(32) | 1 for _ in range(r.randint(0, 4))]
    dst_list = _lst(c, [], 'dst')
    self_ = rnd(c, 0x80)
    e.w32(self_ + 0x48, dst_list)
    src = rnd(c, 0x80)
    if r.random() < 0.75:
        e.w32(src + 0x48, _lst(c, elems, 'src'))
    else:
        e.w32(src + 0x48, 0)
    return [self_, src]


S(0x5c40e0, 'ZRepositionCharacter::CopyData', 'thiscall', None, gen=_rc, n=300)
