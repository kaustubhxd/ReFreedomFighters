"""specs_s6346.py - unclaimed-63 gap-band batch 46: 0x4dc1e0 (A+D+E set; thiscall, one stack argument X, ret 4).
Fakes per case (the image is restored between runs):
  * the engine 0x70039c (heap) has the db at +0x9b, and the db's +8 is the object O1; O1's vtable slot +0x5c (thiscall, ret 4,
    records ECX and its argument) returns a table object R (0x40 bytes: the count byte at +0x1c is 0 to 4, the dwords before it are
    X or random);
  * this's word at +0x5c is 0 in a third of the cases, else random and non-zero;
  * X is an object whose vtable slot +0x36c (thiscall, ret 4) records ECX and its argument;
  * 0x4dc140 and 0x4da770 (original code) are hooks that record ECX and the argument, with ret 4.
Both found and not-found scans run."""
from pilot import S


def _gen_1e0(c):
    e = c.emu
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(0x100))
    w = 0 if c.rng.random() < 1 / 3 else c.rng.randint(1, 0xffff)
    e.wbytes(self_ + 0x5c, w.to_bytes(2, 'little'))
    X = e.alloc(0x400, 4)
    e.wbytes(X, bytes(0x400))
    vtx = e.fake_vtable('X', 0x400 // 4, {0x36c: lambda em, a: (em.calllog.append(('X.call', 0x36c, em.reg('ecx'), (em.arg32(0),))),
                                                                 em.ret(eax=0, argbytes=4))})
    e.w32(X, vtx)
    R = e.alloc(0x40, 4)
    e.wbytes(R, bytes(0x40))
    n = c.rng.randint(0, 4)
    e.wbytes(R + 0x1c, bytes([n]))
    for i in range(n):
        e.w32(R + 4 * i, X if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    O1 = e.alloc(0x40, 4)
    vt1 = e.fake_vtable('O1', 0x200 // 4, {0x5c: lambda em, a: (em.calllog.append(('O1.get', 0x5c, em.reg('ecx'), (em.arg32(0),))),
                                                                em.ret(eax=R, argbytes=4))})
    e.w32(O1, vt1)
    db = e.alloc(0x20, 4)
    e.w32(db + 8, O1)
    eng = e.alloc(0x200, 4)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    e.hook(0x4dc140, lambda em, a: (em.calllog.append(('helper.4dc140', None, em.reg('ecx'), (em.arg32(0),))),
                                    em.ret(eax=0, argbytes=4)))
    e.hook(0x4da770, lambda em, a: (em.calllog.append(('helper.4da770', None, em.reg('ecx'), (em.arg32(0),))),
                                    em.ret(eax=0, argbytes=4)))
    e.mu.ctl_flush_tb()
    return [self_, X]


S(0x4dc1e0, 'unnamed A+D+E 0x4dc1e0 thiscall', 'thiscall', None, ret=None, gen=_gen_1e0,
  note='unclaimed-63 band batch 46')
