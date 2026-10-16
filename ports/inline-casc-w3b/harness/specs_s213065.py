"""specs_s213065.py - batch 213065: 56-entry selector table forwarded to a 5-argument call, Sonnet-w3b."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g5ac660(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    this = rnd(c, 0x80)
    obj = rnd(c, 0x20)
    e.w32(this + 0x6a, 0 if r.random() < 0.05 else obj)
    sel = r.randint(1, 56) if r.random() < 0.9 else r.choice([0, 57, 58, 0xffffffff, 0x80000000, r.getrandbits(32)])
    hook_rec(c, 0x5ec390, 5, ret=r.getrandbits(32), this=True)
    return [this, sel, r.getrandbits(32)]


S(0x5ac660, 'cell_selector_forward', 'thiscall', None, ret=None, gen=g5ac660)
