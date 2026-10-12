"""specs_s6580.py - unclaimed-68 batch 58 (claim 59): ZAnimSequence::ReadInput(DBREAD&) (0x4c4e90), thiscall, one stack argument, ret 4.
The DBREAD operators come from one shared cursor (harness/dbread_cursor.py), so the read order is checked. GetRefTab (0x4e6330) is stubbed."""
import struct
from pilot import S
from engine_stubs import zero_obj
import dbread_cursor


def _setup(c):
    # stream content: a few dwords per read, random bits (NaN floats are counted as nan_payload, not failures)
    vals = [c.rng.getrandbits(32) for _ in range(12)]
    # make the float divisor path see a finite, nonzero value often
    vals[5] = struct.unpack('<I', struct.pack('<f', c.rng.uniform(-8.0, 8.0)))[0]
    c.st = {'buf': dbread_cursor.install(c, vals)}


def _gen(c):
    o = zero_obj(c, 0x100)
    for off in (0x4c, 0x50, 0x54):
        c.emu.w32(o + off, c.rng.getrandbits(32))
    stream = zero_obj(c, 0x40)
    return [o, stream]


S(0x4c4e90, 'ZAnimSequence::ReadInput (residue name) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='unclaimed-68 batch 58; shared DBREAD cursor (u32, u16, float); GetRefTab 0x4e6330 stubbed (not verified)')
