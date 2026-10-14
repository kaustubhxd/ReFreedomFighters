from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_539c90(c):
    o = obj(c, 0x5300, {})  # Size >= 0x52f6 + 4
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

def gen_5eeb00(c):
    o = obj(c, 0x100, {})
    arg_val = c.rng.getrandbits(8)
    return [o, arg_val]

def gen_5f0180(c):
    o = obj(c, 0x100, {})
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

S(0x539c90, 'sub_539c90', 'thiscall', 1, ret='eax', gen=gen_539c90)
S(0x5eeb00, 'sub_5eeb00', 'thiscall', 1, ret='eax', gen=gen_5eeb00)
S(0x5f0180, 'sub_5f0180', 'thiscall', 1, ret='eax', gen=gen_5f0180)
