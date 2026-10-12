"""specs_s5226.py - area 73 batch 52 (gap band, GUESS names): four unnamed functions with no tail jumps.
FUN_4ffba0 and FUN_500a20 are constructor-like (set a vtable word or call the delete helper 0x634273 when the flag's low bit
is set); FUN_4f0eb0 sets a byte and calls vtable slot +0x228 when it changes; FUN_4f6dd0 calls the stdcall helper 0x43ef30
with three arguments, then returns vtable slot +0x370. The helpers are hooked by address and logged."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook_delete(c):
    def hdel(em, r):
        em.calllog.append(('delete634273', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(argbytes=0)
    c.emu.hook(0x634273, hdel)


def _gen_4ffba0(c):
    e = c.emu
    self_o = _rnd(c, 0x100)

    def h(em, r):
        em.calllog.append(('4ffab0', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)
    e.hook(0x4ffab0, h)
    _hook_delete(c)
    return [self_o, c.rng.getrandbits(32)]


def _gen_500a20(c):
    _hook_delete(c)
    return [_rnd(c, 0x100), c.rng.getrandbits(32)]


def _gen_4f0eb0(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    e.wbytes(self_o + 0x20, bytes([c.rng.getrandbits(8)]))
    e.w32(self_o, e.logging_vtable('f0eb0', 0x240 // 4, impl={0x228: lambda em, a: (0, None)}, argwords={0x228: 0}))
    return [self_o, c.rng.getrandbits(32)]


def _gen_4f6dd0(c):
    e = c.emu
    self_o = _rnd(c, 0x100)

    def h(em, r):
        em.calllog.append(('43ef30', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(argbytes=12)
    e.hook(0x43ef30, h)
    rv = c.rng.getrandbits(32)
    e.w32(self_o, e.logging_vtable('f6dd0', 0x380 // 4, impl={0x370: (lambda v: (lambda em, a: (v, None)))(rv)},
                                   argwords={0x370: 0}))
    return [self_o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4ffba0, 'GUESS FUN_4ffba0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4ffba0,
  note='area 73 batch 52; calls 0x4ffab0; flag bit 0 -> delete helper (self, 0x34); returns this')
S(0x500a20, 'GUESS FUN_500a20 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_500a20,
  note='area 73 batch 52; vtable word 0x69c968; flag bit 0 -> delete helper (self, 0x14); returns this')
S(0x4f0eb0, 'GUESS FUN_4f0eb0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f0eb0,
  note='area 73 batch 52; byte +0x20 changes -> vt+0x228(), byte +0x90 = 1')
S(0x4f6dd0, 'GUESS FUN_4f6dd0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_4f6dd0,
  note='area 73 batch 52; stdcall 0x43ef30(a1,a2,a3), then returns vt+0x370()')
