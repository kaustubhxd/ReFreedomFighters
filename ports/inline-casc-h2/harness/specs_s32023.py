from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_47bfb0(c):
    # thiscall(this, arg) ret 4: stores at [ecx+0x5b2], returns arg
    o = obj(c, 0x5c0, {})  # Size >= 0x5b2 + 4
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

def gen_4e7c40(c):
    # thiscall(this, arg) ret 4: stores at [ecx+9], returns arg
    o = obj(c, 0x100, {})
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

S(0x47bfb0, 'sub_47bfb0', 'thiscall', 1, ret='eax', gen=gen_47bfb0)
S(0x4e7c40, 'sub_4e7c40', 'thiscall', 1, ret='eax', gen=gen_4e7c40)
