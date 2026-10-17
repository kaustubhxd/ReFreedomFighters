"""specs_s1625.py - soundtimers batch 1625: small ZDllSound setters and listeners."""
from pilot import S
from sthelp import rnd


def _o(c):
    r = c.rng
    return [rnd(c, 0x5300), rnd(c, 0x20) if r.random() < 0.8 else 0]


S(0x533bc0, 'ZDllSound::SPtrToRef', 'thiscall', None, ret='eax', gen=_o, note='batch1625')
S(0x539c60, 'ZDllSound::SetMasterPan', 'thiscall', None, ret='al', gen=lambda c: [rnd(c, 0x100), c.rng.getrandbits(32)], note='batch1625')
S(0x5332d0, 'ZDllSound::EnableMultiListeners', 'thiscall', None, ret=None,
  gen=lambda c: [rnd(c, 0x100), c.rng.choice([0, 1, c.rng.getrandbits(8)])], note='batch1625')


def _idx(c):
    r = c.rng
    # in-range indexes and the no-op index 4 only: negative indexes fault in both builds
    return [rnd(c, 0x5300), r.choice([0, 1, 2, 3, 4]), r.getrandbits(32), r.getrandbits(32)]


S(0x537e70, 'ZDllSound::ListenerDisable', 'thiscall', None, ret='al',
  gen=lambda c: [rnd(c, 0x5300), _idx(c)[1]], note='batch1625')
S(0x537e90, 'ZDllSound::ListenerEnable', 'thiscall', None, ret='al', gen=_idx, note='batch1625')
