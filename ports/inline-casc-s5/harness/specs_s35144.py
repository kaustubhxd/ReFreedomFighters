"""specs_s35144.py - 0x553980 (stdcall(a) ret 4). Engine table slots 0x138 (returns o: slot 0x88, 2 args, out pointer flag-recorded, writes a random id), 0x58 (1 arg recorded; returns p or 0 in 1/4; p has slot 0x128, 1 arg), 0x114 (six args; the out pointer (index 4) is flag-recorded and
receives a random dword; returns a dword with garbage upper bytes); 0x5003d0 and 0x5002f0 hooked (thiscall, 1 arg); a: random 0x20 bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g553980(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5003d0, 1, this=True, ret=rnd(c, 0x10))
    hook_rec(c, 0x5002f0, 1, this=True)
    p = 0 if r.random() < 1 / 4 else obj(c, 0x20, {0x128: pystub(c, 1, this=True)}, nslots=0x4b)
    o = obj(c, 0x20, {0x88: pystub(c, 2, nullflag=(1,), this=True, side=lambda em, k: em.w32(em.arg32(1), r.getrandbits(32)))}, nslots=0x23)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x58: pystub(c, 1, this=True, ret=p),
                           0x114: pystub(c, 6, nullflag=(4,), this=True, ret=r.getrandbits(32), side=lambda em, k: em.w32(em.arg32(4), r.getrandbits(32)))}, table_size=0x120)
    return [rnd(c, 0x20)]


S(0x553980, 'GUESS apply configured resource word and record output', 'stdcall', None, ret=None, gen=_g553980, note='batch35144')
