"""specs_s31020.py - batch 31020: 2-param setter, mixed store, copy, flag test."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g651010(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val1 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    val2 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val1, val2]

def _g47fb10(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val]

def _g516620(c):
    clear_hooks(c)
    src = obj(c, 0x100, {0: 0x1234, 8: 0x5678})
    dst = obj(c, 0x200, {})
    return [dst, src]

def _g593fd0(c):
    clear_hooks(c)
    hook_rec(c, 0x4670b0, 0)
    flag = c.rng.choice([0, 0x400, 0x3ff, c.rng.getrandbits(32)])
    o = obj(c, 0x500, {0x417: flag})
    return [o]

S(0x651010, 'set_two_dwords_84_88', 'thiscall', None, ret=None, gen=_g651010)
S(0x47fb10, 'set_param_then_const', 'thiscall', None, ret=None, gen=_g47fb10)
S(0x516620, 'copy_two_dwords_from_src', 'thiscall', None, ret=None, gen=_g516620)
S(0x593fd0, 'test_flag_400_jmp_4670b0', 'thiscall', None, ret=None, gen=_g593fd0)
