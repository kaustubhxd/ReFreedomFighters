"""specs_s4419.py - area 73 batch 19 (gap band, GUESS names). FUN_4f6e50 calls the helper 0x4f9af0 (hooked, logged). The
objects and slots are logging stubs; FUN_4f4580 returns the sign-extended byte at the object returned by its slot (random
memory, so both signs occur)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _self(c):
    e = c.emu
    o = _rnd(c, 0x200)
    e.w32(o + 0x70, c.rng.choice([0x20, c.rng.getrandbits(32)]))
    e.w32(o + 0x8f, c.rng.choice([1, c.rng.getrandbits(32)]))
    e.w32(o, e.logging_vtable('g4f4de0', 0x390 // 4, impl={0x2ec: _const(0), 0x384: _const(0)},
                              argwords={0x2ec: 1, 0x384: 1}))
    return o


def _4f6e50(c):
    e = c.emu
    def h(em, r):
        em.calllog.append(('4f9af0', 0, em.reg('ecx'), ()))
        em.ret()
    e.hook(0x4f9af0, h)
    return [_self(c)]


def _two_ptrs(c):
    return [_self(c), _rnd(c, 0x40)]


def _4f4580(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    o = _rnd(c, 0x100)
    e.w32(self_o + 0x9f, o)
    byte_obj = _rnd(c, 0x40)
    e.w32(byte_obj + 0x10, c.rng.getrandbits(32))
    e.w32(o, e.logging_vtable('g4f4580', 0x290 // 4, impl={0x27c: _const(byte_obj)}, argwords={0x27c: 1}))
    return [self_o, c.rng.getrandbits(32)]


S(0x4f4de0, 'GUESS FUN_4f4de0 (unknown) thiscall', 'thiscall', None, ret=None, gen=lambda c: [_self(c)],
  note='area 73 batch 19; slot +0x2ec(1) when +0x70 != 0x20 and +0x8f != 1')
S(0x4f6e50, 'GUESS FUN_4f6e50 (unknown) thiscall', 'thiscall', None, ret=None, gen=_4f6e50,
  note='area 73 batch 19; helper 0x4f9af0 then slot +0x384(+0x8f)')
S(0x4e4fc0, 'GUESS FUN_4e4fc0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_two_ptrs,
  note='area 73 batch 19; three dwords from arg to +0x21, +0x25, +0x29')
S(0x4f03a0, 'GUESS FUN_4f03a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_two_ptrs,
  note='area 73 batch 19; +0x22, +0x26, +0x2a to the arg pointer')
S(0x4f4580, 'GUESS FUN_4f4580 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_4f4580,
  note='area 73 batch 19; sign-extended byte at slot +0x27c(arg)+0x10')
