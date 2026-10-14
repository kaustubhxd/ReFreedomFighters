"""specs_s5834.py - residue 9, 0x489490 (ZMovementBaseMove::Move, gc name map), thiscall, five stack arguments, ret 0x14. The object's own slots +0x40 and +0x48
(five args each) are logging stubs that write nothing; the argument values are random dwords (the float pointers are logged as values)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d9490(c):
    e = c.emu
    rnd = c.rng

    def h40(em, r):
        em.calllog.append(('40', 0, None, tuple(em.arg32(k) for k in range(5))))
        em.ret(eax=0, argbytes=20)

    def h48(em, r):
        em.calllog.append(('48', 0, None, tuple(em.arg32(k) for k in range(5))))
        em.ret(eax=0, argbytes=20)

    vt = e.fake_vtable('d9490_self', 200, {0x40: h40, 0x48: h48})
    self_obj = _rnd(c, 0x100)
    e.w32(self_obj, vt)
    e.w32(self_obj + 0x21, rnd.getrandbits(32))
    return [self_obj] + [rnd.getrandbits(32) for _ in range(5)]


S(0x489490, 'ZMovementBaseMove::Move (gc map) thiscall', 'thiscall', None, ret=None, gen=_d9490,
  note='residue 9; own vt slots +0x40 and +0x48 fake (five args logged)')
