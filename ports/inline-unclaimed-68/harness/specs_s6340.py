"""specs_s6340.py - unclaimed-68 batch 33 (claim 33): ZSoundVolumetricSource::ActivateFrameUpdate (0x4bcc30). The object is a logging
vtable whose slots +0x64 (one argument) and +0x68 (two arguments) log; the flag is random."""
from pilot import S
from engine_stubs import logged_obj


def _act(c):
    o = logged_obj(c, 'ZVolSrc', 0x240, impl={}, argwords={0x64: 1, 0x68: 2})
    return [o, c.rng.randrange(0, 2)]


S(0x4bcc30, 'ZSoundVolumetricSource::ActivateFrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_act,
  note='unclaimed-68 batch 33; slot +0x64 (0x10) or slot +0x68 (0x10, 0); dword +0xd5 cleared on true')
