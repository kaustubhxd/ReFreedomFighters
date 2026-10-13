"""specs_s4121.py - unclaimed-41 batch 21 (slice 13): 0x484b10 ZPlayer::PositionCollisionBox (thiscall, five stack arguments A1, P2, P3,
P4, P5, ret 0x14; void).

self: 0x600 random bytes with the flag byte at +0x591 in {0, 1}. A1 and P2 are 0x100-byte objects (P2 may be 0); P3, P4 and P5 are
16-byte float triples (P4 and P5 may be 0). The unported callees are checksum stubs (GUESS). 0x43e920 writes three random floats
through ecx (the temporary L10), since the float block reads L10 after it. 0x4eb020 and 0x4e2c60 also checksum the contents of L10
(through the pointer) because the float block writes it. Stack-local pointers are not in any checksum (the exe and the port have
different stack addresses). Faulting cases must be 0 (JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss

P = lambda v: struct.pack('<I', v & 0xffffffff)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0]


def _writer43e920(c):
    """0x43e920 stand-in (ecx = L10): writes three random floats through ecx, callee pops 4. Records a call count."""
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    b = (b'\xc7\x01' + P(_f(c)) + b'\xc7\x41\x04' + P(_f(c)) + b'\xc7\x41\x08' + P(_f(c))
         + b'\xff\x05' + P(cnt) + b'\x31\xc0' + b'\xc2\x04\x00')
    return ss.code(c, b)


def _dstub(c, nargs, ecx_chk, edx_deref, arg_deref):
    """Checksum stub that also reads the three floats behind a pointer. ecx_chk adds ecx to acc[0]; edx_deref reads the triple at
    edx into acc[4..12]; arg_deref (a 1-based stack argument number, or None) reads the triple there into acc[16..24]."""
    cnt = c.emu.alloc(4, 4)
    acc = c.emu.alloc(32, 4)
    c.emu.w32(cnt, 0)
    for i in range(8):
        c.emu.w32(acc + 4 * i, 0)
    b = b''
    if ecx_chk:
        b += b'\x01\x0d' + P(acc)                       # add [acc], ecx
    if edx_deref:
        b += b'\x89\xd0'                                # mov eax, edx
        for j in range(3):
            b += b'\x8b\x50' + bytes([4 * j]) + b'\x01\x15' + P(acc + 4 + 4 * j)   # mov edx,[eax+4j]; add [acc+4+4j], edx
    if arg_deref is not None:
        b += b'\x8b\x44\x24' + bytes([4 * arg_deref])   # mov eax, [esp+4k]
        for j in range(3):
            b += b'\x8b\x50' + bytes([4 * j]) + b'\x01\x15' + P(acc + 16 + 4 * j)
    b += b'\xff\x05' + P(cnt) + b'\x31\xc0' + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, b)


def _layout(c):
    ss.patch(c, 0x43e920, _writer43e920(c))
    for addr, st in [
        (0x4e0d00, hs.stub(c, 1, ecx=False, edx=False, mask=[1], cleanup=True, ret=0)[0]),
        (0x43e8e0, hs.stub(c, 1, ecx=False, edx=False, mask=[1], cleanup=True, ret=0)[0]),
        (0x4856d0, hs.stub(c, 0, ecx=False, edx=False, cleanup=True, ret=0)[0]),
        (0x441940, hs.stub(c, 0, ecx=False, edx=True, cleanup=True, ret=0)[0]),
        (0x4de7a0, hs.stub(c, 0, ecx=False, edx=False, cleanup=True, ret=0)[0]),
        (0x4db6c0, hs.stub(c, 2, ecx=True, edx=False, mask=[], cleanup=True, ret=0)[0]),
        (0x4e2c60, _dstub(c, 0, False, True, None)),
        (0x4eb020, _dstub(c, 3, True, False, 3)),
    ]:
        ss.patch(c, addr, st)

    A1 = _rnd(c, 0x100)
    P2 = _rnd(c, 0x100) if c.rng.random() > 1 / 6 else 0
    P3 = _rnd(c, 0x10)
    P4 = _rnd(c, 0x10) if c.rng.random() > 1 / 6 else 0
    P5 = _rnd(c, 0x10) if c.rng.random() > 1 / 6 else 0
    self_ = _rnd(c, 0x600)
    c.emu.wbytes(self_ + 0x591, bytes([c.rng.randint(0, 1)]))
    return [self_, A1, P2, P3, P4, P5]


S(0x484b10, 'ZPlayer::PositionCollisionBox(ZCollisionBox*, ZBaseGeom*, const float*, const float*, const float*)', 'thiscall', None,
  ret=None, gen=_layout,
  note='unclaimed-41 batch 21; nine unported callees are checksum or writer stubs (GUESS); L10 is checked through 0x4eb020 and 0x4e2c60; the /GS cookie check is not reproduced')
