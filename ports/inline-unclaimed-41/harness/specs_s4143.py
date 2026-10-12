"""specs_s4143.py - unclaimed-41 batch 43 (core-todo residue-19): 0x4e6d70 ZRunParamAnim::Create(CHUNKFILE*, bool, float) (thiscall, three
stack arguments cf, b, f; ret 0xc; returns al = 1).

self: 0x100 random bytes; its vtable slot 0x8 is a one-argument checksum stub (callee pops). cf: a 0x40-byte object. b: a random dword (its
low byte is stored). f: a random float in [-5, 5] (so the hook branch runs about half the time). The error hook (0x7003b0) is a counter
stub, always non-null: the exe traps (int3) when it is zero on the negative-f path. Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    s8, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    vt = c.emu.alloc(0x400, 4)
    c.emu.w32(vt + 0x8, s8)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_, vt)
    cf = _rnd(c, 0x40)
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + struct.pack('<I', hook_cnt) + b'\xc3'))
    b = c.rng.getrandbits(32)
    f = struct.unpack('<I', struct.pack('<f', c.rng.uniform(-5.0, 5.0)))[0]
    return [self_, cf, b, f]


S(0x4e6d70, 'ZRunParamAnim::Create(CHUNKFILE*, bool, float)', 'thiscall', None, ret='al', gen=_layout,
  note='unclaimed-41 batch 43; the vtable slot 0x8 is a checksum stub (GUESS); the error hook is a counter stub, always non-null (a zero hook traps)')
