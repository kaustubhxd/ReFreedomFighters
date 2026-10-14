"""specs_s34154.py - tier H. 0x658c40: code 6 / 9 / other (high bits too), slots 0x1e8 (float arg, random eax) and 0x30. 0x477620: floats around +-1 incl. NaN, the real acos stub of the harness, ret st0. 0x4f21f0: byte arg and the stored byte equal in a third; hooked 0x4f2240. 0x59a650: hooked 0x59a5e0, table slot 0x60 returns an object or 0. 0x445ff0: slots 0xd8 / 0xdc return ints. 0x486430: chain of objects, hooked 0x4869e0."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r, center=None):
    k = r.random()
    if k < 0.15:
        v = r.choice(EDGE_F)
    elif k < 0.2:
        return r.getrandbits(32)
    elif center is not None and k < 0.55:
        v = center + r.choice([0.0, 1e-6, -1e-6, 0.01, -0.01, 1.0, -1.0, 1e-3, -1e-3])
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _engi(c, n):
    so = rnd(c, 0x1b0)
    c.emu.w32(so + 0x40, n & 0xffffffff)
    c.emu.w32(0x70039c, so)
    return so


def _g658c40(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x20, {0x1e8: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32)),
                       0x30: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, nslots=0x1ec // 4)
    code = r.choice([6, 6, 9, 9, 0, 1, 5, 7, 8, 10, 0x100000006, r.getrandbits(32)]) & 0xffffffff
    p = rnd(c, 0x10)
    c.emu.w32(p, _fbits(r))
    return [me, code, p]


def _g477620(c):
    clear_hooks(c)
    r = c.rng
    k = r.random()
    if k < 0.5:
        b = _fbits(r, r.choice([1.0, -1.0, 0.0]))
    else:
        b = struct.unpack('<I', struct.pack('<f', r.uniform(-1.2, 1.2)))[0]
    return [b]


def _g4f21f0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4f2240, 2, this=True, pop=8, ret=r.getrandbits(32))
    _engi(c, r.choice([0, 1, -1, 1000, r.getrandbits(32)]))
    me = rnd(c, 0x80)
    cur = r.choice([0, 1, 5])
    c.emu.wbytes(me + 0x6a, bytes([cur]))
    c.emu.w32(me + 0x64, r.getrandbits(32))
    b = r.choice([cur, cur, 0, 1, 0x100, 0x101, 0xff, r.getrandbits(32)])
    return [me, b & 0xffffffff]


def _g59a650(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x59a5e0, 1, this=True, ret=r.getrandbits(32))
    o = rnd(c, 0x90)
    tbl = obj(c, 0x20, {0x60: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, o, o]))}, nslots=0x64 // 4)
    so = rnd(c, 0xa0)
    c.emu.w32(so + 0x9b, tbl)
    c.emu.w32(0x70039c, so)
    return [rnd(c, 0x100), r.getrandbits(32), _fbits(r)]


def _g445ff0(c):
    clear_hooks(c)
    r = c.rng
    vals = [0, 1, -1, 12345, 0x7fffffff, -0x80000000, r.getrandbits(32), r.randrange(-5000, 5000), 0x1000001]
    s = obj(c, 0x20, {0xd8: pystub(c, 0, this=True, ret=lambda em, k: r.choice(vals) & 0xffffffff),
                      0xdc: pystub(c, 0, this=True, ret=lambda em, k: r.choice(vals) & 0xffffffff)}, nslots=0xe0 // 4)
    return [rnd(c, 0x60), s]


def _g486430(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4869e0, 1, this=True, ret=r.getrandbits(32))
    o = obj(c, 0x20, {0x350: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))}, nslots=0x354 // 4)
    p = obj(c, 0x20, {0x10: pystub(c, 0, this=True, ret=o)}, nslots=0x14 // 4)
    _engi(c, r.choice([0, 1, -1, 1000, -0x134, r.getrandbits(32)]))
    me = rnd(c, 0x40)
    c.emu.w32(me + 0xc, p)
    return [me]


S(0x658c40, 'GUESS event dispatch', 'thiscall', None, ret='eax', gen=_g658c40, note='batch34154')
S(0x477620, 'GUESS clamped acos', 'stdcall', None, ret='st0', gen=_g477620, note='batch34154')
S(0x4f21f0, 'GUESS set mode flag', 'thiscall', None, ret=None, gen=_g4f21f0, note='batch34154')
S(0x59a650, 'GUESS look up and scale', 'thiscall', None, ret='eax', gen=_g59a650, note='batch34154')
S(0x445ff0, 'GUESS copy two ints as floats', 'thiscall', None, ret=None, gen=_g445ff0, note='batch34154')
S(0x486430, 'GUESS stamp time and look up', 'thiscall', None, ret='al', gen=_g486430, note='batch34154')
