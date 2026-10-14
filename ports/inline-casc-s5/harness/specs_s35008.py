"""specs_s35008.py - 0x475010. Object slots 0x560 (a-dependent flag, zero in 1/4), 0x504 / 0x500 (return a in 40% of the cases each), 0x3f0 (0xc, 0xd or other), 0x45c (2 args, recorded);
engine table slot 0x4c (1 arg, returns a random value)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g475010(c):
    clear_hooks(c)
    r = c.rng
    a = r.getrandbits(32)

    def pick():
        return a if r.random() < 0.4 else r.getrandbits(32)
    slots = {0x560: pystub(c, 1, ret=0 if r.random() < 0.25 else r.getrandbits(32) | 1, this=True),
             0x504: pystub(c, 0, ret=pick(), this=True),
             0x500: pystub(c, 0, ret=pick(), this=True),
             0x3f0: pystub(c, 0, ret=r.choice([0xc, 0xd, 0xc, 0xd, 0, r.getrandbits(32)]), this=True),
             0x45c: pystub(c, 2, this=True)}
    me = obj(c, 0x40, slots, nslots=0x150)
    sysobj(c, table_slots={0x4c: pystub(c, 1, ret=r.getrandbits(32), this=True)})
    return [me, a]


S(0x475010, 'GUESS notify state when argument is primary/secondary', 'thiscall', None, ret=None, gen=_g475010, note='batch35008')
