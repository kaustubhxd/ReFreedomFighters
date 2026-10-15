"""specs_s1670.py - residue 13 batch 1670: 0x46b200 and 0x46b270 (accessor + constructor, no arguments). The manager
(sys+0x9b) has an object at +8 whose slot 0x44 returns a pointer (random, sometimes zero); ZItemSpawn::ZItemSpawn (0x469c00)
and ZItemState::ZItemState (0x469cc0) are hooked by address with no arguments."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _mk(ctor):
    def gen(c):
        seq = Seq(c)
        r = c.rng
        clear_hooks(c)
        hook(c, seq, ctor, 0, ret=0, this=True, pop=True)
        p = rnd(c, 0x40) if r.random() < 0.8 else 0
        o = obj(c, 0x40, {0x44: stub(c, seq, 0, ret=p)})
        mgr = rnd(c, 0x20)
        c.emu.w32(mgr + 8, o)
        sysobj(c, db=mgr)
        return [rnd(c, 0x10)]
    return gen


S(0x46b200, 'GUESS FUN_46b200', 'thiscall', None, ret='eax', gen=_mk(0x469c00), note='batch1670; SEH frame not reproduced')
S(0x46b270, 'GUESS FUN_46b270', 'thiscall', None, ret='eax', gen=_mk(0x469cc0), note='batch1670; SEH frame not reproduced')
