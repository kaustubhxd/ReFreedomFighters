"""specs_s787.py - unclaimed-77 claim 17 (docs/20-unclaimed-77.md): CGlobalCom::GetpVal(const char*, int) const. Thiscall, two stack
arguments (name pointer, int), ret 8. The callee 0x4d2b40 is a logger stub (GUESS): it logs ecx and both arguments and returns a random
eax; the eax is zero in a quarter of the cases so the zero branch runs."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _stub4d2b40(c, retval):
    """Thiscall, two stack arguments (ret 8): logs ecx, the name pointer and the int in an 8-entry ring, returns retval."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4)
    c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + ss.P(ring)
         + b'\x89\x08'
         + b'\x8b\x54\x24\x04\x89\x50\x04'
         + b'\x8b\x54\x24\x08\x89\x50\x08'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xb8' + ss.P(retval)
         + b'\xc2\x08\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x40)
    name = _rnd(c, 32)
    r = c.rng.getrandbits(32)
    if c.rng.random() < 0.25:
        r = 0
    ss.patch(c, 0x4d2b40, _stub4d2b40(c, r))
    return [self, name, c.rng.getrandbits(32)]


S(0x4d2fc0, 'CGlobalCom::GetpVal (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-77 claim 17; callee 0x4d2b40 stubbed (GUESS)')
