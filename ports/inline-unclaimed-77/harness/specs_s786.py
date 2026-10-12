"""specs_s786.py - unclaimed-77 claim 16 (docs/20-unclaimed-77.md): ZBigFile::Exists(const char*). Thiscall, one argument, ret 4.
The object is random; the name is a random 32-byte block. The callee 0x4d4de0 is a logger stub (GUESS): it logs ecx and its name
argument and returns a random 32-bit value in eax (both the low byte's zero-ness and the upper bits matter)."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub4d4de0(c, retval):
    """Thiscall, one stack argument (ret 4): logs ecx and the argument in an 8-entry ring, returns retval in eax."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x89\x08'
         + b'\x8b\x54\x24\x04\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(retval)
         + b'\xc2\x04\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x40)
    name = _rnd(c, 32)
    # the callee's eax: low byte zero in a quarter of the cases, so both setne outcomes and the upper bits are exercised
    r = c.rng.getrandbits(32)
    if c.rng.random() < 0.25:
        r &= 0xffffff00
    ss.patch(c, 0x4d4de0, _stub4d4de0(c, r))
    return [self, name]


S(0x4d4dc0, 'ZBigFile::Exists (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-77 claim 16; callee 0x4d4de0 stubbed (GUESS, returns a random eax)')
