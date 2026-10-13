"""specs_s1107.py - collision thread batch 1107: 0x4883d0 CheckMovingSphereCollision (box from the batch 1106
generator), 0x61ba10 ChangeDimensions."""
from pilot import S, F
from specs_s1106 import _msc


def _cmsc(c):
    e, r = c.emu, c.rng
    box, impact, oldp, newp, ext, vel, flag = _msc(c)
    p = e.alloc(0x620, 4)
    e.wbytes(p, bytes(r.getrandbits(8) for _ in range(0x620)))
    e.w8(p + 0x5ff, 0 if r.random() < 0.2 else r.randint(1, 255))
    for j in range(3):
        e.w32(p + 0x439 + 4 * j, e.r32(ext + 4 * j))
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(this + 4, p)
    e.w32(this + 8, box)
    return [this, impact, e.alloc(0x30, 4), oldp, e.alloc(0x30, 4), newp, vel]


def _cd(c):
    return [c.emu.alloc(0x10, 4)] + [c.rng.getrandbits(32) for _ in range(4)]


S(0x4883d0, 'ZMovementBase::CheckMovingSphereCollision', 'thiscall', None, ret='al', gen=_cmsc, note='batch1107')
S(0x61ba10, 'ZMovementBase::ChangeDimensions (returns false)', 'thiscall', None, ret='al', gen=_cd, note='batch1107')
