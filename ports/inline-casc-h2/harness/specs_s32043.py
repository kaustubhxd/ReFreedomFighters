from pilot import S
from recruits_util import obj

def gen_5b04c0(c):
    # thiscall(this, ptr1, ptr2) ret 8: copyout function
    # Reads from [ecx+0xc] and [ecx+0x14], writes to *ptr1 and *ptr2

    this_obj = obj(c, 0x20, {})

    # Create output buffers
    out1 = obj(c, 0x10, {})
    out2 = obj(c, 0x10, {})

    # Initialize this object with values to copy
    val1 = c.rng.getrandbits(32)
    val2 = c.rng.getrandbits(32)
    c.emu.w32(this_obj + 0xc, val1)
    c.emu.w32(this_obj + 0x14, val2)

    return [this_obj, out1, out2]

S(0x5b04c0, 'sub_5b04c0', 'thiscall', 2, ret=None, gen=gen_5b04c0)
