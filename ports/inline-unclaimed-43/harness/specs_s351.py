"""specs_s351.py - gap band batch 351: 0x410f10, cdecl with one pointer argument; returns [arg+4] + [arg]*8 (pure arithmetic on the two
dwords). The index dword is random, the base is random."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    h = E.zero_obj(c, 0x20)
    c.emu.w32(h, r.getrandbits(32))
    c.emu.w32(h + 4, r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [h]


S(0x410f10, 'element address (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 351')
