"""specs_s953.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): sixteen trivial thiscall leaves (see src/batch953.cpp). Objects are
0x200 random bytes (0xa00 for the 0x9b7 byte writes). 0x432620 gets a finite random float at +0xe4 (returns st0). The two tail jumps
get logging vtables: 0x459c00 calls slot +0x154 on self, 0x44a6f0 calls slot +0x14 on the object at self+0x18; the slots take no
stack arguments and return a per-case value (captured at setup, so both runs see the same value)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x200)]


def _big(c):
    return [_rnd(c, 0xa00)]


def _flt(c):
    o = _rnd(c, 0x200)
    c.emu.w32(o + 0xe4, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0])
    return [o]


def _tail_self(c):
    v = c.rng.getrandbits(32)
    o = _rnd(c, 0x200)
    c.emu.w32(o, c.emu.logging_vtable('ZGroupTailSelf', 0x56, impl={0x154: (lambda e, a, r=v: (r, None))}))
    return [o]


def _tail_inner(c):
    v = c.rng.getrandbits(32)
    inner = _rnd(c, 0x40)
    c.emu.w32(inner, c.emu.logging_vtable('ZGroupTailInner', 0x06, impl={0x14: (lambda e, a, r=v: (r, None))}))
    o = _rnd(c, 0x200)
    c.emu.w32(o + 0x18, inner)
    return [o]


S(0x432550, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0xfe')
S(0x4325e0, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0xf8')
S(0x4325f0, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0xec')
S(0x432600, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0xe8')
S(0x432610, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0xf0')
S(0x432620, 'float getter (unknown) thiscall', 'thiscall', None, ret='st0', gen=_flt, note='unclaimed-80 gap band; fld dword at +0xe4')
S(0x432640, 'getter (unknown) thiscall', 'thiscall', None, ret='al', gen=_obj, note='unclaimed-80 gap band; byte at +0x100')
S(0x43cfb0, 'vtable setter (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj, note='unclaimed-80 gap band; [ecx] = 0x67c15c')
S(0x441bf0, 'vtable setter (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj, note='unclaimed-80 gap band; [ecx] = 0x67d108')
S(0x444af0, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0xb0')
S(0x4450a0, 'getter (unknown) thiscall', 'thiscall', None, ret='eax', gen=_obj, note='unclaimed-80 gap band; dword at +0xac')
S(0x460c30, 'vtable setter (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj, note='unclaimed-80 gap band; [ecx] = 0x685294')
S(0x42d950, 'flag setter (unknown) thiscall', 'thiscall', None, ret=None, gen=_big, note='unclaimed-80 gap band; byte +0x9b7 = 1')
S(0x42fdf0, 'flag setter (unknown) thiscall', 'thiscall', None, ret=None, gen=_big, note='unclaimed-80 gap band; byte +0x9b7 = 0')
S(0x459c00, 'tail call via vtable (unknown) thiscall', 'thiscall', None, ret='eax', gen=_tail_self,
  note='unclaimed-80 gap band; jmp [vtable+0x154] on self')
S(0x44a6f0, 'tail call via inner object (unknown) thiscall', 'thiscall', None, ret='eax', gen=_tail_inner,
  note='unclaimed-80 gap band; jmp [vtable+0x14] on the object at +0x18')
