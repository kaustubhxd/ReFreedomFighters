"""specs_s606.py - damage batch 606: ZFFHERO::Die (PC 0x5910d0). ZPlayer::Die 0x4830e0 is patched to a stub."""
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge
from dkit import patch_jmp


def _gen(c):
    r = c.rng
    emu = c.emu
    patch_jmp(c, 0x4830e0, stub(c, 3))
    hero = obj(c, 0x1000, {0x3dc: stub(c, 0), 0x220: stub(c, 1), 0x368: stub(c, 0)})
    emu.w32(hero + 0x417, r.getrandbits(32) & ~(0x40000 if r.random() < 0.8 else 0))
    pos = rnd(c, 16)
    d = rnd(c, 16)
    f = r.choice((10.0, 250.0, 249.9, 1000.0, 0.0, -5.0, float('nan'), fedge(c), r.uniform(0, 600)))
    return [hero, pos, d, struct.unpack('<I', struct.pack('<f', f))[0]]


S(0x5910d0, 'ZFFHERO::Die', 'thiscall', ret=None, gen=_gen)


def _gen_p(c):
    r = c.rng
    o = obj(c, 0x20, {8: stub(c, 1)})
    p = obj(c, 0x600, {0x3dc: stub(c, 0)})
    c.emu.w32(p + 0x455, o)
    return [p, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4830e0, 'ZPlayer::Die', 'thiscall', ret=None, gen=_gen_p)
