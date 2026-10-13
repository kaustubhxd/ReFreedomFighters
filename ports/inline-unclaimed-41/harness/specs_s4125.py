"""specs_s4125.py - unclaimed-41 batch 25 (slice 13): 0x5af990 ZFFInventoryBridge::GiveWeapon(EFFItemType, unsigned int, bool, bool)
(thiscall, four stack arguments, ret 0x10; void).

self: 0x100 random bytes. Its first dword is Z (vtable slots 0x55c, 0x20, 0x504) and +4 is P4 (the argument of 0x5af130). 0x5af130 is
a stub returning R0 (an object whose first dword is X, and whose +0xc is a small random int) or 0. X's slot 0x2c4 returns W (or 0). W's
slots: 0x2f0, 0x2d0, 0x364 (returns N, small), 0x360, 0x358, 0x328 (returns R, an object whose slot 0x2c4 returns T). T's slots 0x2f0,
0x2d0, 0x324. Q (0x55c's result) is 0 or an object with slot 0x324. The render manager's object o (rm+0x9b) has slot 0x4c (returns V).
0x473cd0 is a checksum stub. The type, n, a and b arguments are small random values (a and b are 0 or 1). Stack values are not in the
checksums. Faulting cases must be 0 (JSON)."""
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
    vt = c.emu.alloc(0x800, 4)     # slot 0x55c lies past 0x400
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _obj(c, slots):
    o = _rnd(c, 0x40)
    c.emu.w32(o, _vt(c, slots))
    return o


def _layout(c):
    # objects first (their addresses are the stub return values)
    T = _obj(c, {})
    R = _obj(c, {})
    Q = _obj(c, {})
    W = _obj(c, {})
    X = _obj(c, {})
    Z = _obj(c, {})
    o = _rnd(c, 0x1000)      # the port reads o+0xadc, so o is larger than one object
    R0 = _rnd(c, 0x40)
    c.emu.w32(R0 + 0xc, c.rng.randint(0, 5))
    c.emu.w32(R0, X)

    # slots: each stub returns what the path needs
    Qret = Q if c.rng.random() < 0.5 else 0          # Z.vt[0x55c]
    Wret = W if c.rng.random() < 0.9 else 0          # X.vt[0x2c4]
    R0ret = R0 if c.rng.random() < 0.9 else 0        # 0x5af130
    N = c.rng.randint(0, 5)                          # W.vt[0x364]
    V = c.rng.getrandbits(32)                        # o.vt[0x4c]

    c.emu.w32(T, _vt(c, {
        0x2f0: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0],
        0x2d0: hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=0)[0],
        0x324: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0]}))
    c.emu.w32(R, _vt(c, {0x2c4: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=T)[0]}))
    c.emu.w32(Q, _vt(c, {0x324: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0]}))
    c.emu.w32(W, _vt(c, {
        0x2f0: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0],
        0x2d0: hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=0)[0],
        0x364: hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=N)[0],
        0x360: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0],
        0x358: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0],
        0x328: hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=R)[0]}))
    c.emu.w32(X, _vt(c, {0x2c4: hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=Wret)[0]}))
    c.emu.w32(Z, _vt(c, {
        0x55c: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=Qret)[0],
        0x20: hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=c.rng.getrandbits(32))[0],
        0x504: hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=1 if c.rng.random() < 0.3 else 0)[0]}))
    c.emu.w32(o + 0, _vt(c, {0x4c: hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=True, ret=V)[0]}))

    # the render manager: rm+0x9b = o; o+0xadc is an argument value (not dereferenced)
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(o + 0xadc, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, rm)

    s5af130, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=R0ret)
    ss.patch(c, 0x5af130, s5af130)
    s473, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=0)
    ss.patch(c, 0x473cd0, s473)

    self_ = _rnd(c, 0x100)
    c.emu.w32(self_, Z)
    c.emu.w32(self_ + 4, _rnd(c, 0x40))

    typ = c.rng.randint(0, 9)
    n = c.rng.randint(0, 7)
    a = c.rng.randint(0, 1)
    b = c.rng.randint(0, 1)
    return [self_, typ, n, a, b]


S(0x5af990, 'ZFFInventoryBridge::GiveWeapon(EFFItemType, unsigned int, bool, bool)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 25; 0x5af130 and 0x473cd0 are checksum stubs (GUESS); the object vtable slots are checksum stubs (GUESS); the /GS cookie check is not reproduced')
