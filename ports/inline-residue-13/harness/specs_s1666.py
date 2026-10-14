"""specs_s1666.py - residue 13 batch 1666: 0x468f20 (eight reads through the object's slot 0x10; the object records the
destination (heap) and size, so every field is compared)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    o = obj(c, 0x100, {0x10: stub(c, seq, 2)})
    me = rnd(c, 0x80)
    return [me, o]


S(0x468f20, 'GUESS FUN_468f20', 'thiscall', None, ret='al', gen=_gen, note='batch1666; eight slot-0x10 reads; ret 4')
