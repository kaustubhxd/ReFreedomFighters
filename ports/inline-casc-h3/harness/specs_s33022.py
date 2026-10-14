"""specs_s33022.py - h3 batch 33022: conditional field setters."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _me(c, n=0x200):
    return rnd(c, n)

def _g446eb0(c):
    clear_hooks(c)
    # Vary the conditional byte to exercise both branches
    cond = c.rng.choice([0, 1, 0xff, 0x7f])
    return [_me(c), cond]

S(0x446eb0, 'set_based_on_byte', 'thiscall', None, ret=None, gen=_g446eb0)
