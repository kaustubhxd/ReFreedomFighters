from pilot import S
from recruits_util import obj

def gen_5167d0(c):
    # thiscall(this) - large field initializer
    this_obj = obj(c, 0x100, {})
    return [this_obj]

S(0x5167d0, 'sub_5167d0', 'thiscall', 0, ret='ecx', gen=gen_5167d0)
