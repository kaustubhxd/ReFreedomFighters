from pilot import S
from recruits_util import obj

def gen_5df7c0(c):
    # thiscall(this, arg0, arg1, arg2) ret 12: constructor initializer
    # Stores args at [ecx+4], [ecx+8], [ecx+0xc] and vtable at [ecx]

    this_obj = obj(c, 0x20, {})

    # Generate random arguments
    arg0 = c.rng.getrandbits(32)
    arg1 = c.rng.getrandbits(32)
    arg2 = c.rng.getrandbits(32)

    return [this_obj, arg0, arg1, arg2]

S(0x5df7c0, 'sub_5df7c0', 'thiscall', 3, ret='eax', gen=gen_5df7c0)
