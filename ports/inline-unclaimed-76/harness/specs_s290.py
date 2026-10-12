"""specs_s290.py - unclaimed area 76 (docs/20-unclaimed-76.md), residue-15 leaf: 0x464e70, release of one of three handle
slots through engine+0x9b ->vtbl[0x58](key) (returns an object or 0) and obj->vtbl[0x210](1)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _rel(c):
    e = c.emu
    obj_vt = e.logging_vtable('obj464e', 0x85, impl={}, argwords={0x210: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, obj_vt)
    give = c.rng.random() < 0.8
    o_vt = e.logging_vtable('eng464e', 0x17, impl={0x58: lambda em, a: (obj if give else 0, None)}, argwords={0x58: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    self_ = _rnd(c, 0x200)
    slots = []
    for off in (0x12a, 0x12e, 0x132):
        v = c.rng.choice([0, 0x1000 + c.rng.randrange(64), c.rng.getrandbits(32) | 1])
        e.w32(self_ + off, v)
    flags = c.rng.choice([0x00, 0x10, 0x20, 0x30, c.rng.getrandbits(8)])
    return [self_, c.rng.getrandbits(32), flags]


S(0x464e70, 'releaseSlots (GUESS)', 'thiscall', None, ret=None, gen=_rel, note='batch290; ret 8')
