"""specs_s6330.py - unclaimed-68 batch 32 (claim 32): ZSoundVolumetricSource::SetSourceVolume (0x4bcbe0). The flag byte at +0xd0 is set in
about three cases in four. The block (this+0x44 -> +0x18) is zeroed; the two float arguments are random in -100..100."""
from pilot import S, F
from engine_stubs import zero_obj


def _set(c):
    o = zero_obj(c, 0x200)
    c.emu.wbytes(o + 0xd0, bytes([1 if c.rng.random() < 0.75 else 0]))
    s = zero_obj(c, 0x100)
    blk = zero_obj(c, 0x200)
    c.emu.w32(s + 0x18, blk)
    c.emu.w32(o + 0x44, s)
    return [o, F(c.rng.uniform(-100.0, 100.0)), F(c.rng.uniform(-100.0, 100.0))]


S(0x4bcbe0, 'ZSoundVolumetricSource::SetSourceVolume (unknown) thiscall', 'thiscall', None, ret=None, gen=_set,
  note='unclaimed-68 batch 32; float to block +0x84 and truncated int to +0x68 when the flag at +0xd0 is set')
