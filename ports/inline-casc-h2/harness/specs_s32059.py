from pilot import S
from recruits_util import obj

def gen_597b10(c):
    # thiscall(this, arg0) ret 4 - linear search
    # Searches [ecx+0xe6] array for arg0, returns 1 if found else 0

    this_obj = obj(c, 0x1000, {})

    # Array count at [ecx+0x2e6]
    count = c.rng.randint(0, 20)
    c.emu.w32(this_obj + 0x2e6, count)

    # Fill the array at [ecx+0xe6]
    search_value = c.rng.getrandbits(32)

    if count > 0:
        # Place search value at random position, or not at all
        if c.rng.choice([True, False]):
            pos = c.rng.randint(0, count - 1)
            c.emu.w32(this_obj + 0xe6 + pos * 4, search_value)

        # Fill rest with random values
        for i in range(count):
            if c.emu.r32(this_obj + 0xe6 + i * 4) == 0:
                c.emu.w32(this_obj + 0xe6 + i * 4, c.rng.getrandbits(32))

    return [this_obj, search_value]

S(0x597b10, 'sub_597b10', 'thiscall', 1, ret='al', gen=gen_597b10)
