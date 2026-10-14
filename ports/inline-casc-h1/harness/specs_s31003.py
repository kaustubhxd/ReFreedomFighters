"""specs_s31003.py - batch 31003: pointer arithmetic and field reads."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _g473fb0(c):
    # thiscall, adds 0x26a to ecx and calls fn_4666d0
    clear_hooks(c)
    hook_rec(c, 0x4666d0, 0, this=True)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x300, {0x26a + 0x39: val})
    return [o]

def _g474440(c):
    # thiscall, returns lea eax, [ecx + 0x2e7]
    clear_hooks(c)
    return [obj(c, 0x400, {})]

def _g478e90(c):
    # thiscall, returns dword at [ecx + 0x5b2]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x600, {0x5b2: val})
    return [o]

def _g490d10(c):
    # thiscall, adds 0xbcd to ecx and calls 0x4cc1d0
    clear_hooks(c)
    hook_rec(c, 0x4cc1d0, 0, this=True)
    return [obj(c, 0x400, {})]

S(0x473fb0, 'call_with_offset_26a', 'thiscall', None, ret='eax', gen=_g473fb0)
S(0x474440, 'return_pointer_2e7', 'thiscall', None, ret='eax', gen=_g474440)
S(0x478e90, 'read_field_5b2', 'thiscall', None, ret='eax', gen=_g478e90)
S(0x490d10, 'call_with_offset_bcd', 'thiscall', None, ret=None, gen=_g490d10)
