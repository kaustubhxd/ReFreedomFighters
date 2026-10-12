"""specs_s6347.py - unclaimed-63 gap-band batch 47: 0x4d95f0 (A+D+E set; thiscall, two stack arguments X and f, ret 8).
Fakes per case (the image is restored between runs):
  * the engine 0x70039c (heap) has the db at +0x9b; db+8 is O1, whose vtable has slots +0x50 (returns a heap pointer P), +0x58
    (returns a non-zero word for P) and +0x5c (returns the table object R for a word, in both calls);
  * R is a 0x40-byte heap block whose count byte at +0x1c is 0 to 7 (so the early return and both float branches run), with random dwords;
  * this+0x3c is random; the early-return mask 0x200c00 is set in a quarter of the cases, and one of its three bits alone in another 30%; this+0x5c is 0 in a third of the cases;
  * X is an object whose vtable slot +0x368 (thiscall, one argument, ret 4) records ECX and its argument;
  * 0x4d9d20 (original code, another area's claim; ret 4, one stack argument) is a hook that records its argument;
  * f is a float argument (F), random bits (NaN and infinities included, through the multiply and the int conversion)."""
from pilot import S, F


def _gen_95f0(c):
    e = c.emu
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(0x100))
    flags = c.rng.getrandbits(32)
    flags &= ~0x200c00
    r = c.rng.random()
    if r < 0.25:
        flags |= 0x200c00                       # all three bits: early return
    elif r < 0.55:
        flags |= c.rng.choice([0x200000, 0x800, 0x400])   # one bit at a time: each must be tested on its own
    e.w32(self_ + 0x3c, flags)
    w = 0 if c.rng.random() < 1 / 3 else c.rng.randint(1, 0xffff)
    e.wbytes(self_ + 0x5c, w.to_bytes(2, 'little'))
    P = e.alloc(0x20, 4)
    e.wbytes(P, bytes(0x20))
    R = e.alloc(0x40, 4)
    e.wbytes(R, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    e.wbytes(R + 0x1c, bytes([c.rng.randint(0, 7)]))
    nw = c.rng.randint(1, 0xffff)
    vt1 = e.fake_vtable('O1', 0x200 // 4, {
        0x50: lambda em, a: (em.calllog.append(('O1.p', 0x50, em.reg('ecx'), ())), em.ret(eax=P, argbytes=0)),
        0x58: lambda em, a: (em.calllog.append(('O1.word', 0x58, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=nw, argbytes=4)),
        0x5c: lambda em, a: (em.calllog.append(('O1.table', 0x5c, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=R, argbytes=4)),
    })
    O1 = e.alloc(0x40, 4)
    e.w32(O1, vt1)
    db = e.alloc(0x20, 4)
    e.w32(db + 8, O1)
    eng = e.alloc(0x200, 4)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    X = e.alloc(0x400, 4)
    e.wbytes(X, bytes(0x400))
    vtx = e.fake_vtable('X', 0x400 // 4, {0x368: lambda em, a: (em.calllog.append(('X.call', 0x368, em.reg('ecx'), (em.arg32(0),))),
                                                                 em.ret(eax=0, argbytes=4))})
    e.w32(X, vtx)
    e.hook(0x4d9d20, lambda em, a: (em.calllog.append(('helper.4d9d20', None, em.reg('ecx'), (em.arg32(0),))),
                                    em.ret(eax=0, argbytes=4)))
    e.mu.ctl_flush_tb()
    fv = c.rng.choice([0.0, 1.0, -2.5, 3.0e3, float('inf'), float('nan')]) if c.rng.random() < 0.3 else \
        __import__('struct').unpack('<f', c.rng.getrandbits(32).to_bytes(4, 'little'))[0]
    return [self_, X, F(fv)]


S(0x4d95f0, 'unnamed A+D+E 0x4d95f0 thiscall', 'thiscall', None, ret=None, gen=_gen_95f0,
  note='unclaimed-63 band batch 47')
