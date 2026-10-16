"""specs_s210085.py - Sonnet-w3a: 0x4d0b10. The free import at IAT 0x6762ec is a recorder stub (cdecl, 1 arg); the global at 0x6762f0 points at data whose dword +0x18 is 0xd or something else (both branches behave the same)."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def _r(c): return c.rng.getrandbits(32)


def g4d0b10(c):
    clear_hooks(c)
    e = c.emu
    e.w32(0x6762ec, pystub(c, 1, ret=_r(c), pop=0))
    blk = rnd(c, 0x40)
    e.w32(blk + 0x18, c.rng.choice([0xd, 0xd, 0, _r(c)]))
    e.w32(0x6762f0, blk)
    s = rnd(c, 0x20)
    return [s + 8]


S(0x4d0b10, 'free_prefix_pointer', 'thiscall', None, ret='eax', gen=g4d0b10, note='batch210085')
