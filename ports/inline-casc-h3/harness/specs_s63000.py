from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub
import struct

def _g51cf10(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    side_values = [r.choice([-2.0, -0.25, 0.0, 0.25, 0.999, 1.001, 3.0]) for _ in range(3)]

    def write_vec(emulator, _call):
        p = emulator.arg32(0)
        for i, value in enumerate(side_values):
            emulator.w32(p + 4 * i, struct.unpack('<I', struct.pack('<f', value))[0])

    slot36c = pystub(c, 0, this=True)
    slot88 = pystub(c, 1, this=True, deref={0: 3}, side=write_vec)
    slot7c = pystub(c, 2, this=True, deref={0: 3, 1: 3})
    self = obj(c, 0x380, {0x36c: slot36c, 0x88: slot88, 0x7c: slot7c})
    # Distinct, finite float inputs at the unaligned vector fields.
    for off in (0x276, 0x27a, 0x27e, 0x60, 0x64, 0x68):
        value = r.uniform(-4.0, 4.0)
        em.w32(self + off, struct.unpack('<I', struct.pack('<f', value))[0])
    return [self]

S(0x51cf10, 'GUESS_update_clamped_vector_from_helper', 'thiscall', None,
  ret=None, gen=_g51cf10, note='batch63000')
