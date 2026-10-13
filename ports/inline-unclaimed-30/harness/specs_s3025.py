"""specs_s3025.py - unclaimed-30 claim 2 (residue 10): ZFFActor::ClassFrameUpdate (0x59e2a0). The exe helpers 0x477a30 and 0x59ead0 are
patched with logged stubs (their bodies belong to other claims); 0x5a3000 is the tail-jump target taken when slot 0x438 is false. The allocator (0x70038c) is a logged object: slot 0x48 gives a fresh
object for 0xff0000 and 0 otherwise. The message table's slot 0x58 gives an object (or 0) with a logged slot 0x2d0. this's slot 0x438
returns a per-case bool. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, vtable


def _cfu(c):
    e = c.emu
    r = c.rng
    ss.patch(c, 0x477a30, ss.rec(c, 0))
    ss.patch(c, 0x59ead0, ss.rec(c, 0))
    ss.patch(c, 0x5a3000, ss.rec(c, 0))
    got = e.alloc(16)
    def alloc48(em, rr):
        arg = em.arg32(0)
        em.calllog.append(('alloc', 0x48, arg))
        em.ret(eax=got if arg == 0xff0000 else 0, argbytes=4)
    alloc = e.alloc(16)
    e.w32(alloc, e.fake_vtable('alloc', 0x60, {0x48: alloc48}))
    e.w32(0x70038c, alloc)
    o = rnd(c, 0x40)
    e.w32(o, vtable(c, 'o2d0', 0x200, argwords={0x2d0: 2}))
    msg = e.alloc(0xb00)
    ret58 = o if r.random() < 0.6 else 0
    e.w32(msg, vtable(c, 'msg', 0x40, impl={0x58: lambda em, a: ret58}, argwords={0x58: 1}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    self_ = rnd(c, 0x1000)
    ok = r.random() < 0.6
    e.w8(self_ + 0x79f, r.choice([0, 1, 1]))
    e.w32(self_ + 0x78a, r.getrandbits(32))
    e.w32(self_ + 0x784, r.choice([0, 1, 2]))
    e.w32(self_ + 0x92e, r.choice([0, 1, 3]))
    e.w32(self_, vtable(c, 'cfu', 0x300, impl={0x438: lambda em, a: 1 if ok else 0},
                        argwords={0x438: 0}))
    return [self_]


S(0x59e2a0, 'ZFFActor::ClassFrameUpdate', 'thiscall', None, gen=_cfu, n=300)
