"""specs_s391.py - core batch 391: 0x641d80 ZRagdollContainer::GetGravityValue (thiscall, no arguments). It returns the float
global at 0x6ec3cc in ST0. Each run writes a random finite float into that global (the object is a dummy)."""
import struct
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    v = struct.unpack('<I', struct.pack('<f', c.fv(-50.0, 50.0)))[0] if hasattr(c, 'fv') else 0
    c.emu.w32(0x6ec3cc, v)
    o = E.zero_obj(c, 0x40)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x641d80, 'ZRagdollContainer::GetGravityValue (core) thiscall', 'thiscall', None, ret='st0', gen=_gen,
  note='core batch 391; reads float global 0x6ec3cc')
