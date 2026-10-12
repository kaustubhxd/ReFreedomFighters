"""specs_s6370.py - unclaimed-68 batches 38 and 39 (claims 38 and 39): ZSoundExtend::Command (0x4bf0f0) and ZSoundAnimation::Command
(0x4bf0d0). The object is a logging vtable (slots +0x88 with no argument, +0x64 with one). The command word is 0..3 and the stored key
word is 0..3, so matches happen about one time in four."""
from pilot import S
from engine_stubs import logged_obj


def _cmd(c):
    o = logged_obj(c, 'ZSoundCmdObj', 0x240, impl={}, argwords={0x88: 0, 0x64: 1})
    key = c.rng.randrange(0, 4)
    c.emu.wbytes(o + 0x81, bytes([key, 0]))
    c.emu.wbytes(o + 0x48, bytes([key, 0]))
    return [o, c.rng.randrange(0, 4), c.rng.getrandbits(32)]


S(0x4bf0f0, 'ZSoundExtend::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  note='unclaimed-68 batch 38; slot +0x88 with no argument when the word at +0x81 matches')
S(0x4bf0d0, 'ZSoundAnimation::Command (unknown) thiscall', 'thiscall', None, ret='eax', gen=_cmd,
  note='unclaimed-68 batch 39; store arg at +0x4a; slot +0x64 with 0x10 when the word at +0x48 matches')
