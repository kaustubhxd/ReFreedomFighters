"""specs_s6353.py - unclaimed-63 gap-band batch 53: 0x4dcbb0 (C-set; thiscall, one stack argument b, ret 4). Recursive over a child list.
Fakes per case (the image is restored between runs; hooks set in gen):
  * this: flags at +0x3c from a set of masks (0x40000, 0x200000, 0x200c00, 0x800000, 0x100000, the low byte) so every branch runs;
    +0x64 zero or not; +0x5a zero or not; +0x6c zero or an object m; +0x50 the head of the child list; +0x54 is L (zero in a third);
  * L: +0xc is an info block whose dword +0x23 is random (with 0x100000 and 0x800000 set in some cases); L+0x50 is the first child;
  * the children (0 to 2) chain through +0x60; each child has zero +0x50 and +0x54 (no recursion below depth one), random flags, and
    +0x5a and +0x6c as this;
  * the argument b is a random dword with the low byte zero in a quarter of the cases (the original tests bl only);
  * eng+0x190f is an object whose vtable slot +0x190 (thiscall, two arguments, ret 8) records ECX and its arguments;
  * hooks: 0x4da770 (thiscall, one argument, ret 4), 0x4dc630 (thiscall, two arguments, ret 8), 0x4d9d20 (thiscall, one argument,
    ret 4), 0x4dae60, 0x4d9ce0, 0x4d9bf0 (thiscall, no arguments, plain ret), 0x4daff0 (thiscall, no arguments, returns an object or 0):
    all record their arguments. These are other areas' functions or the parked SEH routine; the recursion runs the original code."""
from pilot import S

MASKS = [0x40000, 0x200000, 0x200c00, 0x800000, 0x100000, 0x40040000, 0xa00000]


def _gen_cbb0(c):
    e = c.emu
    eng = e.alloc(0x2000, 4)
    e.wbytes(eng, bytes(0x2000))
    e.w32(0x70039c, eng)
    obj190 = e.alloc(0x40, 4)
    e.w32(obj190, e.fake_vtable('o190', 0x400 // 4, {0x190: lambda em, a: (em.calllog.append(('o190.call', 0x190, em.reg('ecx'), (em.arg32(0), em.arg32(1)))),
                                                                          em.ret(eax=0, argbytes=8))}))
    e.w32(eng + 0x190f, obj190)
    r_obj = e.alloc(0x40, 4)
    e.w32(r_obj, e.fake_vtable('r', 0x400 // 4, {0x320: lambda em, a: (em.calllog.append(('r.320', 0x320, em.reg('ecx'), (em.arg32(0),))),
                                                                       em.ret(eax=0, argbytes=4))}))
    rv = r_obj if c.rng.random() < 0.5 else 0
    e.hook(0x4da770, lambda em, a: (em.calllog.append(('h.4da770', None, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    e.hook(0x4dc630, lambda em, a: (em.calllog.append(('h.4dc630', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))), em.ret(eax=0, argbytes=8)))
    e.hook(0x4d9d20, lambda em, a: (em.calllog.append(('h.4d9d20', None, em.reg('ecx'), (em.arg32(0),))), em.ret(eax=0, argbytes=4)))
    e.hook(0x4dae60, lambda em, a: (em.calllog.append(('h.4dae60', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    e.hook(0x4d9ce0, lambda em, a: (em.calllog.append(('h.4d9ce0', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    e.hook(0x4d9bf0, lambda em, a: (em.calllog.append(('h.4d9bf0', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    e.hook(0x4daff0, lambda em, a: (em.calllog.append(('h.4daff0', None, em.reg('ecx'), ())), em.ret(eax=rv, argbytes=0)))

    def make_node(depth):
        nd = e.alloc(0x100, 4)
        e.wbytes(nd, bytes(0x100))
        fl = c.rng.choice(MASKS) | (c.rng.getrandbits(32) & c.rng.choice([0, 0xff, 0x3ff00]))
        e.w32(nd + 0x3c, fl & 0xffffffff)
        e.wbytes(nd + 0x5a, c.rng.choice([b'\x00\x00', b'\x01\x00', b'\x01\x00', b'\x01\x00']))
        e.w32(nd + 0x64, c.rng.choice([0, 1]))
        e.w32(nd + 0x6c, obj190 if c.rng.random() < 0.8 else 0)
        return nd

    self_ = make_node(0)
    e.w32(self_ + 0x3c, e.r32(self_ + 0x3c) & ~0x200000)   # the list part runs when this has no 0x200000 (b != 0)
    if c.rng.random() < 0.5:
        L = e.alloc(0x100, 4)
        e.wbytes(L, bytes(0x100))
        info = e.alloc(0x40, 4)
        e.wbytes(info, bytes(0x40))
        bits = c.rng.choice([0x100000, 0x100000, 0x900000, 0x800000, 0])
        e.w32(info + 0x23, bits | (c.rng.getrandbits(32) & 0x0fffffff))
        e.w32(L + 0xc, info)
        kids = [make_node(1) for _ in range(c.rng.randint(0, 2))]
        for i, k in enumerate(kids):
            e.w32(k + 0x50, 0)
            e.w32(k + 0x54, 0)
            e.w32(k + 0x60, kids[i + 1] if i + 1 < len(kids) else 0)
        e.w32(L + 0x50, kids[0] if kids else 0)
        e.w32(self_ + 0x54, L)
    else:
        e.w32(self_ + 0x54, 0)
    # this+0x50 is a parent P with P+0x54 = Q (the 0x4daff0 path reads Q+8, so Q is a valid block)
    P = e.alloc(0x40, 4)
    e.wbytes(P, bytes(0x40))
    Q = e.alloc(0x40, 4)
    e.wbytes(Q, bytes(0x40))
    e.w32(P + 0x54, Q)
    e.w32(self_ + 0x50, P)
    # the original tests bl only, so values with a zero low byte but a non-zero high part are included (0x100)
    b = c.rng.choice([0, 1, 0x100, 0x1ff00, c.rng.getrandbits(32) | 1])
    e.mu.ctl_flush_tb()
    return [self_, b]


S(0x4dcbb0, 'unnamed C-set 0x4dcbb0 thiscall', 'thiscall', None, ret=None, gen=_gen_cbb0,
  note='unclaimed-63 band batch 53; recursion runs the original; helpers hooked')
