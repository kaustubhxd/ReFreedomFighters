"""specs_s4105.py - unclaimed-41 batch 5 (slice 13): 0x596710 (copy of a 0x45-byte record), 0x45dc90 (wrapper over 0x4daa70)
and 0x4d3d50 (wrapper over 0x4d24e0).

0x596710 is pure: the source record at this+0x37d..0x3c1 is random and the out buffer is a fresh 0x48-byte block (compared).
0x4daa70 (five stack arguments, ret 0x14) and 0x4d24e0 (four, ret 0x10) are checksum stubs (GUESS): the calls, their
arguments and their ecx are checked, not what the callees do. Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    return [_rnd(c, 0x400), _rnd(c, 0x48)]


def _wrap45(c):
    s, _, _ = hs.stub(c, 5, ecx=True, edx=False)
    ss.patch(c, 0x4daa70, s)
    o = _rnd(c, 0x100)
    obj = _rnd(c, 0x80)
    c.emu.w32(o + 8, obj)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _wrap4d(c):
    s, _, _ = hs.stub(c, 4, ecx=True, edx=False)
    ss.patch(c, 0x4d24e0, s)
    o = _rnd(c, 0x100)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x596710, 'copyRecord596710 (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-41 batch 5; copies 0x40 bytes from +0x37d, dword +0x3bd, byte +0x3c1')
S(0x45dc90, 'wrap45dc90 (unknown) thiscall', 'thiscall', None, ret=None, gen=_wrap45,
  note='unclaimed-41 batch 5; 0x4daa70 is a checksum stub (five arguments, GUESS)')
S(0x4d3d50, 'wrap4d3d50 (unknown) thiscall', 'thiscall', None, ret=None, gen=_wrap4d,
  note='unclaimed-41 batch 5; 0x4d24e0 is a checksum stub (four arguments, GUESS)')
