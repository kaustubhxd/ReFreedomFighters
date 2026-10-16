"""Controlled strict spec for 0x662e20's vector target setter."""
import struct

from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


TOLERANCE = struct.unpack('<f', struct.pack('<I', 0x3dcccccd))[0]


def g662e20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self = rnd(c, 0x40)
    target = rnd(c, 0x20)
    distance = r.choice([
        TOLERANCE, 0.0, -0.0, -TOLERANCE, TOLERANCE * 0.999,
        TOLERANCE * 1.001, 0.1001, 0.0999, 1.0, -1.0,
        float('nan'), float('inf'), -float('inf'), r.uniform(-3.0, 3.0),
    ])
    edx_log = e.alloc(4 * 8, 4)

    def save_edx(emu, call_no):
        emu.w32(edx_log + 4 * min(call_no, 7), emu.reg('edx'))

    hook_rec(c, 0x4e0830, 0, ret=r.getrandbits(32), this=True,
             st0=distance, side=save_edx)
    hook_rec(c, 0x662cf0, 0, ret=r.getrandbits(32), this=True)
    return [self, target]


S(0x662e20, 'vector_ease_set_target', 'thiscall', None, ret=None,
  gen=g662e20, reg_values=True)
