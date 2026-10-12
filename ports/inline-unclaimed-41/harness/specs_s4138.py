"""specs_s4138.py - unclaimed-41 batch 38 (core-todo residue-19): 0x46a770 ZItemAmmo::~ZItemAmmo() deleting destructor (thiscall, one stack
argument flags, ret 4; returns this).

self: 0x100 random bytes. flags is random (all 8 low-bit combinations of bits 0 and 2 occur). 0x46a4f0 is a checksum stub with ecx = this
(no arguments). The free wrappers 0x45c510 (one argument) and 0x4690b0 (two arguments) are cdecl checksum stubs (caller pops). Faulting
cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _layout(c):
    s4f, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x46a4f0, s4f)
    s45, _, _ = hs.stub(c, 1, ecx=False, edx=False, mask=[1], cleanup=False, ret=0)
    ss.patch(c, 0x45c510, s45)
    s46, _, _ = hs.stub(c, 2, ecx=False, edx=False, mask=[1, 2], cleanup=False, ret=0)
    ss.patch(c, 0x4690b0, s46)
    self_ = c.emu.alloc(0x100, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    flags = c.rng.getrandbits(32)
    return [self_, flags]


S(0x46a770, 'ZItemAmmo::~ZItemAmmo()', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 38; deleting destructor; the base destructor 0x46a4f0 and the free wrappers 0x45c510 and 0x4690b0 are stubs (GUESS)')
