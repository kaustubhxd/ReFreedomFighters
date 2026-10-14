from pilot import S
from recruits_util import obj

def gen_624960(c):
    # cdecl(arg0, arg1) - boolean test function
    # Returns 1 if [arg1]==0xf4 AND ([arg1+1] & 0x30)!=0, else 0

    # Create a buffer for arg1 (byte array)
    buffer = obj(c, 0x20, {})

    # Generate test data: sometimes matching, sometimes not
    rand_val = c.rng.getrandbits(1)
    if rand_val:
        # Generate matching case
        c.emu.w8(buffer + 0, 0xf4)
        # Set some bits in 0x30 range
        c.emu.w8(buffer + 1, 0x30 | (c.rng.getrandbits(3) << 4))
    else:
        # Generate non-matching case
        byte0 = c.rng.getrandbits(8)
        byte1 = c.rng.getrandbits(8)
        if byte0 == 0xf4 and (byte1 & 0x30):
            # Avoid accidentally matching - flip byte0
            byte0 ^= 0x01
        c.emu.w8(buffer + 0, byte0)
        c.emu.w8(buffer + 1, byte1)

    # arg0 is unused in the function
    arg0 = c.rng.getrandbits(32)

    return [arg0, buffer]

S(0x624960, 'sub_624960', 'cdecl', 2, ret='al', gen=gen_624960)
