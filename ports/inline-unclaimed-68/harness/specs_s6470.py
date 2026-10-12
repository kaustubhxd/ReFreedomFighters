"""specs_s6470.py - unclaimed-68 batch 47 (claim 47): ZAttachGeomToBone::Detach (0x4b8bb0). The flag byte at +0x58 is set in about three cases in
four; the dword at +0x59 is a logging object pointer (slot +0x294 with three arguments) in those cases, else zero. The engine's slot +0x58 returns
a zeroed block m; the three fields +0x4c, +0x50 are random."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _detach(c):
    o = zero_obj(c, 0x100)
    c.emu.w32(o + 0x4c, c.rng.getrandbits(32))
    c.emu.w32(o + 0x50, c.rng.getrandbits(32))
    c.emu.wbytes(o + 0x58, bytes([1 if c.rng.random() < 0.75 else 0]))
    if c.rng.random() < 0.85:
        tgt = logged_obj(c, 'ZAttachTarget', 0x300, impl={}, argwords={0x294: 3})
        c.emu.w32(o + 0x59, tgt)
    m = zero_obj(c, 0x40)
    en = logged_obj(c, 'ZAttachEngine', 0x80, impl={0x58: (lambda mm: (lambda e, a: (mm, None)))(m)}, argwords={0x58: 0})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return [o]


S(0x4b8bb0, 'ZAttachGeomToBone::Detach (unknown) thiscall', 'thiscall', None, ret=None, gen=_detach,
  note='unclaimed-68 batch 47; slot +0x294 with (m+8, +0x50, +0x4c) when flag and +0x59 set')
