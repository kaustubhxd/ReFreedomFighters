"""specs_s3016.py - unclaimed-30 batch 16 (docs/20-unclaimed-30.md, claim 1): 0x558b50 (no name in the name map, stdcall). The argument's
array object (+4) is built valid (three elements; the element pointers come from the exe's 0x5003d0). The exe's 0x4de7a0 runs as exe
code on its temporary; the message table's collision object has a logged slot 0x238 (five arguments; the three vector arguments are
peeked so their contents are compared)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable, sf


def _u(c):
    e = c.emu
    r = c.rng
    data = e.alloc(8 * 4)
    for k in range(3):
        e.wf32(data + 8 * k, sf(c.fv(-300, 300)))
        e.w8(data + 8 * k + 4, r.getrandbits(8))
    P = e.alloc(16)
    e.w32(P, data)
    e.w32(P + 8, 3)
    arr = e.alloc(16)
    e.w32(arr, P)
    e.w32(arr + 4, 0)
    e.w32(arr + 8, 3)
    arg = e.alloc(16)
    e.w32(arg + 4, arr)
    coll = rnd(c, 0x40)
    e.w32(coll, vtable(c, 'coll558', 0x200, argwords={0x238: 5},
                       opts={0x238: {'peek': {0: 36, 1: 12, 2: 12}}}))
    msg = e.alloc(0xb00)
    e.w32(msg + 0xadc, coll)
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    return [arg]


S(0x558b50, 'unnamed 0x558b50', 'stdcall', None, gen=_u, n=300)
