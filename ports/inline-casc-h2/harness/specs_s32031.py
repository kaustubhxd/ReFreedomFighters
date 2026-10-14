from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_4dbbc0(c):
    # thiscall, read field [ecx+0x54], test for null, vtable jump
    # 50% null, 50% valid vtable
    o = obj(c, 0x100, {})
    
    if c.rng.getrandbits(1):
        # Null case
        c.emu.w32(o + 0x54, 0)
    else:
        # Valid vtable case
        field = obj(c, 0x100, {})
        vt = c.emu.alloc(0x20, 4)
        hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
        c.emu.w32(vt + 0x18, hook_addr)
        hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)
        c.emu.w32(field, vt)
        c.emu.w32(o + 0x54, field)
    
    return [o]

S(0x4dbbc0, 'sub_4dbbc0', 'thiscall', None, ret='eax', gen=gen_4dbbc0)
