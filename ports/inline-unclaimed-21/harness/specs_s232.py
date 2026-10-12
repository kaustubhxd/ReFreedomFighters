"""specs_s232.py - gap band 0x646f30 (batch232). 0x4dfd10 runs as exe code (a struct copy); 0x4de480 (fastcall, tail-jumps
into 0x4419f0) is a stub that stores its edx in a heap cell. All arguments are heap blocks except the stack local."""
import struct
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cell(c):
    a = c.emu.alloc(4, 4)
    c.emu.w32(a, 0)
    return a


def _flush(c):
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.emu.mu.ctl_flush_tb()


def _gen(c):
    A = _rnd(c, 0x800)
    B = _rnd(c, 0x800)
    idx = c.rng.randrange(0, 12)
    C = _rnd(c, 0x40)
    out = _rnd(c, 0x20)
    cell = _cell(c)
    ss.patch(c, 0x4de480, ss.code(c, b'\x89\x15' + struct.pack('<I', cell) + b'\xc3'))   # stores edx; no stack effect
    _flush(c)
    return [A, B, idx, C, out]


S(0x646f30, 'rowCopy (GUESS)', 'stdcall', None, ret=None, gen=_gen,
  note='batch232; gap band; row copy into out, exe struct copies, 0x4de480 (stubbed) on B + idx*36')
