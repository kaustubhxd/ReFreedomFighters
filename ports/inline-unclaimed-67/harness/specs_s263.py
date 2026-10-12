"""specs_s263.py - unclaimed area 67, slice 6: five small functions (three call through vtable slots, logged fakes)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vtobj(c, slot, argwords):
    vt = c.emu.logging_vtable('V%x' % slot, 0x140, impl={slot: lambda e, a: (c.rng.getrandbits(32), None)},
                              argwords={slot: argwords})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    return o


def _obj_a(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


def _obj_bc(c):
    o = _vtobj(c, 0xbc, 1)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _obj_d0(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(8)]


def _copy(c):
    dst = _rnd(c, 0x20)
    src = _rnd(c, 0x20)
    c.emu.mu.ctl_flush_tb()
    return [dst, src]


def _cdecl(c):
    o = _vtobj(c, 0x28, 1)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x5f2c20, 'FUN_5f2c20 (addToPlus8)', 'thiscall', None, ret=None, gen=_obj_a, note='batch263; this+8 += arg')
S(0x4f3fe0, 'FUN_4f3fe0 (callSlotBc)', 'thiscall', None, ret='al', gen=_obj_bc, note='batch263; slot 0xbc with arg 0, returns 0')
S(0x4bcc20, 'FUN_4bcc20 (setByteD0)', 'thiscall', None, ret=None, gen=_obj_d0, note='batch263; byte at +0xd0')
S(0x460e20, 'FUN_460e20 (copy12)', 'fastcall', None, ret=None, gen=_copy, note='batch263; three dwords, edx to ecx')
S(0x61bc60, 'FUN_61bc60 (callSlot28)', 'cdecl', None, ret=None, gen=_cdecl, note='batch263; slot 0x28 of the first argument')
