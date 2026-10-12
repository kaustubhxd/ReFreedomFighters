"""specs_s6360.py - unclaimed-68 batches 36 and 37 (claims 36 and 37): ZSoundVolume2D Load (0x4bd000) and Save (0x4bd020). The stream
object is a logging vtable: slot +0x6c (Load) and +0x68 (Save) log their argument (callee cleanup, one argument). The object's flag
word at +4 is random so the bit-6 clear matters."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _gen(c):
    o = zero_obj(c, 0x100)
    c.emu.w32(o + 4, c.rng.getrandbits(32))
    st = logged_obj(c, 'ZVol2DStream', 0x80, impl={}, argwords={0x6c: 1, 0x68: 1})
    return [o, st]


S(0x4bd000, 'ZSoundVolume2D::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-68 batch 36; clear bit 6 of +4; stream slot +0x6c with this+0x48')
S(0x4bd020, 'ZSoundVolume2D::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-68 batch 37; clear bit 6 of +4; stream slot +0x68 with this+0x48')
