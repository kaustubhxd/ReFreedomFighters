"""specs_s792.py - unclaimed-77 claim 23 (docs/20-unclaimed-77.md): GUESS FUN_4245d0, a thiscall wrapper with one argument that forwards this
and the argument to 0x421d20. The callee is a logger stub (GUESS): it logs ecx and the argument, returns, and writes nothing."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _log421d20(c):
    """Thiscall, one stack argument (ret 4): logs ecx and the argument in an 8-entry ring, writes nothing."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    ring = c.emu.alloc(64, 4)
    c.emu.wbytes(ring, bytes(64))
    b = (b'\xa1' + ss.P(cnt) + b'\x83\xe0\x07\xc1\xe0\x03\x05' + ss.P(ring)
         + b'\x89\x08'
         + b'\x8b\x54\x24\x04\x89\x50\x04'
         + b'\xff\x05' + ss.P(cnt)
         + b'\xc2\x04\x00')
    return ss.code(c, b)


def _gen(c):
    self = _rnd(c, 0x40)
    ss.patch(c, 0x421d20, _log421d20(c))
    return [self, c.rng.getrandbits(32)]


S(0x4245d0, 'GUESS FUN_4245d0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 23; SEH frame not reproduced; callee 0x421d20 stubbed (GUESS)')
