"""specs_s4146.py - unclaimed-41 batch 46 (core-todo residue-19): 0x59efb0 ZFFActor::CreateItemFromItemTemplate(unsigned int) (thiscall, one
stack argument id, ret 4; returns eax = the item I, or the null template C).

self: 0x400 random bytes; its vtable slot 0x6c8 is a one-argument stub returning C (an object, or zero one time in five). C: vtable 0x2c4 (two
arguments) returns I (an object). I: vtable 0x2f0 (one argument), 0x1e0 (one argument, random bool), 0x328 (a sequence: [0, X] or [X, X], so the
second call only happens when the first is non-null), 0x360 (one argument), 0x358 (one argument). X: vtable 0x31c returns w. The render manager
(0x70039c, rm+0x9b = o): o's vtable slot 0x4c (three arguments) returns V. Checksums cover heap arguments only (self and the id are kept; the
MEDI constant and the Y pointer are constants or heap). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _vt(c, slots):
    vt = c.emu.alloc(0x800, 4)
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _layout(c):
    # X (0x328's second result) with 0x31c; I with its slots; C with 0x2c4
    s31c, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=c.rng.getrandbits(32))
    X = _rnd(c, 0x40)
    c.emu.w32(X, _vt(c, {0x31c: s31c}))

    r_nonnull = c.rng.random() < 0.6
    seq328 = [X, X] if r_nonnull else [0, X]
    s2f0, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    s1e0, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=c.rng.randint(0, 1))
    s360, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    s358, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    I = _rnd(c, 0x40)
    c.emu.w32(I, _vt(c, {0x2f0: s2f0, 0x1e0: s1e0, 0x328: ss.seqr(c, 0, seq328), 0x360: s360, 0x358: s358}))

    s2c4, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=I)
    C = _rnd(c, 0x40)
    c.emu.w32(C, _vt(c, {0x2c4: s2c4}))

    s6c8, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=C if c.rng.random() < 0.8 else 0)
    self_ = _rnd(c, 0x400)
    c.emu.w32(self_, _vt(c, {0x6c8: s6c8}))

    # the render manager: rm+0x9b = o (vtable 0x4c, three arguments, returns V); o+0xadc = Y (a heap value passed on)
    s4c, _, _ = hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=True, ret=c.rng.getrandbits(32))
    o = _rnd(c, 0x1000)
    c.emu.w32(o, _vt(c, {0x4c: s4c}))
    c.emu.w32(o + 0xadc, c.rng.getrandbits(32))
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(0x70039c, rm)

    return [self_, c.rng.getrandbits(32)]


S(0x59efb0, 'ZFFActor::CreateItemFromItemTemplate(unsigned int)', 'thiscall', None, ret='eax', gen=_layout,
  note='unclaimed-41 batch 46; the object vtable slots are checksum stubs or sequences (GUESS); the /GS cookie check does not apply')
