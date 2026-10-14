from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_4d61c0(c):
    # stdcall(arg) ret 4: compares [arg+0x42e] with 1, returns 1 or 0
    o = obj(c, 0x500, {})
    val = 1 if c.rng.getrandbits(1) else c.rng.getrandbits(32)
    c.emu.w32(o + 0x42e, val)
    return [o]

def gen_52cf00(c):
    # thiscall(this, arg_byte) ret 4: swap byte at [ecx+0x10]
    o = obj(c, 0x100, {})
    # Initialize byte at 0x10
    old_byte = c.rng.getrandbits(8)
    c.emu.w8(o + 0x10, old_byte)
    new_byte = c.rng.getrandbits(8)
    return [o, new_byte]

def gen_582730(c):
    # thiscall(this, arg) ret 4: copy [arg+0x48] to [ecx+0x48]
    this_obj = obj(c, 0x100, {})
    arg_obj = obj(c, 0x100, {})

    # Put some value at offset 0x48 in both objects
    val = c.rng.getrandbits(32)
    c.emu.w32(arg_obj + 0x48, val)
    # this_obj's 0x48 will be overwritten, so initialize differently
    c.emu.w32(this_obj + 0x48, c.rng.getrandbits(32))

    return [this_obj, arg_obj]

S(0x4d61c0, 'sub_4d61c0', 'stdcall', None, ret='eax', gen=gen_4d61c0)
S(0x52cf00, 'sub_52cf00', 'thiscall', 1, ret='eax', gen=gen_52cf00)
S(0x582730, 'sub_582730', 'thiscall', 1, ret='eax', gen=gen_582730)
