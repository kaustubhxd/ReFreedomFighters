"""specs_s33114.py - h3 () batch 33114: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _vb(x):
    return 0x7fc00000 if x != x else _b(x)


def _g5d0c90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c)
    e.w32(so + 0x48, _vb(r.choice([0.016, 0.0, 0.5, 1.0, 2.0, c.fv(-1, 3, 0.05)])))
    me = rnd(c, 0xb40)
    ax = [0.0, 0.29, 0.3, 0.31, -0.29, -0.3, -0.31, 0.5, 0.49, 0.51, -0.5, -0.49, 1.0, -1.0, 0.1, c.fv(-1, 1, 0.05), float('nan')]
    e.w32(me + 0xb2b, _vb(r.choice(ax)))
    e.w32(me + 0xb23, _vb(r.choice(ax)))
    e.w32(me + 0xadd, _vb(r.choice([1.0, 2.0, 0.5, -1.0, 10.0, 0.0, c.fv(-3, 3, 0.1)])))
    ang = [0.0, 3.0, 3.14, -3.14, -3.1415927, 3.1415927, 6.0, -6.0, 1.0, c.fv(-7, 7, 0.1)]
    e.w32(me + 0xa54, _vb(r.choice(ang)))
    e.w32(me + 0xa5c, _vb(r.choice([0.0, 1.0, -1.0, c.fv(-3, 3, 0.1)])))
    e.w32(me + 0xa9e, _vb(r.choice([-1.0, -0.5, 0.0, -10.0])))
    e.w32(me + 0xaa2, _vb(r.choice([1.0, 0.5, 0.0, 10.0, -2.0])))
    if r.random() < 0.25:
        e.w32(so + 0x48, _b(1.0))
        e.w32(me + 0xb2b, _b(1.0))
        e.w32(me + 0xadd, _b(r.choice([0.8995000720024109, -0.8995000720024109])))
    return [me]


S(0x5d0c90, 'GUESS integrate stick input into angle and pitch', 'thiscall', None, ret=None, gen=_g5d0c90, nan_heap=True, note='batch33114')
