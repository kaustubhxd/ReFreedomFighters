"""specs_s6500.py - unclaimed-68 batch 50 (claim 50): ZGeomSpawn::CheckDeactivate (0x4a7af0, GUESS name), thiscall, bool in AL.
The object's vtable logs slots +0x58 (no args) and +0x68 (two args). The engine global has a dword at +0x40 that is the threshold."""
import struct
from pilot import S
from engine_stubs import zero_obj, logged_obj, set_global


def _f32(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _gen(c):
    o = zero_obj(c, 0x200)
    r = c.rng.random()
    f = 0.0 if r < 0.3 else c.rng.uniform(-2.0, 2.0)
    c.emu.w32(o + 0x56, _f32(f))
    c.emu.w32(o + 0x76, c.rng.randrange(0, 100))
    c.emu.w32(o + 0x50, 0 if c.rng.random() < 0.5 else c.rng.randrange(1, 0x10000))
    c.emu.wbytes(o + 0x7b, bytes([c.rng.randrange(1, 256)]))  # nonzero, so clearing it is visible in the heap compare
    vt = c.emu.logging_vtable('ZGeomSpawnDeact', 0x80, impl={0x58: lambda e, a: (None, None),
                                                              0x68: lambda e, a: (None, None)},
                              argwords={0x68: 2})
    c.emu.w32(o, vt)
    eng = zero_obj(c, 0x400)
    c.emu.w32(eng + 0x40, c.rng.randrange(0, 100))
    set_global(c, 0x70039c, eng)
    return [o]


S(0x4a7af0, 'ZGeomSpawn::CheckDeactivate (GUESS) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-68 batch 50; vtable slot +0x58 (no args) or +0x68 (args 0x10, 0); engine +0x40 threshold')
