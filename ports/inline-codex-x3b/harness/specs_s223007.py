"""Controlled strict spec for 0x662ab0's scalar easing snap setter."""
import struct

from pilot import F, S
from recruits_util import clear_hooks, rnd


def bits(value):
    return struct.unpack('<I', struct.pack('<f', value))[0]


def g662ab0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    easing = rnd(c, 0x40)
    now_owner = rnd(c, 0x50)
    e.w32(0x70039c, now_owner)
    e.w32(now_owner + 0x40, r.getrandbits(32))
    current = r.choice([0.0, -0.0, 1.0, -1.0, 10.0, -10.0,
                        r.uniform(-100.0, 100.0)])
    threshold = r.choice([0.0, 0.001, 0.01, 0.1, 1.0, 10.0])
    value = r.choice([current, current + threshold, current - threshold,
                      current + threshold * 1.01,
                      current - threshold * 1.01,
                      r.uniform(-100.0, 100.0), float('nan'),
                      float('inf'), -float('inf')])
    e.w32(easing, bits(current))
    e.w32(easing + 0x19, bits(threshold))
    return [easing, F(value)]


S(0x662ab0, 'ease_set_current', 'thiscall', None, ret='al',
  gen=g662ab0, reg_values=True)
