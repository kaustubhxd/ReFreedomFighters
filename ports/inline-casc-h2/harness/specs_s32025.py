from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_4d4040(c):
    # thiscall, adds offset 0x10db, reads vtable, jumps to [vtable+0]
    # Create large object to hold the offset
    o = obj(c, 0x11000, {})  # Size >= 0x10db + 4

    # At offset 0x10db, place a vtable pointer
    vt = c.emu.alloc(0x40, 4)
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    c.emu.w32(vt + 0, hook_addr)  # First vtable slot
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)

    c.emu.w32(o + 0x10db, vt)

    return [o]

S(0x4d4040, 'sub_4d4040', 'thiscall', None, ret='eax', gen=gen_4d4040)
