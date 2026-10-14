"""specs_s32095.py - h2 () batch 32095: eight tier H float / SSE functions. Float args F(); float returns ret='st0'; NaN-able heap floats use nan_heap=True."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = 0x7fc00000


def _f(bits):
    return struct.unpack('<f', struct.pack('<I', bits))[0]


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _fbits(c, lo=-5, hi=5):
    r = c.rng
    return r.choice([_fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), _fb(c.fv(lo, hi)), NAN, 0x7f800000, 0xff800000, 0, 0x80000000])


def _fval(c, lo=-5, hi=5):
    return _f(_fbits(c, lo, hi))


def g475250(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x467410, 6, this=True, pop=0x18, ret=r.getrandbits(32))
    return [rnd(c, 0x300), F(c.fv(-10, 10)), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g4dfe20(c):
    clear_hooks(c)
    e = c.emu
    P = rnd(c, 0x10)
    Q = rnd(c, 0x20)
    for i in range(2):
        e.wbytes(P + 4 * i, _fbits(c, -5, 5).to_bytes(4, 'little'))
    for i in range(4):
        e.wbytes(Q + 4 * i, _fbits(c, -5, 5).to_bytes(4, 'little'))
    return [P, Q]


def g52b130(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x52e670, 4, this=True, pop=0x10, ret=r.getrandbits(32))
    me = rnd(c, 0x80)
    c.emu.wbytes(me + 0x65, rnd(c, 0x20).to_bytes(4, 'little'))
    return [me, r.getrandbits(32), F(c.fv(-10, 10)), F(c.fv(-10, 10)), F(c.fv(-10, 10))]


def g46ee10(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k1 = _f(e.r32(0x678858))
    k2 = _f(e.r32(0x680a70))
    me = rnd(c, 0xc0)
    v = r.choice([k1 + c.fv(-1, 1), k1 + k2 * 0.5, k1 + k2, k1 + k2 + 1.0, k1 - 1.0, k1, c.fv(-10, 10), _f(NAN)])
    e.wbytes(me + 0xac, _fb(v).to_bytes(4, 'little'))
    return [me]


def g4c2bc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x90)
    inner = rnd(c, 0x30)
    e.w32(inner + 0x18, o)
    me = rnd(c, 0xe0)
    e.w32(me + 0x44, inner)
    e.wbytes(me + 0xd1, bytes([r.choice([0, 1, 1, 1, 7])]))
    b = r.choice([c.fv(-1000, 1000), 0.5, -0.5, 1e10, -1e10, _f(NAN), float('inf'), 3.99, -3.99])
    return [me, F(c.fv(-100, 100)), F(b)]


def g4fa7c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = _f(e.r32(0x678858))
    me = obj(c, 0xb0, {0x358: pystub(c, 0, ret=r.getrandbits(32), this=True)}, nslots=0x358 // 4 + 1)
    e.wbytes(me + 0xab, r.choice([0, 1, 100, 0xffffff00, 0x80000000, r.getrandbits(32), r.randrange(0, 1000)]).to_bytes(4, 'little'))
    a = r.choice([k, k + 1.0, k - 0.25, 0.0, -0.0, -1.0, c.fv(-5, 5), _f(NAN), float('inf')])
    return [me, F(a)]


def g5ab190(c):
    clear_hooks(c)
    r = c.rng
    return [rnd(c, 0x3d0)] + [r.getrandbits(32) for _ in range(18)]


def g5d13a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    k = _f(e.r32(0x679540))
    me = rnd(c, 0xb40)
    e.wbytes(me + 0xb1f, r.choice([_fb(k), _fb(k + 0.5), _fb(k - 0.5), NAN, _fb(c.fv(-5, 5)), 0x7f800000]).to_bytes(4, 'little'))
    a = r.choice([0, 0, 1, 5, 0x7fffffff, 0x80000000, 0xffffffff, r.getrandbits(32), r.randrange(0, 1000)])
    return [me, a]


S(0x475250, 'GUESS forward with this and float and 16-byte block', 'thiscall', None, ret='eax', gen=g475250, note='batch32095')
S(0x4dfe20, 'GUESS 2x2 matrix times vector (register ABI)', 'fastcall', None, ret=None, gen=g4dfe20, nan_heap=True, note='batch32095')
S(0x52b130, 'GUESS forward to member with three floats', 'thiscall', None, ret='eax', gen=g52b130, note='batch32095')
S(0x46ee10, 'GUESS clamped fraction', 'thiscall', None, ret='st0', gen=g46ee10, note='batch32095')
S(0x4c2bc0, 'GUESS set float and truncated int on nested object', 'thiscall', None, ret=None, gen=g4c2bc0, nan_heap=True, note='batch32095')
S(0x4fa7c0, 'GUESS clamped scale then slot 0x358', 'thiscall', None, ret='eax', gen=g4fa7c0, nan_heap=True, note='batch32095')
S(0x5ab190, 'GUESS store 76-byte block', 'thiscall', None, ret=None, gen=g5ab190, note='batch32095')
S(0x5d13a0, 'GUESS arm timer from int', 'thiscall', None, ret=None, gen=g5d13a0, nan_heap=True, note='batch32095')
