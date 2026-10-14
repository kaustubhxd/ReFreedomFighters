from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub

def gen_530fb0(c):
    # thiscall(this, arg1_byte, arg2_byte) ret 8
    o = obj(c, 0x20, {})  # minimal object
    arg1 = c.rng.getrandbits(8)
    arg2 = c.rng.getrandbits(8)
    return [o, arg1, arg2]

def gen_5b07f0(c):
    # thiscall(this, arg1, arg2) ret 8
    o = obj(c, 0x20, {})  # minimal object
    arg1 = c.rng.getrandbits(32)
    arg2 = c.rng.getrandbits(32)
    return [o, arg1, arg2]

def gen_62c9b0(c):
    # cdecl(obj) - initializes object
    o = obj(c, 0x20, {})  # minimal object
    return [o]

S(0x530fb0, 'sub_530fb0', 'thiscall', 2, ret='eax', gen=gen_530fb0)
S(0x5b07f0, 'sub_5b07f0', 'thiscall', 2, ret='eax', gen=gen_5b07f0)
S(0x62c9b0, 'sub_62c9b0', 'cdecl', 1, ret=None, gen=gen_62c9b0)
