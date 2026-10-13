"""specs_s4128.py - unclaimed-41 batch 28 (slice 13): 0x4a2c50 ZParamAnim::CopyData(S) (thiscall, one stack argument, ret 4).
SEH frame not reproduced (fs:[0] writes not compared).

self: 0x400 random bytes. this+0x44 = A (vtable: 0x4c returns E, an object or 0; 0x1d8 returns R; 0x3c checksum), A+4 is random
(zero one time in three, which selects the 0x67c8e8 default), A+8 = B (B+0x6c random; zero half the time skips 0x4da6d0). this+0x59 = Q
(Q+4 is a three-argument stub returning al, the copy path's branch; it is called with ecx = this+0x59). this+0x11c is 0 or 1. this's
vtable: 0x58 and 0x68 are checksum stubs. The logger (0x700390) has slot 0x20 returning O (vtable slot 0x2c: three-argument caller-pop
stub). The render manager (0x70039c, rm+0x9b = o) has slot 0x114 returning a random 32-bit value (the word stored). The direct calls
0x4da6d0 and 0x4cc1d0 (returns R2) and 0x4cbec0 are stubs (GUESS). S: 0x400 random bytes, with the float at S+0x11e random. Stack
locals (L90) are not in any checksum. Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss

P = lambda v: struct.pack('<I', v & 0xffffffff)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, slots):
    vt = c.emu.alloc(0x400, 4)
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _layout(c):
    f = struct.unpack('<I', struct.pack('<f', c.rng.uniform(-10.0, 10.0)))[0]

    # O: the logger's object; its slot 0x2c takes three arguments and the caller pops them (plain ret)
    s2c, _, _ = hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=False, ret=0)
    O = _rnd(c, 0x40)
    c.emu.w32(O, _vt(c, {0x2c: s2c}))
    sL20, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=O)
    L = _rnd(c, 0x40)
    c.emu.w32(L, _vt(c, {0x20: sL20}))
    c.emu.w32(0x700390, L)

    # E (the A.vt[0x4c] result): an object or zero
    E_obj = _rnd(c, 0x40)
    E = E_obj if c.rng.random() < 0.6 else 0
    R = _rnd(c, 0x40)

    # A (this+0x44): 0x4c returns E; 0x1d8 returns R (checksum of its second argument); 0x3c takes one argument
    s4c, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=E)
    s1d8, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[2], cleanup=True, ret=R)
    s3c, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    A = _rnd(c, 0x40)
    c.emu.w32(A, _vt(c, {0x4c: s4c, 0x1d8: s1d8, 0x3c: s3c}))
    c.emu.w32(A + 4, c.rng.getrandbits(32) if c.rng.random() < 2 / 3 else 0)
    B = _rnd(c, 0x80)
    c.emu.w32(B + 0x6c, c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0)
    c.emu.w32(A + 8, B)

    # the copy path's function pointer: Q+4 is the three-argument stub (checksum of its arguments; returns al)
    sq, _, _ = hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=True, ret=c.rng.randint(0, 1))
    Q = _rnd(c, 0x40)
    c.emu.w32(Q + 4, sq)

    # this: vtable slots 0x58 and 0x68; this+0x44 = A, this+0x59 = Q, this+0x11c is 0 or 1
    s58, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    s68, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=0)
    self_ = _rnd(c, 0x400)
    c.emu.w32(self_, _vt(c, {0x58: s58, 0x68: s68}))
    c.emu.w32(self_ + 0x44, A)
    c.emu.w32(self_ + 0x59, Q)
    c.emu.wbytes(self_ + 0x11c, bytes([c.rng.randint(0, 1)]))

    # rm: rm+0x9b = o, with slot 0x114 (four arguments, callee pops, returns a random word)
    s114, _, _ = hs.stub(c, 4, ecx=True, edx=False, mask=[1, 2, 3, 4], cleanup=True, ret=c.rng.getrandbits(32))
    o = _rnd(c, 0x40)
    c.emu.w32(o, _vt(c, {0x114: s114}))
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)

    # direct calls: 0x4da6d0 (no arguments), 0x4cc1d0 (returns R2), 0x4cbec0 (ecx = a stack local, no arguments)
    s4da, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x4da6d0, s4da)
    s4cc, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=c.rng.getrandbits(32))
    ss.patch(c, 0x4cc1d0, s4cc)
    s4cb, _, _ = hs.stub(c, 0, ecx=False, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x4cbec0, s4cb)

    # S: 0x400 random bytes, with the float at +0x11e random
    S_ = _rnd(c, 0x400)
    c.emu.w32(S_ + 0x11e, f)
    return [self_, S_]


S(0x4a2c50, 'ZParamAnim::CopyData(ZParamAnim const*)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 28; SEH frame not reproduced (fs:[0] writes not compared); 0x4da6d0, 0x4cc1d0, 0x4cbec0 are stubs (GUESS); the object slots are checksum stubs (GUESS); the /GS cookie check is not reproduced')
