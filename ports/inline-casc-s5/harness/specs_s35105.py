"""specs_s35105.py - 0x46d530 (thiscall(A, B) ret 8, ret='eax'). this: vtable slot 0x2c8 (0 args, returns an id), [+4] name pointer (null in a third); engine table slots 0x154 (2 args recorded, returns a record with an unaligned dword at +0x23) and 0x4c (1 arg recorded);
A: factory with slot 0x298 (five args, ECX recorded) returning o (null in 1/4); o: slots 0x2e4 (1 arg), 0x154, 0x158 (0 args), [o+8] random; 0x4dc630 hooked (thiscall, 2 args)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g46d530(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc630, 2, this=True)
    o = 0 if r.random() < 1 / 4 else obj(c, 0x20, {0x2e4: pystub(c, 1, this=True), 0x154: pystub(c, 0, this=True), 0x158: pystub(c, 0, this=True)}, nslots=0x57)
    if o:
        e.w32(o + 8, rnd(c, 0x10))
    A = obj(c, 0x20, {0x298: pystub(c, 5, this=True, ret=o)}, nslots=0xa7)
    rec = rnd(c, 0x40)
    sysobj(c, table_slots={0x154: pystub(c, 2, this=True, ret=rec), 0x4c: pystub(c, 1, this=True, ret=r.getrandbits(32))}, table_size=0x160)
    me = obj(c, 0x20, {0x2c8: pystub(c, 0, this=True, ret=r.getrandbits(32))}, nslots=0xb3)
    if r.random() < 1 / 3:
        e.w32(me + 4, 0)
    return [me, A, r.getrandbits(32)]


S(0x46d530, 'GUESS create child through factory and initialise', 'thiscall', None, ret='eax', gen=_g46d530, note='batch35105')
