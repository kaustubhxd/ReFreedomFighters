"""specs_s6460.py - unclaimed-68 batch 46 (claim 46): ZSoundToggle::Init (0x4bb5e0). The flag byte at +0x50 is random; the sub-object at +0x44 is
null in about one case in four, otherwise a zeroed block. The two callees (ZSNDOBJ::Stop and DefaultValues) are exe code."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _init(c):
    o = zero_obj(c, 0x100)
    c.emu.wbytes(o + 0x50, bytes([c.rng.randrange(0, 2)]))
    blk = zero_obj(c, 0x200)
    c.emu.w32(blk + 0x80, c.rng.getrandbits(32))
    sub = logged_obj(c, 'ZSoundToggleSub', 0x80, impl={0x104: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={0x104: 1})
    c.emu.w32(sub + 0x18, blk)
    c.emu.w32(o + 0x44, sub)
    en = logged_obj(c, 'ZSoundToggleEngine', 0x80, impl={0x114: lambda e, a: (c.rng.getrandbits(16), None)}, argwords={0x114: 4})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    return [o]


S(0x4bb5e0, 'ZSoundToggle::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_init,
  note='unclaimed-68 batch 46; ZSNDOBJ::Stop on the sub-object when the flag is clear; then DefaultValues (exe)')
