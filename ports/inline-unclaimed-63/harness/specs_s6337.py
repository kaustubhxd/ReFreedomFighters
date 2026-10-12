"""specs_s6337.py - unclaimed-63 gap-band batch 37: 0x4cd300 (C-set; thiscall, one flags argument, ret 4). SEH tagged: the SEH frame and
the cookie are not reproduced (see the source comment).
Fakes per case (the image is restored between runs):
  * the exe's vtable 0x695734 is written into the image: its slot +0x7c is a fake (records ECX and its node argument, ret 4). The
    function writes 0x695734 into this[0] before the walk, so the slot is what both sides call;
  * 0x634273 (the deleter, cdecl): a hook that records its two arguments (the object and the size 0x1c; caller cleans);
  * the list: 0 to 4 heap nodes linked through +4 (the last points to 0), and this+0xc, +0x14 are random.
The flags argument is random, so the delete path runs in half the cases."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_cd30(c):
    e = c.emu
    self_ = _rnd(c, 0x20)
    nodes = [_rnd(c, 0x10) for _ in range(c.rng.randint(0, 4))]
    for i, nd in enumerate(nodes):
        e.w32(nd + 4, nodes[i + 1] if i + 1 < len(nodes) else 0)
    e.w32(self_ + 4, nodes[0] if nodes else 0)

    def slot7c(em, args):
        em.calllog.append(('this.node', 0x7c, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    e.w32(0x695734 + 0x7c, e.stub_fn('vt 0x695734 +0x7c', slot7c))

    def deleter(em, args):
        em.calllog.append(('deleter', 0x634273, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, deleter)
    e.mu.ctl_flush_tb()
    return [self_, c.rng.getrandbits(32)]


S(0x4cd300, 'unnamed C-set 0x4cd300 thiscall', 'thiscall', None, ret=None, gen=_gen_cd30,
  note='unclaimed-63 band batch 37; SEH frame not reproduced')
