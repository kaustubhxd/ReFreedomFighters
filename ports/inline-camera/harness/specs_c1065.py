"""specs_c1065.py - camera batch 1065: ZCAMERA::SetViewport (0x446e60)."""
from pilot import S
from camgen import rnd


def _vp(c):
    r = c.rng
    cam = rnd(c, 0x200)
    v = rnd(c, 0x20)
    for i in range(4):
        c.emu.w32(v + 4 * i, r.getrandbits(32) if r.random() < 0.3 else c.rng.randint(0, 2000))
    return [cam, v]


S(0x446e60, 'ZCAMERA::SetViewport', 'thiscall', gen=_vp)
