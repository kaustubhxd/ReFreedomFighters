"""specs_s1663.py - residue 13 batch 1663: 0x4764b0 (constructor shape). ZGROUP::ZGROUP (0x43e990) is hooked by address
with three stack arguments (thiscall, callee pops 12). The function returns this."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x43e990, 3, ret=0, this=True, pop=True)
    me = rnd(c, 0x100)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x4764b0, 'GUESS FUN_4764b0', 'thiscall', None, ret='eax', gen=_gen, note='batch1663; ZGROUP ctor hooked; ret 0xc')
