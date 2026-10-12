"""specs_s6420.py - unclaimed-68 batch 42 (claim 42): ZPlaySound::FrameUpdate (0x4a3160). The engine's sound object answers slot +0x60 with a
block (about three cases in four) or null; the object's own slot +0x68 logs; the sub-object at +0x44 holds a block at +8 with random dwords.
A logging object's slot +0x60 returns the answer block; the answer block is zeroed."""
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _fu(c):
    ans = zero_obj(c, 0x100)
    use = c.rng.random() < 0.75
    en = logged_obj(c, 'ZPlayEng', 0x240, impl={0x60: (lambda a_: (lambda e, a: (a_ if use else 0, None)))(ans)}, argwords={0x60: 1})
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x9b, en)
    set_global(c, 0x70039c, eng)
    o = logged_obj(c, 'ZPlaySoundObj', 0x240, impl={}, argwords={0x68: 2})
    sub = zero_obj(c, 0x100)
    blk = zero_obj(c, 0x100)
    for k in range(0, 0x30, 4):
        c.emu.w32(blk + k, c.rng.getrandbits(32))
    c.emu.w32(sub + 8, blk)
    c.emu.w32(o + 0x44, sub)
    c.emu.w32(o + 0x50, c.rng.getrandbits(32))
    return [o]


S(0x4a3160, 'ZPlaySound::FrameUpdate (unknown) thiscall', 'thiscall', None, ret=None, gen=_fu,
  note='unclaimed-68 batch 42; engine slot +0x60; null -> own slot +0x68 (0x10, 0); else two block copies')
