"""specs_s6290.py - unclaimed-68 batch 28 (claim 28): ZSoundVolumetricSource::Init (0x4bc310). The sub-object at +0x44 holds a block at
+0x18 whose +8 is a random dword; the block is zeroed except that dword; the clear at +0x84 is checked in the same block."""
from pilot import S
from engine_stubs import zero_obj


def _init(c):
    o = zero_obj(c, 0x200)
    s = zero_obj(c, 0x100)
    blk = zero_obj(c, 0x200)
    c.emu.w32(blk + 8, c.rng.getrandbits(32))
    c.emu.wbytes(blk + 0x84, bytes(c.rng.getrandbits(8) for _ in range(4)))
    c.emu.w32(s + 0x18, blk)
    c.emu.w32(o + 0x44, s)
    return [o]


S(0x4bc310, 'ZSoundVolumetricSource::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-68 batch 28; sub-object at +0x44 -> block at +0x18; copy +8 to this+0xa8; clear +0x84')
