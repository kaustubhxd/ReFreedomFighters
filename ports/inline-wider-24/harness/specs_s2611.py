"""specs_s2611.py - wider batch 2611. 0x5cabb0: thiscall, no args, plain ret. [0x70039c] = engine object with slot 0x1a8 (recorder, 1 arg); the object at
this+0x5a8 (null in 25 pct) has slot 0 (recorder, 1 arg, records the flag); the base destructor body 0x4f6b20 is hooked (thiscall, no args)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4f6b20, 0, this=True)
    so = sysobj(c, slots={0x1a8: pystub(c, 1, this=True)})
    me = rnd(c, 0x600)
    if r.random() < 0.75:
        e.w32(me + 0x5a8, obj(c, 0x20, {0: pystub(c, 1, this=True)}))
    else:
        e.w32(me + 0x5a8, 0)
    return [me]


S(0x5cabb0, 'GUESS destructor body (SEH frame, plain)', 'thiscall', None, ret=None, gen=_gen, note='batch2611')
