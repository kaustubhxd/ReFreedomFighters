from pilot import S
from recruits_util import obj

def gen_534d80(c):
    this_obj = obj(c, 0x6000, {})

    # Just test with zero (return path only)
    c.emu.w32(this_obj + 0x52fa, 0)

    return [this_obj]

S(0x534d80, 'sub_534d80', 'thiscall', 0, ret=None, gen=gen_534d80)
