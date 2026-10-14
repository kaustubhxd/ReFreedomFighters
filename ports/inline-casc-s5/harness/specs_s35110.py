"""specs_s35110.py - 0x5b6a30 (thiscall, no args). [this+0x48] = list L (null in 1/6; slots 0x4c, 0x64 (1 arg, out pointer flag-recorded; hands out 0..3 entries then 0) and 0 (delete, 1 arg)); entries hold objects at +4 and +8 (null in a third each, slot 0 delete stubs)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g5b6a30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ents = []
    for _ in range(r.choice([0, 1, 2, 3])):
        p = rnd(c, 0x10)
        for off in (4, 8):
            e.w32(p + off, 0 if r.random() < 1 / 3 else obj(c, 0x10, {0: pystub(c, 1, this=True)}, nslots=2))
        ents.append(p)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True), 0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: ents[k] if k < len(ents) else 0),
                                                    0: pystub(c, 1, this=True)}, nslots=0x1a)
    me = rnd(c, 0x60)
    e.w32(me + 0x48, L)
    return [me]


S(0x5b6a30, 'GUESS destroy list and held object pairs', 'thiscall', None, ret=None, gen=_g5b6a30, note='batch35110')
