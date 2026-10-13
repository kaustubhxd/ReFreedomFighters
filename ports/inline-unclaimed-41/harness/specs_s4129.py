"""specs_s4129.py - unclaimed-41 batch 29 (slice 13): 0x5c1910 FUN_5c1910 (thiscall, no arguments, ret 0, void); the helper 0x5c1aa0 is
also run (it is in the same function body in the port).

self: 0x400 bytes (the object sits 8 bytes into its allocation, so self-4 is readable). this+0x10c is a random byte; this+0x111 is a
random dword (zero half the time, so the list walk runs); this+0x44 = A, whose vtable: 0x1e0 returns al (random bool), 0x20 returns A
itself or a random value, 0x3c and 0x25c (returns Ob or 0) are checksum stubs. The object at this+0x10d (A or A.vt[0x20]'s result) is
A, so A's 0x25c is what the helper calls. Ob objects (returned by 0x25c) have vtable slot 0xbc (checksum stub). rm (0x70039c): +0x1b5d
random (zero half the time); rm+0x9b = o: vtable 0x138 returns r (vtable 0x60 checksum), 0x4c returns V; o+0xadc = X1: vtable 0x25c
returns e0 (a Z object or 0), 0x294 returns e1 (a Z object). Z objects: vtable 0x21c (checksum). W (0x7003b8): +0x2c15 = V2 (a 0x1100
byte object) with a random byte at +0x103f. Y (0x70038c): vtable 0x20 returns e (zero half the time), 0xac is a checksum; +8 is a stub
function pointer (zero one time in four), +0xc and +0x10 bounds chosen so that the call is taken about half the time. The lists at
0x6eef68 and 0x6eef78 are the exe's own data (pointer values, not dereferenced by the exe: only passed to 0x25c). The stubs are GUESS.
The hook (0x7003b0) is a counter stub. Faulting cases must be 0 (JSON)."""
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
    vt = c.emu.alloc(0x800, 4)     # the largest slot used is 0x294
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _layout(c):
    # Ob: the object returned by A's 0x25c (vtable 0xbc, one argument, checksum)
    s_bc, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    Ob = _rnd(c, 0x40)
    c.emu.w32(Ob, _vt(c, {0xbc: s_bc}))

    # A: vtable 0x1e0 (bool), 0x20 (returns A itself or random), 0x3c, 0x25c (returns Ob or 0)
    A = _rnd(c, 0x40)
    s1e0, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=c.rng.randint(0, 1))
    # A.vt[0x20] returns A or P2 (an object with its own 0x25c; the helper calls 0x25c on whatever this+0x10d holds)
    P2 = _rnd(c, 0x40)
    s25cP, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=Ob if c.rng.random() < 0.8 else 0)
    c.emu.w32(P2, _vt(c, {0x25c: s25cP}))
    s20A, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=A if c.rng.random() < 0.5 else P2)
    s3c, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    s25cA, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=Ob if c.rng.random() < 0.8 else 0)
    c.emu.w32(A, _vt(c, {0x1e0: s1e0, 0x20: s20A, 0x3c: s3c, 0x25c: s25cA}))

    # Z objects: vtable 0x21c (checksum)
    s21c, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    Z = _rnd(c, 0x40)
    c.emu.w32(Z, _vt(c, {0x21c: s21c}))
    Z2 = _rnd(c, 0x40)
    c.emu.w32(Z2, _vt(c, {0x21c: s21c}))

    # r (o.vt[0x138]): vtable 0x60 (checksum); V (o.vt[0x4c]) a random value
    s60, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=0)
    r = _rnd(c, 0x40)
    c.emu.w32(r, _vt(c, {0x60: s60}))
    V = c.rng.getrandbits(32)

    # X1 (o+0xadc): 0x25c returns e0 (Z or 0), 0x294 returns e1 (Z2)
    e0 = Z if c.rng.random() < 0.5 else 0
    s25cX, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=e0)
    s294X, _, _ = hs.stub(c, 4, ecx=True, edx=False, mask=[1, 2, 3, 4], cleanup=True, ret=Z2)
    X1 = _rnd(c, 0x40)
    c.emu.w32(X1, _vt(c, {0x25c: s25cX, 0x294: s294X}))

    # o: 0x138 returns r, 0x4c returns V (checksum of its arguments)
    s138, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=r)
    s4c, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=V)
    o = _rnd(c, 0x1000)      # the code reads o+0xadc, so o is larger than one object
    c.emu.w32(o, _vt(c, {0x138: s138, 0x4c: s4c}))
    c.emu.w32(o + 0xadc, X1)

    # render manager: rm+0x9b = o; the flag at +0x1b5d
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(rm + 0x1b5d, c.rng.choice([0, 0, 1]))
    c.emu.w32(0x70039c, rm)

    # W (0x7003b8): +0x2c15 = V2 with a random byte at +0x103f
    V2 = _rnd(c, 0x1100)
    c.emu.wbytes(V2 + 0x103f, bytes([c.rng.choice([0, 1])]))
    W = _rnd(c, 0x2c20)
    c.emu.w32(W + 0x2c15, V2)
    c.emu.w32(0x7003b8, W)

    # Y (0x70038c): vtable 0x20 returns e (zero half the time), 0xac (checksum); +8 is a stub function pointer
    e_y = c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0
    s20Y, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=e_y)
    sacY, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    s8Y, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=c.rng.getrandbits(32))
    Y = _rnd(c, 0x40)
    c.emu.w32(Y, _vt(c, {0x20: s20Y, 0xac: sacY}))
    if c.rng.random() < 0.75:
        c.emu.w32(Y + 8, s8Y)
    else:
        c.emu.w32(Y + 8, 0)
    # the bounds: this must satisfy [Y+0xc] <= this < [Y+0x10] for the call to be taken; set them around the object's address
    self_raw = _rnd(c, 0x408)
    self_ = self_raw + 8
    lo = self_ - (c.rng.randint(0, 0x100) if c.rng.random() < 0.7 else 0)
    hi = self_ + (c.rng.randint(1, 0x100) if c.rng.random() < 0.7 else 0)
    c.emu.w32(Y + 0xc, lo & 0xffffffff)
    c.emu.w32(Y + 0x10, hi & 0xffffffff)
    c.emu.w32(0x70038c, Y)

    # this: vtable 0x68 (checksum); the fields the function reads or writes
    s68, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=0)
    c.emu.w32(self_, _vt(c, {0x68: s68}))
    c.emu.w32(self_ + 0x44, A)
    c.emu.wbytes(self_ + 0x10c, bytes([c.rng.randint(0, 1)]))
    c.emu.w32(self_ + 0x111, c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0)
    c.emu.w32(self_ + 0x48, c.rng.randint(0, 7))
    c.emu.w32(self_ - 4, c.rng.getrandbits(32) if c.rng.random() < 0.5 else 0)

    # the hook (0x7003b0) is a counter stub
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + P(hook_cnt) + b'\xc3'))
    return [self_]


S(0x5c1910, 'FUN_5c1910 (GUESS name)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 29; with the helper 0x5c1aa0 in the same body; the object vtables are checksum stubs (GUESS); the function pointer at Y+8 is a stub (GUESS); the /GS cookie check is not reproduced')
