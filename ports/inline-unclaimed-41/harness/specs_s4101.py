"""specs_s4101.py - unclaimed-41 batch 1 (residue 13, small end): CAction::Load2 (0x4a1350, thiscall, no arguments, plain ret).

P = this+0x44 has a vtable whose slot +0x1e0 takes one argument (0x1007d1) and returns a random eax (al is used). P+8 = Q is a
0x80-byte object whose dword at +0x3c is random. The second half, 0x4a1270, is a checksum stub with no stack arguments (GUESS:
its own effects are not modelled). Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _load2(c):
    s, _, _ = hs.stub(c, 0, ecx=True, edx=False)
    ss.patch(c, 0x4a1270, s)
    vt = c.emu.alloc(0x400, 4)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False, mask=[1], ret=c.rng.getrandbits(32))
    c.emu.w32(vt + 0x1e0, s)
    p = _rnd(c, 0x100)
    c.emu.w32(p, vt)
    q = _rnd(c, 0x80)
    c.emu.w32(p + 8, q)
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x44, p)
    return [self_]


S(0x4a1350, 'CAction::Load2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_load2,
  note='unclaimed-41 batch 1; slot +0x1e0 is a stub; 0x4a1270 is a checksum stub (GUESS)')
