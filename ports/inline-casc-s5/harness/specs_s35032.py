"""specs_s35032.py - 0x5d7b10 (no arguments). Engine at 0x70039c: slot 0xbc returns s (slots 0x7c: signed value from -5..0x80, 0x80: 1 arg recorded); engine table slot 0x134 returns an object o with slot 0x88
(2 args: first arg recorded, writes a value through the out pointer: zero in 1/3 for the first call, values around 100 and large ones for the second)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub, sysobj


def _g5d7b10(c):
    clear_hooks(c)
    r = c.rng
    vals = [0, 1, 50, 99, 100, 101, 200, 0x7fffffff, 0x80000000, 0xffffffff]
    first = 0 if r.random() < 1 / 3 else r.choice(vals[1:])
    rv = r.choice([0xfffffffb, 0, 5, 99, 100, 101, 0x80, 0x80000000, r.getrandbits(32)])
    sec = r.choice(vals)

    def w88(em, k):
        em.w32(em.arg32(1), first if k == 0 else sec)
    o = obj(c, 0x10, {0x88: pystub(c, 2, this=True, nullflag=(1,), side=w88)}, nslots=0x24)
    s = obj(c, 0x10, {0x7c: pystub(c, 0, this=True, ret=rv), 0x80: pystub(c, 1, this=True)}, nslots=0x22)
    sysobj(c, slots={0xbc: pystub(c, 0, ret=s, this=True)}, table_slots={0x134: pystub(c, 0, ret=o, this=True)}, table_size=0x140)
    return []


S(0x5d7b10, 'GUESS read setting and clamp level', 'cdecl', None, ret=None, gen=_g5d7b10, note='batch35032')
