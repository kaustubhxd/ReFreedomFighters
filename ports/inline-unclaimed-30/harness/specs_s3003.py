"""specs_s3003.py - unclaimed-30 batch 3 (docs/20-unclaimed-30.md, claim 1): ZOffsetAlloc ctor (0x4ccdd0). The entry buffer comes
from the exe's operator new through the allocator object at 0x70038c (slot +8 = alloc, logged). Cases keep a2 > a1, so the
assert branch is reached on a third of the cases (a2 == a1) with a logged hook installed at 0x7003b0; without a hook
the exe traps with int3. The capacity is small so the allocation never fails."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _alloc_obj(c):
    e = c.emu

    def new(em, rr):
        n = em.arg32(0)
        em.calllog.append(('alloc', n))
        em.ret(eax=em.alloc(n, 16, 0x5a) if n < 0x200000 else 0, argbytes=4)
    a = e.alloc(16)
    e.w32(a, e.fake_vtable('allocator', 0x10, {8: new}))
    e.w32(0x70038c, a)


def _offalloc(c):
    r = c.rng
    e = c.emu
    _alloc_obj(c)
    obj = e.alloc(0x20)
    # the assert hook (0x7003b0) is always set, so the a2 <= a1 branch runs without the int3 trap
    def hook(em, rr):
        em.calllog.append(('assert',))
        em.ret(argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert_hook', hook))
    a1 = r.getrandbits(16)
    a2 = a1 if r.random() < 0.3 else a1 + 1 + r.getrandbits(16)
    cap = r.randint(1, 8)
    return [obj, a1, a2, cap]


S(0x4ccdd0, 'ZOffsetAlloc::ZOffsetAlloc', 'thiscall', None, gen=_offalloc, n=300)
