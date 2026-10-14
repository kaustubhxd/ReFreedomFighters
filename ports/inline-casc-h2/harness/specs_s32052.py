from pilot import S
from recruits_util import obj

def gen_570620(c):
    # thiscall(this, source) ret 4: copy multiple fields
    # Copies 5 dwords and 1 byte from source to this

    # Allocate two objects large enough for the offsets
    this_obj = obj(c, 0x300, {})
    source_obj = obj(c, 0x300, {})

    # Initialize source object with random values at the offsets we'll copy from
    source_vals = []
    for offset in [0x1b0, 0x1b4, 0x1b8, 0x1bc, 0x190]:
        val = c.rng.getrandbits(32)
        c.emu.w32(source_obj + offset, val)
        source_vals.append(val)

    byte_val = c.rng.getrandbits(8)
    c.emu.w8(source_obj + 0x1a3, byte_val)

    # Initialize this object with different values (will be overwritten)
    for offset in [0x1b0, 0x1b4, 0x1b8, 0x1bc, 0x190]:
        c.emu.w32(this_obj + offset, c.rng.getrandbits(32))
    c.emu.w8(this_obj + 0x1a3, c.rng.getrandbits(8))

    return [this_obj, source_obj]

S(0x570620, 'sub_570620', 'thiscall', 1, ret=None, gen=gen_570620)
