from pilot import S
from recruits_util import obj

def gen_5cf7f0(c):
    # thiscall(this, output) ret 4: copy three dwords to output
    # Copies [ecx+0xc71], [ecx+0xc75], [ecx+0xc79] to [output+0], [output+4], [output+8]

    this_obj = obj(c, 0x1000, {})
    output = obj(c, 0x20, {})

    # Initialize the three fields in this object at the required offsets
    val1 = c.rng.getrandbits(32)
    val2 = c.rng.getrandbits(32)
    val3 = c.rng.getrandbits(32)

    c.emu.w32(this_obj + 0xc71, val1)
    c.emu.w32(this_obj + 0xc75, val2)
    c.emu.w32(this_obj + 0xc79, val3)

    return [this_obj, output]

S(0x5cf7f0, 'sub_5cf7f0', 'thiscall', 1, ret=None, gen=gen_5cf7f0)
