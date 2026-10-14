"""specs_s1712.py - residue 13 batch 1712: 0x575150. Both callees (0x573da0 base init thunk, 0x575230 zone-map init; thiscall,
no arguments, plain ret) are hooked by address; their records hold this, the call count and the sequence number, so the call
order and the restored ecx are both checked."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x573da0, 0, ret=r.getrandbits(32), this=True, pop=True)
    hook(c, seq, 0x575230, 0, ret=r.getrandbits(32), this=True, pop=True)
    return [rnd(c, 0x100)]


S(0x575150, 'GUESS FUN_575150', 'thiscall', None, ret='eax', gen=_gen, note='batch1712; base init 0x573da0 then tail 0x575230 (both hooked)')
