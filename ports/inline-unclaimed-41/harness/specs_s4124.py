"""specs_s4124.py - unclaimed-41 batch 24 (slice 13): 0x645490 ZBoneModifyBase::AttachBaseGeomToBone (thiscall, four stack arguments
g, bone, a3, a4; ret 0x10; returns al). SEH frame not reproduced (fs:[0] writes not compared).

self: 0x400 random bytes with the count at +0x69 in 0..7 (0..8 includes the early return at 8: never generated). Half the cases
put an entry (E, bone) at index 0 so the duplicate path runs. o (rm+0x9b): slot 0x50 returns E. L (0x700390): slot 0x20 returns O2
(vtable slot 0x2c is a caller-pop stub: three arguments, ecx = R3). p (rm+0x190f): slot 0x20 returns a value (one argument g).
The unported callees are stubs (GUESS): 0x4da2f0, 0x4cc1d0, 0x4cbec0, 0x63d7d0, and two writer stubs (0x4de420, 0x4de7a0) that
write nine dwords into the caller's block (the L40 region). Stack-local pointers are not in any checksum. The hook (0x7003b0) is a
counter stub. Faulting cases must be 0 (JSON)."""
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


def _blockw(c, edx_chk):
    """Writer for 0x4de420 / 0x4de7a0 (ecx = the block): writes nine random dwords at [ecx+0..32]; optional edx checksum; ret."""
    cnt = c.emu.alloc(4, 4)
    acc = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    c.emu.w32(acc, 0)
    b = b''
    if edx_chk:
        b += b'\x01\x15' + P(acc)                    # add [acc], edx
    for k in range(9):
        b += b'\xc7\x41' + bytes([4 * k]) + P(c.rng.getrandbits(32))   # mov dword [ecx+4k], imm32
    b += b'\xff\x05' + P(cnt) + b'\xc3'              # inc [cnt]; ret (callee pops nothing)
    return ss.code(c, b)


def _layout(c):
    count = c.rng.randint(0, 7)
    E = c.rng.getrandbits(32)
    bone = c.rng.randint(0, 5)

    # the bone table: index 0 holds (E, bone) half the time, so the duplicate path runs
    self_ = _rnd(c, 0x400)
    c.emu.w32(self_ + 0x69, count)
    if count > 0 and c.rng.random() < 0.5:
        c.emu.w32(self_ + 0x6d + 4, bone)
        c.emu.w32(self_ + 0x6d, E)

    # the render manager: rm+0x9b = o (slot 0x50), rm+0x190f = p (slot 0x20)
    s50, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=E)
    o = _rnd(c, 0x40)
    c.emu.w32(o, _vt(c, {0x50: s50}))
    p_s20, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=c.rng.getrandbits(32))
    p = _rnd(c, 0x40)
    c.emu.w32(p, _vt(c, {0x20: p_s20}))
    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x9b, o)
    c.emu.w32(rm + 0x190f, p)
    c.emu.w32(0x70039c, rm)

    # the logger (0x700390): slot 0x20 (two arguments, callee pops) returns O2; O2's slot 0x2c is a caller-pop stub (three arguments)
    s2c, _, _ = hs.stub(c, 3, ecx=True, edx=False, mask=[1, 2, 3], cleanup=False, ret=0)
    O2 = _rnd(c, 0x40)
    c.emu.w32(O2, _vt(c, {0x2c: s2c}))
    sL20, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[], cleanup=True, ret=O2)
    L = _rnd(c, 0x40)
    c.emu.w32(L, _vt(c, {0x20: sL20}))
    c.emu.w32(0x700390, L)

    # the unported callees
    s4da, _, _ = hs.stub(c, 2, ecx=True, edx=False, mask=[2], cleanup=True, ret=c.rng.getrandbits(32))
    ss.patch(c, 0x4da2f0, s4da)
    s4cc, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=c.rng.getrandbits(32))
    ss.patch(c, 0x4cc1d0, s4cc)
    s4cb, _, _ = hs.stub(c, 0, ecx=False, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x4cbec0, s4cb)
    ss.patch(c, 0x4de420, _blockw(c, True))
    ss.patch(c, 0x4de7a0, _blockw(c, False))
    s63, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x63d7d0, s63)

    # the error hook (never reached: count is below 8 here) is a counter stub
    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + P(hook_cnt) + b'\xc3'))

    g = _rnd(c, 0x40)
    a3 = _rnd(c, 0x10) if c.rng.random() > 1 / 6 else 0
    a4 = 0
    if c.rng.random() > 1 / 6:
        a4 = _rnd(c, 0x0c)
        for i in range(3):
            c.emu.w32(a4 + 4 * i, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0])
    return [self_, g, bone, a3, a4]


S(0x645490, 'ZBoneModifyBase::AttachBaseGeomToBone(const ZBaseGeom*, unsigned int, const float*, const float*)', 'thiscall', None,
  ret='al', gen=_layout,
  note='unclaimed-41 batch 24; SEH frame not reproduced (fs:[0] writes not compared); unported callees are stubs (GUESS): 0x4da2f0, 0x4cc1d0, 0x4cbec0, 0x4de420, 0x4de7a0, 0x63d7d0 and the logger/vtable slots')
