"""specs_s957.py - area 56 band, claim A19: 0x53a8f0 (vt[0](1) on this+0 and on this+4, each when non-null).

The object is 0x40 random bytes; +0 and +4 are each null in about one case in four, otherwise a fake object whose slot 0 is a
GUESS recording stub (logs its argument, plain ret 4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    rng = c.rng

    def h0(e2, r):
        e2.calllog.append(('Slot0', e2.reg('ecx'), e2.arg32(0)))
        e2.ret(argbytes=4)

    this = _rnd(c, 0x40)
    for off in (0, 4):
        if rng.random() < 0.25:
            e.w32(this + off, 0)
        else:
            o = e.fake_object('pair_obj', 0x40, slots={0: h0})
            e.w32(this + off, o)
    return [this]


S(0x53a8f0, 'unnamed 0x53a8f0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A19; slot 0 of each sub-object is a GUESS recording stub')
