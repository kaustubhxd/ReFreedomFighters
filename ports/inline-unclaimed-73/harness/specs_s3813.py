"""specs_s3813.py - area 73 batch 13 (gap band, GUESS names): FUN_4f65d0 (returns [[this+0x97]+0xc]), FUN_4e6870 (vtable slot 0
with twice [this+8]), FUN_4f22c0 (returns the low byte of its argument), FUN_4f65f0 (vtable slot +0xbc with 1). Slots are logging stubs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _const(v):
    return lambda em, a: (v, None)


def _ret_chain(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    inner = _rnd(c, 0x40)
    e.w32(inner + 0xc, c.rng.getrandbits(32))
    e.w32(self_o + 0x97, inner)
    return [self_o]


def _slot0(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    e.w32(self_o + 8, c.rng.getrandbits(32))
    e.w32(self_o, e.logging_vtable('g4e6870', 0x40 // 4, impl={0: _const(0)}, argwords={0: 1}))
    return [self_o]


def _byte_arg(c):
    self_o = _rnd(c, 0x40)
    return [self_o, c.rng.getrandbits(32)]


def _slotbc(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    e.w32(self_o, e.logging_vtable('g4f65f0', 0x100 // 4, impl={0xbc: _const(0)}, argwords={0xbc: 1}))
    return [self_o]


S(0x4f65d0, 'GUESS FUN_4f65d0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ret_chain,
  note='area 73 batch 13; [[this+0x97]+0xc]')
S(0x4e6870, 'GUESS FUN_4e6870 (unknown) thiscall', 'thiscall', None, ret=None, gen=_slot0,
  note='area 73 batch 13; vtable slot 0 with [this+8]*2')
S(0x4f22c0, 'GUESS FUN_4f22c0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_byte_arg,
  note='area 73 batch 13; low byte of arg')
S(0x4f65f0, 'GUESS FUN_4f65f0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_slotbc,
  note='area 73 batch 13; vtable slot +0xbc with 1')
