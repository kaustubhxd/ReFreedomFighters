"""specs_s5752.py - unclaimed-57, band batch 52 (GUESS): 0x5d8880. Thiscall, no args. The fields +0x20 and +0x24 are set (or zero) at random. Hooks, logged:
0x41e2c0 (cdecl, one arg), 0x634273 (cdecl, (ptr, size)), 0x43de70 (thiscall, no args, the base destructor). Effects of the hooked callees are not
modelled."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dt(c):
    def l1(em, r):
        em.calllog.append(('41e2c0', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    def l2(em, r):
        em.calllog.append(('634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    def l3(em, r):
        em.calllog.append(('43de70', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x41e2c0, l1)
    c.emu.hook(0x634273, l2)
    c.emu.hook(0x43de70, l3)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x20, c.rng.getrandbits(32) if c.rng.random() < 0.6 else 0)
    c.emu.w32(obj + 0x24, c.rng.getrandbits(32) if c.rng.random() < 0.6 else 0)
    return [obj]


S(0x5d8880, 'unnamed_5d8880 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_dt,
  note='unclaimed-57 band batch 52; 0x41e2c0, 0x634273 and base dtor 0x43de70 hooked and logged')
