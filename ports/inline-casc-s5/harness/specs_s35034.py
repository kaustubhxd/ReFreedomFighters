"""specs_s35034.py - 0x5a4dc0 (thiscall, no args). Object of 0x130 random bytes (so every cleared field is observable); engine table slot 0x58 (1 arg, recorded) returns a different random value per call."""
from pilot import S
from recruits_util import rnd, clear_hooks, pystub, sysobj


def _g5a4dc0(c):
    clear_hooks(c)
    r = c.rng
    vals = [r.getrandbits(32) for _ in range(2)]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: vals[min(k, 1)])})
    return [rnd(c, 0x130)]


S(0x5a4dc0, 'GUESS reset record and re-resolve handles', 'thiscall', None, ret=None, gen=_g5a4dc0, note='batch35034')
