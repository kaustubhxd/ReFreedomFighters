"""specs_s6343.py - unclaimed-63 gap-band batch 43: 0x4d2fe0 (C-set; thiscall, one stack argument P, ret 4).
Fakes per case (the image is restored between runs):
  * this: vtable slot +0xc (thiscall, no arguments) records ECX;
  * P: vtable slot +0x18 (thiscall, buffer and length; ret 8). With length 4 it writes the next value of a short sequence
    (0 to 3 small sizes, then -1 to end the loop) into the buffer; otherwise it writes random bytes into the buffer.
    Slot +0x40 (thiscall, one argument, ret 4) writes an index 0 to 30 through its argument (the caller's argument slot);
  * 0x4cd9b0 (the pool allocator, hook, thiscall, ret 8) records its arguments and returns a 0x10-aligned offset below 0x800;
  * the object at this+0x4008: vtable slot +4 (thiscall, one argument, ret 4) records ECX and its argument.
this+0x4004 is a 0x1000-byte heap block, so the copied bytes stay inside it."""
from pilot import S


def _gen_2fe0(c):
    e = c.emu
    self_ = e.alloc(0x4100, 4)
    e.wbytes(self_, bytes(0x4100))
    buf = e.alloc(0x1000, 4)
    e.w32(self_ + 0x4004, buf)

    def slot_c(em, a):
        em.calllog.append(('this.init', 0xc, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    e.w32(self_, e.fake_vtable('this', 0x200 // 4, {0xc: slot_c}))

    seq = [c.rng.choice([0, 1, 2, 8, 0x10, 0x23, 0x40]) for _ in range(c.rng.randint(0, 3))] + [0xffffffff]
    pos = [0]

    def slot18(em, a):
        ecx = em.reg('ecx')
        dst, ln = em.arg32(0), em.arg32(1)
        em.calllog.append(('P.read', 0x18, ecx, (ln,)))
        if ln == 4:
            v = seq[pos[0]] if pos[0] < len(seq) else 0xffffffff
            pos[0] += 1
            em.w32(dst, v)
        else:
            em.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(ln)))
        em.ret(eax=0, argbytes=8)

    def slot40(em, a):
        em.calllog.append(('P.index', 0x40, em.reg('ecx'), ()))
        em.w32(em.arg32(0), c.rng.randint(0, 30))
        em.ret(eax=0, argbytes=4)
    P = e.alloc(0x20, 4)
    e.w32(P, e.fake_vtable('P', 0x200 // 4, {0x18: slot18, 0x40: slot40}))

    e.hook(0x4cd9b0, lambda em, a: (em.calllog.append(('pool.alloc', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))),
                                    em.ret(eax=0x10 * c.rng.randrange(0, 0x80), argbytes=8)))

    obj = self_ + 0x4008

    def slot4(em, a):
        em.calllog.append(('O.store', 4, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.w32(obj, e.fake_vtable('O', 0x200 // 4, {4: slot4}))
    e.mu.ctl_flush_tb()
    return [self_, P]


S(0x4d2fe0, 'unnamed C-set 0x4d2fe0 thiscall', 'thiscall', None, ret=None, gen=_gen_2fe0,
  note='unclaimed-63 band batch 43')
