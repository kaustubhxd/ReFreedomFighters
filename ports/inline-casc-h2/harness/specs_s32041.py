from pilot import S
from recruits_util import obj

def gen_4c1e00(c):
    # thiscall: chain of reads with bit manipulation and conditional jump
    # [ecx+0x44] -> obj1, [obj1+8] -> obj2, [obj2+0x3c] -> value
    # Shift right 10, NOT, test bit 0, jump or return

    this_obj = obj(c, 0x50, {})
    obj1 = obj(c, 0x20, {})
    obj2 = obj(c, 0x50, {})

    c.emu.w32(this_obj + 0x44, obj1)
    c.emu.w32(obj1 + 8, obj2)

    # Create value that won't trigger jump: (val >> 10) with bit 0 clear
    val = c.rng.getrandbits(32) & ~1  # Clear bit 0 after shift
    val <<= 10  # So (val >> 10) will have bit 0 clear
    c.emu.w32(obj2 + 0x3c, val)

    return [this_obj]

S(0x4c1e00, 'sub_4c1e00', 'thiscall', None, ret=None, gen=gen_4c1e00)
