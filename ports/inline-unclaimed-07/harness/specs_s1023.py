"""specs_s1023.py - unclaimed-07 batch 23 (slice 6): ZSoundVolumetricSource::ActivateVolume (0x4bcc20). A byte store."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _activate(c):
    o = _rnd(c, 0x100)
    return [o, c.rng.getrandbits(32)]


S(0x4bcc20, 'ZSoundVolumetricSource::ActivateVolume (unknown) thiscall', 'thiscall', None, ret=None, gen=_activate,
  note='unclaimed-07 batch 23; low byte of arg at +0xd0')
