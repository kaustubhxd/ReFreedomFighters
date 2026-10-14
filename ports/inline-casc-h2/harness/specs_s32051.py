from pilot import S
from recruits_util import obj

def gen_521780(c):
    # thiscall(this, arg0, arg1) ret 8: conditional flag setter
    # Tests [this+0x260b], stores args at [this+0x2610] and [this+0x2609]

    # Need to allocate a large object to accommodate large offsets
    this_obj = obj(c, 0x2700, {})  # Allocate 0x2700 bytes

    # Generate random arguments
    arg0 = c.rng.getrandbits(32)
    arg1 = c.rng.getrandbits(8)

    # Initialize the flag byte at 0x260b to either 0 or 1
    flag_val = c.rng.getrandbits(1)
    c.emu.w8(this_obj + 0x260b, flag_val)

    # Initialize the storage locations with random values
    c.emu.w32(this_obj + 0x2610, c.rng.getrandbits(32))
    c.emu.w8(this_obj + 0x2609, c.rng.getrandbits(8))

    return [this_obj, arg0, arg1]

S(0x521780, 'sub_521780', 'thiscall', 2, ret=None, gen=gen_521780)
