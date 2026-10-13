"""specs_s4103.py - unclaimed-41 batch 3 (residue 13): ZAnimSequence::Command (0x4c4c10, thiscall, two stack arguments, ret 8,
returns 1 on every path).

The command word matches +0x48 (about 4 cases in 10), matches +0x4a (about 3 in 10), or matches neither. The helpers
0x4c5090 (two stack arguments, ret 8) and 0x4c4fc0 (no arguments) are checksum stubs (GUESS). The vtable slot +0x64 takes one
argument (checksum). The global at 0x70039c has a dword at +0x40 (random; the port copies it to this+0x65 when the addresses
differ). Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cmd(c):
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False)
    ss.patch(c, 0x4c5090, s)
    s, _, _ = hs.stub(c, 0, ecx=True, edx=False)
    ss.patch(c, 0x4c4fc0, s)
    g = _rnd(c, 0x200)
    c.emu.w32(0x70039c, g)
    vt = c.emu.alloc(0x400, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1])
    c.emu.w32(vt + 0x64, s)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_, vt)
    cmd = c.rng.getrandbits(16)
    r = c.rng.random()
    if r < 0.4:
        c.emu.wbytes(self_ + 0x48, cmd.to_bytes(2, 'little'))
        c.emu.wbytes(self_ + 0x4a, c.rng.getrandbits(16).to_bytes(2, 'little'))
    elif r < 0.7:
        c.emu.wbytes(self_ + 0x4a, cmd.to_bytes(2, 'little'))
        c.emu.wbytes(self_ + 0x48, c.rng.getrandbits(16).to_bytes(2, 'little'))
    else:
        c.emu.wbytes(self_ + 0x48, c.rng.getrandbits(16).to_bytes(2, 'little'))
        c.emu.wbytes(self_ + 0x4a, c.rng.getrandbits(16).to_bytes(2, 'little'))
    c.emu.wbytes(self_ + 0x69, bytes([0 if c.rng.random() < 0.5 else c.rng.getrandbits(8) | 1]))
    return [self_, cmd, _rnd(c, 0x20)]


S(0x4c4c10, 'ZAnimSequence::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  note='unclaimed-41 batch 3; helpers 0x4c5090 and 0x4c4fc0 are checksum stubs (GUESS); vt +0x64 is a stub')
