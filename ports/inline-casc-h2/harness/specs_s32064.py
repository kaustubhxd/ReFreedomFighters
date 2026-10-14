from pilot import S
from recruits_util import obj

def gen_62c9d0(c):
    arg0_obj = c.rng.choice([None, c.emu.alloc(0x100, 4)])
    arg1 = c.rng.choice([0xf, 0x12, 0x29, 0x1c, c.rng.getrandbits(16)])
    
    if arg0_obj is not None:
        c.emu.w32(arg0_obj + 0xc, c.rng.choice([0, 1, c.rng.getrandbits(32)]))
    
    return [arg0_obj if arg0_obj else 0, arg1]

S(0x62c9d0, 'sub_62c9d0', 'cdecl', 2, ret='eax', gen=gen_62c9d0)
