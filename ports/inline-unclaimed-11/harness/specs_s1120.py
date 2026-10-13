"""specs_s1120.py - unclaimed-11 batch 21 (gap band): two short functions, both stubbed callees (unverified, no GC names).
0x5a5490 (GUESS): cdecl free(this+4, 4) then free(this+8, 4) via 0x634273 (stubbed: records the pointer into a heap ring).
0x5b76f0 (GUESS): eax = render object (global 0x70039c, +0x9b) slot 0x58(this+0x48); dword result to this+0x50.
The stub 0x58 returns a random value and writes its argument to a heap ring."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _ring(c, n=4):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(n))
    return a


def _free_stub(c, ring):
    b = b'\xb8' + ss.P(ring) + b'\x8b\x4c\x24\x04' + b'\x89\x08' + b'\xc3'
    return ss.code(c, b)


def _free_gen(c):
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o + 4, c.emu.alloc(8, 4))
    c.emu.w32(o + 8, c.emu.alloc(8, 4))
    ss.patch(c, 0x634273, _free_stub(c, _ring(c, 8)))
    return [o]


def _rm_gen(c):
    o = c.emu.alloc(0x80, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    c.emu.w32(o + 0x48, c.rng.getrandbits(32))
    obj = ss.mkobj(c, {0x58: ss.rec(c, 1, ret=c.rng.getrandbits(32))}, size=0x40)
    rm = c.emu.alloc(0x200, 4)
    c.emu.wbytes(rm, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)
    c.emu._image_dirty = True
    return [o]


S(0x5a5490, 'GUESS (no name) two frees thiscall', 'thiscall', None, ret=None, gen=_free_gen, note='unclaimed-11 batch 21')
S(0x5b76f0, 'GUESS (no name) render slot 0x58 into +0x50 thiscall', 'thiscall', None, ret=None, gen=_rm_gen,
  note='unclaimed-11 batch 21')
