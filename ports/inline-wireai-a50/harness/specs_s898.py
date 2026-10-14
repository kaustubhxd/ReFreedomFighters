"""specs_s898.py - gap-band slice, batch 898: three flag accessors with the engine-float gate (thiscall, one stack arg, ret 4, al):
0x420380 (off 0xf0b, result bit 4, test 0x08), 0x4203d0 (off 0xf0b, result bit 5, test 0x04), 0x420220 (off 0xa0b, result bit 4, test
0x08). The engine float at +0x9c7 is drawn equal to the constant at 0x6785d0, above it, or NaN. Heap bytes are compared."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x3000)
    idx = r.choice([0, 1, 2, 7, r.randint(0, 40)])
    for off in (0xa0b, 0xf0b):
        e.w8(self + 5 * idx + off, r.getrandbits(8))
    const = e.rf32(0x6785d0)
    g = rnd(c, 0x1b00)
    e.w32(0x70039c, g)
    ch = r.random()
    val = const if ch < 0.4 else (const + 1.0 if ch < 0.7 else float('nan'))
    e.wf32(g + 0x9c7, val)
    return [self, idx]


S(0x420380, 'FreeActionMap (ZSysInterfaceGC)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch898 (band slice)')
S(0x4203d0, 'InitActionMap (ZSysInterfaceGC)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch898 (band slice)')
S(0x420220, 'CheckKeyTap (ZSysInterfaceGC)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch898 (band slice)')
