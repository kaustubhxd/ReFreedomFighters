"""specs_s6350.py - unclaimed-68 batches 34 and 35 (claims 34 and 35): ZSoundRandomVolume::ActivateFrameUpdate (0x4bc060) and
ZSoundSpline::ActivateFrameUpdate (0x4be6a0). Logging vtable with slots +0x64 (one argument) and +0x68 (two); the flag is random."""
from pilot import S
from engine_stubs import logged_obj


def _act(c):
    o = logged_obj(c, 'ZActObj', 0x240, impl={}, argwords={0x64: 1, 0x68: 2})
    return [o, c.rng.randrange(0, 2)]


S(0x4bc060, 'ZSoundRandomVolume::ActivateFrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_act,
  note='unclaimed-68 batch 34; tail jump on true (slot +0x64), slot +0x68 on false')
S(0x4be6a0, 'ZSoundSpline::ActivateFrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_act,
  note='unclaimed-68 batch 35; dword +0xd2 cleared on true, then slot +0x64')
