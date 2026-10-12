"""specs_s1382.py - unclaimed-13 claim 1, batch 2: ZMatPosAnim::SetRotMat (0x4a5fc0). The object is 0x800 random bytes
(the copy lands at +0x93, 36 bytes); the argument points to 36 random bytes (nine dwords). ret 4, void."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj_src(c):
    return [_rnd(c, 0x800), _rnd(c, 0x24)]


S(0x4a5fc0, 'ZMatPosAnim::SetRotMat (unknown) thiscall', 'thiscall', None, ret=None, gen=_obj_src,
  note='unclaimed-13 claim 1 batch 2; copies 36 bytes from the argument to +0x93')
