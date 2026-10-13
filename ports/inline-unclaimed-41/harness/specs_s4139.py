"""specs_s4139.py - unclaimed-41 batch 39 (core-todo residue-19): 0x5171f0 ZCar::~ZCar() deleting destructor (thiscall, one stack argument
flags, ret 4; returns this).

self: 0x400 random bytes (the member at +0x2d8 is inside it). flags is random, so bits 0 and 2 both occur. 0x511950 and 0x512070 are
checksum stubs (thiscall, no arguments; ecx is the member address or this). The free wrappers 0x45c510 (one argument) and 0x4690b0 (two
arguments) are cdecl checksum stubs (caller pops). Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _layout(c):
    s511, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x511950, s511)
    s512, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x512070, s512)
    s45, _, _ = hs.stub(c, 1, ecx=False, edx=False, mask=[1], cleanup=False, ret=0)
    ss.patch(c, 0x45c510, s45)
    s46, _, _ = hs.stub(c, 2, ecx=False, edx=False, mask=[1, 2], cleanup=False, ret=0)
    ss.patch(c, 0x4690b0, s46)
    self_ = c.emu.alloc(0x400, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x400)))
    flags = c.rng.getrandbits(32)
    return [self_, flags]


S(0x5171f0, 'ZCar::~ZCar()', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 39; deleting destructor; member destructors 0x511950 and 0x512070 and the free wrappers 0x45c510 and 0x4690b0 are stubs (GUESS)')
