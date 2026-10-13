"""specs_s332.py - decomp area 64 (docs/20-unclaimed-64.md): 0x519cb0 two lookups (exe 0x5003d0), then exe method 0x514410."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _call(c):
    e = c.emu
    # 0x523b90 (called by 0x514410 on the sub-object; SEH frame, scene calls) faults on any input here, so it is stubbed
    # on both sides: the stub stores ecx and its two stack words in a heap block, returns 0, and pops 8 (ret 8).
    blk = e.alloc(12, 4)
    e.wbytes(blk, bytes(12))
    stub = (b'\x89\x0d' + ss.P(blk)                                  # mov [blk], ecx
            + b'\x8b\x54\x24\x04' + b'\x89\x15' + ss.P(blk + 4)      # mov edx,[esp+4]; mov [blk+4], edx
            + b'\x8b\x54\x24\x08' + b'\x89\x15' + ss.P(blk + 8)      # mov edx,[esp+8]; mov [blk+8], edx
            + b'\xb8' + ss.P(0) + b'\xc2\x08\x00')                   # mov eax, 0; ret 8
    ss.patch(c, 0x523b90, ss.code(c, stub))
    # Lookup table: T[0] = inner, T[+4] = base, T[+8] = count; inner[0] = data, inner[+8] = size. Indices 0 and 1.
    data = _rnd(c, 0x100)
    inner = _rnd(c, 0x10)
    e.w32(inner, data)
    e.w32(inner + 0x8, 0x100)
    T = _rnd(c, 0x10)
    e.w32(T, inner)
    e.w32(T + 0x4, c.rng.randrange(0, 4))
    e.w32(T + 0x8, c.rng.randrange(2, 8))
    p = _rnd(c, 0x10)
    e.w32(p + 0x4, T)
    # Child object: its sub-object at +0x5c is what 0x514410 calls. Both are random, so the call is exercised with
    # arbitrary data (the exe's own code runs on it).
    sub = _rnd(c, 0x80)
    child = _rnd(c, 0x100)
    e.w32(child + 0x5c, sub)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x14, child)
    return [self_, p]


S(0x519cb0, 'childCall (GUESS)', 'thiscall', None, ret='eax', gen=_call,
  note='batch332; one stack pointer p; ret 4; lookups at indices 1 and 0; exe 0x514410 with (u32, float); eax preset')
