"""specs_s4520.py - area 73 batch 20 (gap band, GUESS names). FUN_4f50a0 (ret 8) calls slot +0x20 on this and slot +0x128 on the
result; FUN_4f6430 (ret 4) calls the helper 0x4cc500 (hooked, logged, returns a dword) and then slot +0x280 on this."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _50a0(c):
    e = c.emu
    o = _rnd(c, 0x40)
    e.w32(o, e.logging_vtable('g4f50a0o', 0x130 // 4, impl={0x128: _const(0)}, argwords={0x128: 3}))
    self_o = _rnd(c, 0x100)
    e.w32(self_o, e.logging_vtable('g4f50a0s', 0x88 // 4, impl={0x20: _const(o)}, argwords={0x20: 0}))
    return [self_o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _6430(c):
    e = c.emu
    rv = c.rng.getrandbits(32)

    def h(em, r):
        em.calllog.append(('4cc500', 0, em.reg('ecx'), ()))
        em.ret(eax=rv, argbytes=0)

    e.hook(0x4cc500, h)
    self_o = _rnd(c, 0x100)
    e.w32(self_o, e.logging_vtable('g4f6430', 0x290 // 4, impl={0x280: _const(0)}, argwords={0x280: 1}))
    return [self_o, c.rng.getrandbits(32)]


S(0x4f50a0, 'GUESS FUN_4f50a0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_50a0,
  note='area 73 batch 20; slot +0x20 gives o; o slot +0x128(arg1, arg2, 0); returns 0')
S(0x4f6430, 'GUESS FUN_4f6430 (unknown) thiscall', 'thiscall', None, ret=None, gen=_6430,
  note='area 73 batch 20; helper 0x4cc500(arg) then slot +0x280(r)')
