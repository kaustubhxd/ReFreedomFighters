"""specs_s1662.py - residue 13 batch 1662: 0x468270 (ZIKLNKOBJ::Save hooked with one argument, ret 4, random eax; the
object's slots 0x10 (two arguments), 0x3c (one) and 0x4c (one, random eax) are recorders). Returns Save's eax on a zero low
byte, else the last call's eax with its low byte set to 1."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x467770, 1, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]), this=True, pop=True)
    o = obj(c, 0x100, {0x10: stub(c, seq, 2), 0x3c: stub(c, seq, 1), 0x4c: stub(c, seq, 1, ret=r.getrandbits(32))})
    me = rnd(c, 0x300)
    return [me, o]


S(0x468270, 'GUESS FUN_468270', 'thiscall', None, ret='eax', gen=_gen, note='batch1662; ZIKLNKOBJ::Save hooked; ret 4')
