"""specs_s35152.py - 0x44a790 (thiscall(a, b) ret 8, ret=None). this: 0x40 random bytes, [+0x18] = null in 1/6, else a collection whose iterator stubs (reftab_vt) yield 0..4 random ids; engine table slot 0x58 (1 arg, recorded) returns per call an object (null in a third) with slot 0x128 (3 args, recorded)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj, reftab_vt


def _g44a790(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x40)
    elems = [0 if r.random() < 0.15 else r.getrandbits(32) for _ in range(r.choice([0, 1, 2, 3, 4]))]
    coll = rnd(c, 0x20)
    e.w32(coll, reftab_vt(c, elems, end_value=r.choice([0, 0, r.getrandbits(32) | 1])))
    e.w32(me + 0x18, 0 if r.random() < 1 / 6 else coll)
    objs = [0 if r.random() < 1 / 3 else obj(c, 0x20, {0x128: pystub(c, 3, this=True)}, nslots=0x4c) for _ in range(5)]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs[min(k, 4)])}, table_size=0x60)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x44a790, 'GUESS forward call to every live collection entry', 'thiscall', None, ret=None, gen=_g44a790, note='batch35152')
