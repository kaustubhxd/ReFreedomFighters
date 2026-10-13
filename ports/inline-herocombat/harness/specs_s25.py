"""specs_s25.py - inline session batch 25 (Haiku, overnight): 0x4ab280, 0x4c09d0, 0x49df30."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c, lo=-300.0, hi=300.0):
    return struct.unpack('<f', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


# 0x4ab280 thiscall, one stack arg. The table is 200 records of 0x1b8 bytes at this+0x694. The value is taken from the
# table about half the time so that matches happen.
def _clear(c):
    r = c.rng
    obj = _rnd(c, 0x694 + 200 * 0x1b8 + 16)
    for i in range(0, 200, 7):
        c.emu.w32(obj + 0x694 + 0x1b8 * i, r.randint(1, 9))
    return [obj, r.randint(1, 9)]


S(0x4ab280, 'clearSlot (unknown) thiscall', 'thiscall', None, ret='eax', gen=_clear,
  note='batch25; clears the first record whose dword at +0x694 equals the argument; 200 records of 0x1b8 bytes')


# 0x4c09d0 thiscall, no args. The record is 0x90 bytes; the floats are kept in int range so the truncations are plain.
def _copy(c):
    r = c.rng
    obj = _rnd(c, 0x90)
    c.emu.wbytes(obj + 0x58, bytes([r.getrandbits(8)]))
    for off in (0x59, 0x5d, 0x61):
        c.emu.wf32(obj + off, _f(c))
    return [obj]


S(0x4c09d0, 'copyFields (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='batch25; field copies and three float to int truncations')


# 0x49df30 thiscall: this holds a pointer to a tagged string. The first byte's bits 0 and 1 select the branch.
def _tag(c):
    r = c.rng
    s = c.emu.alloc(48, 4)
    body = bytes(r.choice(b'ab\x00\x20') for _ in range(47)) + b'\x00'
    first = r.choice([0x00, 0x01, 0x02, 0x03, 0x12, 0x13, 0x22, 0x23, 0x41])
    body = bytes([first]) + body[1:]
    c.emu.wbytes(s, body)
    holder = _rnd(c, 8)
    c.emu.w32(holder, s)
    return [holder]


S(0x49df30, 'scanTag (unknown) thiscall', 'thiscall', None, ret='eax', gen=_tag,
  note='batch25; bit 1 clear returns 0; bit 0 clear returns s+1; otherwise the position after the next NUL')
