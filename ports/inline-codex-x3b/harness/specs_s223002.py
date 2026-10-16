"""Controlled strict spec for 0x662fd0's vector/easing update."""
import struct

from pilot import S
from recruits_util import clear_hooks, hook_rec, rnd


THRESHOLD = struct.unpack('<f', struct.pack('<I', 0x3dcccccd))[0]


def g662fd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    self = rnd(c, 0x60)
    source_vec = rnd(c, 0x20)

    # COMISS/JBE treats equality and unordered results as the skip path.
    distance = r.choice([
        THRESHOLD, 0.0, -0.0, -THRESHOLD, THRESHOLD * 0.999,
        THRESHOLD * 1.001, 0.1001, 0.0999, 1.0, -1.0,
        float('nan'), float('inf'), -float('inf'), r.uniform(-3.0, 3.0),
    ])
    first_edx = e.alloc(4 * 8, 4)
    second_edx = e.alloc(4 * 8, 4)

    def save_first_edx(emu, call_no):
        emu.w32(first_edx + 4 * min(call_no, 7), emu.reg('edx'))

    def save_second_edx(emu, call_no):
        emu.w32(second_edx + 4 * min(call_no, 7), emu.reg('edx'))

    blend = r.choice([0.0, -0.0, 1.0, -1.0, 0.125, -3.5,
                      r.uniform(-100.0, 100.0)])
    hook_rec(c, 0x4e0830, 0, ret=r.getrandbits(32), this=True,
             st0=distance, side=save_first_edx)
    hook_rec(c, 0x4e0030, 0, ret=r.getrandbits(32), this=True,
             st0=blend, side=save_second_edx)
    hook_rec(c, 0x662ab0, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x662b00, 1, ret=r.getrandbits(32), this=True)
    return [self, source_vec]


S(0x662fd0, 'matrix_ease_set_vector', 'thiscall', None, ret=None,
  gen=g662fd0, reg_values=True)
