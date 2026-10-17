"""specs_s1222.py - pathfinding batch 1222: ZPathfinder3::SerializeData(char* blob, int mode).

Real exe code: the octree constructor (0x52cfd0), Init0 (0x530fb0), the allocator, the reporter. Stubbed the same way in
both builds: the octree's own SerializeData (0x531270, its own batch) returns 16 bytes, and the assert hook returns.
"""
import struct
from pilot import S
from pfspec import rnd, reporter, allocator
import pilot

P = lambda v: struct.pack('<I', v & 0xffffffff)
MAGICS = [0x1923482, 0x1923483, 0x1923484, 0x82349201, 0x83349201, 0x84349201, 0x12345678]


def code(c, b):
    a = c.emu.alloc(len(b) + 16, 16)
    c.emu.wbytes(a, b)
    return a


def _sd(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    allocator(c)
    e.w32(0x7003b0, code(c, b'\xc3'))                       # assert hook: returns
    e.wbytes(0x531270, b'\xb8' + P(code(c, b'\xb8' + P(16) + b'\xc2\x0c\x00')) + b'\xff\xe0')   # octree SerializeData stub
    e.w8(0x701b58, r.choice([0, 1]))
    self_ = e.alloc(0xa0, 4)
    e.wbytes(self_, bytes(0xa0))                           # a fresh ZPathfinder3: zeroed fields
    e.w8(self_ + 0x31, r.choice([0, 1]))                   # cPackData
    blob = e.alloc(0x80, 16)
    e.wbytes(blob, bytes(r.getrandbits(8) for _ in range(0x80)))
    mode = r.choice([1, 1, 2, 2, 3])
    if mode == 1:
        e.w32(blob, r.choice(MAGICS) if r.random() < 0.9 else r.getrandbits(32))
    return [self_, blob, mode]


S(0x52cb60, 'ZPathfinder3::SerializeData', 'thiscall', None, ret='eax', gen=_sd, n=200)
