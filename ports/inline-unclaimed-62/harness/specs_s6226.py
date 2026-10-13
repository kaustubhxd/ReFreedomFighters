"""specs_s6226.py - unclaimed-62 claim 19 (larger, 103 instructions): 0x4ce6a0 (thiscall, two arguments; returns eax). The sub-object C at this+0x24
is embedded-vtable free: C is null in about a third of the cases (the 0x4cd540 path, a logged hook that returns a block + 4) and otherwise a
logged vtable object (slots 0 (release, 1 arg), 0x14 (0 or non-zero), 0x44, 0x4c (writes the loc word), 0x5c (writes the loc word, returns a
region pointer)). The list words (a1 - 8 + 4n, this+0x1c, this+0x20) are null or point at small blocks, so every write is in range. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _x(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x100)
    n = r.randint(2, 5)
    e.w32(rec + 0x18, n)
    blocks = [e.alloc(0x40) for _ in range(3)]
    loc0 = r.choice([0, 1])
    region = e.alloc(0x80)
    e.wbytes(region, bytes(r.getrandbits(8) for _ in range(0x80)))
    mid = region + 0x40        # the 0x5c result: edi = mid + (2 - n) * 4 stays inside the region

    def loc_set(em, a):
        em.w32(a[0], loc0)
        return 0

    def ret5c(em, a):
        em.w32(a[0], loc0)
        return mid

    if r.random() < 0.67:
        cobj = e.alloc(0x40)     # the sub-object: its first dword is the vtable
        e.w32(cobj, vtable(c, 'cobj4ce', 0x80, impl={0x0: lambda em, a: 0, 0x14: lambda em, a: r.choice([0, 1, 5]),
                                                     0x44: lambda em, a: 0, 0x4c: loc_set, 0x5c: ret5c},
                           argwords={0x0: 1, 0x14: 0, 0x44: 1, 0x4c: 1, 0x5c: 1}))
        e.w32(rec + 0x24, cobj)
    else:
        e.w32(rec + 0x24, 0)
    blk = blocks[0]
    e.w32(rec + 0x1c, r.choice([0, blk]))
    e.w32(rec + 0x20, r.choice([0, blocks[1]]))
    base = e.alloc(0x100)
    a1 = base + 0x20
    slot = base + 0x18 + 4 * n
    e.w32(slot, r.choice([0, blocks[2]]))

    def h4cd540(em, rr):
        em.calllog.append(('4cd540', em.arg32(0)))
        em.ret(eax=blocks[2] + 4, argbytes=4)
    e.hook(0x4cd540, h4cd540)
    a2 = e.alloc(0x40)
    e.wbytes(a2, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [rec, a1, a2]


S(0x4ce6a0, 'unnamed 0x4ce6a0', 'thiscall', None, ret='eax', gen=_x, n=1000)
