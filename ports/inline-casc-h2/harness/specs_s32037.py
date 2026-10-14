from pilot import S
from recruits_util import rnd, obj

def gen_4e5450(c):
    # thiscall(this, arg) ret 4: returns [arg] + 1 + [ecx+8]
    this_obj = obj(c, 0x20, {})  # Need space for offset 8
    arg_obj = obj(c, 0x20, {})   # Need space for offset 0

    # Initialize with random values
    val1 = c.rng.getrandbits(32)
    val2 = c.rng.getrandbits(32)

    c.emu.w32(arg_obj + 0, val1)
    c.emu.w32(this_obj + 8, val2)

    return [this_obj, arg_obj]

def gen_5eebd0(c):
    # thiscall(this, arg) ret 4: conditional setter
    this_obj = obj(c, 0x80, {})  # Need space for offsets 0x45 and 0x77

    # Generate arg and existing field value
    arg = c.rng.getrandbits(32)
    existing = c.rng.getrandbits(32)

    # Initialize field at 0x45
    c.emu.w32(this_obj + 0x45, existing)
    # Initialize byte at 0x77
    c.emu.w8(this_obj + 0x77, 0)

    return [this_obj, arg]

S(0x4e5450, 'sub_4e5450', 'thiscall', 1, ret='eax', gen=gen_4e5450)
S(0x5eebd0, 'sub_5eebd0', 'thiscall', 1, ret=None, gen=gen_5eebd0)
