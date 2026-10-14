"""specs_s1659.py - residue 13 batch 1659: 0x47f6c0 (constructor shape). ZSTDOBJ::ZSTDOBJ (0x43de40) is hooked by address
with three stack arguments (thiscall, callee pops 12). The function returns this."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x43de40, 3, ret=0, this=True, pop=True)
    me = rnd(c, 0x100)
    return [me, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x47f6c0, 'GUESS FUN_47f6c0', 'thiscall', None, ret='eax', gen=_gen, note='batch1659; ZSTDOBJ ctor hooked; ret 0xc')
