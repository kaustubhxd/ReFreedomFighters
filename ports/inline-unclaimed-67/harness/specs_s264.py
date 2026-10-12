"""specs_s264.py - unclaimed area 67, slice 6: three functions (one stdcall pure, one thiscall pure, one vtable slot 0x280)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _nested(c):
    p = _rnd(c, 0x20)
    c.emu.mu.ctl_flush_tb()
    return [p]


def _hash(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


def _slot280(c):
    res = _rnd(c, 0x40)
    vt = c.emu.logging_vtable('V280', 0x290, impl={0x280: lambda e, a: (res, None)}, argwords={0x280: 1})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32)]


S(0x4cf5a0, 'FUN_4cf5a0 (nestedSize)', 'stdcall', None, ret='eax', gen=_nested, note='batch264; p[0] + p[1]*4 + 0x10')
S(0x4e68e0, 'FUN_4e68e0 (hashMix)', 'thiscall', None, ret='eax', gen=_hash, note='batch264; high32(low32(arg*K)*[this+8])')
S(0x4f6560, 'FUN_4f6560 (byteFromSlot280)', 'thiscall', None, ret='eax', gen=_slot280, note='batch264; byte at result+0xc of slot 0x280')
