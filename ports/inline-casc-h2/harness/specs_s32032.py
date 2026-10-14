from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_462d00(c):
    # thiscall: reads [ecx+0x6c], reads vtable from field, jumps to [vtable+0x24]
    outer = obj(c, 0x100, {})
    field = obj(c, 0x100, {})
    c.emu.w32(outer + 0x6c, field)

    vtable = obj(c, 0x100, {})
    c.emu.w32(field, vtable)
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)
    c.emu.w32(vtable + 0x24, hook_addr)

    return [outer]

def gen_470540(c):
    # thiscall: reads [ecx+0x94], reads vtable from field, jumps to [vtable+0x3c]
    outer = obj(c, 0x200, {})
    field = obj(c, 0x100, {})
    c.emu.w32(outer + 0x94, field)

    vtable = obj(c, 0x100, {})
    c.emu.w32(field, vtable)
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)
    c.emu.w32(vtable + 0x3c, hook_addr)

    return [outer]

def gen_64fad0(c):
    # thiscall: reads [ecx+0xbd], test for null, jump to [vtable+0x60] or return 0
    outer = obj(c, 0x300, {})  # larger object to ensure valid memory at 0xbd

    # 50% null case
    if c.rng.getrandbits(1):
        c.emu.w32(outer + 0xbd, 0)
        return [outer]

    # 50% vtable case - ensure field is allocated with enough space
    field = obj(c, 0x100, {})
    c.emu.w32(outer + 0xbd, field)

    vtable = obj(c, 0x100, {})
    c.emu.w32(field + 0, vtable)  # write vtable at field[0]
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)
    c.emu.w32(vtable + 0x60, hook_addr)

    return [outer]

S(0x462d00, 'sub_462d00', 'thiscall', None, ret='eax', gen=gen_462d00)
S(0x470540, 'sub_470540', 'thiscall', None, ret='eax', gen=gen_470540)
S(0x64fad0, 'sub_64fad0', 'thiscall', None, ret='eax', gen=gen_64fad0)
