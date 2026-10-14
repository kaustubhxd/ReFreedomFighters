"""specs_s35156.py - 0x555f20 (stdcall(a) ret 4, ret=None). 0x5003d0 hooked (thiscall, 1 arg; returns one of three random blocks per call); engine table slots 0x58 (1 arg; returns p with slot 0x128 taking 1 arg) and 0x114 (six args; the out pointer, index 4, is flag-recorded and receives zero in
a third of the calls, else a random dword; returns a dword with garbage upper bytes); 0x5002f0 hooked (thiscall, 1 arg); a: random 0x20 bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g555f20(c):
    clear_hooks(c)
    r = c.rng
    blks = [rnd(c, 0x10) for _ in range(3)]
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: blks[min(k, 2)])
    hook_rec(c, 0x5002f0, 1, this=True)
    p = obj(c, 0x20, {0x128: pystub(c, 1, this=True)}, nslots=0x4b)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=p),
                           0x114: pystub(c, 6, nullflag=(4,), this=True, ret=r.getrandbits(32),
                                         side=lambda em, k: em.w32(em.arg32(4), 0 if r.random() < 1 / 3 else r.getrandbits(32)))}, table_size=0x120)
    return [rnd(c, 0x20)]


S(0x555f20, 'GUESS apply configured resource word and store presence flag', 'stdcall', None, ret=None, gen=_g555f20, note='batch35156')
