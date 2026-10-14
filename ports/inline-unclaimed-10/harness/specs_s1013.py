"""specs_s1013.py - unclaimed-10, batch 9: ZFFHeroMovementStand::GetAnims (0x5e4790). Thiscall, no arguments (ret).
Every virtual call is a stub: the object's vtable (slots +0x54 and +0x58, one argument each) and the four embedded
sub-objects at +0x10d, +0x13d, +0x16d, +0x155 (vtable slot +8, three arguments). The stubs log (slot, this, args) and
return a value that is a fixed function of the first argument, so the stores that follow are deterministic. The
callees are not verified; the calls, their arguments, their order and the stored fields are."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _anims(c):
    e = c.emu
    o = _rnd(c, 0x800)
    vt_this = e.logging_vtable('stand', 40,
                               impl={0x58: lambda em, a: (a[0] ^ 0x5a5a5a5a, None)},
                               argwords={0x58: 1, 0x54: 1})
    vt_sub = e.logging_vtable('stand_sub', 8, argwords={8: 3})
    e.w32(o, vt_this)
    for off in (0x10d, 0x13d, 0x16d, 0x155):
        e.w32(o + off, vt_sub)
    return [o]


S(0x5e4790, 'ZFFHeroMovementStand::GetAnims (unknown) thiscall', 'thiscall', None, ret=None, gen=_anims,
  note='unclaimed-10 batch 9; every virtual call stubbed (logging); sub-objects at +0x10d/+0x13d/+0x16d/+0x155')
