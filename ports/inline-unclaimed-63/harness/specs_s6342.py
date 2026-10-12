"""specs_s6342.py - unclaimed-63 gap-band batch 42: 0x4dcac0 (A+D+E set; thiscall, two stack arguments a1 and a2, ret 8).
Fakes per case (the image is restored between runs; the same shape as batch 34's 0x4dca60): the engine 0x70039c (heap) has the geom db
at +0x9b, the db has the object at +0x5d31, and that object's vtable slot 0 records ECX and its argument (the callee pops 4).
a1 is a random 0x24-byte block; a2 is a random triple. In half the cases this+0x24..0x2c is set to the triple and this's first six
dwords are set from a1 (the early return); otherwise one dword is changed. The checker compares the heap and the call log."""
from pilot import S


def _gen_cac0(c):
    e = c.emu
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, c.rng.randbytes(0x40))
    a1 = e.alloc(0x24, 4)
    e.wbytes(a1, c.rng.randbytes(0x24))
    a2 = e.alloc(0x0c, 4)
    e.wbytes(a2, c.rng.randbytes(0x0c))
    if c.rng.random() < 0.5:
        e.wbytes(self_ + 0x24, e.rbytes(a2, 12))
        e.wbytes(self_, e.rbytes(a1, 24))
        if c.rng.random() < 0.5:
            k = c.rng.randrange(6)
            e.w32(self_ + 4 * k, e.r32(self_ + 4 * k) ^ (1 << c.rng.randrange(32)))
    eng = e.alloc(0x200, 4)
    e.w32(0x70039c, eng)
    db = e.alloc(0x6000, 4)
    e.w32(eng + 0x9b, db)
    obj = e.alloc(0x40, 4)
    e.w32(db + 0x5d31, obj)

    def slot0(em, args):
        em.calllog.append(('obj.call', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    vt = e.fake_vtable('obj', 4, {0: slot0})
    e.w32(obj, vt)
    e.mu.ctl_flush_tb()
    return [self_, a1, a2]


S(0x4dcac0, 'unnamed A+D+E 0x4dcac0 thiscall', 'thiscall', None, ret=None, gen=_gen_cac0,
  note='unclaimed-63 band batch 42')
