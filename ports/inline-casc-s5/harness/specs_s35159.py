"""specs_s35159.py - 0x50c7e0 (stdcall(id) ret 4, ret='eax'). Engine table slot 0x58 (1 arg, recorded) returns an entry (null in 1/4) with a random dword at +4 and slot 0x1e0 (1 arg; al true in half, garbage upper bytes when false).
Logger at 0x700390: slot 0x20 (2 args, recorded) returns an object whose slot 0x2c is recorded (2 args when the entry is null, else 3; ECX = the vtable, caller-popped)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g50c7e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ok = r.random() < 0.5
    ent = 0 if r.random() < 0.25 else obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=(r.getrandbits(32) | 1) if ok else (r.getrandbits(24) << 8))}, nslots=0x7a)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ent)}, table_size=0x60)
    lg2 = obj(c, 0x20, {0x2c: pystub(c, 2 if not ent else 3, this=True, pop=0)}, nslots=0x20)
    lg = obj(c, 0x20, {0x20: pystub(c, 2, ret=lg2, this=True)}, nslots=0x20)
    e.w32(0x700390, lg)
    return [r.getrandbits(32)]


S(0x50c7e0, 'GUESS fetch engine entry by id and check kind with logging', 'stdcall', None, ret='eax', gen=_g50c7e0, note='batch35159')
