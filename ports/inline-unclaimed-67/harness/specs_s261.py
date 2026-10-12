"""specs_s261.py - unclaimed area 67, slice 6: five leaves and one tail call through a vtable slot."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _nested(c):
    inner = _rnd(c, 0x20)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0xc, inner)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _tail(c):
    vt = c.emu.logging_vtable('TailObj', 0x140, impl={0xc: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={0xc: 0})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x5c, obj)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x59aa20, 'FUN_59aa20 (readGlobal6ed024)', 'thiscall', None, ret='eax', gen=_obj, note='batch261; global 0x6ed024')
S(0x432520, 'FUN_432520 (addrAC)', 'thiscall', None, ret='eax', gen=_obj, note='batch261; this+0xac')
S(0x49a4e0, 'FUN_49a4e0 (readNested)', 'thiscall', None, ret='eax', gen=_nested, note='batch261; [[this+0xc]+8]')
S(0x4d4d20, 'FUN_4d4d20 (setVtableWord)', 'thiscall', None, ret=None, gen=_obj, note='batch261; stores 0x696634 at [this]')
S(0x606220, 'FUN_606220 (zero16)', 'thiscall', None, ret=None, gen=_obj, note='batch261; zeroes 16 bytes at this')
S(0x513160, 'FUN_513160 (tailSlot0c)', 'thiscall', None, ret='eax', gen=_tail, note='batch261; tail call slot 0xc of this+0x5c')
