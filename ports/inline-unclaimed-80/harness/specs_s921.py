"""specs_s921.py - unclaimed-80 claim 1 (docs/20-unclaimed-80.md): ZFFHeroMovementPlaceC4::~ZFFHeroMovementPlaceC4 (0x5e1630).
The member destructor 0x480fd0 and the base 0x4878d0 are no-op thiscall stubs; the delete 0x634273 is a logging cdecl stub
(two arguments: pointer and size). Bit 0 of the flag is drawn both ways."""
import struct
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cdecl_log(c, nargs):
    P = lambda v: struct.pack('<I', v & 0xffffffff)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(4 * max(nargs, 1), 4)
    c.emu.wbytes(ring, bytes(4 * max(nargs, 1)))
    b = b''
    for k in range(nargs):
        b += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x15' + P(ring + 4 * k)
    b += b'\xff\x05' + P(cnt) + b'\xc3'
    return ss.code(c, b)


def _dtor(c):
    ss.patch(c, 0x480fd0, ss.rec(c, 0, ret=0))
    ss.patch(c, 0x4878d0, ss.rec(c, 0, ret=0))
    ss.patch(c, 0x634273, _cdecl_log(c, 2))
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x5e1630, 'ZFFHeroMovementPlaceC4::~ZFFHeroMovementPlaceC4 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-80 claim 1; member and base dtors no-op; delete 0x634273 logged')
