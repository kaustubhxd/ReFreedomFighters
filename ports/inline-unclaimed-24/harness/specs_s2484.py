"""specs_s2484.py - decomp area 24, batch 2484.
0x486700 ZActionPushButton::Execute(), thiscall, void-like, AL = 1. Logger at 0x700390 (slot 0x20 then cdecl slot 0x2c).
Child calls: +8 slot 0x80 (writes the 5-float buffer), +0xc slot 0x384 (writes two 3-float buffers), +0xc slot 0x8c (writes a 3-float
buffer), +0x10 slot 0x1c (5 stack args, including a 16-byte struct), +0xc slot 0x228 (5 stack args). The output buffers are filled
with values fixed at generation time, so the uninitialised stack contents never reach the comparison."""
import struct
from pilot import S
from recruits_util import rnd, pystub, obj, logger, clear_hooks


def _fb(r, lo=-100.0, hi=100.0):
    return struct.unpack('<I', struct.pack('<f', r.uniform(lo, hi)))[0]


def _write(emu, p, vals):
    for j, v in enumerate(vals):
        emu.w32(p + 4 * j, v)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c)
    # Mixed scales so that |z| > |x| and |x| >= |z| both occur after the matrix step.
    v40 = [_fb(r) for _ in range(5)]
    v64 = [_fb(r, -10.0, 10.0) for _ in range(9)]  # 3x3 matrix for vmtmul
    v1c = [_fb(r, -1.0, 1.0) for _ in range(3)]
    v10 = [_fb(r, -1.0, 1.0), _fb(r, -1.0, 1.0), _fb(r, -100.0, 100.0)]
    s80 = pystub(c, 2, stackmark=(0, 1), side=lambda emu, k: _write(emu, emu.arg32(0), v40))
    s384 = pystub(c, 2, stackmark=(0, 1),
                  side=lambda emu, k: (_write(emu, emu.arg32(0), v64), _write(emu, emu.arg32(1), v1c)))
    s8c = pystub(c, 1, stackmark=(0,), side=lambda emu, k: _write(emu, emu.arg32(0), v10))
    s1c = pystub(c, 8, stackmark=(2,))
    s228 = pystub(c, 5)
    o8 = obj(c, 0x40, {0x80: s80})
    oc = obj(c, 0x40, {0x384: s384, 0x8c: s8c, 0x228: s228})
    o10 = obj(c, 0x40, {0x1c: s1c})
    self_ = rnd(c, 0x20)
    e.w32(self_ + 0x8, o8)
    e.w32(self_ + 0xc, oc)
    e.w32(self_ + 0x10, o10)
    e.w32(self_ + 0x14, r.getrandbits(32))
    return [self_]


S(0x486700, 'ZActionPushButton::Execute', 'thiscall', None, ret='al', gen=_gen, note='batch2484')
