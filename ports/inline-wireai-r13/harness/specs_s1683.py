"""specs_s1683.py - residue 13 batch 1683: 0x4766a0 (accessor + constructor 0x469870 hooked; flag, zero stores; vtable 0x689d2c)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x469870, 0, ret=0, this=True, pop=True)
    p = rnd(c, 0x80) if r.random() < 0.8 else 0
    o = obj(c, 0x40, {0x44: stub(c, seq, 0, ret=p)})
    mgr = rnd(c, 0x20)
    c.emu.w32(mgr + 8, o)
    sysobj(c, db=mgr)
    return [rnd(c, 0x10)]


S(0x4766a0, 'GUESS FUN_4766a0', 'thiscall', None, ret='eax', gen=_gen, note='batch1683; accessor; ctor 0x469870 hooked')
