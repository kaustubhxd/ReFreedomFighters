"""specs_s33079.py - h3 () batch 33079: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fl(c):
    return F(c.fv(-10.0, 10.0, 0.25))


def _fbits(c):
    return struct.unpack('<I', struct.pack('<f', c.fv(-10.0, 10.0, 0.25)))[0]


def _ints(c):
    return c.rng.choice([0, 0, 1, 0xffffffff, 127, 0x7fffffff, 0x80000000, _w(c), c.rng.randrange(-1000, 1000) & 0xffffffff])


def _g5d13f0(c):
    clear_hooks(c)
    me = rnd(c, 0xb40)
    r = c.rng
    old = r.choice([0.0, 0.0001220703125, 0.00012207031, 0.0002, -1.0, float('nan'), 1.0, _fbits(c)])
    bits = old if isinstance(old, int) else struct.unpack('<I', struct.pack('<f', old))[0]
    c.emu.w32(me + 0xb23, bits)
    c.emu.wbytes(me + 0xa71, bytes([0xff]))
    return [me, _ints(c)]


def _g4f38e0(c):
    clear_hooks(c)
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x6f, _ints(c))
    e.w32(so + 0x73, _ints(c))
    p = rnd(c, 0x10)
    e.w32(p, _fbits(c))
    e.w32(p + 4, _fbits(c))
    s = pystub(c, 1, this=True, ret=lambda em, k: _w(c))
    return [obj(c, 0x320, {0x304: s}), p]


def _g467f20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    e.w32(o + 0x70, r.choice([_fbits(c), 0x3dcccccd, 0x3dccccce, 0x3dcccccc, 0x7fc00000, 0]))
    s60 = pystub(c, 1, this=True, ret=lambda em, k: r.choice([o, o, 0]))
    sysobj(c, table_slots={0x60: s60})
    me = rnd(c, 0x160)
    e.w32(me + 0x153, r.choice([0, _w(c) | 1]))
    return [me]


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _g52a270(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dcd70, 1, this=True, ret=lambda em, k: _w(c))
    me = rnd(c, 0x60)
    mode = r.choice(['rand', 'rand', 'assoc', 'eq'])
    if mode == 'assoc':
        big = r.choice([1e8, 3e7, 1e10])
        v31, v14, a = _f32(big), _f32(r.choice([1.0, 0.5, 3.0])), _f32(-big)
        vals = {0x31: _b(v31), 0x14: _b(v14)}
    else:
        vals = {0x31: _fbits(c), 0x14: _fbits(c)}
        a = _f32(r.uniform(-10, 10))
    e.w32(me + 0x31, vals[0x31])
    e.w32(me + 0x14, vals[0x14])
    f31 = struct.unpack('<f', struct.pack('<I', vals[0x31]))[0]
    f14 = struct.unpack('<f', struct.pack('<I', vals[0x14]))[0]
    try:
        x = _f32(_f32(f31 + f14) + a)
        hi_bits = _b(x)
    except OverflowError:
        hi_bits = _fbits(c)
    e.w32(me + 0x35, r.choice([hi_bits, hi_bits, _fbits(c)]) if mode == 'eq' else _fbits(c))
    e.w32(me + 0x39, _fbits(c))
    a_obj = rnd(c, 0x20)
    inner = rnd(c, 0x20)
    e.w32(a_obj + 8, inner)
    e.w32(me + 0x18, a_obj)
    return [me, F(a)]


def _g441890(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x90)
    c.emu.w32(me + 0x88, r.choice([0, 0x80000000, 0x7fc00000, _fbits(c), _fbits(c), 0x3f800000]))
    return [me, _fl(c)]


def _g4f6820(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x48, _fbits(c))
    s = pystub(c, 2, this=True, ret=lambda em, k: _w(c))
    o = obj(c, 0x3d0, {0x374: s})
    e.w32(o + 0xa3, _fbits(c))
    me = rnd(c, 0x60)
    e.w32(me + 0x44, o)
    e.w32(me + 0x4c, _fbits(c))
    e.wbytes(me + 0x50, bytes([r.choice([0, 0, 1]), r.choice([0, 1])]))
    return [me]


def _g462fd0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blk = rnd(c, 0x400)
    for i in range(0, 0x400, 4):
        if r.random() < 0.9:
            e.w32(blk + i, _fbits(c))
    s58 = pystub(c, 1, this=True)
    ch = obj(c, 0x80, {0x58: s58})
    s2cc = pystub(c, 0, this=True, ret=lambda em, k: blk)
    me = obj(c, 0x80, {0x2cc: s2cc})
    e.w32(me + 0x6c, ch)
    return [me, r.randrange(0, 8)]


S(0x5d13f0, 'GUESS int to float over 127 with state byte', 'thiscall', None, ret=None, gen=_g5d13f0, note='batch33079')
S(0x4f38e0, 'GUESS divide sysobj ints by pair then tail', 'thiscall', None, ret='eax', gen=_g4f38e0, note='batch33079')
S(0x5d1300, 'GUESS negated int over 127', 'thiscall', None, ret=None, gen=_g5d13f0, note='batch33079')
S(0x467f20, 'GUESS clear id when value below 0.1', 'thiscall', None, ret=None, gen=_g467f20, note='batch33079')
S(0x52a270, 'GUESS clamp sum then tail', 'thiscall', None, ret='eax', gen=_g52a270, note='batch33079')
S(0x441890, 'GUESS scale pair from field ratio', 'thiscall', None, ret=None, gen=_g441890, note='batch33079')
S(0x4f6820, 'GUESS compute float then vcall 374', 'thiscall', None, ret='eax', gen=_g4f6820, note='batch33079')
S(0x462fd0, 'GUESS triple product from record array', 'thiscall', None, ret='st0', gen=_g462fd0, note='batch33079')
