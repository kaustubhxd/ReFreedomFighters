"""specs_s1226.py - pathfinding batch 1226: ZPathfinderControl scalar deleting destructor (0x4c5390).

Stubbed the same way in both builds: the owned list's deleting destructor (vtable slot 0, logged), the engine's message
table (vtable +0x34, logged), and the delete hook at 0x7003b0 (returns). The exe's SEH frame is not reproduced.
"""
import struct
from pilot import S
from pfspec import rnd, reporter, vtable, hooks
import pilot


def _dtor(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    e.w32(0x7003b0, e.stub_fn('delete hook', lambda em, rr: em.ret()))
    lst = e.alloc(0x40, 4)
    e.w32(lst, vtable(c, 'list', 0x40, impl={0: lambda em, a: 0}, argwords={0: 1}))
    eng = e.alloc(0x200, 4)
    e.wbytes(eng, bytes(0x200))
    msgs = e.alloc(0x40, 4)
    e.w32(msgs, vtable(c, 'msgs', 0x40, impl={0x34: lambda em, a: 0}, argwords={0x34: 1}))
    e.w32(eng + 0x9b, msgs)
    e.w32(0x70039c, eng)
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(0x100))
    if r.random() < 0.8:
        e.w32(self_ + 0x48, lst)
    e.w32(self_ + 0x44, r.getrandbits(32))
    e.w32(self_ + 0x30, r.getrandbits(32))
    return [self_, r.choice([0, 1, 2, 4, 5, 6, 7, 3])]


S(0x4c5390, 'ZPathfinderControl::~ZPathfinderControl', 'thiscall', None, ret='eax', gen=_dtor, n=200)
