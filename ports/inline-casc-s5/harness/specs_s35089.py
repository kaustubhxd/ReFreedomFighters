"""specs_s35089.py - 0x5c5620 (thiscall, no args, ret='eax'). Engine table slots 0x138 (returns o with slot 0x88: 2 args, writes a random id (zero in 1/4) through the out pointer), 0x58 (1 arg, returns p or 0 in 1/4; p has slot 0x128, 1 arg), 0x114
(six args, the out pointer is index 4: writes a random dword; returns a dword with garbage upper bits)."""
from pilot import S
from recruits_util import obj, clear_hooks, pystub, sysobj


def _g5c5620(c):
    clear_hooks(c)
    r = c.rng
    p = 0 if r.random() < 1 / 4 else obj(c, 0x20, {0x128: pystub(c, 1, this=True)}, nslots=0x4b)
    o = obj(c, 0x20, {0x88: pystub(c, 2, nullflag=(1,), this=True, side=lambda em, k: em.w32(em.arg32(1), 0 if r.random() < 0.25 else r.getrandbits(32)))}, nslots=0x23)
    sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=o), 0x58: pystub(c, 1, this=True, ret=p),
                           0x114: pystub(c, 6, nullflag=(4,), this=True, ret=r.getrandbits(32), side=lambda em, k: em.w32(em.arg32(4), r.getrandbits(32)))}, table_size=0x140)
    return [obj(c, 0x60, {}, nslots=1)]


S(0x5c5620, 'GUESS resolve configured id and apply resource word', 'thiscall', None, ret='eax', gen=_g5c5620, note='batch35089')
