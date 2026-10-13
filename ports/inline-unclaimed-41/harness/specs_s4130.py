"""specs_s4130.py - unclaimed-41 batch 30 (slice 13): 0x4edc50 ZCollisionBase::InstallInsideBuffer(char*, int) (thiscall, two stack
arguments s and n, ret 8).

self: 0x200 random bytes. n is -1 one time in four (the early exit), otherwise random. The allocator 0x41e290 (cdecl; the port pops
nothing) is a stub returning a fresh 0x40-byte buffer filled with random bytes (so the zeroing matters), or null one time in four. The
octree constructor 0x4e3d60 (callee pops 4) is a checksum stub with ecx = the object and the argument s (a random 0x40-byte buffer).
Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss

P = lambda v: struct.pack('<I', v & 0xffffffff)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    buf = _rnd(c, 0x40)
    if c.rng.random() < 0.25:
        alloc_code = ss.code(c, b'\x31\xc0\xc3')                 # xor eax, eax; ret (null)
    else:
        alloc_code = ss.code(c, b'\xb8' + P(buf) + b'\xc3')      # mov eax, buf; ret
    ss.patch(c, 0x41e290, alloc_code)

    s4e, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x4e3d60, s4e)

    self_ = _rnd(c, 0x200)
    s = _rnd(c, 0x40)
    n = 0xffffffff if c.rng.random() < 0.25 else c.rng.getrandbits(32)
    return [self_, s, n]


S(0x4edc50, 'ZCollisionBase::InstallInsideBuffer(char*, int)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 30; the exe allocator 0x41e290 (cdecl) and the octree constructor 0x4e3d60 are stubs (GUESS); the /GS cookie check is not reproduced')
