"""specs_s895.py - gap-band slice, batch 895: 0x420300 (GUESS name Flag420300), thiscall, one stack arg (index), ret 4, returns a byte.
The flag byte at this+5*idx+0xf0b is drawn with bits 1 and 7 random; the engine float +0x9c7 is drawn equal to the constant at
0x6785d0 (read from the image), unequal, or NaN, so the equal, unequal and unordered cases all run. Heap bytes are compared."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x3000)
    idx = r.choice([0, 1, 2, 7, r.randint(0, 40)])
    e.w8(self + 5 * idx + 0xf0b, r.getrandbits(8))
    const = e.rf32(0x6785d0)
    g = rnd(c, 0x1b00)
    e.w32(0x70039c, g)
    choice = r.random()
    if choice < 0.4:
        val = const
    elif choice < 0.7:
        val = const + 1.0
    else:
        val = float('nan')
    e.wf32(g + 0x9c7, val)
    return [self, idx]


S(0x420300, 'Flag420300 (GUESS name)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch895 (band slice)')
