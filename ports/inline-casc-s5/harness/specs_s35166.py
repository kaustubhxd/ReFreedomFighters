"""specs_s35166.py - 0x4a1190 (thiscall, no args, ret=None). Engine table slots 0x138 (0 args; returns o with slot 0x60, 2 args recorded), 0x4c (2 args recorded; returns a random dword), 0x114 (4 args recorded; returns a dword with random upper half so the word store matters). this: 0x8c0 random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g4a1190(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x20, {0x60: pystub(c, 2, this=True)}, nslots=0x20)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x4c: pystub(c, 2, this=True, ret=r.getrandbits(32)),
                           0x114: pystub(c, 4, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x120)
    return [rnd(c, 0x8c0)]


S(0x4a1190, 'GUESS reset widget: register name, read two words, clear links', 'thiscall', None, ret=None, gen=_g4a1190, note='batch35166')
