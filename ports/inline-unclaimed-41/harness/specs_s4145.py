"""specs_s4145.py - unclaimed-41 batch 45 (core-todo residue-19): 0x4702b0 ZItemState::ReadInput(DBREAD&) (thiscall, one stack argument r,
ret 4). SEH frame not reproduced (fs:[0] writes not compared).

self: 0x200 random bytes. r: a 0x40-byte object. The DBREAD operators are stubs: 0x4e5e60 (unsigned int) returns a random sequence (seqr,
one value per call, wrapping after eight); 0x4e5ea0 returns one random dword; 0x4e5e80 (float, returned in st0) is a fixed random float
(fld from a cell). The local object helpers 0x4cbe80 (constructor, one argument), 0x4cbee0 (one argument, ecx = this+0x61) and 0x4cbec0
(destructor, no arguments) are checksum stubs (GUESS). Stack locals are not in any checksum. Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    # DBREAD operators
    ss.patch(c, 0x4e5e60, ss.seqr(c, 0, [c.rng.getrandbits(32) for _ in range(8)]))
    ss.patch(c, 0x4e5ea0, ss.seqr(c, 0, [c.rng.getrandbits(32)]))
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0])
    ss.patch(c, 0x4e5e80, ss.code(c, b'\xd9\x05' + struct.pack('<I', cell) + b'\xc3'))

    # local object helpers
    # ecx and the argument of the constructor are stack locals (not in the checksum); the assign's argument is a stack local too
    s1, _, _ = hs.stub(c, 1, ecx=False, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x4cbe80, s1)
    s2, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[], cleanup=True, ret=0)
    ss.patch(c, 0x4cbee0, s2)
    s3, _, _ = hs.stub(c, 0, ecx=False, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x4cbec0, s3)

    self_ = _rnd(c, 0x200)
    r = _rnd(c, 0x40)
    return [self_, r]


S(0x4702b0, 'ZItemState::ReadInput(DBREAD&)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 45; SEH frame not reproduced (fs:[0] writes not compared); DBREAD operators and local helpers are stubs (GUESS)')
