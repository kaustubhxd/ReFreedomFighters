"""specs_s4123.py - unclaimed-41 batch 23 (slice 13): 0x43b2d0 ZInputAction::UpdateActionBooleans() (thiscall, no arguments, ret 0).

self: 0x100 random bytes; the flag bytes at +0x32 and +0x33 are random; the dwords A25 (+0x25), A1d (+0x1d), A2d (+0x2d), A21 (+0x21),
A29 (+0x29) are F minus a small random number, so the float comparisons take both sides. rm (the render manager, 0x70039c) is 0x2000
random bytes: rm+0x1c = F (a frame count), rm+0x1907 = p2, a 0x40-byte object whose float at +4 is 0.0 about one time in four (the
early return) and random otherwise. rm's vtable: slot 0x190 returns R, an object whose vtable slot 0x184 is a caller-pop stub (four
arguments; the port uses an asm call that pops 16). The seven flag blocks are the only calls besides the early-exit checks.
Stack and vtable pointers are heap addresses in both builds, so they are kept in the checksums. Faulting cases must be 0 (JSON)."""
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
    F = c.rng.randint(0, 1000)

    self_ = _rnd(c, 0x100)
    for off in (0x25, 0x1d, 0x2d, 0x21, 0x29):
        c.emu.w32(self_ + off, (F - c.rng.randint(-200, 200)) & 0xffffffff)
    c.emu.wbytes(self_ + 0x32, bytes([c.rng.getrandbits(8), c.rng.getrandbits(8)]))

    # boundary cases: (1) x2 + K2 == 0.0 exactly (the G1 test), (2) A25 - A2d == 0x99 exactly (the G2 test)
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    K1 = struct.unpack('<f', struct.pack('<I', c.emu.r32(0x6785e4)))[0]
    K2 = struct.unpack('<f', struct.pack('<I', c.emu.r32(0x679540)))[0]
    # (3) the first early return: 2*x1 > T1 (T1 = 2^20 - 1, K1 = 2^-10, so F - A25 > 2^29) and x2 + K2 < 0 (A1d above F)
    if c.rng.random() < 0.3:
        c.emu.w32(self_ + 0x25, (F - 0x40000000) & 0xffffffff)
        c.emu.w32(self_ + 0x1d, (F + c.rng.randint(1, 5000)) & 0xffffffff)
    if c.rng.random() < 0.5:
        target = -K2
        n0 = round(target / K1) if K1 != 0 else 0
        for n in range(n0 - 4, n0 + 5):
            if f32(f32(float(n)) * K1) == f32(target):
                c.emu.w32(self_ + 0x1d, (F - n) & 0xffffffff)
                c.emu.w32(self_ + 0x25, (F - 100000) & 0xffffffff)   # x1 large enough for the x1 + x1 > T1 test
                break
    if c.rng.random() < 0.3:
        c.emu.w32(self_ + 0x25, (F - 100000) & 0xffffffff)
        c.emu.w32(self_ + 0x2d, (F - 100000 - 0x99) & 0xffffffff)

    # the block object R: its vtable slot 0x184 is a caller-pop stub (four arguments, plain ret)
    s184, _, _ = hs.stub(c, 4, ecx=True, edx=False, mask=[1, 2, 3, 4], cleanup=False, ret=0)
    R = _rnd(c, 0x40)
    c.emu.w32(R, _vt(c, {0x184: s184}))

    # rm: vtable slot 0x190 returns R; rm+0x1c = F; rm+0x1907 = p2 (float at +4 zero about one time in four)
    s190, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=R)
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm, _vt(c, {0x190: s190}))
    c.emu.w32(rm + 0x1c, F)
    p2 = _rnd(c, 0x40)
    pv = 0.0 if c.rng.random() < 0.25 else c.rng.uniform(-2.0, 2.0)
    c.emu.w32(p2 + 4, struct.unpack('<I', struct.pack('<f', pv))[0])
    c.emu.w32(rm + 0x1907, p2)
    c.emu.w32(0x70039c, rm)

    # the error hook is never reached here; keep it a counter stub so a stray call is visible
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + P(hook_cnt) + b'\xc3'))
    return [self_]


S(0x43b2d0, 'ZInputAction::UpdateActionBooleans()', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 23; whole function in one file; the rm.vt[0x190] and the block object vtable slot 0x184 are stubs (GUESS); the /GS cookie check is not reproduced')
