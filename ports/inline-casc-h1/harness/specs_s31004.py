"""specs_s31004.py - batch 31004: vtable stores and field reads."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _g4d5570(c):
    # thiscall, stores vtable and returns
    clear_hooks(c)
    return [obj(c, 0x80, {})]

def _g4f3c30(c):
    # thiscall, stores vtable and tail-jumps to 0x43ea20
    clear_hooks(c)
    hook_rec(c, 0x43ea20, 0, this=True)
    return [obj(c, 0x80, {})]

def _g4f5990(c):
    # thiscall, stores vtable and tail-jumps to 0x43ea20
    clear_hooks(c)
    hook_rec(c, 0x43ea20, 0, this=True)
    return [obj(c, 0x80, {})]

def _g4f9f40(c):
    # thiscall, returns dword at [ecx + 0x8f]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0xa0, {0x8f: val})
    return [o]

S(0x4d5570, 'store_vtable_6967bc', 'thiscall', None, ret=None, gen=_g4d5570)
S(0x4f3c30, 'store_vtable_69909c', 'thiscall', None, ret=None, gen=_g4f3c30)
S(0x4f5990, 'store_vtable_69a370', 'thiscall', None, ret=None, gen=_g4f5990)
S(0x4f9f40, 'read_field_8f', 'thiscall', None, ret='eax', gen=_g4f9f40)
