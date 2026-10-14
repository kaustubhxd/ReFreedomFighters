"""specs_u69_48.py - area 69, group 48 (slice 8): 0x5b3540, no callees. Globals 0x70039c (object g) and 0x7003b8 (object h) are set up,
and the object at self+0x63 (p) is given the dwords at +0xa4c and +0xe1c that the code tests.
Byte inputs are biased so each branch is reached often. Half the runs set the threshold at g+0x40 to exactly the value the float path
computes (in single precision, from the two constants in the exe), so the >= comparison is tested at its boundary."""
import struct
from pilot import S
from ckit import rnd


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _rd_f(e, a):
    return struct.unpack('<f', struct.pack('<I', e.r32(a)))[0]


def _wb(e, a, v):
    e.wbytes(a, bytes([v & 0xff]))


def _gen(c):
    e = c.emu
    r = c.rng
    d = rnd(c, 0x200)
    p = rnd(c, 0xe20)
    e.w32(d + 0x63, p)
    e.w32(p + 0xa4c, 0 if r.random() < 0.5 else r.getrandbits(32))
    e.w32(p + 0xe1c, 2 if r.random() < 0.4 else r.getrandbits(32))
    g = rnd(c, 0x100)
    e.w32(0x70039c, g)
    h = rnd(c, 0x2c90)
    e.w32(0x7003b8, h)
    e.w32(d + 0x4d, 3 if r.random() < 0.4 else r.getrandbits(32))
    x = _f32(r.uniform(-120.0, 120.0))
    e.wbytes(d + 0x1e5, struct.pack('<f', x))
    e.w32(g + 0x40, r.randrange(-150, 150) & 0xffffffff)
    _wb(e, g + 0x6c, 0 if r.random() < 0.5 else r.getrandbits(8))
    _wb(e, h + 0x2c89, 0 if r.random() < 0.4 else r.getrandbits(8))
    for off in (0x55, 0x56, 0x1bc, 0x1e9, 0x1b2, 0x176, 0x1a4):
        _wb(e, d + off, r.choice([0, 1, r.getrandbits(8)]))
    if r.random() < 0.5:
        # boundary case: threshold equals the float path's result, the float path runs, and the flag bytes that the >= guards
        t = _f32(_f32(x + _rd_f(e, 0x67a288)) * _rd_f(e, 0x678620))
        e.w32(g + 0x40, int(t) & 0xffffffff)
        _wb(e, d + 0x176, 0)
        _wb(e, d + 0x1e9, 1)
        _wb(e, d + 0x1b2, 0x55)
        _wb(e, g + 0x6c, 0)
    return [d]


S(0x5b3540, 'flagUpdate5b3540 (thiscall, no args, void)', 'thiscall', None, ret=None, gen=_gen, note='u69 group 48; no callees; SSE floats')
