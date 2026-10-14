"""specs_s37019.py - cascade s6 batch 37019: 0x4d0d20 (pixel format repack through 0x4d06a0, which runs as original code). Random pixel and random previous word at this+0x213."""
from pilot import S
from recruits_util import rnd


def _g4d0d20(c):
    r = c.rng
    me = rnd(c, 0x230)
    v = r.choice([r.getrandbits(32), 0xffffffff, 0, 0x80ffffff, 0x7f010203, r.getrandbits(16), 0xff000000 | r.getrandbits(24)])
    if r.random() < 0.4:
        c.emu.w32(me + 0x213, r.choice([r.getrandbits(16), 0x7fff, 0x8000, 0xffff, r.getrandbits(32)]))
    return [me, v]


S(0x4d0d20, 'GUESS pixel repack 8888 to 1555 and previous back', 'thiscall', None, ret='eax', gen=_g4d0d20, note='batch37019')
