from pilot import S
from recruits_util import obj

def gen_623050(c):
    # cdecl(arg0, arg1, arg2, arg3) - byte copy loop
    # arg0 = pointer to source counter
    # arg1 = source limit
    # arg2 = pointer to destination counter
    # arg3 = destination limit

    src_counter_ptr = c.emu.alloc(4, 4)
    dst_counter_ptr = c.emu.alloc(4, 4)
    src_buffer = c.emu.alloc(0x100, 4)
    dst_buffer = c.emu.alloc(0x100, 4)

    # Initialize counters
    src_start = c.rng.randint(0, 50)
    src_limit = src_start + c.rng.randint(1, 30)
    c.emu.w32(src_counter_ptr, src_start)

    dst_limit = c.rng.randint(1, 30)
    c.emu.w32(dst_counter_ptr, 0)

    # Fill source buffer with data
    for i in range(src_start, min(src_limit, src_start + 100)):
        c.emu.w8(src_buffer + (i - src_start), c.rng.getrandbits(8))

    return [src_counter_ptr, src_buffer + src_start, dst_counter_ptr, dst_buffer]

S(0x623050, 'sub_623050', 'cdecl', 4, ret=None, gen=gen_623050)
