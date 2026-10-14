from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_4fa700(c):
    # thiscall(this, arg) ret 4: stores at [ecx+0x68], returns arg
    o = obj(c, 0x100, {})
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

def gen_520d30(c):
    # thiscall(this, arg_byte) ret 4: movzx to dword at [ecx+0x2620]
    o = obj(c, 0x2650, {})  # Size >= 0x2620 + 4
    arg_val = c.rng.getrandbits(8)  # Byte argument
    return [o, arg_val]

S(0x4fa700, 'sub_4fa700', 'thiscall', 1, ret='eax', gen=gen_4fa700)
S(0x520d30, 'sub_520d30', 'thiscall', 1, ret='eax', gen=gen_520d30)
