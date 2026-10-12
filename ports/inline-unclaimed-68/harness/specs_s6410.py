"""specs_s6410.py - unclaimed-68 batch 41 (claim 41): CGeomSound::OnSetDelay (0x4a3640). The engine global at 0x70039c points at a zeroed
block with a random dword at +0x40; the argument is random (zero in about one case in five)."""
from pilot import S
from engine_stubs import zero_obj, set_global


def _delay(c):
    eng = zero_obj(c, 0x100)
    c.emu.w32(eng + 0x40, c.rng.getrandbits(32))
    set_global(c, 0x70039c, eng)
    o = zero_obj(c, 0x100)
    arg = 0 if c.rng.random() < 0.2 else c.rng.getrandbits(20)
    return [o, arg]


S(0x4a3640, 'CGeomSound::OnSetDelay (unknown) thiscall', 'thiscall', None, ret='eax', gen=_delay,
  note='unclaimed-68 batch 41; (arg << 10 + engine+0x40) >> 10 to this+0x54 when arg nonzero')
