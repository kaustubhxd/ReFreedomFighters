"""specs_s2803.py - area 73 batch 3 (residue 12): ZPlayer::CopyDataBlock (0x482800). The helpers 0x473370, 0x4e1600 (returns
a byte, 0x0b in 40% of cases), 0x4e12e0, 0x4e1b30 and 0x4dc630 are hooked to logging stubs. The player's own slots +0x40 and
+0x20 are logging stubs (+0x20 returns an object whose +8 field is an object)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    e = c.emu
    self_o = _rnd(c, 0x800)
    dblk = _rnd(c, 0x100)
    ret4e1600 = 0x0b if c.rng.random() < 0.4 else c.rng.getrandbits(32)

    def log(name, nargs):
        def h(em, r):
            args = tuple(em.arg32(k) for k in range(nargs))
            em.calllog.append((name, 0, em.reg('ecx'), args))
            em.ret(eax=0, argbytes=4 * nargs)
        return h

    def h4e1600(em, r):
        em.calllog.append(('4e1600', 0, em.reg('ecx'), ()))
        em.ret(eax=ret4e1600, argbytes=0)

    e.hook(0x473370, log('473370', 1))
    e.hook(0x4e1600, h4e1600)
    e.hook(0x4e12e0, log('4e12e0', 2))
    e.hook(0x4e1b30, log('4e1b30', 0))
    e.hook(0x4dc630, log('4dc630', 2))

    obj8 = _rnd(c, 0x40)
    e.w32(self_o + 8, obj8)
    obj = _rnd(c, 0x100)
    obj8b = _rnd(c, 0x40)
    e.w32(obj + 8, obj8b)
    e.w32(self_o, e.logging_vtable('player', 0x48 // 4, impl={0x40: _const(0), 0x20: lambda em, a: (obj, None)},
                                   argwords={0x40: 0, 0x20: 0}))
    return [self_o, dblk]


def _const(v):
    return lambda em, a: (v, None)


S(0x482800, 'ZPlayer::CopyDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='area 73 batch 3; helpers 0x473370, 0x4e1600, 0x4e12e0, 0x4e1b30, 0x4dc630; slots +0x40 and +0x20')
