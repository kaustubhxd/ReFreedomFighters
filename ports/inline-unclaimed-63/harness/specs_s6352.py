"""specs_s6352.py - unclaimed-63 gap-band batch 52: 0x4d9430 (A+D+E set; thiscall, no stack arguments, plain ret). SEH frame not
reproduced (tagged): the original's fs:[0] frame is not set up, and its cookie check is not called.
Fakes per case (the image is restored between runs; hooks set in gen):
  * the engine 0x70039c (heap): its +0x9b is the db; db+8 is O1 (vtable slot +0x24, records ECX and its argument); db+0x5d35 is obj
    (vtable slot +0x10, records ECX and its argument) in half the cases, else 0; eng+0x190f is obj2 (vtable slot +0x188, records) in
    half the cases, else 0;
  * this: +0x68 random (zero in a third of the cases); +0x3c random with bit 0x40000 in half the cases, the sign bit in a third, and
    the low byte set in half; +0x64 random; +0x50 is a parent P with P+0x54 = Q (always set), Q+8 = R (a heap object);
  * +0x54 is L (zero in half the cases); L+0xc is an info block whose dword at +0x23 is random; L's vtable slot +0x210 records;
  * Q's vtable slot +0x290 records ECX and its two arguments;
  * 0x4dc630 (thiscall, two arguments), 0x4dae60 (thiscall, no arguments) are hooks recording their arguments; 0x4daff0 (thiscall, no
    arguments) is a hook that returns a fake object with vtable slot +0x320 (records) or 0 at random.
The objects are heap blocks, so the checker compares the stores and the call log."""
from pilot import S


def _rec_vt(e, name, slots):
    return e.fake_vtable(name, 0x400 // 4, slots)


def _gen_9430(c):
    e = c.emu
    self_ = e.alloc(0x100, 4)
    e.wbytes(self_, bytes(0x100))
    flags = c.rng.getrandbits(32)
    if c.rng.random() < 0.5:
        flags |= 0x40000
    else:
        flags &= ~0x40000
    if c.rng.random() < 0.33:
        flags |= 0x80000000
    else:
        flags &= ~0x80000000
    if c.rng.random() < 0.5:
        flags |= 0x1
    else:
        flags &= ~0xff
    if c.rng.random() < 0.15:
        flags = 0          # the zero boundary of the sign test
    e.w32(self_ + 0x3c, flags & 0xffffffff)
    e.w32(self_ + 0x64, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    e.w32(self_ + 0x68, 0 if c.rng.random() < 1 / 3 else c.rng.getrandbits(32))
    # parent P -> Q -> R
    P = e.alloc(0x100, 4)
    e.wbytes(P, bytes(0x100))
    Q = e.alloc(0x100, 4)
    e.wbytes(Q, bytes(0x100))
    R = e.alloc(0x40, 4)
    e.wbytes(R, bytes(0x40))
    e.w32(P + 0x54, Q)
    e.w32(Q + 8, R)
    e.w32(self_ + 0x50, P)
    # list node L with info block
    L = 0
    if c.rng.random() < 0.5:
        info = e.alloc(0x40, 4)
        e.wbytes(info, bytes(0x40))
        e.w32(info + 0x23, c.rng.getrandbits(32))
        L = e.alloc(0x40, 4)
        e.wbytes(L, bytes(0x40))
        e.w32(L + 0xc, info)
    e.w32(self_ + 0x54, L)
    calls = []

    def rec(name):
        def h(em, a):
            em.calllog.append((name, None, em.reg('ecx'), tuple(em.arg32(k) for k in range(2))))
            em.ret(eax=0, argbytes=0)
        return h

    def mk_vt(name, slots):
        out = {}
        for off, nm in slots:
            out[off] = (lambda nm2, nargs: (lambda em, a: (em.calllog.append((nm2, off, em.reg('ecx'), tuple(em.arg32(k) for k in range(nargs)))),
                                                           em.ret(eax=0, argbytes=4 * nargs))))(name + ' ' + nm, 1)
        return _rec_vt(e, name, out)

    e.w32(L, mk_vt('L', [(0x210, '+0x210')])) if L else None
    e.w32(Q, e.fake_vtable('Q', 0x400 // 4, {0x290: lambda em, a: (em.calllog.append(('Q.290', 0x290, em.reg('ecx'), (em.arg32(0), em.arg32(1)))),
                                                                      em.ret(eax=0, argbytes=8))}))
    # engine and its objects
    eng = e.alloc(0x2000, 4)
    e.wbytes(eng, bytes(0x2000))
    db = e.alloc(0x6000, 4)
    e.w32(eng + 0x9b, db)
    e.w32(0x70039c, eng)
    O1 = e.alloc(0x40, 4)
    e.w32(O1, e.fake_vtable('O1', 0x400 // 4, {0x24: lambda em, a: (em.calllog.append(('O1.24', 0x24, em.reg('ecx'), (em.arg32(0),))),
                                                                    em.ret(eax=0, argbytes=4))}))
    e.w32(db + 8, O1)
    if c.rng.random() < 0.5:
        obj = e.alloc(0x40, 4)
        e.w32(obj, e.fake_vtable('obj', 0x400 // 4, {0x10: lambda em, a: (em.calllog.append(('obj.10', 0x10, em.reg('ecx'), (em.arg32(0),))),
                                                                          em.ret(eax=0, argbytes=4))}))
        e.w32(db + 0x5d35, obj)
    else:
        e.w32(db + 0x5d35, 0)
    if c.rng.random() < 0.5:
        obj2 = e.alloc(0x40, 4)
        e.w32(obj2, e.fake_vtable('obj2', 0x400 // 4, {0x188: lambda em, a: (em.calllog.append(('obj2.188', 0x188, em.reg('ecx'), (em.arg32(0),))),
                                                                              em.ret(eax=0, argbytes=4))}))
        e.w32(eng + 0x190f, obj2)
    else:
        e.w32(eng + 0x190f, 0)
    # helpers (other areas' code): 0x4dc630 thiscall two arguments, 0x4dae60 none, 0x4daff0 returns an object or 0
    e.hook(0x4dc630, lambda em, a: (em.calllog.append(('helper.4dc630', None, em.reg('ecx'), (em.arg32(0), em.arg32(1)))),
                                    em.ret(eax=0, argbytes=8)))
    e.hook(0x4dae60, lambda em, a: (em.calllog.append(('helper.4dae60', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    r_obj = e.alloc(0x40, 4)
    e.w32(r_obj, e.fake_vtable('r', 0x400 // 4, {0x320: lambda em, a: (em.calllog.append(('r.320', 0x320, em.reg('ecx'), (em.arg32(0),))),
                                                                         em.ret(eax=0, argbytes=4))}))
    rv = r_obj if c.rng.random() < 0.5 else 0
    e.hook(0x4daff0, lambda em, a: (em.calllog.append(('helper.4daff0', None, em.reg('ecx'), ())), em.ret(eax=rv, argbytes=0)))
    e.mu.ctl_flush_tb()
    return [self_]


S(0x4d9430, 'unnamed A+D+E 0x4d9430 thiscall', 'thiscall', None, ret=None, gen=_gen_9430,
  note='unclaimed-63 band batch 52; SEH frame not reproduced; 0x4dc630/0x4dae60/0x4daff0 hooked (other areas)')
