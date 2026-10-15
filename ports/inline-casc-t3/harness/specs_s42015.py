"""specs_s42015.py - Sonnet t3 batch 42015. 0x521600: x87 normalise (no callees). Source vec3 with zeros, tiny, huge, NaN and ordinary components; destination block 0x300 bytes of random data."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([0.0, 0.0, -0.0, r.uniform(-10, 10), r.uniform(-1e3, 1e3), r.uniform(-1e-3, 1e-3), 1e-30, 1e30, 1.0, float('nan'), float('inf')])


def g521600(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x300)
    src = rnd(c, 0x10)
    e.wbytes(src, struct.pack('<fff', _fv(r), _fv(r), _fv(r)))
    return [me, src]


S(0x521600, 'GUESS store a direction vector and normalise it in place', 'thiscall', None, ret=None, gen=g521600, note='batch42015')
