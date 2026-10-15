"""specs_c121.py - climb thread batch 121: ZMovementBaseMove::GetAnims (0x488bc0)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt, cstr


def _ga(c):
    r = c.rng
    e = c.emu
    pool = [rnd(c, 0x20) for _ in range(6)]

    def name(e, t, a):
        s = bytes(e.rbytes(a[0], 40)).split(b'\0')[0]
        return (0 if r.random() < 0.15 else pool[r.randrange(len(pool))], None, (s,))

    def reg(e, t, a):
        return (0, None, (a[0] - e.r32(0x70039c) if False else a[0],))
    self_ = rnd(c, 0x500)
    e.w32(self_, rvt(e, 'movement', {0x58: (1, name), 0x54: (1, reg)}, nslots=0x60 // 4))
    # embedded sub-objects that receive slot-8 calls: each starts with its own vtable
    for b in (37, 61, 85):
        def slot8(e, t, a):
            return (0, None, (a[0], a[1], a[2]))
        sub_vt = rvt(e, 'sub%d' % b, {8: (3, slot8)}, nslots=3)
        e.w32(self_ + b, sub_vt)
    return [self_]


S(0x488bc0, 'ZMovementBaseMove::GetAnims', 'thiscall', None, ret=None, gen=_ga,
  note='c121; generated from the disassembly (84 operations); name lookups and sub-object calls are logging fakes')
