"""specs_s34147.py - tier H float functions. Float values are passed / stored as raw bit patterns drawn from ordinary values, edge values (0, -0, inf, NaN, denormals) and the exe constants' neighbourhoods.
0x467700: float at the unaligned +0x35, compared with the constant at 0x6785d0; 0x524370: floats at +0xc and +0, constant 0x67a284 added; 0x5243f0: float argument; 0x658c20: float argument, engine object [0x70039c]+0x1aa3 -> block."""
import math
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, clear_hooks
from pe_emu import DEFAULT_EXE
import pefile

_pe = pefile.PE(DEFAULT_EXE)
_img = _pe.OPTIONAL_HEADER.ImageBase


def _const(addr):
    return struct.unpack('<f', _pe.get_data(addr - _img, 4))[0]


def _fbits(r, center=None):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.55:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 100.0, -100.0])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g467700(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)
    c.emu.wbytes(me + 0x35, _fbits(r, _const(0x6785d0)).to_bytes(4, 'little'))
    return [me]


def _g524370(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x20)
    k = _const(0x67a284)
    lo = _fbits(r)
    c.emu.w32(me, lo)
    base = struct.unpack('<f', struct.pack('<I', lo))[0]
    c.emu.w32(me + 0xc, _fbits(r, (base - k) if math.isfinite(base) else None))
    return [me]


def _g5243f0(c):
    clear_hooks(c)
    me = rnd(c, 0x20)
    return [me, _fbits(c.rng)]


def _g658c20(c):
    clear_hooks(c)
    r = c.rng
    blk = rnd(c, 0xa0)
    so = rnd(c, 0x1ab0)
    c.emu.wbytes(so + 0x1aa3, blk.to_bytes(4, 'little'))
    c.emu.w32(0x70039c, so)
    return [_fbits(r)]


S(0x467700, 'GUESS float below limit', 'thiscall', None, ret='al', gen=_g467700, note='batch34147')
S(0x524370, 'GUESS float range test', 'thiscall', None, ret='al', gen=_g524370, note='batch34147')
S(0x5243f0, 'GUESS set 2D vector', 'thiscall', None, ret=None, gen=_g5243f0, note='batch34147')
S(0x658c20, 'GUESS store engine float', 'stdcall', None, ret=None, gen=_g658c20, note='batch34147')
