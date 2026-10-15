"""specs_s67535.py - cascade s6 batch 67535 (0x42d730, thiscall(stream) ret 4, returns the last slot's eax). The stream object has recorder slots 0xc / 0x40 / 0x48 / 0x50 / 0x58 / 0x5c / 0x68
(1 arg each, callee pops); the object is a plain random block (only addresses are used)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g42d730(c):
    clear_hooks(c)
    r = c.rng
    slots = {o: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32)) for o in (0xc, 0x40, 0x48, 0x50, 0x58, 0x5c)}
    slots[0x68] = pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    st = obj(c, 0x20, slots)
    t = rnd(c, 0x1b80)
    return [t, st]


S(0x42d730, 'GUESS serialize_fields', 'thiscall', None, ret='eax', gen=_g42d730, note='batch67535')
