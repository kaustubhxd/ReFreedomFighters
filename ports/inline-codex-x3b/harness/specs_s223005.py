"""Controlled strict spec for 0x662b00's scalar easing destination setter."""
import math

from pilot import F, S
from recruits_util import clear_hooks, rnd


def g662b00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    easing = rnd(c, 0x40)
    now_owner = rnd(c, 0x50)
    e.w32(0x70039c, now_owner)
    e.w32(now_owner + 0x40, r.getrandbits(32))

    current = r.choice([0.0, -0.0, 1.0, -1.0, 10.0, -10.0,
                        r.uniform(-100.0, 100.0)])
    prior = r.choice([current, current + 0.01, current - 0.01,
                      current + 1.0, current - 1.0,
                      r.uniform(-100.0, 100.0)])
    threshold = r.choice([0.0, 0.001, 0.01, 0.1, 1.0, 10.0])
    destination = r.choice([prior, prior + threshold, prior - threshold,
                            prior + threshold * 1.01,
                            prior - threshold * 1.01,
                            current, r.uniform(-100.0, 100.0),
                            float('nan'), float('inf'), -float('inf')])
    if not math.isfinite(destination) and r.random() < 0.5:
        threshold = 0.1
    e.w32(easing, __import__('struct').unpack('<I', __import__('struct').pack('<f', current))[0])
    e.w32(easing + 4, __import__('struct').unpack('<I', __import__('struct').pack('<f', prior))[0])
    e.w32(easing + 0x19, __import__('struct').unpack('<I', __import__('struct').pack('<f', threshold))[0])
    return [easing, F(destination)]


S(0x662b00, 'ease_set_destination', 'thiscall', None, ret=None,
  gen=g662b00, reg_values=True)
