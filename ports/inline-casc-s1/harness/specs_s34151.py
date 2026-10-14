"""specs_s34151.py - tier H. 0x4e5e80: hooked 0x4e5f90 (float in st0) and 0x4e6420, ret st0. 0x4850c0: engine [0x70039c] with an int at +0x40, float at this+0xc around the matching value. 0x5b7b90: returns this. 0x524980: two float cells (distinct NaNs sometimes). 0x5d1350: int arg (0 in a tenth), unaligned float at +0xb1f around the constant 0x679540."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec
from pe_emu import DEFAULT_EXE
import pefile

_pe = pefile.PE(DEFAULT_EXE)
_img = _pe.OPTIONAL_HEADER.ImageBase


def _const(addr):
    return struct.unpack('<f', _pe.get_data(addr - _img, 4))[0]


def _f32(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _fval(r):
    k = r.random()
    if k < 0.2:
        v = r.choice([x for x in EDGE_F if x == x])
    else:
        v = r.uniform(-1000, 1000)
    return _f32(v) if abs(v) < 3e38 or v != v else v


def _fbits(r, center=None):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.5:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 100.0, -100.0])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g4e5e80(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5f90, 0, this=True, pop=0, st0=lambda em, k: _fval(r))
    hook_rec(c, 0x4e6420, 0, this=True, pop=0)
    return [rnd(c, 0x20)]


def _g4850c0(c):
    clear_hooks(c)
    r = c.rng
    k = _const(0x678620)
    n = r.choice([0, 5, -5, 100, 0x7fff0000, r.randrange(-3000, 3000)])
    so = rnd(c, 0x50)
    c.emu.w32(so + 0x40, n & 0xffffffff)
    c.emu.w32(0x70039c, so)
    me = rnd(c, 0x20)
    base = (n / k) if k else 0.0
    mode = r.random()
    if mode < 0.4 and abs(base) < 1e9:
        v = base + r.choice([0.0, 0.0, 0.3, -0.3, 0.9999, 1.0, 1e-3])
        bits = struct.unpack('<I', struct.pack('<f', v))[0]
    else:
        bits = _fbits(r)
    c.emu.w32(me + 0xc, bits)
    return [me]


def _g5b7b90(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x40), r.getrandbits(32), _fbits(r)]


def _g524980(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x30)
    a, b = rnd(c, 0x10), rnd(c, 0x10)
    c.emu.w32(a, _fbits(r))
    c.emu.w32(b, _fbits(r) if r.random() < 0.8 else c.emu.r32(a))
    if r.random() < 0.12:
        c.emu.w32(a, 0x7f800000 | (r.getrandbits(23) | 1) | (r.getrandbits(1) << 31))
        c.emu.w32(b, 0x7f800000 | (r.getrandbits(23) | 1) | (r.getrandbits(1) << 31))
    return [me, a, b]


def _g5d1350(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xb40)
    c.emu.wbytes(me + 0xb1f, _fbits(r, _const(0x679540)).to_bytes(4, 'little'))
    i = 0 if r.random() < 0.1 else r.choice([1, -1, 100, 0x7fffffff, -0x80000000, r.getrandbits(32), r.randrange(-5000, 5000)])
    return [me, i & 0xffffffff]


S(0x4e5e80, 'GUESS float getter with side call', 'thiscall', None, ret='st0', gen=_g4e5e80, note='batch34151')
S(0x4850c0, 'GUESS resync with engine value', 'thiscall', None, ret=None, gen=_g4850c0, note='batch34151')
S(0x5b7b90, 'GUESS init record', 'thiscall', None, ret='eax', gen=_g5b7b90, note='batch34151')
S(0x524980, 'GUESS set pointers and abs difference', 'thiscall', None, ret=None, gen=_g524980, note='batch34151')
S(0x5d1350, 'GUESS store int over constant with flag', 'thiscall', None, ret=None, gen=_g5d1350, note='batch34151')
