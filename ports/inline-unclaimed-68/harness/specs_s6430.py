"""specs_s6430.py - unclaimed-68 batch 43 (claim 43): ZSIGTE::PushPopScene (0x4a9200). The engine block at 0x70039c holds random dwords; the
object is zeroed; the flag is random (zero in about half of the cases)."""
from pilot import S
from engine_stubs import zero_obj, set_global


def _pp(c):
    eng = zero_obj(c, 0x1000)
    for k in range(0x9e7, 0x9f3, 4):
        c.emu.w32(eng + k, c.rng.getrandbits(32))
    set_global(c, 0x70039c, eng)
    o = zero_obj(c, 0x200)
    for k in (0x8b, 0x8f, 0x97, 0x9b, 0x9f):
        c.emu.w32(o + k, c.rng.getrandbits(32))
    return [o, 0 if c.rng.random() < 0.5 else 1]


S(0x4a9200, 'ZSIGTE::PushPopScene (unknown) thiscall', 'thiscall', None, ret=None, gen=_pp,
  note='unclaimed-68 batch 43; flag zero: clear +0x8b/+0x8f, copy engine +0x9e7/+0x9eb/+0x9ef to +0x97/+0x9b/+0x9f')
