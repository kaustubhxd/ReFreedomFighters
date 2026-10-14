from pilot import S
from recruits_util import obj

def gen_4e5080(c):
    # stdcall(this, arg) ret 4: nested dereference with byte offset indexing
    # Reads [arg+0x80] as table pointer, [ecx+0xc] as byte offset
    # Returns [table + byte_offset]

    this_obj = obj(c, 0x20, {})

    # Create an argument object
    arg_obj = obj(c, 0x100, {})

    # Create a large table for dereferencing
    table = obj(c, 0x1000, {})

    # Store table pointer at [arg_obj + 0x80]
    c.emu.w32(arg_obj + 0x80, table)

    # Initialize entire table with random values
    for i in range(0, 0x1000, 4):
        val = c.rng.getrandbits(32)
        c.emu.w32(table + i, val)

    # Generate random byte offset that stays within bounds
    # Max safe offset (0-252 by 4 = 0-1008 bytes)
    byte_offset = (c.rng.getrandbits(8) % 64) * 4

    # Store byte offset at [ecx + 0xc]
    c.emu.w32(this_obj + 0xc, byte_offset)

    return [this_obj, arg_obj]

S(0x4e5080, 'sub_4e5080', 'stdcall', 1, ret='eax', gen=gen_4e5080)
