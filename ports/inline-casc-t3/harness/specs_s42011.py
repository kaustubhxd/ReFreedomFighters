"""specs_s42011.py - Sonnet t3 batch 42011. 0x4dfe60: fastcall(out, in) returning the length on st0 (ret='st0'). Inputs: zeros, tiny, huge, NaN, inf, ordinary floats; CRT sqrt runs for real."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fv(r):
    return r.choice([0.0, 0.0, -0.0, r.uniform(-10, 10), r.uniform(-1e3, 1e3), r.uniform(-1e-3, 1e-3), 1e-30, -1e-30, 1e30, float('nan'), float('inf'), 1.0, -1.0])


def g4dfe60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    out = rnd(c, 0x10)
    inp = rnd(c, 0x10)
    e.wbytes(inp, struct.pack('<ff', _fv(r), _fv(r)))
    return [out, inp]


S(0x4dfe60, 'GUESS normalise a 2D vector, return its length', 'fastcall', None, ret='st0', gen=g4dfe60, note='batch42011')
