from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec

def gen_54dce0(c):
    # Global at 0x713e19 needs to be allocated and writable
    # Allocate the global region if not already done
    try:
        c.emu.w8(0x713e19, 0x42)
    except:
        pass  # Both sides will fault, which is parity

    # Create a vtable with a hooked slot at 0x18
    vt = c.emu.alloc(0x20, 4)
    hook_addr = 0x700000 + (c.rng.getrandbits(12) << 4)  # Aligned heap address
    c.emu.w32(vt + 0x18, hook_addr)
    hook_rec(c, hook_addr, 1, ret=c.rng.getrandbits(32), this=True)

    # Create object with vtable and field at offset 4
    o = obj(c, 0x100, {0: vt})
    c.emu.w32(o + 4, c.rng.getrandbits(32))

    return [o]

S(0x54dce0, 'sub_54dce0', 'thiscall', None, ret='eax', gen=gen_54dce0)
