"""specs_c1069.py - camera batch 1069: the clip-plane builder 0x4453c0 (name not in the class map).

The index argument equals the current count (the original's check passes); the callback at 0x7003b0 is set to a stub (it
is not reached). Planes include zero normals and NaN components."""
import struct
from pilot import S
from camgen import rnd, Log, fbits


def _fl(c, lo, hi):
    return struct.unpack('<I', struct.pack('<f', c.rng.uniform(lo, hi)))[0]


def _plane(c):
    r = c.rng
    pl = rnd(c, 0x20)
    if r.random() < 0.15:
        for i in range(3):
            c.emu.w32(pl + 4 * i, 0)
    else:
        for i in range(3):
            c.emu.w32(pl + 4 * i, fbits(c) if r.random() < 0.1 else _fl(c, -2.0, 2.0))
    c.emu.w32(pl + 12, fbits(c) if r.random() < 0.1 else _fl(c, -300, 300))
    return pl


def _add(c):
    r = c.rng
    self_ = rnd(c, 0x200)
    n = r.randint(0, 4)
    c.emu.w32(self_, n)
    c.emu.w32(self_ + 4, r.getrandbits(16))
    c.emu.hook(0x7003b0, lambda e, res: None) if False else None
    return [self_, _plane(c), n]


S(0x4453c0, 'ZCamPlanes::Add (unnamed)', 'thiscall', gen=_add)
