from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_45f420(c):
    # thiscall, reads [ecx+8], checks [field+0x50], conditional jump or return 0
    hook_rec(c, 0x4dc130, 1, ret=c.rng.getrandbits(32), this=True)

    # Create outer object with pointer at offset 8
    o = obj(c, 0x100, {})
    inner = obj(c, 0x100, {})
    c.emu.w32(o + 8, inner)

    # Populate inner object with value at 0x50 (offset 0x14 in dwords)
    # 50% chance to trigger the branch
    if c.rng.getrandbits(1):
        c.emu.w32(inner + 0x50, 0x1000)  # Non-zero, call ext_4dc130
    else:
        c.emu.w32(inner + 0x50, 0)       # Zero, return 0

    return [o]

def gen_474700(c):
    # thiscall, reads [ecx] (vtable), jumps through [vtable+0x4f4]
    # Create vtable with hooked slot at offset 0x4f4 (0x13d in dwords)
    vt = c.emu.alloc(0x500, 4)
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    c.emu.w32(vt + 0x4f4, hook_addr)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)

    # Create object with vtable pointer
    o = obj(c, 0x100, {0: vt})

    return [o]

S(0x45f420, 'sub_45f420', 'thiscall', None, ret='eax', gen=gen_45f420)
S(0x474700, 'sub_474700', 'thiscall', None, ret='eax', gen=gen_474700)
