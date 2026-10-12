"""specs_s6440.py - unclaimed-68 batch 44 (claim 44): ZDllSound::GetPitchChange (0x4c0a20). The argument is random in -400..400 and zero in about
one case in ten; the float result is compared in ST0 (ret 'st0')."""
from pilot import S


def _pitch(c):
    if c.rng.random() < 0.1:
        return [0]
    return [c.rng.randrange(-400, 401)]


S(0x4c0a20, 'ZDllSound::GetPitchChange (unknown) stdcall', 'stdcall', None, ret='st0', gen=_pitch,
  note='unclaimed-68 batch 44; low-confidence name; ST0 result; constants 1200.0 and 1.0 from the exe')
