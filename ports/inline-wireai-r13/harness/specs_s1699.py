"""specs_s1699.py - residue 13 batch 1699: 0x47f6f0 (destructor shape). The chain 0x43de70 is hooked (no arguments, random eax);
the manager's slot 0x58 returns an object (or zero) whose slot 0x210 (one argument) is a recorder."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x43de70, 0, ret=r.getrandbits(32), this=True, pop=True)
    tgt = obj(c, 0x40, {0x210: stub(c, seq, 1)})
    mgr = obj(c, 0x100, {0x58: stub(c, seq, 1, ret=tgt if r.random() < 0.8 else 0)})
    sysobj(c, db=mgr)
    me = rnd(c, 0x40)
    c.emu.w32(me + 0x18, r.choice([0, r.getrandbits(32), 1]))
    return [me]


S(0x47f6f0, 'GUESS FUN_47f6f0', 'thiscall', None, ret='eax', gen=_gen, note='batch1699; dtor shape; 0x43de70 hooked')
