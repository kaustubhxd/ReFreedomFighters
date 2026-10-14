"""specs_s959.py - area 56 claim A21 (0x645af0): bounds check, then the entry loop.

this (0x300 random bytes): +0x11 the entry count (1 to 3), +0x275/+0x279/+0x27d floats in [-6, 6] (the bounds), the vector at
+0x281 is random floats in [-6, 6]. A (the 12-byte vector argument) is random floats in [-6, 6]. The entry array (base) holds
count entries of 0x30 bytes of random floats in [-6, 6], and the second pointer argument is base plus a random offset in
[0, 0x40] (the helpers read inside the array). The helpers 0x43e920, 0x4856d0, 0x441a60, 0x43e960 and 0x43e8e0 run as original
exe code (no hooks), so the spec must keep their inputs as the exe expects: pointers into the buffers above."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _gen(c):
    e = c.emu
    rng = c.rng
    this = _rnd(c, 0x300)
    e.w32(this + 0x11, rng.randint(1, 3))
    for off in (0x275, 0x279, 0x27d):
        e.w32(this + off, _fl(c, 2.0, 12.0) if rng.random() < 0.8 else _fl(c, -6.0, 6.0))  # bounds mostly wide so the loop runs
    for i in range(3):
        e.w32(this + 0x281 + 4 * i, _fl(c, -6.0, 6.0))
    a = _rnd(c, 0x20)
    for i in range(3):
        e.w32(a + 4 * i, _fl(c, -6.0, 6.0))
    count = rng.randint(1, 3)
    base = _rnd(c, 0x30 * 3 + 0x80)
    for k in range(0x30 * 3 // 4):
        e.w32(base + 4 * k, _fl(c, -6.0, 6.0))
    v12 = base + rng.randrange(0, 0x41, 4)
    # Tie planting (half the cases): 0x43e8e0 is hooked to write l3 = (l1.x + 1, l1.y + 1, l1.z), so the final z test is an exact
    # tie (the exe's l1 is ecx+0x18 at the hook, as the port's frame layout is l3 + 0x18). The other cases run the real helper.
    if rng.random() < 0.5:
        c.emu.hook(0x43e8e0, _tie_hook)
    else:
        c.emu.unhook(0x43e8e0)
    return [this, a, v12, base]


def _tie_hook(e2, r):
    l3 = e2.reg('ecx')
    x1, y1, z1 = struct.unpack('<fff', e2.rbytes(l3 + 0x18, 12))
    e2.wbytes(l3, struct.pack('<fff', x1 + 1.0, y1 + 1.0, z1))
    e2.ret(argbytes=4)


S(0x645af0, 'unnamed 0x645af0 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A21; helpers 0x43e920/0x4856d0/0x441a60/0x43e960/0x43e8e0 run as original exe code')
