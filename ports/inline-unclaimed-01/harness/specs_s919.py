"""specs_s919.py - unclaimed-01 claim 18 (docs/20-unclaimed-01.md): ZMoveOnSpline::~ZMoveOnSpline (0x5120c0). The exe's
callees are patched for the run: 0x634273 and 0x4690b0 and 0x45c510 are cdecl logging stubs (their arguments go to a
ring in the heap, so they are compared), and the base destructor 0x43ea20 is a no-op thiscall stub (rec, nargs 0). The
three optional sub-objects (+0x127, +0x12b, +0x1ed) are null about half the time, else logging fakes whose slot 0 is
called with one argument. The flag bits 0 and 2 are drawn both ways."""
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
        b += b'\x8b\x54\x24' + bytes([4 + 4 * k]) + b'\x89\x15' + P(ring + 4 * k)   # mov edx,[esp+..]; mov [ring+..],edx
    b += b'\xff\x05' + P(cnt) + b'\xc3'                                             # inc [cnt]; ret 0 (cdecl)
    return ss.code(c, b)


def _fakeobj(c):
    o = _rnd(c, 0x20)
    c.emu.w32(o, c.emu.logging_vtable('ZSplineSub', 0x10, argwords={0: 1}))
    return o


def _dtor(c):
    ss.patch(c, 0x634273, _cdecl_log(c, 2))
    ss.patch(c, 0x4690b0, _cdecl_log(c, 2))
    ss.patch(c, 0x45c510, _cdecl_log(c, 1))
    ss.patch(c, 0x43ea20, ss.rec(c, 0, ret=0))
    o = _rnd(c, 0x200)
    c.emu.w32(o + 0x5c, c.rng.getrandbits(32))
    for off in (0x127, 0x12b, 0x1ed):
        c.emu.w32(o + off, _fakeobj(c) if c.rng.random() < 0.5 else 0)
    return [o, c.rng.getrandbits(32)]


S(0x5120c0, 'ZMoveOnSpline::~ZMoveOnSpline (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-01 claim 18; deletes and base dtor stubbed; slot 0 of optional sub-objects logged')
