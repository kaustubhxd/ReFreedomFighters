"""specs_s1150.py - collision thread batch 1150 (GUESS name): 0x4e3d60, ZOctreeCompiled::Init. The argument X is a 0x20-byte record
(three floats at +4, +8, +0xc; a dword at +0x10). The callee 0x4e3360 runs as exe code. The object is 0x40 bytes."""
import struct
from pilot import S, F


def _init(c):
    e, r = c.emu, c.rng
    X = e.alloc(0x20, 16)
    e.wbytes(X, bytes(r.getrandbits(8) for _ in range(0x20)))
    for i in range(3):
        e.wf32(X + 4 + 4 * i, r.uniform(-100, 100))
    self_ = e.alloc(0x40, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x40)))
    return [self_, X]


S(0x4e3d60, 'octree Init: store X, the dword at X+0x10, and the three floats of X via 0x4e3360 (name GUESS)', 'thiscall', None,
  ret=None, gen=_init, note='batch1150')
