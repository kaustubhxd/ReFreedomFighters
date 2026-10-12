"""specs_s6460.py - area 73 batch 64 (gap band, GUESS names).
FUN_4e8090 (ret 4, returns 0): t = 0x4e8000(this, arg) (hooked by address, ret 4), then vtable +0x20 on the object at this+0x1d.
FUN_4e66c0 (ret 4, returns this): vtable 0x6974d0; a non-null [this+4] is deleted (size 1); when the argument's low bit is set,
this is deleted (size 0xc). Delete helper 0x634273 hooked and logged.
FUN_4f0460 (ret 4): vtable +0x6c on g_sys+0x9b obj, then 0x45f070(this, arg) (hooked, ret 4), then vtable +0x68 on g_sys+0x9b obj.
FUN_4f83e0 (ret 8): [this+0x93] = a2, [this+0x8f] = a1, vtable +0x364(a2 - a1 + 1), then vtable +0x374(0)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _del_hook(c):
    def h(em, r):
        em.calllog.append(('delete634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    c.emu.hook(0x634273, h)


def _gen_4e8090(c):
    e = c.emu
    o = _rnd(c, 0x100)
    t = c.rng.getrandbits(32)

    def h(em, r):
        em.calllog.append(('4e8000', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=t, argbytes=4)
    e.hook(0x4e8000, h)
    obj = _rnd(c, 0x100)
    e.w32(obj, e.logging_vtable('obj8090', 0x80 // 4, impl={0x20: lambda em, a: (0, None)}, argwords={0x20: 1}))
    e.w32(o + 0x1d, obj)
    return [o, c.rng.getrandbits(32)]


def _gen_4e66c0(c):
    e = c.emu
    _del_hook(c)
    o = _rnd(c, 0x40)
    e.w32(o + 4, _rnd(c, 0x20) if c.rng.random() < 0.6 else 0)
    return [o, c.rng.getrandbits(32)]


def _gen_4f0460(c):
    e = c.emu
    sys = _rnd(c, 0x200)
    ctl = _rnd(c, 0x100)
    e.w32(ctl, e.logging_vtable('ctl0460', 0x80 // 4,
                                impl={0x6c: lambda em, a: (0, None), 0x68: lambda em, a: (0, None)},
                                argwords={0x6c: 0, 0x68: 0}))
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)

    def h(em, r):
        em.calllog.append(('45f070', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)
    e.hook(0x45f070, h)
    o = _rnd(c, 0x100)
    return [o, c.rng.getrandbits(32)]


def _gen_4f83e0(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o, e.logging_vtable('f83e0', 0x380 // 4,
                              impl={0x364: lambda em, a: (0, None), 0x374: lambda em, a: (0, None)},
                              argwords={0x364: 1, 0x374: 1}))
    a1 = c.rng.getrandbits(16)
    a2 = (a1 + c.rng.randint(0, 40)) & 0xffffffff
    return [o, a1, a2]


S(0x4e8090, 'GUESS FUN_4e8090 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4e8090,
  note='area 73 batch 64; t = 0x4e8000(this, arg); vt(this+0x1d)+0x20(t); returns 0')
S(0x4e66c0, 'GUESS FUN_4e66c0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4e66c0,
  note='area 73 batch 64; vt 0x6974d0; delete([this+4], 1); if arg&1: delete(this, 0xc); returns this')
S(0x4f0460, 'GUESS FUN_4f0460 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f0460,
  note='area 73 batch 64; vt(g_sys+0x9b)+0x6c(); 0x45f070(this, arg); vt(g_sys+0x9b)+0x68()')
S(0x4f83e0, 'GUESS FUN_4f83e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f83e0,
  note='area 73 batch 64; [this+0x93]=a2, [this+0x8f]=a1, vt+0x364(a2-a1+1), vt+0x374(0)')
