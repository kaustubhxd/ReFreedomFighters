from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_63ea80(c):
    # stdcall(arg) ret 4: reads [arg+4] and returns it
    o = obj(c, 0x100, {})
    c.emu.w32(o + 4, c.rng.getrandbits(32))
    return [o]

def gen_650dc0(c):
    # thiscall(this, arg) ret 4: stores at [ecx+0xc]
    o = obj(c, 0x100, {})
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

def gen_464710(c):
    # thiscall(this, arg) ret 4: reads [ecx+0x6c], stores arg at [field+0x268]
    o = obj(c, 0x300, {})
    field = obj(c, 0x300, {})
    c.emu.w32(o + 0x6c, field)
    arg_val = c.rng.getrandbits(32)
    return [o, arg_val]

S(0x63ea80, 'sub_63ea80', 'stdcall', 1, ret='eax', gen=gen_63ea80)
S(0x650dc0, 'sub_650dc0', 'thiscall', 1, ret='eax', gen=gen_650dc0)
S(0x464710, 'sub_464710', 'thiscall', 1, ret='eax', gen=gen_464710)
