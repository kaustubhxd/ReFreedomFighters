"""specs_s896.py - gap-band slice, batch 896: four byte-flag accessors (thiscall, one stack arg = index, ret 4, returns al):
0x4201d0 (off 0xa0b, result bit 7, clears bit 1's byte), 0x420350 (off 0xf0b, same), 0x4202d0 (off 0xa0b, result bit 5, test bit 2,
clear bit 5), 0x420420 (off 0xf0b, same as 0x4202d0). The flag bytes are random; the index is small. Heap bytes are compared."""
from pilot import S
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x3000)
    idx = r.choice([0, 1, 2, 7, r.randint(0, 40)])
    for off in (0xa0b, 0xf0b):
        e.w8(self + 5 * idx + off, r.getrandbits(8))
    return [self, idx]


S(0x4201d0, 'CheckKeyAlways (ZSysInterfaceGC)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch896 (band slice)')
S(0x420350, 'Flag420350 (named GetRegPaths in the map; shape only)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch896 (band slice)')
S(0x4202d0, 'CheckKeyTapAlways (ZSysInterfaceGC)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch896 (band slice)')
S(0x420420, 'TexturePath (ZSysInterfaceGC; shape only)', 'thiscall', None, ret='al', gen=_gen, note='area50 batch896 (band slice)')
