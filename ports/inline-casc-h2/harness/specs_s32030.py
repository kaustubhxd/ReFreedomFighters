from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_475910(c):
    # thiscall(this, arg_byte) ret 4: setne byte at [ecx+0x3bb]
    o = obj(c, 0x400, {})  # Size >= 0x3bb + 1
    # Test both zero and non-zero values to exercise both branches
    arg_val = c.rng.getrandbits(8) if c.rng.getrandbits(1) else 0
    return [o, arg_val]

S(0x475910, 'sub_475910', 'thiscall', 1, ret='eax', gen=gen_475910)
