"""specs_s34148.py - tier H. 0x5d1190: int argument (small, large and negative), exe constant 0x67af20. 0x514430 / 0x5213d0: callees 0x523cc0 / 0x5289d0 hooked (this recorded, two arguments, one of them a float bit pattern, random eax). 0x466800: out block prefilled with random dwords, float at the unaligned +0x1ca, this slot 0x84 (1 arg) returns random."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec


def _fbits(r):
    k = r.random()
    if k < 0.2:
        v = r.choice(EDGE_F)
    elif k < 0.25:
        return r.getrandbits(32)
    else:
        v = r.uniform(-1000, 1000)
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _g5d1190(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xb40)
    i = r.choice([0, 1, -1, 100, -100, 0x7fffffff, -0x80000000, r.getrandbits(32), r.randrange(-5000, 5000)])
    return [me, i & 0xffffffff]


def _g514430(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x523cc0, 2, this=True, ret=r.getrandbits(32))
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x5c, rnd(c, 0x20))
    return [me, r.getrandbits(32), _fbits(r)]


def _g5213d0(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5289d0, 2, this=True, ret=r.getrandbits(32))
    return [rnd(c, 0x400), _fbits(r), r.getrandbits(32)]


def _g466800(c):
    clear_hooks(c)
    r = c.rng
    me = obj(c, 0x1d0, {0x84: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32), deref={0: 3})}, nslots=0x88 // 4)
    c.emu.wbytes(me + 0x1ca, _fbits(r).to_bytes(4, 'little'))
    return [me, rnd(c, 0x10)]


S(0x5d1190, 'GUESS store int over constant', 'thiscall', None, ret=None, gen=_g5d1190, note='batch34148')
S(0x514430, 'GUESS forward float to child', 'thiscall', None, ret='eax', gen=_g514430, note='batch34148')
S(0x5213d0, 'GUESS forward float to embedded', 'thiscall', None, ret='eax', gen=_g5213d0, note='batch34148')
S(0x466800, 'GUESS make vector and tail call', 'thiscall', None, ret='eax', gen=_g466800, note='batch34148')
