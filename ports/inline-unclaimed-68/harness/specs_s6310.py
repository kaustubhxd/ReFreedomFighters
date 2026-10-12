"""specs_s6310.py - unclaimed-68 batch 30 (claim 30): ZSoundSpline::End (0x4bf500). The field at +0x6d (unaligned) holds a logging object
in about three cases in four, and is null otherwise. The logging object's slot 0 logs its argument (callee cleanup)."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _end(c):
    o = zero_obj(c, 0x100)
    if c.rng.random() < 0.75:
        c.emu.alloc(3, 1)   # pad so the sub-object address has a non-zero low byte (the first byte of the field)
        s = logged_obj(c, 'ZSplineSub', 0x40, impl={}, argwords={0: 1})
        c.emu.w32(o + 0x6d, s)
    return [o]


S(0x4bf500, 'ZSoundSpline::End (unknown) thiscall', 'thiscall', None, ret=None, gen=_end,
  note='unclaimed-68 batch 30; unaligned pointer at +0x6d; slot 0 with 1; then cleared')
