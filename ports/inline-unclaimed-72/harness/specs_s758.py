"""specs_s758.py - bottom-up helpers for ZActionPushButton::Execute. PSVECSubtract (fastcall: out in ecx, a in edx, b on the
stack) and vmtmul (fastcall: out in ecx, matrix in edx). Random floats in about [-200, 200]; the exe runs as the reference."""
import struct
from pilot import S
from specs_s701 import _rnd


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _vec(c, blk):
    c_ = [_f(c.rng.uniform(-200.0, 200.0)) for _ in range(3)]
    return c_


def _g_sub(c):
    e = c.emu
    out = _rnd(c, 0x40)
    a = _rnd(c, 0x40)
    b = _rnd(c, 0x40)
    e.wbytes(a, struct.pack('<3f', *_vec(c, a)))
    e.wbytes(b, struct.pack('<3f', *_vec(c, b)))
    return [out, a, b]


def _g_mt(c):
    e = c.emu
    out = _rnd(c, 0x40)
    e.wbytes(out, struct.pack('<3f', *_vec(c, out)))
    m = _rnd(c, 0x40)
    e.wbytes(m, struct.pack('<12f', *[_f(c.rng.uniform(-3.0, 3.0)) for _ in range(12)]))
    return [out, m]


S(0x43e920, 'psvec_sub', ('fastcall'), None, ret=None, gen=_g_sub, note='b758 bottom-up helper for 0x486700; fastcall')
S(0x441a60, 'vmtmul', ('fastcall'), None, ret=None, gen=_g_mt, note='b758 bottom-up helper for 0x486700; fastcall')
