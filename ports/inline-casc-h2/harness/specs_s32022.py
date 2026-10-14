from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_4754d0(c):
    # thiscall(this, arg_byte) ret 4: stores byte at [ecx+0x3e9], returns arg
    o = obj(c, 0x400, {})  # Size >= 0x3e9 + 1
    arg_val = c.rng.getrandbits(8)
    return [o, arg_val]

S(0x4754d0, 'sub_4754d0', 'thiscall', 1, ret='eax', gen=gen_4754d0)
