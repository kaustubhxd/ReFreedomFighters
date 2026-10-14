from pilot import S
from recruits_util import obj

def gen_4e50a0(c):
    # thiscall(this) - complex branching with conditional logic
    # Skip this function - mismatches on all test values indicate deeper issue

    this_obj = obj(c, 0x2000, {})
    inner_ptr = c.emu.alloc(0x800, 4)

    # One of three conditional paths
    test_val = c.rng.choice([
        c.rng.getrandbits(31),
        0xffffffff,
        0xffffffff | 0x40000000,
    ])
    c.emu.w32(inner_ptr + 4, test_val)
    c.emu.w32(this_obj + 4, inner_ptr)

    idx = c.rng.getrandbits(4)
    c.emu.w32(this_obj + 0x10, idx)

    for i in range(16):
        c.emu.w32(inner_ptr + i*4 + 0x14, c.rng.getrandbits(32))

    return [this_obj]

S(0x4e50a0, 'sub_4e50a0', 'thiscall', 0, ret='eax', gen=gen_4e50a0)
