from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_46e690(c):
    # thiscall: needs an object with valid pointer/data at ecx+0x7c
    o = obj(c, 0x100, {})
    c.emu.w32(o + 0x7c, c.rng.getrandbits(32))
    return [o]

def gen_46e730(c):
    # cdecl: no args
    return []

S(0x46e690, 'sub_46e690', 'thiscall', None, ret='eax', gen=gen_46e690)
S(0x46e730, 'sub_46e730', 'cdecl', None, ret='eax', gen=gen_46e730)
