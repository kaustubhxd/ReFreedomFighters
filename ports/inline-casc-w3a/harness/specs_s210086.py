"""specs_s210086.py - Sonnet-w3a: 0x4e6700. The stdcall import at IAT 0x6760b4 is a recorder stub (2 args, callee pops)."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def _r(c): return c.rng.getrandbits(32)


def g4e6700(c):
    clear_hooks(c)
    e = c.emu
    e.w32(0x6760b4, pystub(c, 2, ret=_r(c)))
    s = rnd(c, 0x20)
    e.w32(s + 8, c.rng.choice([0, 0, _r(c) | 1, 1]))
    return [s, _r(c)]


S(0x4e6700, 'call_import_with_handle', 'thiscall', None, ret='eax', gen=g4e6700, note='batch210086')
