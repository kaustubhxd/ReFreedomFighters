"""specs_s31009.py - batch 31009: bit test, stores, compare, vtable store."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _g5490f0(c):
    # thiscall, test bit 4 at [ecx+4], conditional jump to 0x5491a0
    clear_hooks(c)
    hook_rec(c, 0x5491a0, 0, this=True)
    val = c.rng.choice([0, 4, 8, 12, c.rng.getrandbits(8)])
    o = obj(c, 0x80, {4: val})
    return [o]

def _g5b0290(c):
    # thiscall, stores dword and byte, then tail-jumps to 0x5b0220
    clear_hooks(c)
    hook_rec(c, 0x5b0220, 0, this=True)
    return [obj(c, 0x2000, {})]

def _g613350(c):
    # thiscall, compare [ecx+0x22030] != 0, return bool
    clear_hooks(c)
    val = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    o = obj(c, 0x22050, {0x22030: val})
    return [o]

def _g655a60(c):
    # stdcall, stores vtable, returns this
    clear_hooks(c)
    return [obj(c, 0x80, {})]

S(0x5490f0, 'test_bit_4', 'thiscall', None, ret=None, gen=_g5490f0)
S(0x5b0290, 'store_dword_byte', 'thiscall', None, ret=None, gen=_g5b0290)
S(0x613350, 'compare_ne_0', 'thiscall', None, ret='al', gen=_g613350)
S(0x655a60, 'store_vtable_ret_this', 'stdcall', None, ret='eax', gen=_g655a60)
