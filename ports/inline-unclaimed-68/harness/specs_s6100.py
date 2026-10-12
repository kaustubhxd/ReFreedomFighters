"""specs_s6100.py - unclaimed-68 batch 11 (claim 10): ConstrainedParticleSystem::SetParticleVel (0x547830). The base pointer at
+0xf (unaligned) points at a zeroed block; the index is 0..7 so every store lands inside it; the vector holds random dwords."""
from pilot import S
from engine_stubs import zero_obj


def _vel(c):
    o = c.emu.alloc(0x40, 16)
    c.emu.wbytes(o, bytes(0x40))
    base = zero_obj(c, 0x400)
    c.emu.w32(o + 0xf, base)
    v = c.emu.alloc(12, 4)
    c.emu.wbytes(v, bytes(c.rng.getrandbits(8) for _ in range(12)))
    return [o, c.rng.randrange(0, 8), v]


S(0x547830, 'ConstrainedParticleSystem::SetParticleVel (unknown) thiscall', 'thiscall', None, ret=None, gen=_vel,
  note='unclaimed-68 batch 11; base dword at +0xf; three dwords to base+idx*0x34+0x24')
