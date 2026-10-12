"""specs_s262.py - unclaimed area 67, slice 6: four functions; three call through vtable slots (logged fakes)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vtobj(c, slot, argwords):
    vt = c.emu.logging_vtable('Slot%x' % slot, 0x140, impl={slot: lambda e, a: (c.rng.getrandbits(32), None)},
                              argwords={slot: argwords})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    return o


def _slot30(c):
    inner = _vtobj(c, 0x30, 1)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x2c, inner)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _slot1c(c):
    inner = _vtobj(c, 0x1c, 0)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x65, inner)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _slot100(c):
    vt = c.emu.logging_vtable('Slot100', 0x140, impl={0x100: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={0x100: 0})
    o = _rnd(c, 0x100)
    c.emu.w32(o, vt)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _zero(c):
    o = _rnd(c, 0xd00)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x612160, 'FUN_612160 (callSlot30)', 'thiscall', None, ret='eax', gen=_slot30, note='batch262; slot 0x30 with ecx = vtable')
S(0x436120, 'FUN_436120 (tailSlot1c)', 'thiscall', None, ret='eax', gen=_slot1c, note='batch262; tail call slot 0x1c of this+0x65')
S(0x45eda0, 'FUN_45eda0 (tailSlot100)', 'thiscall', None, ret='eax', gen=_slot100, note='batch262; tail call slot 0x100 of this')
S(0x491b60, 'FUN_491b60 (zeroAtBc5)', 'thiscall', None, ret=None, gen=_zero, note='batch262; zero at +0xbc5, ret 8')
