"""specs_s1711.py - residue 13 batch 1711: 0x628ed0. The tail target 0x622ad0 (cdecl, four arguments, plain ret) is hooked by
address with recorders for all four arguments; the first must arrive as 0x6be728."""
from pilot import S
from sthelp import Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x622ad0, 4, ret=r.getrandbits(32), this=False, pop=False)
    return [r.getrandbits(32) for _ in range(4)]


S(0x628ed0, 'GUESS FUN_628ed0', 'cdecl', None, ret='eax', gen=_gen, note='batch1711; tail to 0x622ad0 (cdecl, hooked)')
