"""specs_s2761.py - unclaimed-27 batch 61: 0x662660 (GUESS). thiscall, one stack arg (object), ret 4, returns bool (AL).
HOOKED (stub, NOT verified): vtable slots +0x4c (one float on the stack) and +0x60 (one byte-extended dword); both pop 4,
append the argument to a log buffer in order and record ecx. The source struct is 0x30 random bytes with float-heavy edge values."""
from pilot import S
import struct

EDGE = [0x00000000, 0x80000000, 0x3f800000, 0xbf800000, 0x7fc00000, 0x7fa00001, 0xffc00123, 0x7f800000, 0xff800000, 0x00000001]


def _gen(c):
    p = lambda v: struct.pack('<I', v)
    cnt = c.emu.alloc(0x10, 4)
    buf = c.emu.alloc(0x80, 4)
    code = (b'\x89\x0d' + p(cnt + 4) + b'\xa1' + p(cnt) + b'\x8b\x54\x24\x04\x89\x14\x85' + p(buf) + b'\x40\xa3' + p(cnt) +
            b'\xc2\x04\x00')
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    vt = c.emu.alloc(0x200, 4)
    c.emu.wbytes(vt, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(vt + 0x4c, st)
    c.emu.w32(vt + 0x60, st)
    o = c.emu.alloc(0x40, 4)
    c.emu.w32(o, vt)
    src = c.emu.alloc(0x30, 4)
    c.emu.wbytes(src, bytes(c.rng.getrandbits(8) for _ in range(0x30)))
    for off in (0, 4, 8, 0xc, 0x11, 0x15, 0x19, 0x1d, 0x21, 0x25, 0x29):
        if c.rng.getrandbits(32) % 3 == 0:
            c.emu.wbytes(src + off, p(c.rng.choice(EDGE)))
    c.emu.mu.ctl_flush_tb()
    return [src, o]


S(0x662660, 'FUN_662660 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-27 batch 61; SSE movss floats passed on the stack to hooked vtable slots +0x4c / +0x60 (stubs)')
