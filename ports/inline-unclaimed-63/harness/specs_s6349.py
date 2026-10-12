"""specs_s6349.py - unclaimed-63 gap-band batch 49: 0x4cd470 (C-set; thiscall, one stack argument A, ret 4, returns a pointer).
Fakes per case (the image is restored between runs):
  * this+0x18 is 0 to 3 (the index offset), this+0x20 is 0 or a heap node (its +4 is written), this+0x1c is random;
  * this+0x24 is a fake object O in half of the cases, else 0 (the 0x4cd540 path, a hook of another area's code, which returns a
    heap entry E; E-4 is inside the heap block);
  * O's vtable (records ECX and its argument; ret 4 unless stated): slot 0 (the deleting destructor), +0x44 (writes the flag L through
    its argument), +0x4c (plain), +0x5c (writes the flag L and returns a node N, a heap block with N-8 .. N+0x38 inside it), and
    +0x14 (no arguments, returns 0 or 1; ret 0);
  * the argument A is a heap cell (it is written through when L is 0);
  * the flag L is 0 or 1 at random, so both the L != 0 and the L == 0 paths run;
  * the value of 0x4cd540 is recorded as a call, the object and the store are compared through the heap."""
from pilot import S


def _gen_d470(c):
    e = c.emu
    self_ = e.alloc(0x40, 4)
    e.wbytes(self_, bytes(0x40))
    e.w32(self_ + 0x18, c.rng.randint(0, 3))
    e.w32(self_ + 0x1c, c.rng.getrandbits(32))
    if c.rng.random() < 0.5:
        t = e.alloc(0x20, 4)
        e.wbytes(t, bytes(0x20))
        e.w32(self_ + 0x20, t)
    else:
        e.w32(self_ + 0x20, 0)
    Lflag = c.rng.randint(0, 1)
    Lflag2 = c.rng.randint(0, 1)
    ret14 = c.rng.randint(0, 1)
    N = e.alloc(0x40, 4) + 8
    e.wbytes(N - 8, bytes(0x48))

    def slot0(em, a):
        em.calllog.append(('O.dtor', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def slot44(em, a):
        em.calllog.append(('O.44', 0x44, em.reg('ecx'), ()))
        em.w32(em.arg32(0), Lflag2)
        em.ret(eax=0, argbytes=4)

    def slot4c(em, a):
        em.calllog.append(('O.4c', 0x4c, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=4)

    def slot5c(em, a):
        em.calllog.append(('O.5c', 0x5c, em.reg('ecx'), ()))
        em.w32(em.arg32(0), Lflag)
        em.ret(eax=N, argbytes=4)

    def slot14(em, a):
        em.calllog.append(('O.14', 0x14, em.reg('ecx'), ()))
        em.ret(eax=ret14, argbytes=0)
    obj_present = c.rng.random() < 0.5
    if obj_present:
        O = e.alloc(0x40, 4)
        e.w32(O, e.fake_vtable('O', 0x100 // 4, {0: slot0, 0x44: slot44, 0x4c: slot4c, 0x5c: slot5c, 0x14: slot14}))
        e.w32(self_ + 0x24, O)
    else:
        e.w32(self_ + 0x24, 0)
    E = e.alloc(0x40, 4) + 8
    e.wbytes(E - 8, bytes(0x48))
    e.hook(0x4cd540, lambda em, a: (em.calllog.append(('helper.4cd540', None, em.reg('ecx'), (em.arg32(0),))),
                                    em.ret(eax=E, argbytes=4)))
    e.mu.ctl_flush_tb()
    # the argument is stored through when the flag is 0 (and by the 0x4cd540 path the store goes to the entry), so it is a heap cell
    A = e.alloc(0x40, 4) + 8
    e.wbytes(A - 8, bytes(0x48))
    return [self_, A]


S(0x4cd470, 'unnamed C-set 0x4cd470 thiscall', 'thiscall', None, ret='eax', gen=_gen_d470,
  note='unclaimed-63 band batch 49; 0x4cd540 stubbed (area 21)')
