"""specs_s6341.py - unclaimed-63 gap-band batch 41: 0x4db7e0 (C-set; thiscall, no stack arguments, returns a node pointer or 0).
Fakes per case (the image is restored between runs):
  * this+0x54 is the first child (or 0), this+0x50 is a parent whose +0x54 is a child (or 0); both branches run;
  * each child has a fake vtable: slot +0x1e0 (thiscall, one argument, ret 4) returns a random boolean in al (the other bits random),
    and slot +0x20 (thiscall, ret 0) returns the next child of a chain of 0 to 3 children (0 at the end), by child address;
  * each child's +0xc points to an info block whose dword at +0x23 is random, with the 0x100000 bit set in half the cases.
The children's predicate results are fixed per case, so the first true child (or none) is found in the chain order."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_7e0(c):
    e = c.emu
    self_ = _rnd(c, 0x60)
    par = _rnd(c, 0x60)
    kids = [_rnd(c, 0x60) for _ in range(c.rng.randint(0, 3))]
    nxt = {k: (kids[i + 1] if i + 1 < len(kids) else 0) for i, k in enumerate(kids)}
    pred = {k: c.rng.random() < 0.25 for k in kids}
    rnd_ret = {k: c.rng.getrandbits(32) for k in kids}

    def slot1e0(em, a):
        ecx = em.reg('ecx')
        em.calllog.append(('child.pred', 0x1e0, ecx, (em.arg32(0),)))
        em.ret(eax=((rnd_ret[ecx] & ~0xff) | (1 if pred.get(ecx) else 0)), argbytes=4)

    def slot20(em, a):
        ecx = em.reg('ecx')
        em.calllog.append(('child.next', 0x20, ecx, ()))
        em.ret(eax=nxt.get(ecx, 0), argbytes=0)
    vt = e.fake_vtable('child', 0x200 // 4, {0x1e0: slot1e0, 0x20: slot20})
    for k in kids:
        e.w32(k, vt)
        info = _rnd(c, 0x30)
        v = c.rng.getrandbits(32)
        if c.rng.random() < 0.5:
            v |= 0x100000
        else:
            v &= ~0x100000
        e.w32(info + 0x23, v)
        e.w32(k + 0xc, info)
    # the parent's +0x54 and this's +0x54 point to the chain (or nothing)
    e.w32(self_ + 0x54, kids[0] if kids and c.rng.random() < 0.7 else 0)
    e.w32(self_ + 0x50, par)
    e.w32(par + 0x54, kids[0] if kids and c.rng.random() < 0.5 else 0)
    e.mu.ctl_flush_tb()
    return [self_]


S(0x4db7e0, 'unnamed C-set 0x4db7e0 thiscall', 'thiscall', None, ret='eax', gen=_gen_7e0,
  note='unclaimed-63 band batch 41')
