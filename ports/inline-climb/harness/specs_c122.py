"""specs_c122.py - climb thread batch 122: ZFFHeroMovementBaseMove::GetAnims (0x5e3e90).

The base ZMovementBaseMove::GetAnims (0x488bc0) runs as original code, so the sub-objects it needs (+0x25, +0x3d, +0x55)
are created here as well as the ones this function uses (+0x25, +0x3d, +0x55, +0x6d area, +0x3d3 and up, see generator)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt, cstr

SUB_OFFSETS = (37, 61, 85, 979, 1003, 1195, 1315)  # every slot-8 call base in the generated body, plus the base GetAnims' (37, 61, 85)


def _ga(c):
    r = c.rng
    e = c.emu
    pool = [rnd(c, 0x20) for _ in range(6)]

    def name(e, t, a):
        s = bytes(e.rbytes(a[0], 40)).split(b'\0')[0]
        return (0 if r.random() < 0.15 else pool[r.randrange(len(pool))], None, (s,))

    def reg(e, t, a):
        return (0, None, (a[0],))
    self_ = rnd(c, 0x800)
    e.w32(self_, rvt(e, 'hero', {0x58: (1, name), 0x54: (1, reg)}, nslots=0x60 // 4))
    e.w32(0x70039c, 0)   # sys is not read by GetAnims itself; the base function reads nothing from it
    for b in SUB_OFFSETS:
        def slot8(e, t, a):
            return (0, None, (a[0], a[1], a[2]))
        e.w32(self_ + b, rvt(e, 'sub%d' % b, {8: (3, slot8)}, nslots=3))
    return [self_]


S(0x5e3e90, 'ZFFHeroMovementBaseMove::GetAnims', 'thiscall', None, ret=None, gen=_ga,
  note='c122; generated from the disassembly; the base ZMovementBaseMove::GetAnims runs as original code')
