"""specs_s4109.py - unclaimed-41 batch 9 (slice 13, x87): 0x542110 (thiscall, no arguments, returns this).

The global object (0x70039c) has a vtable slot +0x1c4 with two stack arguments (ret 8) that returns a float in st0. The stub is
machine code: fld dword [T + counter*4]; counter++; ret 8, so the three calls return three different random floats in [-100, 100].
Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    tbl = c.emu.alloc(12, 4)
    for i in range(3):
        c.emu.w32(tbl + 4 * i, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0])
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    P = ss.P
    # mov edx,[cnt]; fld dword ptr [edx*4+tbl]; inc edx; mov [cnt],edx; ret 8
    code = b'\x8b\x15' + P(cnt) + b'\xd9\x04\x95' + P(tbl) + b'\x42' + b'\x89\x15' + P(cnt) + b'\xc2\x08\x00'
    stub = ss.code(c, code)
    vt = c.emu.alloc(0x300, 4)
    c.emu.w32(vt + 0x1c4, stub)
    g = _rnd(c, 0x200)
    c.emu.w32(g, vt)
    c.emu.w32(0x70039c, g)
    self_ = _rnd(c, 0x100)
    return [self_]


S(0x542110, 'fn542110 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_fn,
  note='unclaimed-41 batch 9; global vtable +0x1c4 returns st0 (machine-code stub; three values)')
