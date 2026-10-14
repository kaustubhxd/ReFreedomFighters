from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_4711e0(c):
    # thiscall(this, arg) ret 4: stores arg at [ecx+0xba]
    o = obj(c, 0xc0, {})  # Size >= 0xba + 4
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

S(0x4711e0, 'sub_4711e0', 'thiscall', 1, ret='eax', gen=gen_4711e0)
