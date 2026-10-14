"""specs_s35024.py - 0x44a510. [this+0x1c] = list L (null in 1/6; slots 0x4c, 0x64 (out param flag-recorded; hands out 0..3 record pointers then 0)); records hold an id and two words at +4 / +6;
engine table slot 0x58 returns an object (null in 1/3) with slot 0x128 (3 args); b includes values with low byte zero."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, sysobj


def _g44a510(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    recs = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 3]))]
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: recs[k] if k < len(recs) else 0)}, nslots=0x20)
    ents = [0 if r.random() < 1 / 3 else obj(c, 0x10, {0x128: pystub(c, 3, this=True)}, nslots=0x4c) for _ in range(4)]
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: ents[min(k, 3)])})
    me = rnd(c, 0x40)
    e.w32(me + 0x1c, L)
    return [me, r.getrandbits(32), r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])]


S(0x44a510, 'GUESS apply listed entries to table objects', 'thiscall', None, ret=None, gen=_g44a510, note='batch35024')
