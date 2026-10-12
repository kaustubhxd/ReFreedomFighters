"""specs_s4135.py - unclaimed-41 batch 35 (core-todo residue-19): 0x5c5cf0 ZFFSearchLightAddActors::Save(ZSaveGame*) (thiscall, one stack
argument s, ret 4; returns al = 1).

self: 0x80 random bytes (the flags dword at +4 and the values at +0x48 and +0x4c vary). s: a 0x40-byte object whose vtable slots 0x3c and
0x44 are one-argument checksum stubs (callee pops). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    vt = c.emu.alloc(0x400, 4)
    s3c, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    s44, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    c.emu.w32(vt + 0x3c, s3c)
    c.emu.w32(vt + 0x44, s44)
    s = _rnd(c, 0x40)
    c.emu.w32(s, vt)
    self_ = _rnd(c, 0x80)
    return [self_, s]


S(0x5c5cf0, 'ZFFSearchLightAddActors::Save(ZSaveGame*)', 'thiscall', None, ret='al', gen=_layout,
  note='unclaimed-41 batch 35; the save object slots 0x3c and 0x44 are checksum stubs (GUESS); the /GS cookie check does not apply')
