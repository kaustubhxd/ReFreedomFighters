"""specs_s1707.py - residue 13 batch 1707: 0x4632d0 (the object's slot 0x58 returns a source block; the destination is a block;
the copy runs as exe code) and 0x4c5750 (the argument's slot 0x60 records its argument and returns random eax)."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _gen_632(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    src = rnd(c, 0x40)
    o = obj(c, 0x40, {0x58: stub(c, seq, 1, ret=src)})
    me = rnd(c, 0x100)
    c.emu.w32(me + 0x6c, o)
    return [me, rnd(c, 0x40)]


def _gen_c57(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    o = obj(c, 0x40, {0x60: stub(c, seq, 1, ret=r.getrandbits(32))})
    me = rnd(c, 0x100)
    c.emu.w8(me + 0x52, r.getrandbits(8))
    return [me, o]


S(0x4632d0, 'GUESS FUN_4632d0', 'thiscall', None, ret=None, gen=_gen_632, note='batch1707; copies 0x24 bytes via exe mcpy')
S(0x4c5750, 'GUESS FUN_4c5750', 'thiscall', None, ret='eax', gen=_gen_c57, note='batch1707; slot 0x60; returns with low byte 1')
