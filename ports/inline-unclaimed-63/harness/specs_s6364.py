"""specs_s6364.py - unclaimed-63 batch 64: 0x482480 (ZPlayer::ClassInit2; thiscall, no arguments, plain ret).
Fakes per case (the image is restored between runs): this+0x459 is a count 0 to 3; this+0x461 onward holds that many object pointers,
each a fake object (zero in a quarter of the cases) whose vtable slot +0 (thiscall, no arguments, plain ret) records ECX.
0x472fd0 (thiscall, plain ret; another area's code) is a hook that records ECX."""
from pilot import S


def _gen_2480(c):
    e = c.emu
    this = e.alloc(0x500, 4)
    e.wbytes(this, bytes(0x500))
    n = c.rng.randint(0, 3)
    e.w32(this + 0x459, n)
    for i in range(n):
        if c.rng.random() < 0.25:
            e.w32(this + 0x461 + 4 * i, 0)
            continue
        o = e.alloc(0x40, 4)
        e.wbytes(o, bytes(0x40))
        e.w32(o, e.fake_vtable('o', 0x400 // 4, {0: lambda em, a: (em.calllog.append(('obj.0', 0, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0))}))
        e.w32(this + 0x461 + 4 * i, o)
    e.hook(0x472fd0, lambda em, a: (em.calllog.append(('h.472fd0', None, em.reg('ecx'), ())), em.ret(eax=0, argbytes=0)))
    e.mu.ctl_flush_tb()
    return [this]


S(0x482480, 'ZPlayer::ClassInit2 thiscall', 'thiscall', None, ret=None, gen=_gen_2480,
  note='unclaimed-63 batch 64; 0x472fd0 hooked (other area)')
