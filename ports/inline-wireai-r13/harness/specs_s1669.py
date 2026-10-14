"""specs_s1669.py - residue 13 batch 1669: 0x462a20 (four stack arguments; only the fourth is read). The table lookup
0x463030 is hooked (thiscall, two arguments, ret 8, random eax); the manager's slot 0x114 (four arguments, random eax) and
this's slot 0x128 (three arguments, random eax) are recorders. The result is eax with its low byte cleared."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook, sysobj


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x463030, 2, ret=r.getrandbits(32), this=True, pop=True)
    mgr = obj(c, 0x100, {0x114: stub(c, seq, 4, ret=r.getrandbits(32))})
    sysobj(c, db=mgr)
    me = obj(c, 0x100, {0x128: stub(c, seq, 3, ret=r.getrandbits(32))})
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), rnd(c, 0x40)]


S(0x462a20, 'GUESS FUN_462a20', 'thiscall', None, ret='eax', gen=_gen, note='batch1669; ret 0x10; lookup hooked')
