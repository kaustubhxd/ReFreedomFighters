from pilot import S
from recruits_util import obj

def gen_4619e0(c):
    # thiscall(this, arg) ret 4: boolean function with array indexing
    # [ecx+0x1c] is array, tests byte at [array + arg*3*8 + 4]

    this_obj = obj(c, 0x30, {})

    # Create large array for the indexed access
    # Max safe index with reasonable arg range (0-100): arg*3*8+4 = max 2404
    array = obj(c, 0x1000, {})  # Large array

    # Initialize array with some values
    for i in range(0, 0x100, 1):
        val = c.rng.getrandbits(8)
        c.emu.w8(array + i, val)

    # Store array pointer at [ecx+0x1c]
    c.emu.w32(this_obj + 0x1c, array)

    # Generate random arg that won't go out of bounds
    arg = c.rng.getrandbits(8) % 50  # arg*3*8+4 max = 1204

    return [this_obj, arg]

S(0x4619e0, 'sub_4619e0', 'thiscall', 1, ret='al', gen=gen_4619e0)
