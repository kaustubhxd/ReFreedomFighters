"""specs_s1643.py - residue 13 batch 1643: ZMovementGuide::CalcNewSpeed. The base call 0x487c70 is a recorder (it writes
nothing here, so both runs see the same out buffer). The object is the 0x800-byte guide with its +4 object (flags +0x417)
and the byte/word flags and pointer. The vector helpers 0x451890, 0x4e09b0, 0x4e0d80 run as exe code."""
import struct
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _f(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x487c70, 4, this=True, pop=True)
    o = obj(c, 0x800, {})
    c.emu.w32(o + 0x417, r.getrandbits(32))
    if r.random() < 0.5:
        c.emu.w32(o + 0x417, r.choice([0, 1, 2, 3, 4, 8, 0x10, 0x18, 0x1c, 0x20]))
    self_ = rnd(c, 0x800)
    c.emu.w32(self_ + 4, o)
    for off in (0x3ad, 0x3bb, 0x3bc, 0x3be):
        c.emu.w8(self_ + off, r.choice([0, 0, 1, 2]))
    c.emu.w16(self_ + 0x3bb, r.choice([0, 1, 0xffff]))
    pv = rnd(c, 8)
    c.emu.wf32(pv + 4, r.uniform(-5, 5))
    c.emu.w32(self_ + 0x21, pv if r.random() < 0.6 else 0)
    a = rnd(c, 0x20)
    b = rnd(c, 0x20)
    out = rnd(c, 0x20)
    for i in range(3):
        c.emu.wf32(a + 4 * i, r.uniform(-10, 10))
        c.emu.wf32(b + 4 * i, r.uniform(-10, 10))
    speed = _f(r.choice([0.0, 1.0, -2.0, 3.5, r.uniform(-10, 10)]))
    return [self_, a, b, out, speed]


S(0x487e50, 'ZMovementGuide::CalcNewSpeed', 'thiscall', None, ret=None, gen=_gen, note='batch1643')
