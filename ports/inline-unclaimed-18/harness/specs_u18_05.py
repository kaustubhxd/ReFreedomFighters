"""specs_u18_05.py - area 18, group 5 (unclaimed-18 thread)."""
from pilot import S
from ckit import rnd


def _pitch(c):
    e = c.emu
    e.hook(0x4c14b0, lambda e, r: (e.calllog.append(('GetValues', e.reg('ecx'), e.arg32(0))), e.ret(argbytes=4)))
    return [rnd(c, 0x100), c.rng.getrandbits(32)]


S(0x4bf4d0, 'ZSoundSegmentPitch::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_pitch,
  note='u18; GetValues is a logging hook (not lifted, 500 bytes)')


def _sb(c):
    r = c.rng
    o = rnd(c, 0x100)
    c.emu.w32(o + 0x5d, r.choice([0, 1, 0x80000000, r.getrandbits(32)]))
    return [o, c.rng.getrandbits(32)]


S(0x54e090, '_ZSoundBuffer::CopyWaveData', 'thiscall', None, ret='al', gen=_sb, note='u18')


def _lm(c):
    return [rnd(c, 0x1000), rnd(c, 0x1000)]


S(0x56b410, 'CLoadMenu::CopyData', 'thiscall', None, ret=None, gen=_lm, note='u18')
