from pilot import S
from recruits_util import obj

def gen_5edc80(c):
    # thiscall(this, end_ptr) ret 4: swap/reverse elements from opposite ends
    # Swaps elements from this pointer and end_ptr moving towards each other

    # Create data buffer with room for swapping
    data = obj(c, 0x200, {})

    # Initialize entire buffer with random values
    for i in range(0, 0x200, 4):
        val = c.rng.getrandbits(32)
        c.emu.w32(data + i, val)

    # Create start and end pointers within the buffer
    # Ensure they're properly aligned and within bounds
    num_elements = c.rng.getrandbits(5) + 4  # 4-35 elements
    start_ptr = data + 0x40  # Start at offset 0x40
    end_ptr = start_ptr + (num_elements * 4)  # End after num_elements

    # Make sure end_ptr doesn't exceed our buffer
    if end_ptr >= data + 0x200:
        end_ptr = data + 0x1fc

    return [start_ptr, end_ptr]

S(0x5edc80, 'sub_5edc80', 'thiscall', 1, ret=None, gen=gen_5edc80)
