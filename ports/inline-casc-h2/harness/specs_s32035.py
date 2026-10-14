from pilot import S
from recruits_util import rnd, obj

def gen_646040(c):
    # thiscall: checks [ecx+0x291] and [ecx+0x295] for zero
    o = obj(c, 0x300, {})  # need space for offsets 0x291 and 0x295
    # Create both zero and non-zero cases
    if c.rng.getrandbits(1):
        # Both zero case
        c.emu.w32(o + 0x291, 0)
        c.emu.w32(o + 0x295, 0)
    else:
        # Non-zero case
        c.emu.w32(o + 0x291, c.rng.getrandbits(32) or 1)
        c.emu.w32(o + 0x295, c.rng.getrandbits(32) or 1)
    return [o]

S(0x646040, 'sub_646040', 'thiscall', None, ret='al', gen=gen_646040)
