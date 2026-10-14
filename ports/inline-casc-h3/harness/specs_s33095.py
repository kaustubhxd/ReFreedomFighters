"""specs_s33095.py - h3 () batch 33095: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g607da0(c):
    clear_hooks(c)
    r = c.rng
    s5c = pystub(c, 6, this=True, ret=lambda em, k: _w(c))
    a = obj(c, 0x20, {0x5c: s5c})
    b = rnd(c, 8)
    cc = rnd(c, 8)
    c.emu.w32(cc, r.choice([0, 1, 5, 0x1000, 0x7fffffff, _w(c)]))
    return [rnd(c, 0x40), a, b, cc, r.choice([0, 0x208, 0x8, 0x200, _w(c)])]


S(0x607da0, 'GUESS ctor of a 36-byte-record buffer descriptor + slot 0x5c', 'thiscall', None, ret='eax', gen=_g607da0, note='batch33095')
