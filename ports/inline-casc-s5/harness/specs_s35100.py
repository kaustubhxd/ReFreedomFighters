"""specs_s35100.py - 0x491a80 (thiscall(a) ret 4). Engine (sysobj, 0x2000 random bytes so +0x1aab is observable) with vtable slot 0xc (four stack args, ECX = engine); engine table slots 0x134 (returns o, with slots 0x88 (2 args: out pointer, flag-recorded; writes 2 in half the
cases, else 0 or random) and 0x5c (3 args)); this: random 0xc00 bytes with vtable slots 0xa8 (0 args), 0xa0 and 0x18c (1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g491a80(c):
    clear_hooks(c)
    r = c.rng
    v = r.choice([2, 2, 0, 1, r.getrandbits(32)])
    o = obj(c, 0x20, {0x88: pystub(c, 2, nullflag=(1,), this=True, side=lambda em, k: em.w32(em.arg32(1), v)), 0x5c: pystub(c, 3, this=True)}, nslots=0x1a)
    sysobj(c, slots={0xc: pystub(c, 4, this=True)}, table_slots={0x134: pystub(c, 0, this=True, ret=o)}, table_size=0x140)
    me = obj(c, 0xc00, {0xa8: pystub(c, 0, this=True), 0xa0: pystub(c, 1, this=True), 0x18c: pystub(c, 1, this=True)}, nslots=0x64)
    return [me, r.getrandbits(32)]


S(0x491a80, 'GUESS reset screen state and rebuild', 'thiscall', None, ret=None, gen=_g491a80, note='batch35100')
