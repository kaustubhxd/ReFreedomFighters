"""specs_s6150.py - area 73 batch 61 (gap band, GUESS name). FUN_4e80c0 (ret 4): r = vtable +8 on this with (arg, 0). When r
is non-null: t = 0x4e8000(this, r) (hooked by address, one argument, ret 4), then vtable +0x20 on the object at this+0x1d with t."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    r = 0 if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    e.w32(o, e.logging_vtable('e80c0', 0x40 // 4, impl={8: (lambda v: (lambda em, a: (v, None)))(r)}, argwords={8: 2}))
    obj = _rnd(c, 0x100)
    e.w32(obj, e.logging_vtable('obj80c0', 0x80 // 4, impl={0x20: lambda em, a: (0, None)}, argwords={0x20: 1}))
    e.w32(o + 0x1d, obj)
    tv = c.rng.getrandbits(32)

    def h(em, rr):
        em.calllog.append(('4e8000', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=tv, argbytes=4)
    e.hook(0x4e8000, h)
    return [o, c.rng.getrandbits(32)]


S(0x4e80c0, 'GUESS FUN_4e80c0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 61; r = vt+8(arg, 0); if r: t = 0x4e8000(this, r); vt(this+0x1d)+0x20(t)')
