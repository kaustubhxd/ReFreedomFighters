"""specs_s1671.py - residue 13 batch 1671: 0x46b2e0 and 0x46b350 (accessor, ZItemState constructor (hooked), vtable store).
The manager's object at +8 has slot 0x44 returning a random pointer (sometimes zero); the constructor is hooked."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x469cc0, 0, ret=0, this=True, pop=True)
    p = rnd(c, 0x40) if r.random() < 0.8 else 0
    o = obj(c, 0x40, {0x44: stub(c, seq, 0, ret=p)})
    mgr = rnd(c, 0x20)
    c.emu.w32(mgr + 8, o)
    sysobj(c, db=mgr)
    return [rnd(c, 0x10)]


S(0x46b2e0, 'GUESS FUN_46b2e0', 'thiscall', None, ret='eax', gen=_gen, note='batch1671; SEH frame not reproduced; ctor hooked')
S(0x46b350, 'GUESS FUN_46b350', 'thiscall', None, ret='eax', gen=_gen, note='batch1671; SEH frame not reproduced; ctor hooked')
