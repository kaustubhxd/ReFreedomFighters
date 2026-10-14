from pilot import S
from recruits_util import obj

def gen_52cfd0(c):
    # thiscall(this) - multi-field constructor
    # Need object large enough for all the field writes at offsets up to 0x9c
    this_obj = obj(c, 0x200, {})
    return [this_obj]

S(0x52cfd0, 'sub_52cfd0', 'thiscall', 0, ret='ecx', gen=gen_52cfd0)
