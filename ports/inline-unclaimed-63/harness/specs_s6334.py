"""specs_s6334.py - unclaimed-63 gap-band batch 34: 0x4dca60 (A+D set; thiscall, one pointer argument, ret 4).
The engine 0x70039c (heap fake) has a geom db at +0x9b, and the db has the object at +0x5d31. That object's vtable slot 0
(a fake) records ECX and its argument (the contents, not the address) and pops 4. The argument is a random 0x24-byte block.
In half the cases it matches this in its first 24 bytes (the early return), otherwise one of the six dwords differs.
Heap writes (the 0x24-byte copy, bit 0x100000) are compared by the checker."""
from pilot import S


def _gen_dca60(c):
    e = c.emu
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, c.rng.randbytes(0x40))
    arg = e.alloc(0x40, 4)
    e.wbytes(arg, c.rng.randbytes(0x40))
    if c.rng.random() < 0.5:
        e.wbytes(arg, e.rbytes(self_, 24))
        if c.rng.random() < 0.5:
            k = c.rng.randrange(6)
            e.w32(arg + 4 * k, e.r32(arg + 4 * k) ^ (1 << c.rng.randrange(32)))
    eng = e.alloc(0x200, 4)
    e.w32(0x70039c, eng)
    db = e.alloc(0x6000, 4)
    e.w32(eng + 0x9b, db)
    obj = e.alloc(0x40, 4)
    e.w32(db + 0x5d31, obj)

    def slot0(em, r):
        em.calllog.append(('obj.call', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    vt = e.fake_vtable('obj', 4, {0: slot0})
    e.w32(obj, vt)
    e.mu.ctl_flush_tb()
    return [self_, arg]


S(0x4dca60, 'unnamed A+D 0x4dca60 thiscall', 'thiscall', None, ret=None, gen=_gen_dca60,
  note='unclaimed-63 band batch 34')
