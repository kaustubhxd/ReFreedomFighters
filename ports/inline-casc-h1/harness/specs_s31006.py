"""specs_s31006.py - batch 31006: byte read, offset call, pointer arithmetic, vtable store."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _g54ba10(c):
    # thiscall, returns byte at [ecx + 0xa273]
    clear_hooks(c)
    val = c.rng.randint(0, 255)
    o = obj(c, 0xa300, {0xa273: val})
    return [o]

def _g59ad30(c):
    # thiscall, adds 0x1218c to ecx and calls 0x4cd0e0
    clear_hooks(c)
    hook_rec(c, 0x4cd0e0, 0, this=True)
    return [obj(c, 0x200, {})]

def _g59b3b0(c):
    # thiscall, returns lea eax, [ecx + 0x121b0]
    clear_hooks(c)
    return [obj(c, 0x100, {})]

def _g5ab4b0(c):
    # thiscall, stores vtable and returns
    clear_hooks(c)
    return [obj(c, 0x80, {})]

S(0x54ba10, 'read_byte_a273', 'thiscall', None, ret='al', gen=_g54ba10)
S(0x59ad30, 'call_with_offset_1218c', 'thiscall', None, ret=None, gen=_g59ad30)
S(0x59b3b0, 'return_pointer_121b0', 'thiscall', None, ret='eax', gen=_g59b3b0)
S(0x5ab4b0, 'store_vtable_6b01dc', 'thiscall', None, ret=None, gen=_g5ab4b0)
