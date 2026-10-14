"""specs_u69_21.py - area 69, group 21 (slice 8): address constants and global reads."""
from pilot import S


def _none(c):
    return []


S(0x5335c0, 'addrGetter5335c0', 'cdecl', None, ret='eax', gen=_none, note='u69 group 21')
S(0x601b00, 'addrGetter601b00', 'cdecl', None, ret='eax', gen=_none, note='u69 group 21')
def _glob(c):
    # both neighbouring words get fresh random values, so a read of the wrong word is visible
    c.emu.w32(0x7003ac, c.rng.getrandbits(32))
    c.emu.w32(0x7003a8, c.rng.getrandbits(32))
    return []


S(0x490780, 'globalGetter490780', 'cdecl', None, ret='eax', gen=_glob, note='u69 group 21; reads .data 0x7003ac (0x7003a8 randomised as the decoy)')
S(0x5b2500, 'globalGetter5b2500', 'cdecl', None, ret='eax', gen=_none, note='u69 group 21; reads .data 0x6ed350')
