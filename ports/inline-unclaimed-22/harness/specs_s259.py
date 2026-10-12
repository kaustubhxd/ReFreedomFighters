"""specs_s259.py - area 22, batch259 (src/batch259.cpp): CMoveAlongPath::SetMoveParams, ZPlayer::GetMoveSpeeds,
ZPlayer::CreateMovementAction. Floats are passed as bit patterns (values around 1.0, negatives, zero, NaN, infinities).
The allocator 0x41e290 is hooked (cdecl, logs the size, returns a heap block or 0 per case); the constructor 0x487600 runs
as original code (verified in inline-unclaimed-21)."""
import struct
from pilot import S
from helpers22 import _rnd, _multi_vt, _hk


def _r(c):
    return c.rng.getrandbits(32)


def _f(c):
    k = c.rng.random()
    if k < 0.1:
        return c.rng.choice([0x7fc00000, 0xffc00000, 0x7f800000, 0xff800000, 0x80000000, 0])
    if k < 0.2:
        return 0x3f800000 + c.rng.choice([-1, 0, 1])
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(-3.0, 4.0)))[0]


def _g_523b10(c):
    self_ = _rnd(c, 0x70)
    c.emu.w32(self_, _multi_vt(c, {8: (lambda em, a: (0, None), 2)}))
    c.emu.w32(self_ + 0x39, c.rng.choice([1, 1, 0, 2, 0x101]))
    return [self_, _f(c), _f(c), _f(c)]


def _g_483b10(c):
    return [_rnd(c, 0x460), _rnd(c, 12)]


def _g_482890(c):
    blk = c.rng.choice([_rnd(c, 0x30)] * 4 + [0])
    _hk(c, 0x41e290, 'new', 1, eax=blk, pop=0)
    c.emu.mu.ctl_flush_tb()
    return [_rnd(c, 0x40)]


S(0x523b10, 'CMoveAlongPath::SetMoveParams', 'thiscall', None, ret=None, gen=_g_523b10, nan_heap=True,
  note='batch259; void; below-1.0 values clamp to 1.0 (NaN kept)')
S(0x483b10, 'ZPlayer::GetMoveSpeeds', 'thiscall', None, ret=None, gen=_g_483b10,
  note='batch259; void; three-word copy')
S(0x482890, 'ZPlayer::CreateMovementAction', 'thiscall', None, ret='eax', gen=_g_482890,
  note='batch259; allocator hooked; constructor 0x487600 runs as exe code; SEH frame and cookie not reproduced')
