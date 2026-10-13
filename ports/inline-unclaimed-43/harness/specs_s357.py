"""specs_s357.py - gap band batch 357: 0x4109e0, cdecl with one pointer argument; zeroes the five dwords at +8 .. +0x18 and returns 0
(eax). The block has random bytes so the stores show in the heap compare."""
from pilot import S
import engine_stubs as E


def _gen(c):
    p = E.zero_obj(c, 0x40)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x4109e0, 'zero five dwords from +8 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 357')
