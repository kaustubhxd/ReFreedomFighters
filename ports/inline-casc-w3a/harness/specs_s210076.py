"""specs_s210076.py - Sonnet-w3a: 0x4d3f10. Allocation (0x41e290) and copy (0x634d22) hooked; the sort import at IAT 0x676450 is a recorder stub (cdecl, 4 args)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g4d3f10(c):
    clear_hooks(c)
    e = c.emu
    buf = rnd(c, 0x40)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    hook_rec(c, 0x634d22, 3, ret=_r(c), pop=0)
    e.w32(0x676450, pystub(c, 4, ret=_r(c), pop=0))
    n = c.rng.choice([0, 1, 2, 5, 0x3fffffff, 0x40000000, 0x40000001, 0x80000000, 0xffffffff, _r(c)])
    return [rnd(c, 0x20), rnd(c, 0x20), n]


S(0x4d3f10, 'ctor_sorted_copy', 'thiscall', None, ret='eax', gen=g4d3f10, note='batch210076')
