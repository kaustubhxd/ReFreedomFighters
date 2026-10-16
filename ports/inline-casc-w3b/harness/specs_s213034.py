"""specs_s213034.py - batch 213034: mode-driven field select from a copied block, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g5e9b70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    P = rnd(c, 0x3d0)
    this = rnd(c, 0x1d60)
    e.wbytes(this + 0x1d0f, struct.pack("<I", P))
    mode = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 0x20, r.getrandbits(32)])
    e.wbytes(P + 0x3c2, struct.pack('<I', mode))
    prev = r.choice([mode, mode, 8, r.getrandbits(8), r.randint(0, 9)])
    e.wbytes(this + 0x1d47, struct.pack('<I', prev))
    for o in (4, 0xc, 0x15, 0x25, 0x39, 0x3d, 0x2d, 0x29, 0x31, 0, 8, 0x19):
        if r.random() < 0.25:
            e.wbytes(P + 0x37d + o, bytes(4))
    if r.random() < 0.4:
        e.wbytes(P + 0x37d + 0x1d, struct.pack('<I', 2))
    hook_rec(c, 0x4f9680, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5ab230, 1, ret=r.getrandbits(32), this=True)
    hook_rec(c, 0x5ab2a0, 1, ret=r.getrandbits(32), this=True)
    return [this]


S(0x5e9b70, 'mode_field_select', 'thiscall', None, ret='eax', gen=g5e9b70)
