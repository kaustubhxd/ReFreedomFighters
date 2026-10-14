from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_4632c0(c):
    # thiscall, reads [ecx+8] and calls ext_4db2c0
    hook_rec(c, 0x4db2c0, 1, ret=c.rng.getrandbits(32), this=True)
    o = obj(c, 0x100, {})
    inner = obj(c, 0x80, {})
    c.emu.w32(o + 8, inner)
    return [o]

def gen_4673c0(c):
    # thiscall, reads field at offset 0x25 and compares with 0x7fffffff
    o = obj(c, 0x100, {})
    # Put a random value at offset 0x25 that may or may not be 0x7fffffff
    if c.rng.getrandbits(1):
        c.emu.w32(o + 0x25, 0x7fffffff)  # Return 0
    else:
        c.emu.w32(o + 0x25, c.rng.getrandbits(31))  # Return address
    return [o]

S(0x4632c0, 'sub_4632c0', 'thiscall', None, ret='eax', gen=gen_4632c0)
S(0x4673c0, 'sub_4673c0', 'thiscall', None, ret='eax', gen=gen_4673c0)
