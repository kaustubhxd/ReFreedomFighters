"""specs_s791.py - unclaimed-77 claims 21 and 22 (docs/20-unclaimed-77.md). The CRT delete 0x634273 is a logger stub (GUESS, cdecl, two
arguments, pops nothing). The native function pointer at the global 0x6763ac is a logger stub (GUESS, cdecl, one argument, returns a
random eax). Both functions read or write only their arguments and the globals 0x724270 and 0x6763ac."""
from pilot import S
import struct
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _recc2(c):
    """Cdecl stub with two stack arguments (p, n): logs both in an 8-entry ring, pops nothing, returns 0."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\x31\xc0\xc3')
    return ss.code(c, b)


def _native(c, retval):
    """Cdecl stub with one stack argument (ret 0): logs it in an 8-entry ring, returns retval in eax."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(32, 4)
    c.emu.wbytes(ring, bytes(32))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x02\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(retval)
         + b'\xc3')
    return ss.code(c, b)


def _gen_dtor(c):
    self = _rnd(c, 0x40)
    ss.patch(c, 0x634273, _recc2(c))
    return [self, c.rng.getrandbits(32)]


def _gen_close(c):
    fd = _rnd(c, 0x20)
    ss.patch(c, 0x634273, _recc2(c))
    c.emu.w32(0x6763ac, _native(c, c.rng.getrandbits(32)))
    return [fd]


S(0x5fa600, 'ScriptHostInterface_t::~ScriptHostInterface_t (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_dtor,
  note='unclaimed-77 claim 21; CRT delete 0x634273 stubbed (GUESS)')
S(0x4d4a00, 'IOFSPhysicalAccess_t::nativeClose (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen_close,
  note='unclaimed-77 claim 22; native pointer 0x6763ac and CRT delete stubbed (GUESS)')
