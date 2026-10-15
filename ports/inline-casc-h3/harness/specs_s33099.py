"""specs_s33099.py - h3 (Sonnet) batch 33099: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g4b5d00(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    s114 = pystub(c, 4, this=True, ret=lambda em, k: _w(c))
    sysobj(c, table_slots={0x114: s114})
    return [rnd(c, 0x60), rnd(c, 0x10)]


S(0x4b5d00, 'GUESS read config: three id lookups then two floats and a flag', 'thiscall', None, ret=None, gen=_g4b5d00, note='batch33099')
