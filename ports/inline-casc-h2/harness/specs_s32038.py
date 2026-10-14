from pilot import S
from recruits_util import rnd, obj, hook_rec

def gen_54c300(c):
    # thiscall: reads [ecx+0x50], test for null, jump to [vtable+0x18] or return 0
    o = obj(c, 0x60, {})

    if c.rng.getrandbits(1):
        # Null case
        c.emu.w32(o + 0x50, 0)
        return [o]

    # Vtable case
    field = obj(c, 0x100, {})
    c.emu.w32(o + 0x50, field)

    vtable = obj(c, 0x100, {})
    c.emu.w32(field, vtable)
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)
    c.emu.w32(vtable + 0x18, hook_addr)

    return [o]

S(0x54c300, 'sub_54c300', 'thiscall', None, ret='eax', gen=gen_54c300)
