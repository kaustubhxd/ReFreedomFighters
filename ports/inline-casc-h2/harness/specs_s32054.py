from pilot import S
from recruits_util import obj

def gen_5df790(c):
    # thiscall(this, arg0, arg1, arg2, arg3) ret 16: 4-param constructor with duplicate
    # Stores arg0 at [ecx+4] and [ecx+14h], args 1-3 at [ecx+8-10h], vtable at [ecx]

    this_obj = obj(c, 0x20, {})

    # Generate 4 random arguments
    arg0 = c.rng.getrandbits(32)
    arg1 = c.rng.getrandbits(32)
    arg2 = c.rng.getrandbits(32)
    arg3 = c.rng.getrandbits(32)

    return [this_obj, arg0, arg1, arg2, arg3]

S(0x5df790, 'sub_5df790', 'thiscall', 4, ret='eax', gen=gen_5df790)
