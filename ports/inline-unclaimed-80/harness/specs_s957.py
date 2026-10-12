"""specs_s957.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x432440 and 0x4324a0 (see src/batch957.cpp). The object's logging vtable
has slot +0x54 (one argument, callee-cleaned) returning r (zero 30%). The IAT slot 0x6762d8 is set to a cdecl recording stub (logs its
argument, returns a per-case value, caller pops). Both null and non-null r paths run; the second stack argument is random."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cdecl_rec(c, ret):
    """cdecl recording stub: logs its first argument in a ring of eight dwords and returns ret (no pop)."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
    b += b'\x8b\x54\x24\x04\x89\x10'
    b += b'\xb8' + ss.P(ret) + b'\xff\x05' + ss.P(cnt) + b'\xc3'
    return ss.code(c, b)


def _gen(c):
    c.emu.w32(0x6762d8, _cdecl_rec(c, c.rng.getrandbits(32)))
    r = 0 if c.rng.random() < 0.3 else (c.rng.getrandbits(31) | 1)
    vt = c.emu.logging_vtable('ZGroupIatCall', 0x16, impl={0x54: (lambda e, a, v=r: (v, None))}, argwords={0x54: 1})
    self_o = _rnd(c, 0x100)
    c.emu.w32(self_o, vt)
    return [self_o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x432440, 'slot call then IAT test (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 gap band; slot +0x54 (one argument); IAT 0x6762d8 cdecl; returns (result != 0) or a2 low byte')
S(0x4324a0, 'slot call then IAT result (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-80 gap band; slot +0x54 (one argument); IAT 0x6762d8 cdecl; returns the IAT result or a2')
