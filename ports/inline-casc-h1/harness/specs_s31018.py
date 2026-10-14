"""specs_s31018.py - batch 31018: zero-fill, 2-param setters, conditional jump."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g5aedb0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    return [o]

def _g4646f0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val1 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    val2 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val1, val2]

def _g467cd0(c):
    clear_hooks(c)
    hook_rec(c, 0x465930, 0)
    val = c.rng.choice([0, 1, 0xff, c.rng.randint(0, 255)])
    o = obj(c, 0x200, {0: val})
    return [o]

def _g4c3280(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val1 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    val2 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val1, val2]

S(0x5aedb0, 'zero_fill_multiple', 'thiscall', None, ret=None, gen=_g5aedb0)
S(0x4646f0, 'set_two_dwords_68_60', 'thiscall', None, ret=None, gen=_g4646f0)
S(0x467cd0, 'cond_test_byte_jmp_465930', 'thiscall', None, ret=None, gen=_g467cd0)
S(0x4c3280, 'set_two_dwords_48_4c', 'thiscall', None, ret=None, gen=_g4c3280)
