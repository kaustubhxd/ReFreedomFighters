"""specs_s528.py - weapons batch 528: ZCollisionBox setter (0x4eb020)."""
from pilot import S
from wkit import rnd, vec


def _box(c):
    o = rnd(c, 0x60)
    mat = vec(c, 9, -5, 5)
    a = vec(c, 3, -100, 100)
    b = vec(c, 3, -100, 100)
    return [o, mat, a, b]


S(0x4eb020, 'ZCollisionBox setter (mat + two vectors)', 'thiscall', None, ret=None, gen=_box)
