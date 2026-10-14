"""specs_s35160.py - 0x50c200 (stdcall(a) ret 4, ret=None). 0x5003d0 hooked (thiscall, 1 arg; returns a block with a random dword, zero in a third of the later calls); engine table slot 0x58 (1 arg) returns an entry (null in 1/4) with slot 0x1e0 (1 arg; al true in 3/4, garbage upper bytes when false) and slot 0x300 (1 arg);
logger at 0x700390: slot 0x20 (2 args) returns an object whose slot 0x2c is recorded (2 args, ECX = the vtable, caller-popped); a: 0x20 random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g50c200(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    b0, b1 = rnd(c, 0x10), rnd(c, 0x10)
    if r.random() < 1 / 3:
        e.w32(b1, 0)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: b0 if k == 0 else b1)
    ok = r.random() < 0.75
    ent = 0 if r.random() < 0.25 else obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=(r.getrandbits(32) | 1) if ok else (r.getrandbits(24) << 8)),
                                                0x300: pystub(c, 1, this=True)}, nslots=0xc1)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ent)}, table_size=0x60)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [rnd(c, 0x20)]


S(0x50c200, 'GUESS apply record flag to engine entry with logging', 'stdcall', None, ret=None, gen=_g50c200, note='batch35160')
