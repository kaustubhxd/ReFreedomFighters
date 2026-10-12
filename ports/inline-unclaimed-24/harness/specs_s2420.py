"""specs_s2420.py - decomp area 24, batch 2420: STATICREFTAB::AddUnique(unsigned int) (0x4ce030), thiscall, ret 4.
The function calls the pointer at global 0x7003b0 with no pushed argument and returns 0. Its own argument is unused
(the callee's first stack word is this function's return address, not passed on). A null pointer is an int3 in the
original, so the spec always sets a recorder (cdecl, no arguments, ret 0)."""
from pilot import S
from recruits_util import rnd, pystub, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    o = rnd(c, 0x100)
    c.emu.w32(0x7003b0, pystub(c, 0, ret=0, pop=0))
    return [o, r.getrandbits(32)]


S(0x4ce030, 'STATICREFTAB::AddUnique', 'thiscall', None, ret='eax', gen=_gen, note='batch2420')
