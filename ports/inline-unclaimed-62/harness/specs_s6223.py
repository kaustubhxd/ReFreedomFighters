"""specs_s6223.py - unclaimed-62 claim 16 (larger, 100 instructions): 0x4d9090 (thiscall, two arguments). The SEH frame is not reproduced.
The object at this+0 is a logged vtable object (slots 0x34 with one argument, 0x2c with two, 4 with one); the exe helpers 0x4d8db0, 0x4d8ef0,
0x4cca60, 0x41e290 and 0x634273 are hooked by address as recording stubs (GUESS: their bodies are not verified here). The object returned by
0x34 is 0 in about half the cases (the create path) and a fresh block otherwise; the 0x4d8ef0 result is 0 or a live slot. No faulting cases."""
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
    blocks = [e.alloc(0x40) for _ in range(4)]
    for b in blocks:
        e.w32(b, vtable(c, 'blk4d9', 0x40, impl={0x4: lambda em, a: r.getrandbits(32)}, argwords={0x4: 1}))
    slots = [e.alloc(16) for _ in range(4)]
    for s in slots:
        e.w32(s, r.getrandbits(32))
    # per case: slot 0x34 gives 0 (create path) or a block with a vtable (the 0x4d8ef0 path); 0x4d8ef0 gives 0 or a live slot
    v34 = r.choice([0, blocks[0], blocks[1]])
    v8ef = r.choice([0, slots[0], slots[1]])
    obj = e.alloc(0x40)
    e.w32(obj, vtable(c, 'obj4d9', 0x100, impl={
        0x34: lambda em, a: v34,
        0x2c: lambda em, a: 0,
        0x4: lambda em, a: r.getrandbits(32)}, argwords={0x34: 1, 0x2c: 2, 0x4: 1}))
    e.w32(rec, obj)
    e.w8(rec + 4, r.choice([0, 1]))

    def h4d8db0(em, rr):
        em.calllog.append(('4d8db0', em.arg32(0), em.arg32(1)))
        em.ret(eax=r.getrandbits(32), argbytes=8)

    def h4d8ef0(em, rr):
        em.calllog.append(('4d8ef0', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=v8ef, argbytes=12)

    def h4cca60(em, rr):
        em.calllog.append(('4cca60', em.arg32(0), em.arg32(1)))
        em.ret(eax=blocks[3], argbytes=8)

    def h41e290(em, rr):
        em.calllog.append(('new', em.arg32(0)))
        em.ret(eax=em.alloc(em.arg32(0), 16, 0x5a), argbytes=0)

    def h634273(em, rr):
        em.calllog.append(('free', em.arg32(0), em.arg32(1)))
        em.ret(argbytes=0)

    e.hook(0x4d8db0, h4d8db0)
    e.hook(0x4d8ef0, h4d8ef0)
    e.hook(0x4cca60, h4cca60)
    e.hook(0x41e290, h41e290)
    e.hook(0x634273, h634273)
    return [rec, r.getrandbits(32), r.getrandbits(32)]


S(0x4d9090, 'unnamed 0x4d9090', 'thiscall', None, ret='eax', gen=_x, n=1000)
