"""specs_s6560.py - area 73 batch 65 (gap band, GUESS name). FUN_4f71d0 (ret 4): 0x4fa120(this, 1) (hooked by address, one
argument), then when the argument's low byte is 0: vtable +0x35c() and +0x360() on this; otherwise vtable +0x364() on this."""
from pilot import S


def _gen(c):
    e = c.emu

    def h(em, r):
        em.calllog.append(('4fa120', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)
    e.hook(0x4fa120, h)
    o = e.alloc(0x400, 4)
    e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x400)))
    e.w32(o, e.logging_vtable('f71d0', 0x380 // 4,
                              impl={0x35c: lambda em, a: (0, None), 0x360: lambda em, a: (0, None),
                                    0x364: lambda em, a: (0, None)},
                              argwords={0x35c: 0, 0x360: 0, 0x364: 0}))
    flag = c.rng.choice([0, 1, c.rng.getrandbits(8) | 1, c.rng.getrandbits(8) << 8])
    return [o, flag]


S(0x4f71d0, 'GUESS FUN_4f71d0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 65; 0x4fa120(this, 1); arg byte 0: vt+0x35c(), vt+0x360(); else vt+0x364()')
