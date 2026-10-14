"""specs_s34014.py - cascade tier E, batch 34014: 0x476ae0. Engine table (+0x9b) slot 0x58 is a recorder returning a fresh object (null in a quarter of the
cases) whose slots 0x2c / 0x138 are recorders; a1 has slot 0x288 as a recorder. self +0x60 is the ring index (1 forces the reload from +0x5c), +0x68 the
pointer array, +0x70 a word."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g(c):
    clear_hooks(c)
    r = c.rng
    o = 0 if r.random() < 0.25 else obj(c, 0x40, {0x2c: pystub(c, 0, this=True), 0x138: pystub(c, 3, this=True)}, nslots=0x50)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=o, this=True)})
    me = rnd(c, 0x100)
    arr = rnd(c, 0x40)
    c.emu.w32(me + 0x68, arr)
    c.emu.w32(me + 0x60, r.choice([1, 1, 2, 3, 8, r.randint(1, 15)]))
    a1 = obj(c, 0x40, {0x288: pystub(c, 3, this=True)})
    return [me, a1, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x476ae0, 'GUESS ring fetch + configure + register', 'thiscall', None, ret='eax', gen=_g, note='batch34014')
