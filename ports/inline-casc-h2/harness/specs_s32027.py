from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_5f2df0(c):
    # thiscall: reads [ecx+0xc] then [result+4], tail-calls 0x5fc260
    hook_rec(c, 0x5fc260, 1, ret=c.rng.getrandbits(32), this=True)

    # Create outer object with pointer at offset 0xc
    o = obj(c, 0x100, {})
    inner = obj(c, 0x100, {})
    c.emu.w32(o + 0xc, inner)

    # Put a pointer at offset 4 of the inner object
    inner2 = obj(c, 0x80, {})
    c.emu.w32(inner + 4, inner2)

    return [o]

S(0x5f2df0, 'sub_5f2df0', 'thiscall', None, ret='eax', gen=gen_5f2df0)
