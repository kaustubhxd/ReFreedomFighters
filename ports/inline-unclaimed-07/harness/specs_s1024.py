"""specs_s1024.py - unclaimed-07 batch 24 (slice 6): ZTreeGroup::FreeDynamicTrees (0x442f60). The tree pointer at +0x71 is
null about a third of the time; otherwise 0x4e3f00 (thiscall, no arguments) and the delete helper 0x634273 (cdecl) are
hooked to logging stubs, so the call order and the pointer are compared."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _free(c):
    e = c.emu
    o = _rnd(c, 0x100)
    if c.rng.random() < 0.67:
        t = _rnd(c, 0x80)
        e.w32(o + 0x71, t)
    else:
        e.w32(o + 0x71, 0)

    def h4e3f00(em, r):
        em.calllog.append(('4e3f00', 0, em.reg('ecx'), ()))
        em.ret()

    def hdel(em, r):
        em.calllog.append(('delete634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)

    e.hook(0x4e3f00, h4e3f00)
    e.hook(0x634273, hdel)
    return [o]


S(0x442f60, 'ZTreeGroup::FreeDynamicTrees (unknown) thiscall', 'thiscall', None, ret=None, gen=_free,
  note='unclaimed-07 batch 24; tree at +0x71: 0x4e3f00, delete(ptr, 0x2d), clear +0x71')
