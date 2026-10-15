"""specs_s1661.py - residue 13 batch 1661: 0x468220 (ZIKLNKOBJ::Load hooked with one argument, ret 4, returning a random
eax; the object's slots 0x18 (two arguments), 0x40 and 0x50 (one argument each) are recorders). The function returns
Load's eax when its low byte is zero, else eax with the low byte set to 1."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x466dc0, 1, ret=r.getrandbits(32), this=True, pop=True)
    o = obj(c, 0x100, {0x18: stub(c, seq, 2), 0x40: stub(c, seq, 1), 0x50: stub(c, seq, 1, ret=r.getrandbits(32))})
    me = rnd(c, 0x300)
    return [me, o]


S(0x468220, 'GUESS FUN_468220', 'thiscall', None, ret='eax', gen=_gen, note='batch1661; ZIKLNKOBJ::Load hooked; ret 4')
