"""specs_s1710.py - residue 13 batch 1710: 0x433350. The notify helper 0x431410 (two arguments, ret 8) is hooked by address with
recorders for both arguments; the flag is the low byte of the second argument, so zero and nonzero bytes are both drawn."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x431410, 2, ret=r.getrandbits(32), this=True, pop=True)
    me = rnd(c, 0x100)
    return [me, r.getrandbits(32), r.choice([0, 1, 0x100, 0xff, r.getrandbits(32)])]


S(0x433350, 'GUESS FUN_433350', 'thiscall', None, ret='eax', gen=_gen, note='batch1710; tail to notify helper 0x431410 (hooked)')
