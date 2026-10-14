"""specs_s1713.py - residue 13 batch 1713: 0x651010 (two-field setter) and 0x64fad0 (null-checked virtual tail through the child
at this+0xbd, slot 0x60). The slot is a stub address replaced by a hook recorder, so the child ecx, the call count and the sequence
number are compared; eax is not (the null path leaves it unset)."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook, stub, obj


def _set(c):
    r = c.rng
    clear_hooks(c)
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32)]


def _tail(c):
    r = c.rng
    clear_hooks(c)
    seq = Seq(c)
    me = rnd(c, 0x100)
    if r.random() < 0.3:
        c.emu.w32(me + 0xbd, 0)
    else:
        fn = stub(c, seq, 0)
        hook(c, seq, fn, 0, ret=r.getrandbits(32), this=True, pop=True)
        c.emu.w32(me + 0xbd, obj(c, 0x40, {0x60: fn}))
    return [me]


S(0x651010, 'GUESS FUN_651010', 'thiscall', None, ret=None, gen=_set, note='batch1713; stores +0x84, +0x88')
S(0x64fad0, 'GUESS FUN_64fad0', 'thiscall', None, ret=None, gen=_tail, note='batch1713; child +0xbd, virtual tail slot 0x60 (hooked stub)')
