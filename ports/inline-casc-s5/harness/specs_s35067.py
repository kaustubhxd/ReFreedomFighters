"""specs_s35067.py - 0x5d9e20 (thiscall, no args). Engine table slot 0x58 (1 arg recorded) returns, by call index, o1, o2, o3, o4: o1 / o3 objects with slots 0x27c (1 arg), 0x250 (0 args; writes a marker into +0x30), fields +0x30 and +0x48;
o2 / o4 random blocks (+0x30); o2 is o1 in a fifth of the cases (and o4 is o3), so the |= 0x400 / = 0 order is observable. this = random 0xa0 bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g5d9e20(c):
    clear_hooks(c)
    r = c.rng

    def mkobj():
        return obj(c, 0x60, {0x27c: pystub(c, 1, this=True), 0x250: pystub(c, 0, this=True, side=lambda em, k: em.w32(em.reg('ecx') + 0x30, 0x5000 + k))}, nslots=0xa0)
    o1, o3 = mkobj(), mkobj()
    o2 = o1 if r.random() < 0.2 else rnd(c, 0x40)
    o4 = o3 if r.random() < 0.2 else rnd(c, 0x40)
    seq = [o1, o2, o3, o4]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: seq[min(k, 3)])})
    return [rnd(c, 0xa0)]


S(0x5d9e20, 'GUESS reset two target objects and clear counters', 'thiscall', None, ret=None, gen=_g5d9e20, note='batch35067')
