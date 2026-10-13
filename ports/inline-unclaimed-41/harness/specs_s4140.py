"""specs_s4140.py - unclaimed-41 batch 40 (core-todo residue-19): 0x4a9970 CCheckVisible::~CCheckVisible() deleting destructor (thiscall, one
stack argument flags, ret 4; returns this). SEH frame not reproduced (fs:[0] writes not compared).

self: 0x100 random bytes. flags is random (bits 0 and 2 both occur). 0x4a9880 is a checksum stub (ecx = this, no arguments). The free
wrapper 0x4690b0 is a cdecl checksum stub over its two arguments (caller pops). The error hook 0x7003b0 is a counter stub (always non-null: the exe traps with int3 when it is zero). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _layout(c):
    s9880, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x4a9880, s9880)
    s46, _, _ = hs.stub(c, 2, ecx=False, edx=False, mask=[1, 2], cleanup=False, ret=0)
    ss.patch(c, 0x4690b0, s46)
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    # the exe traps (int3) when the hook is zero on this error path, so the hook is always a counter stub here
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + struct.pack('<I', hook_cnt) + b'\xc3'))
    self_ = c.emu.alloc(0x100, 4)
    c.emu.wbytes(self_, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    flags = c.rng.getrandbits(32)
    return [self_, flags]


S(0x4a9970, 'CCheckVisible::~CCheckVisible()', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 40; SEH frame not reproduced (fs:[0] writes not compared); member destructor 0x4a9880 and free wrapper 0x4690b0 are stubs (GUESS); the hook is a counter stub')
