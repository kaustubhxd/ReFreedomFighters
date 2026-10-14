from pilot import S
from recruits_util import obj, hook_rec

def gen_466400(c):
    # thiscall: nested dereference with vtable jump
    # [ecx+0x1ce] -> obj1, [obj1+4] -> obj2, [obj2] -> vtable, jump [vtable+4]

    this_obj = obj(c, 0x200, {})
    obj1 = obj(c, 0x20, {})

    # 50% null case
    if c.rng.getrandbits(1):
        c.emu.w32(this_obj + 0x1ce, 0)
        return [this_obj]

    # 50% valid case with vtable
    obj2 = obj(c, 0x20, {})
    c.emu.w32(this_obj + 0x1ce, obj1)
    c.emu.w32(obj1 + 4, obj2)

    vtable = obj(c, 0x20, {})
    c.emu.w32(obj2, vtable)

    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)
    c.emu.w32(vtable + 4, hook_addr)

    return [this_obj]

S(0x466400, 'sub_466400', 'thiscall', None, ret='eax', gen=gen_466400)
