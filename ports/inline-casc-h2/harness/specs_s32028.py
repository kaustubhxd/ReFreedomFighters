from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_61bc70(c):
    # thiscall, reads arg (stack param) and its vtable, jumps to [vtable+0x18]
    # Create dummy this object (unused in this function but required for thiscall)
    this_obj = obj(c, 0x100, {})

    # Create object that will be passed as argument
    arg = obj(c, 0x100, {})

    # Create vtable with hooked slot at offset 0x18 (6 in dwords)
    vt = c.emu.alloc(0x30, 4)
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    c.emu.w32(vt + 0x18, hook_addr)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)

    # Set arg[0] to vtable
    c.emu.w32(arg, vt)

    # Return this_obj as ecx and arg as stack param
    return [this_obj, arg]

S(0x61bc70, 'sub_61bc70', 'thiscall', 1, ret='eax', gen=gen_61bc70)
