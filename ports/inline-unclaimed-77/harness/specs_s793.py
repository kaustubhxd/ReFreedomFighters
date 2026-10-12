"""specs_s793.py - unclaimed-77 claims 24 to 26 (docs/20-unclaimed-77.md). Stubs (GUESS): the stdcall function pointer at 0x676144 (logs its
two arguments, returns a random eax, ret 8), CRT 0x634d22 (cdecl, logs three arguments, returns 0), and 0x41e2c0 (cdecl, logs one argument)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stdcall_r(c, retval):
    """Stdcall, two stack arguments (ret 8): logs both in an 8-entry ring, returns retval in eax."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x8b\x54\x24\x04\x89\x10'
         + b'\x8b\x54\x24\x08\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(retval)
         + b'\xc2\x08\x00')
    return ss.code(c, b)


def _cdecl_logn(c, nargs):
    """Cdecl stub with nargs stack arguments (logs them, pops nothing, returns 0): ring of 8 entries of 4 dwords."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring))
    for i in range(nargs):
        b += b'\x8b\x54\x24' + bytes([4 + 4 * i]) + (b'\x89\x10' if i == 0 else b'\x89\x50' + bytes([4 * i]))
    b += b'\xff\x05' + ss.P(cnt) + b'\x31\xc0\xc3'
    return ss.code(c, b)


def _gen_frame(c):
    self = _rnd(c, 0x40)
    c.emu.w32(0x701b6c, c.rng.getrandbits(32))
    r = c.rng.getrandbits(32)
    if c.rng.random() < 0.3:
        r = 0x102
    fn = _stdcall_r(c, r)                       # a stub code address stored in the global pointer
    c.emu.w32(0x676144, fn)
    return [self]


def _gen_54a200(c):
    self = _rnd(c, 0x2400)
    ss.patch(c, 0x634d22, _cdecl_logn(c, 3))
    return [self, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _gen_4d5540(c):
    self = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.w32(self + 8, 0)
    else:
        c.emu.w32(self + 8, c.rng.randint(1, 0x7fffffff))
    ss.patch(c, 0x41e2c0, _cdecl_logn(c, 1))
    return [self]


S(0x549800, 'ZSynthGC::CmdFrameReady (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_frame,
  note='unclaimed-77 claim 24; function pointer at 0x676144 stubbed (GUESS)')
S(0x54a200, 'GUESS FUN_54a200 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_54a200,
  note='unclaimed-77 claim 25; CRT 0x634d22 stubbed (GUESS)')
S(0x4d5540, 'GUESS FUN_4d5540 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4d5540,
  note='unclaimed-77 claim 26; 0x41e2c0 stubbed (GUESS)')
