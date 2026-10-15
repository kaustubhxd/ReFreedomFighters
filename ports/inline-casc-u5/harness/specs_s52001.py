"""specs_s52001.py - tier H. 0x636a80: records of 4x4 colour blocks (sizes 0..20, odd ones to hit the round-up), random data, the real 0x636540 runs on both sides (float argument F())."""
import struct
from pilot import S, EDGE_F, F
from recruits_util import rnd, clear_hooks


def _fv(r):
    k = r.random()
    if k < 0.2:
        v = r.choice([x for x in EDGE_F if x == x and abs(x) < 1e6])
    elif k < 0.6:
        v = r.uniform(0, 1)
    else:
        v = r.uniform(-2, 3)
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _g636a80(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 1, 2, 3])
    recs = c.emu.alloc(0x14 * 4 + 8, 4)
    for i in range(n):
        w = r.choice([0, 1, 3, 4, 5, 7, 8, 9, 12, 16, 20, -1, 2])
        h = r.choice([0, 1, 3, 4, 5, 7, 8, 9, 12, 16, 20, -1, 2])
        wr = (w + 3) & ~3
        hr = (h + 3) & ~3
        blocks = max(1, ((max(hr - 3, 1) - 1) // 4 + 1) * ((max(wr - 3, 1) - 1) // 4 + 1)) + 1
        data = rnd(c, 8 + 16 * blocks + 16)
        c.emu.wbytes(recs + 0x14 * i, rnd_bytes(r, 0x14))
        c.emu.w32(recs + 0x14 * i + 4, w & 0xffffffff)
        c.emu.w32(recs + 0x14 * i + 8, h & 0xffffffff)
        c.emu.w32(recs + 0x14 * i + 0x10, data)
    me = rnd(c, 0x20)
    c.emu.w32(me + 0x10, n)
    c.emu.w32(me + 0x14, recs)
    return [me, F(_fv(r))]


def rnd_bytes(r, n):
    return bytes(r.getrandbits(8) for _ in range(n))


S(0x636a80, 'GUESS recode colour blocks', 'thiscall', None, ret=None, gen=_g636a80, note='batch52001')
