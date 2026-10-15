"""specs_s66082.py - cascade s4 batch 66082: 0x4c29a0 (write a small record to a stream writer)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub


def _g4c29a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    w = obj(c, 0x40, {0x40: pystub(c, 1, this=True), 0x60: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True)})
    t = e.alloc(0x100, 8)
    e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x100)))
    return [t, w]


S(0x4c29a0, 'GUESS write a small record to a stream writer', 'thiscall', None, ret='al', gen=_g4c29a0, note='batch66082')
