"""specs_s686.py - unclaimed-68 batch 6 (claim 5): 0x597fb0 (ZGameOSD::HideHintMessage) and its two leaves 0x5ed9b0 and 0x5efdf0.
The chain: this+0x1d0f -> object -> +0x634 -> object whose +0x94 is set to 1. Each object is a zeroed block (no calls, so no
logging needed); the getter reads the dword at +0xe3 of random bytes."""
from pilot import S
from engine_stubs import zero_obj


def _chain(c):
    self_ = zero_obj(c, 0x2000)
    hint = zero_obj(c, 0x1000)
    target = zero_obj(c, 0x400)
    c.emu.w32(hint + 0x634, target)
    c.emu.w32(self_ + 0x1d0f, hint)
    return [self_]


def _rnd_obj(c):
    a = c.emu.alloc(0x400, 16)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x400)))
    return [a]


S(0x597fb0, 'ZGameOSD::HideHintMessage (unknown) thiscall', 'thiscall', None, ret=None, gen=_chain,
  note='unclaimed-68 batch 6; chain via this+0x1d0f and +0x634; flag +0x94 = 1')
S(0x5ed9b0, 'GUESS FUN_5ed9b0 (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_rnd_obj,
  note='unclaimed-68 batch 6; GUESS name; dword at +0xe3')
S(0x5efdf0, 'GUESS FUN_5efdf0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_rnd_obj,
  note='unclaimed-68 batch 6; GUESS name; dword at +0x94 = 1')
