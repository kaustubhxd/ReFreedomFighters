from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_45edb0(c):
    # thiscall, reads ecx[2] and calls ext_4db150
    hook_rec(c, 0x4db150, 1, ret=c.rng.getrandbits(32), this=True)
    o = obj(c, 0x100, {})
    # Set ecx[2] to another object
    inner = obj(c, 0x80, {})
    c.emu.w32(o + 8, inner)
    return [o]

def gen_45f030(c):
    # thiscall, reads ecx[2] and calls ext_4db600
    hook_rec(c, 0x4db600, 1, ret=c.rng.getrandbits(32), this=True)
    o = obj(c, 0x100, {})
    # Set ecx[2] to another object
    inner = obj(c, 0x80, {})
    c.emu.w32(o + 8, inner)
    return [o]

S(0x45edb0, 'sub_45edb0', 'thiscall', None, ret='eax', gen=gen_45edb0)
S(0x45f030, 'sub_45f030', 'thiscall', None, ret='eax', gen=gen_45f030)
