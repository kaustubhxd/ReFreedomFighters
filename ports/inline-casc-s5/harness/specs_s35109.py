"""specs_s35109.py - 0x5b9640 (thiscall(s) ret 4, ret='al'). s: slot 0x40 (1 arg: out pointer, flag-recorded; writes a fresh random dword through it); engine table slot 0x58 (1 arg recorded: the id) returns a different random value per call; this: random 0x70 bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g5b9640(c):
    clear_hooks(c)
    r = c.rng
    vals = [r.getrandbits(32) for _ in range(2)]
    s = obj(c, 0x20, {0x40: pystub(c, 1, nullflag=(0,), this=True, side=lambda em, k: em.w32(em.arg32(0), r.getrandbits(32)))}, nslots=0x11)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: vals[min(k, 1)])})
    return [rnd(c, 0x70), s]


S(0x5b9640, 'GUESS read entry with two resolved ids from stream', 'thiscall', None, ret='al', gen=_g5b9640, note='batch35109')
