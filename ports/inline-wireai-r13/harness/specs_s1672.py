"""specs_s1672.py - residue 13 batch 1672: 0x46b3c0 (accessor; constructor 0x469870 hooked with no arguments; flag and
word stores; vtable 0x6867cc)."""
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


S(0x46b3c0, 'GUESS FUN_46b3c0', 'thiscall', None, ret='eax', gen=_gen, note='batch1672; SEH frame not reproduced; ctor 0x469870 hooked')
