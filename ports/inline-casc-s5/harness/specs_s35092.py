"""specs_s35092.py - 0x50e760 (stdcall(s) ret 4). s: random 0x20 bytes with [+4], [+8] (random heap words), [+0xc] = X (object with slot 0 (2 args, returns o)); o: slots 0x30 (1 arg), 0x24 (returns a value), 0x28 (0 args); 0x5003d0 hooked (thiscall, 1 arg)
returning, by call index, a record (value dword and kind byte at +4) for the id and the slot record; the second record's kind among 0, 4 (value = object with slot 0x28), other; engine table slot 0x58 (1 arg) returns an object whose +4 is a name pointer, null name, or no object."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _g50e760(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = obj(c, 0x20, {0x30: pystub(c, 1, this=True), 0x24: pystub(c, 0, this=True, ret=r.getrandbits(32)), 0x28: pystub(c, 0, this=True)}, nslots=0x1a)
    X = obj(c, 0x20, {0: pystub(c, 2, this=True, ret=o)}, nslots=2)
    rec1 = rnd(c, 8)
    rec2 = rnd(c, 8)
    k = r.choice([0, 4, 4, 0, 1, 2, 5])
    e.wbytes(rec2 + 4, bytes([k]))
    if k == 4:
        e.w32(rec2, obj(c, 0x10, {0x28: pystub(c, 0, this=True)}, nslots=0x1a))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, kk: (rec1, rec2)[min(kk, 1)])
    ent = 0 if r.random() < 0.25 else rnd(c, 0x10)
    if ent and r.random() < 0.3:
        e.w32(ent + 4, 0)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=ent)})
    me = rnd(c, 0x20)
    e.w32(me + 0xc, X)
    return [me]


S(0x50e760, 'GUESS create object, name it and store in tagged slot', 'stdcall', None, ret=None, gen=_g50e760, note='batch35092')
