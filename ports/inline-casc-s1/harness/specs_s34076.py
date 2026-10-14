"""specs_s34076.py - 0x5ae680: hooked 0x5b1440 (bool in al, random low byte), 0x5ad2b0 (records the first 5 bytes of its argument), 0x5c2c80, 0x5b1150, 0x5ae710, /GS; byte [this+3] is 0x52 in a third; exe globals 0x6b09f0/4 random."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5b1440, 1, ret=lambda em, k: r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)]), this=True)
    hook_rec(c, 0x5ad2b0, 1, this=True, deref={0: -5})
    hook_rec(c, 0x5c2c80, 0, this=True, pop=0)
    hook_rec(c, 0x5b1150, 2, this=True)
    hook_rec(c, 0x5ae710, 1, this=True)
    hook_rec(c, 0x633654, 0, pop=0)
    c.emu.wbytes(0x6b09f0, bytes(r.getrandbits(8) for _ in range(5)))
    me = rnd(c, 0x520)
    c.emu.wbytes(me + 3, bytes([r.choice([0x52, 0x52, 0x41, r.getrandbits(8)])]))
    return [me]


S(0x5ae680, 'GUESS rebuild record and refresh', 'thiscall', None, ret=None, gen=_g, note='batch34076')
