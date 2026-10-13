"""specs_s4127.py - unclaimed-41 batch 27 (slice 13): 0x5aa710 ZOnScreenDisplay::MapIconSetupIcons() (thiscall, no arguments, ret 0).

self: 0x1000 random bytes. The count at +0x69d is 0..3 (0 skips the loop). For element i: E0_i (0x80 bytes) at self+0x4cc+4i, the index
at self+0x7c1+4i (0..12), the flag byte at self+0x881+i (0 or 1), the optional object ec_i at self+0x821+4i (vtable slot 0x70 is a
checksum stub; a null ec_i skips the call), and the float triple P_i = self+0x6a5+12i (random floats). dv (self+0x89a) is an object
with vtable slot 0x8c (checksum stub) or null. rm (0x70039c) holds two random small ints at +0x6f and +0x73. The direct calls are
stubs (GUESS): 0x5a8360 returns B (an object, whose first dword is passed to 0x5ebd80); 0x446320 is a writer that stores two random
floats into its first argument (out) and is checksummed through its ecx; 0x5ec660, 0x5ebd80 and 0x5ed1e0 take ecx = E0 and checksum
their arguments. The stack locals (L34, L1c, L10) are not in any checksum. The hook (0x7003b0) is a counter stub. Faulting cases must be
0 (JSON)."""
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
    vt = c.emu.alloc(0x800, 4)
    for off, st in slots.items():
        c.emu.w32(vt + off, st)
    return vt


def _f(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-50.0, 50.0)))[0]


def _writer446320(c):
    """0x446320 stand-in: out (the first argument) gets two random floats; ecx (dv) is not used. Callee pops 8."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    b = (b'\x8b\x44\x24\x04'                 # mov eax, [esp+4]  (out)
         + b'\xc7\x00' + P(_f(c))            # mov dword [eax], imm
         + b'\xc7\x40\x04' + P(_f(c))        # mov dword [eax+4], imm
         + b'\xff\x05' + P(cnt)              # inc [cnt]
         + b'\xc2\x08\x00')                  # ret 8
    return ss.code(c, b)


def _layout(c):
    count = c.rng.randint(0, 3)

    B = _rnd(c, 0x40)
    s5a8360, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=B)
    ss.patch(c, 0x5a8360, s5a8360)

    s5ec660, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x5ec660, s5ec660)
    s5ebd80, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], cleanup=True, ret=0)
    ss.patch(c, 0x5ebd80, s5ebd80)
    s5ed1e0, _, _ = hs.stub(c, 5, ecx=True, edx=False, mask=[1, 2, 3, 4, 5], cleanup=True, ret=0)
    ss.patch(c, 0x5ed1e0, s5ed1e0)
    ss.patch(c, 0x446320, _writer446320(c))

    s70, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[], cleanup=True, ret=0)
    s8c, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[], cleanup=True, ret=0)
    dv = _rnd(c, 0x40)
    c.emu.w32(dv, _vt(c, {0x8c: s8c}))

    rm = _rnd(c, 0x2000)
    c.emu.w32(rm + 0x6f, c.rng.randint(-40, 40) & 0xffffffff)
    c.emu.w32(rm + 0x73, c.rng.randint(-40, 40) & 0xffffffff)
    c.emu.w32(0x70039c, rm)

    hook_cnt = c.emu.alloc(4, 4)
    c.emu.w32(hook_cnt, 0)
    c.emu.w32(0x7003b0, ss.code(c, b'\xff\x05' + P(hook_cnt) + b'\xc3'))

    self_ = _rnd(c, 0x1000)
    c.emu.w32(self_ + 0x69d, count)
    c.emu.w32(self_ + 0x89a, dv if c.rng.random() < 0.7 else 0)
    for i in range(count):
        E0 = _rnd(c, 0x80)
        c.emu.w32(self_ + 0x4cc + 4 * i, E0)
        c.emu.w32(self_ + 0x7c1 + 4 * i, c.rng.randint(0, 12))
        c.emu.wbytes(self_ + 0x881 + i, bytes([c.rng.randint(0, 1)]))
        if c.rng.random() < 0.7:
            ec = _rnd(c, 0x40)
            c.emu.w32(ec, _vt(c, {0x70: s70}))
            c.emu.w32(self_ + 0x821 + 4 * i, ec)
        else:
            c.emu.w32(self_ + 0x821 + 4 * i, 0)
        for k in range(3):
            c.emu.w32(self_ + 0x6a5 + 12 * i + 4 * k, _f(c))
    return [self_]


S(0x5aa710, 'ZOnScreenDisplay::MapIconSetupIcons()', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 27; 0x5a8360, 0x446320, 0x5ec660, 0x5ebd80, 0x5ed1e0 are stubs (GUESS); the object vtable slots 0x8c and 0x70 are checksum stubs (GUESS); the /GS cookie check is not reproduced')
