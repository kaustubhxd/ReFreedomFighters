"""specs_s1416.py - unclaimed-14 batch 16 (residue 13): ZAnimSequence::ReadInput (0x4c4e90, thiscall, one stack argument, ret 4).

The DBREAD operators are checksum stubs (helper_stubs.stub): 0x4e6330 (GetRefTab, one stack argument, ecx = DBREAD),
0x4e5e40 (u16, returns a random eax). 0x4e5e60 (u32) returns three values in order (seqr from serial_stubs: the three
calls get three different values, one of them zero or not with equal chance). 0x4e5e80 is a float reader: a stub that
does `fld dword ptr [X]` (leaves X on the x87 stack, as the PC's float reader does) and returns. The values the function
stores are compared in the heap (this+0x48, +0x58, +0x5c, +0x60, +0x64).

Each case: a random 0x80-byte ZAnimSequence and a 0x40-byte DBREAD object; the float X is random (finite, in [-100, 100]).
Faulting cases must be 0 (check the JSON)."""
import struct
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ri(c):
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False)
    ss.patch(c, 0x4e6330, s)
    s, _, _ = hs.stub(c, 0, ecx=True, edx=False, ret=c.rng.getrandbits(32))
    ss.patch(c, 0x4e5e40, s)
    # 0x4e5e60: three values in order
    vals = [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.choice([0, c.rng.getrandbits(32)])]
    ss.patch(c, 0x4e5e60, ss.seqr(c, 0, vals))
    # 0x4e5e80: fld dword [X]; ret
    x = c.emu.alloc(4, 4)
    c.emu.w32(x, struct.unpack('<I', struct.pack('<f', c.rng.uniform(-100.0, 100.0)))[0])
    code = ss.code(c, b'\xd9\x05' + ss.P(x) + b'\xc3')
    ss.patch(c, 0x4e5e80, code)
    self_ = _rnd(c, 0x80)
    dbread = _rnd(c, 0x40)
    return [self_, dbread]


S(0x4c4e90, 'ZAnimSequence::ReadInput (unknown) thiscall', 'thiscall', None, ret=None, gen=_ri,
  note='unclaimed-14 batch 16 (residue 13); DBREAD operators are stubs; 0x4e5e80 leaves a float on the x87 stack')
