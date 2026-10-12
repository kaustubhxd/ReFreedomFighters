"""specs_s4015.py - area 73 batch 15 (gap band, GUESS names). Setters take random arguments. FUN_4fa610 calls a logging slot
+0x2ec when [this+0x70] != 0x20 (the value is random, so both branches run). FUN_4e6810 frees the pointer at this+4 through the
delete helper 0x634273, hooked and logged."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setter(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


def _4fa610(c):
    e = c.emu
    self_o = _rnd(c, 0x200)
    e.w32(self_o + 0x70, c.rng.choice([0x20, 0x20, c.rng.getrandbits(32)]))
    e.w32(self_o, e.logging_vtable('g4fa610', 0x2f0 // 4, impl={0x2ec: lambda em, a: (0, None)}, argwords={0x2ec: 1}))
    return [self_o]


def _4e6810(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    ptr = _rnd(c, 0x20)
    e.w32(self_o + 4, ptr)

    def hdel(em, r):
        em.calllog.append(('delete634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)

    e.hook(0x634273, hdel)
    return [self_o]


S(0x4fa710, 'GUESS FUN_4fa710 (unknown) thiscall', 'thiscall', None, ret=None, gen=_setter,
  note='area 73 batch 15; dword store at +0x8f')
S(0x4f4e00, 'GUESS FUN_4f4e00 (unknown) thiscall', 'thiscall', None, ret=None, gen=_setter,
  note='area 73 batch 15; byte store at +0x88')
S(0x4f9340, 'GUESS FUN_4f9340 (unknown) thiscall', 'thiscall', None, ret=None, gen=_setter,
  note='area 73 batch 15; dword store at +0x1d7')
S(0x4fa610, 'GUESS FUN_4fa610 (unknown) thiscall', 'thiscall', None, ret=None, gen=_4fa610,
  note='area 73 batch 15; slot +0x2ec(1) when +0x70 != 0x20')
S(0x4e6810, 'GUESS FUN_4e6810 (unknown) thiscall', 'thiscall', None, ret=None, gen=_4e6810,
  note='area 73 batch 15; vtable 0x697510; delete(this+4, 4)')
