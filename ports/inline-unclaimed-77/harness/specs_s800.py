"""specs_s800.py - unclaimed-77 batch 800: 0x4b89c0 and 0x4c8dc0, forwarders to 0x4b8a30 and 0x4c8e20 (stubbed: log ecx and the
stack argument, return a random dword, pop 4)."""
import struct
from pilot import S
import serial_stubs as ss


def _logger(c, ret, pop, args=1):
    P = lambda v: struct.pack('<I', v)
    cnt = c.emu.alloc(4, 4); c.emu.w32(cnt, 0)
    ring = c.emu.alloc(128, 4); c.emu.wbytes(ring, bytes(128))
    b = (b'\xa1' + P(cnt) + b'\x83\xe0\x07\xc1\xe0\x04\x05' + P(ring) + b'\x89\x08'
         + (b'\x8b\x54\x24\x04\x89\x50\x04' if args >= 1 else b'') + b'\xff\x05' + P(cnt)
         + b'\xb8' + P(ret) + (b'\xc3' if pop == 0 else b'\xc2' + struct.pack('<H', pop)))
    return ss.code(c, b)


def _mk(target):
    def gen(c):
        ss.patch(c, target, _logger(c, c.rng.getrandbits(32), 4))
        return [ss.mkobj(c, {}, size=0x40), c.rng.getrandbits(32)]
    return gen


S(0x4b89c0, 'GUESS FUN_4b89c0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_mk(0x4b8a30),
  note='unclaimed-77 claim 49; forwarder to 0x4b8a30 (stubbed, GUESS)')
S(0x4c8dc0, 'GUESS FUN_4c8dc0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_mk(0x4c8e20),
  note='unclaimed-77 claim 50; forwarder to 0x4c8e20 (stubbed, GUESS)')
