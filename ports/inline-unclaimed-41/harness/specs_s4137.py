"""specs_s4137.py - unclaimed-41 batch 37 (core-todo residue-19): 0x4879b0 ZMovementGuide::~ZMovementGuide() scalar deleting destructor
(thiscall, one stack argument flags, ret 4; returns this).

self: 0x100 random bytes. The member destructor 0x480fd0 is a checksum stub with ecx = the member address (no arguments, callee returns).
The CRT free wrapper 0x634273 is a cdecl checksum stub over its two arguments (caller pops). flags is 0 or 1 at random. Faulting cases must
be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _layout(c):
    s480, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x480fd0, s480)
    s634, _, _ = hs.stub(c, 2, ecx=False, edx=False, mask=[1, 2], cleanup=False, ret=0)
    ss.patch(c, 0x634273, s634)
    self_ = c.emu.alloc(0x100, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    flags = c.rng.getrandbits(32)
    return [self_, flags]


S(0x4879b0, 'ZMovementGuide::~ZMovementGuide()', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 37; scalar deleting destructor; the member destructor 0x480fd0 and the CRT free 0x634273 are stubs (GUESS)')
