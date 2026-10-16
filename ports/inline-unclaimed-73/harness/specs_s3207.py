"""specs_s3207.py - area 73 batch 7 (residue 12): ZActionChamberItem::Load (0x486cc0). The load object is a fake vtable: slot
+0x50 (one argument, a heap pointer, logged); slot +0x68 writes the flag byte and slot +0x40 writes the value through their
stack pointers (not logged; the value written is what the code uses). The value covers 0..7, so the switch's default branch
(assert) is reached too. The assert pointer at 0x7003b0 is a logging stub."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    flag_val = 0 if c.rng.random() < 0.2 else 1
    val = c.rng.randint(0, 7)

    def h50(em, r):
        em.calllog.append(('load', 0x50, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h68(em, r):
        p = em.arg32(0)
        em.calllog.append(('load', 0x68, em.reg('ecx'), ()))
        em.wbytes(p, bytes([flag_val]))
        em.ret(eax=0, argbytes=4)

    def h40(em, r):
        p = em.arg32(0)
        em.calllog.append(('load', 0x40, em.reg('ecx'), ()))
        em.w32(p, val)
        em.ret(eax=0, argbytes=4)

    load = _rnd(c, 0x100)
    e.w32(load, e.fake_vtable('zloadgame_chamber', 0x80 // 4, {0x40: h40, 0x50: h50, 0x68: h68}))

    def assert_fn(em, r):
        em.calllog.append(('assert7003b0', 0, None, ()))
        em.ret(eax=0, argbytes=0)

    e.w32(0x7003b0, e.stub_fn('assert', assert_fn))
    return [self_o, load]


S(0x486cc0, 'ZActionChamberItem::Load (unknown) thiscall', 'thiscall', None, ret=None, gen=_load,
  note='area 73 batch 7; load slots +0x50(+0x2c), +0x68 flag, +0x40 value; switch to this+0x28 or assert')
