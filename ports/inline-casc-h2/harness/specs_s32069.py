from pilot import S
from recruits_util import obj

def gen_4bb9d0(c):
    # thiscall(this) ret 4 - field modification then external call
    this_obj = obj(c, 0x100, {})

    # Initialize field at [ecx+4]
    c.emu.w32(this_obj + 4, c.rng.getrandbits(32))

    return [this_obj]

S(0x4bb9d0, 'sub_4bb9d0', 'stdcall', 0, ret='al', gen=gen_4bb9d0)
