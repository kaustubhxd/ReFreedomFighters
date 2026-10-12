"""specs_s2447.py - decomp area 24, batch 2447 (gap band).
0x45c140 ZBloodSplatters::RunMark(int), thiscall, ret 4: slot 0xb8 of the sys table ([0x70039c]+0x9b) is called with no new
argument; the caller's argument stays on the stack. The slot is a zero-argument recorder: its first stack word is the caller's
return address, which differs between builds, so it is not recorded."""
from pilot import S
from recruits_util import rnd, pystub, sysobj, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0xb8: pystub(c, 0, pop=0)})
    return [rnd(c, 0x40), r.getrandbits(32)]


S(0x45c140, 'ZBloodSplatters::RunMark', 'thiscall', None, ret=None, gen=_gen, note='batch2447')
