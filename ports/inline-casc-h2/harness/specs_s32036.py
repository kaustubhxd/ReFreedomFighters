from pilot import S
from recruits_util import rnd, obj

def gen_4e5080(c):
    # thiscall(this, arg) ret 4: table lookup
    # Reads [arg+0x80] as table, [ecx+0xc] as index, returns table[index]
    this_obj = obj(c, 0x20, {})  # Need space for offset 0xc
    arg_obj = obj(c, 0x100, {})  # Need space for offset 0x80

    # Create a small table (10 entries)
    table = obj(c, 0x40, {})  # 10 dwords = 0x28 bytes

    # Initialize table with some values
    for i in range(10):
        c.emu.w32(table + i*4, i * 0x12345 + 0x1000)

    # Store table pointer at arg[0x80]
    c.emu.w32(arg_obj + 0x80, table)

    # Generate random index within table bounds
    index = c.rng.getrandbits(8) % 10
    c.emu.w32(this_obj + 0xc, index)

    return [this_obj, arg_obj]

S(0x4e5080, 'sub_4e5080', 'thiscall', 1, ret='eax', gen=gen_4e5080)
