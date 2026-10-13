"""specs_s4162.py - unclaimed-41 batch 51 (residue 0): 0x522880 ZTankIf::SoundEngineStart (thiscall, one stack argument a, ret 4).
this->[0x1c] is an object whose vtable slot 0x390 is a checksum stub returning a random word w; 0x5003d0 (ecx = a->[8], one word, ret 4)
is a checksum stub returning a random block r; 0x5002f0 (ecx = r, one word, ret 4) checksums ecx and w. Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _layout(c):
    vt = c.emu.alloc(0x800, 4)
    s390, _, _ = hs.stub(c, 0, ecx=True, edx=False, cleanup=True, ret=c.rng.getrandbits(32))
    c.emu.w32(vt + 0x390, s390)
    e = _rnd(c, 0x40)
    c.emu.w32(e, vt)
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 0x1c, e)
    a = _rnd(c, 0x40)
    c.emu.w32(a + 8, _rnd(c, 0x40))
    r = _rnd(c, 0x40)
    s3d0, _, _ = hs.stub(c, 1, ecx=True, edx=False, cleanup=True, ret=r)
    s2f0, _, _ = hs.stub(c, 1, ecx=True, edx=False, cleanup=True, ret=0)
    ss.patch(c, 0x5003d0, s3d0)
    ss.patch(c, 0x5002f0, s2f0)
    return [self_, a]


S(0x522880, 'ZTankIf::SoundEngineStart(OpaqueCallParameters_t&)', 'thiscall', None, ret=None, gen=_layout,
  note='unclaimed-41 batch 51; the vtable slot 0x390, 0x5003d0 and 0x5002f0 are checksum stubs (GUESS)')
