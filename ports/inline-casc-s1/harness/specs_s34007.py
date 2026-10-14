"""specs_s34007.py - cascade escalation batch 34007: 0x536260. The unaligned pointer at +0x52fa is null in half the cases; the tail target 0x53b100
is a recorder hook (ECX and one stack argument recorded, random return)."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x53b100, 1, ret=r.getrandbits(32), this=True)
    me = rnd(c, 0x5400)
    c.emu.wbytes(me + 0x52fa, (0 if r.random() < 0.5 else r.getrandbits(32) or 1).to_bytes(4, 'little'))
    return [me, r.getrandbits(32)]


S(0x536260, 'GUESS forward to member +0x52fa when set', 'thiscall', None, ret='eax', gen=_g, note='batch34007')
