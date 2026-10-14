"""specs_s35120.py - 0x4728a0 (thiscall(a) ret 4). this slots 0x504 / 0x500 (return a in 40% of the cases each), 0x3f0 (0xe, 0xf or other), 0x45c (2 args, recorded); engine table slot 0x4c (1 arg) returns a random value."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub, sysobj


def _g4728a0(c):
    clear_hooks(c)
    r = c.rng
    a = r.getrandbits(32)

    def pick():
        return a if r.random() < 0.4 else r.getrandbits(32)
    slots = {0x504: pystub(c, 0, ret=pick(), this=True), 0x500: pystub(c, 0, ret=pick(), this=True),
             0x3f0: pystub(c, 0, ret=r.choice([0xe, 0xf, 0xe, 0xf, 0, r.getrandbits(32)]), this=True), 0x45c: pystub(c, 2, this=True)}
    me = obj(c, 0x40, slots, nslots=0x120)
    sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))})
    return [me, a]


S(0x4728a0, 'GUESS notify state when argument is primary/secondary', 'thiscall', None, ret=None, gen=_g4728a0, note='batch35120')
