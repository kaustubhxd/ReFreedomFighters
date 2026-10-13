"""specs_s4126.py - unclaimed-41 batch 26 (slice 13): 0x59f6d0 ZFFActor::DropWeapons() (thiscall, no arguments, ret 0, void).

self: 0x1000 random bytes; +0x788 is a random signed 16-bit value (sometimes non-negative, which replaces the weight), +0x78a and +0x78e
random. The vtable of self: 0x504 returns E (an object, or 0 one time in five), 0x500 returns R (an object, or 0 one time in four),
0x4f4 is a checksum stub. E and R share one vtable (EV): 0x80, 0x2d0, 0x320, 0x360, 0x7c, 0x2f0 are checksum stubs; 0x2e8 returns G
(an object with vtable GV: 0x2c4 returns E, 0x300 returns a bool); 0x1e0 returns a bool; 0x364 returns N (small). rm (0x70039c): +0x1b5d
is 0, 1 or 2; +0x9b is o (vtable: 0x4c returns V); rm's vtable slot 0x1c0 returns a float in st0 (a fixed random float). The list at
0x7003b8 holds a count at +0x8b4 (0..5) and entries; entry 0 is E about one time in three so the found path runs. The unported
functions 0x475ac0, 0x475aa0, 0x46abf0 are checksum stubs (GUESS). Stack locals (L34, L10) are not in any checksum. Faulting cases must
be 0 (JSON)."""
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
    vt = c.emu.alloc(0x800, 4)     # the largest slot used is 0x504
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _fld_ret(c, val_bits):
    """Returns a float in st0 (fld dword [cell], where the cell holds the float bits) and pops two stack arguments (ret 8)."""
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, val_bits)
    return ss.code(c, b'\xd9\x05' + P(cell) + b'\xc2\x08\x00')


def _layout(c):
    flag = c.rng.choice([0, 0, 1, 2])
    # the zero exits: E.vt[0x2e8] returns 0 on its first call (the K == 0 exit; only with flag != 0, where that is the first call);
    # G.vt[0x2c4] returns 0 on its first call (the H == 0 exit; only reached with flag == 0)
    zeroK = (flag != 0) and c.rng.random() < 0.3
    zeroH = c.rng.choice(['none', 'A', 'B', 'none'])   # A: part A's H is 0; B: part A's H is E and part B's H2 is 0
    # G (result of E.vt[0x2e8]) and E (result of 0x504, the 0x500 result, and the 0x2c4 result)
    GV = _vt(c, {
        0x2c4: 0, 0x300: 0})
    G = _rnd(c, 0x40)
    c.emu.w32(G, GV)

    EV = _vt(c, {})
    E = _rnd(c, 0x40)
    c.emu.w32(E, EV)

    N = c.rng.randint(0, 9)
    rets2c4 = {'A': [0] + [E] * 7, 'B': [E, 0] + [E] * 6}.get(zeroH, [E] * 8)
    s300, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=c.rng.randint(0, 1))
    c.emu.w32(GV + 0x2c4, ss.seqr(c, 2, rets2c4))
    c.emu.w32(GV + 0x300, s300)

    c.emu.w32(EV + 0x80, hs.stub(c, 2, ecx=True, edx=False, mask=[], cleanup=True, ret=0)[0])
    c.emu.w32(EV + 0x2d0, hs.stub(c, 2, ecx=True, edx=False, mask=[1, 2], cleanup=True, ret=0)[0])
    rets2e8 = ([0] if zeroK else [G]) + [G] * 7
    c.emu.w32(EV + 0x2e8, ss.seqr(c, 0, rets2e8))
    c.emu.w32(EV + 0x320, hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)[0])
    c.emu.w32(EV + 0x360, hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0])
    c.emu.w32(EV + 0x7c, hs.stub(c, 2, ecx=True, edx=False, mask=[], cleanup=True, ret=0)[0])
    c.emu.w32(EV + 0x2f0, hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0])
    c.emu.w32(EV + 0x1e0, hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=c.rng.randint(0, 1))[0])
    c.emu.w32(EV + 0x364, hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=N)[0])

    # self: 0x504 -> E or 0; 0x500 -> R (E's vtable) or 0; 0x4f4 is a checksum stub
    self_ = _rnd(c, 0x1000)
    SV = _vt(c, {})
    c.emu.w32(self_, SV)
    e_ret = E if c.rng.random() < 0.8 else 0
    r_ret = E if c.rng.random() < 0.75 else 0
    c.emu.w32(SV + 0x504, hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=e_ret)[0])
    c.emu.w32(SV + 0x500, hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=r_ret)[0])
    c.emu.w32(SV + 0x4f4, hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)[0])
    c.emu.w32(self_ + 0x788, c.rng.randint(-2, 40) & 0xffff)
    c.emu.w32(self_ + 0x78a, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x78e, c.rng.getrandbits(32))

    # rm: flag at +0x1b5d; o at +0x9b (vtable slot 0x4c returns V); rm's slot 0x1c0 returns a float in st0
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x1b5d, flag)
    o = _rnd(c, 0x1000)
    V = c.rng.getrandbits(32)
    c.emu.w32(o, _vt(c, {0x4c: hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=True, ret=V)[0]}))
    c.emu.w32(o + 0xadc, c.rng.getrandbits(32))
    c.emu.w32(rm + 0x9b, o)
    rf = struct.unpack('<I', struct.pack('<f', c.rng.uniform(-3.0, 40.0)))[0]
    c.emu.w32(rm, _vt(c, {0x1c0: _fld_ret(c, rf)}))
    c.emu.w32(0x70039c, rm)

    # the list at 0x7003b8: count, entries; entry 0 is E about one time in three
    LST = _rnd(c, 0x4000)
    cnt = c.rng.randint(0, 5)
    c.emu.w32(LST + 0x8b4, cnt)
    for i in range(cnt + 0x22e):
        c.emu.w32(LST + 0x8b8 + 4 * i, c.rng.getrandbits(32))
    if cnt > 0 and c.rng.random() < 0.33:
        c.emu.w32(LST + 0x8b8, E)
    c.emu.w32(0x7003b8, LST)

    s475ac0, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x475ac0, s475ac0)
    s475aa0, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x475aa0, s475aa0)
    s46ab, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x46abf0, s46ab)

    return [self_]


S(0x59f6d0, 'ZFFActor::DropWeapons()', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 26; the vtable slots and 0x475ac0, 0x475aa0, 0x46abf0 are checksum stubs (GUESS); rm.vt[0x1c0] returns a float in st0; the /GS cookie check is not reproduced')
