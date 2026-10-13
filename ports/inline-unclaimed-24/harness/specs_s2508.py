"""specs_s2508.py - decomp area 24, batch 2508.
0x46d6c0 (ZItemTemplateWeapon::DestroyItem, GUESS signature): stdcall(obj), ret 4. Null obj returns. Otherwise tail jump to
vtable slot 0x210 with this = obj and the argument 1 (slot is a recorder, thiscall, 1 arg, pops 4)."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    if r.random() < 0.2:
        return [0]
    o = rnd(c, 0x40)
    vt = e.alloc(0x240, 4)
    for off in range(0, 0x240, 4):
        e.w32(vt + off, r.getrandbits(32))
    e.w32(vt + 0x210, pystub(c, 1, this=True, ret=r.getrandbits(32), pop=4))
    e.w32(o, vt)
    return [o]


S(0x46d6c0, 'ZItemTemplateWeapon::DestroyItem (GUESS)', 'stdcall', None, ret=None, gen=_gen, note='batch2508')
