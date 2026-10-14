from pilot import S
from recruits_util import obj

def gen_466470(c):
    # thiscall: clears bit 0x20000 at [ecx+0x136]
    o = obj(c, 0x140, {})  # Need space for offset 0x136
    # Initialize with some value that has the bit set
    c.emu.w32(o + 0x136, c.rng.getrandbits(32) | 0x20000)
    return [o]

def gen_468a20(c):
    # thiscall: returns byte from [ecx+0x52]
    o = obj(c, 0x60, {})  # Need space for offset 0x52
    # Initialize with random byte
    c.emu.w8(o + 0x52, c.rng.getrandbits(8))
    return [o]

S(0x466470, 'sub_466470', 'thiscall', None, ret=None, gen=gen_466470)
S(0x468a20, 'sub_468a20', 'thiscall', None, ret='al', gen=gen_468a20)
