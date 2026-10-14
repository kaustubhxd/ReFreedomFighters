"""specs_s1412.py - unclaimed-14 batch 12 (slice 13, heavy): ZMovementGuide::Move (0x4894d0, thiscall, five stack arguments,
ret 0x14). Helpers come from helper_stubs.py (checksum stubs, outputs not modelled, GUESS):

  this->vtable+0x3c (stack args a, b, &vec, &aux; ret 0x10): writes three random floats into vec (the output the function reads).
  global->+0x9b->vtable+0x4c (one value): returns a random eax.
  0x4e0d00, 0x43e8e0, 0x4de420, 0x4946a0 and the same-class 0x4895e0 are patched with checksum stubs. Stack-local pointers
  (&vec, the 4th argument of 0x4895e0) are left out of the checksum.

Each case: a random 0x400-byte this, this+8 -> a 0x100-byte object, this+0x18 is 0.0 about 30% of the time (else a random
float), this+0x371 random; the global at 0x70039c is 0x200 random bytes with +0x48 a random float and +0x9b the callee object.
d and out are heap pointers; a, b, c are random values (never dereferenced by a stub)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fbits(c):
    if c.rng.random() < 0.3:
        return 0
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-10.0, 10.0)))[0]


def _move(c):
    # helpers patched in the image (checksums; outputs not written except where noted)
    s, _, _ = hs.stub(c, 1, ecx=False, edx=False, mask=[1])
    ss.patch(c, 0x4e0d00, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=True, mask=[])            # 0x43e8e0: its stack argument is &vec (left out)
    ss.patch(c, 0x43e8e0, s)
    s, _, _ = hs.stub(c, 0, ecx=True, edx=True)                     # 0x4de420
    ss.patch(c, 0x4de420, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1])          # 0x4946a0
    ss.patch(c, 0x4946a0, s)
    s, _, _ = hs.stub(c, 4, ecx=True, edx=False, mask=[1, 2, 3])    # 0x4895e0 (same class); 4th argument is &vec
    ss.patch(c, 0x4895e0, s)

    # the callee object of the global: vtable slot +0x4c returns a random eax and records its argument
    vt_gb = c.emu.alloc(0x80, 4)
    gb_ret = c.rng.getrandbits(32)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=gb_ret)
    c.emu.w32(vt_gb + 0x4c, s)
    gb = _rnd(c, 0x200)
    c.emu.w32(gb, vt_gb)
    g = _rnd(c, 0x200)
    c.emu.w32(g + 0x9b, gb)
    c.emu.w32(g + 0x48, _fbits(c))
    c.emu.w32(0x70039c, g)

    # this: vtable slot +0x3c writes three random floats through its third stack argument (&vec)
    vt_self = c.emu.alloc(0x80, 4)
    writes = [(3, 0, _fbits(c)), (3, 4, _fbits(c)), (3, 8, _fbits(c))]
    # 4 stack arguments: a, b, &vec (3rd, written), &aux (4th, left out); the callee pops 16
    s, _, _ = hs.stub(c, 4, ecx=True, edx=False, mask=[1, 2], writes=writes)
    c.emu.w32(vt_self + 0x3c, s)
    self_ = _rnd(c, 0x400)
    c.emu.w32(self_, vt_self)
    obj2 = _rnd(c, 0x100)
    c.emu.w32(self_ + 8, obj2)
    c.emu.w32(self_ + 0x18, 0 if c.rng.random() < 0.3 else _fbits(c))
    c.emu.w32(self_ + 0x371, c.rng.getrandbits(32))

    a, b, cc = c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)
    d = _rnd(c, 0x100)
    out = c.emu.alloc(12, 4)
    return [self_, a, b, cc, d, out]


S(0x4894d0, 'ZMovementGuide::Move (unknown) thiscall', 'thiscall', None, ret=None, gen=_move,
  note='unclaimed-14 batch 12; five helpers + same-class 0x4895e0 are checksum stubs; this vtable +0x3c writes vec')
