"""specs_s6320.py - unclaimed-68 batch 31 (claim 31): ZSoundRandomVolume::Init (0x4bbe10). The sub-object at +0x44 holds a block at +0x18
with a random dword at +0x84; this+0x50 holds a random dword (copied unaligned to +0x79). The object is zeroed otherwise."""
from pilot import S
from engine_stubs import zero_obj


def _init(c):
    o = zero_obj(c, 0x200)
    s = zero_obj(c, 0x100)
    blk = zero_obj(c, 0x200)
    c.emu.w32(blk + 0x84, c.rng.getrandbits(32))
    c.emu.w32(s + 0x18, blk)
    c.emu.w32(o + 0x44, s)
    c.emu.w32(o + 0x50, c.rng.getrandbits(32))
    return [o]


S(0x4bbe10, 'ZSoundRandomVolume::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-68 batch 31; stores from the block at +0x18 of the sub-object at +0x44')
