from pilot import S
from recruits_util import obj

def gen_4e53d0(c):
    # thiscall(this, arg1, arg2) ret 8: complex 2-param indexed access
    # Reads [arg1+0x80] as table, [ecx+0xc] as field
    # Computes [table + arg2*4 + field + 4] + field

    this_obj = obj(c, 0x20, {})

    # Create argument1 object
    arg1_obj = obj(c, 0x100, {})

    # Create a large table
    table = obj(c, 0x2000, {})

    # Store table pointer at [arg1_obj + 0x80]
    c.emu.w32(arg1_obj + 0x80, table)

    # Initialize table with random values
    for i in range(0, 0x2000, 4):
        val = c.rng.getrandbits(32)
        c.emu.w32(table + i, val)

    # Generate random field value (offset into table)
    field = c.rng.getrandbits(8) % 32

    # Store field at [ecx + 0xc]
    c.emu.w32(this_obj + 0xc, field)

    # Generate random arg2 that doesn't overflow
    arg2 = c.rng.getrandbits(10) % 256

    return [this_obj, arg1_obj, arg2]

S(0x4e53d0, 'sub_4e53d0', 'thiscall', 2, ret='eax', gen=gen_4e53d0)
