"""specs_s2602.py - wider batch 2602. 0x434d10: thiscall(arg), ret 4, returns an element object or 0. this+4 = iterator source (reftab fake: slot
0x4c begin, 0x64 next returning the address of a cell holding the element object); each element object has slot 0x14 (1 arg, thiscall, deterministic
true/false per object, recorder)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub, reftab_vt


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cells = []
    for _ in range(r.choice([0, 1, 2, 3, 5])):
        cell = e.alloc(8, 4)
        o = obj(c, 0x20, {0x14: pystub(c, 1, this=True, ret=r.choice([0, 0, 1, 0x100, 5]))})
        e.w32(cell, o)
        cells.append(cell)
    me = rnd(c, 0x40)
    if r.random() < 0.9:
        mem = rnd(c, 0x40)
        e.w32(mem, reftab_vt(c, cells))
        e.w32(me + 4, mem)
    else:
        e.w32(me + 4, 0)
    return [me, r.choice([0, r.getrandbits(32) | 1, r.getrandbits(32) | 1])]


S(0x434d10, 'GUESS list find (iterator cells)', 'thiscall', None, ret='eax', gen=_gen, note='batch2602')
