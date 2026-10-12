"""specs_s267.py - unclaimed area 67, slice 6: two functions that call through vtable slots (logged fakes)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, slots):
    vt = c.emu.logging_vtable('V267', 0x540, argwords=slots)
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    return o


def _replace(c):
    o = _rnd(c, 0x400)
    if c.rng.random() < 0.6:
        inner = _vt(c, {0x210: 1})
        c.emu.w32(o + 0x1db, inner)
    else:
        c.emu.w32(o + 0x1db, 0)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


def _two(c):
    o = _rnd(c, 0x100)
    obj = _vt(c, {0x48: 2, 0x2c: 1})
    c.emu.w32(o + 0x8, c.rng.getrandbits(32))
    c.emu.w32(o + 0xc, c.rng.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [o, obj]


S(0x4f3360, 'FUN_4f3360 (replaceAt1db)', 'thiscall', None, ret=None, gen=_replace, note='batch267; slot 0x210 with 1, then store')
S(0x600820, 'FUN_600820 (callTwoSlots)', 'thiscall', None, ret=None, gen=_two, note='batch267; slot 0x48 and two slot 0x2c calls')
