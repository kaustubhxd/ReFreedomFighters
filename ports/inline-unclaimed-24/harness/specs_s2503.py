"""specs_s2503.py - decomp area 24, batch 2503.
0x50af30 (GUESS registry handler filler): thiscall, ret 4.
Fills a 50-element registry array with 19 different handler function pointers.
Stores different handlers in each iteration while a flag byte at param+0xc is non-zero.
When the registry is full (counter >= 0x32), calls overflow handler via vtable slot 0x44.
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _gen(c):
    clear_hooks(c)
    r = c.rng

    # Set up globals
    # 0x7011f8 = counter (registry index)
    # 0x701200 = registry array (50 dwords)
    # 0x7003b0 = logger function pointer

    c.emu.w32(0x7011f8, 0)  # Start with counter = 0

    # Clear registry
    for i in range(50):
        c.emu.w32(0x701200 + i*4, 0)

    # Set logger to a valid recorder
    hook_rec(c, 0x7003b0, 0)  # cdecl, no args

    # Hook the vtable overflow handler at slot 0x44
    # Create a vtable with a mock handler
    vtable_addr = rnd(c, 0x100)
    # Set vtable[0x44/4] to call a recorder
    c.emu.w32(vtable_addr + 0x44, 0x633654)  # Call a known func
    hook_rec(c, 0x633654, 0)  # cdecl handler, no args

    # Create the "this" object with the vtable
    this_obj = rnd(c, 0x100)
    c.emu.w32(this_obj, vtable_addr)

    # Create the parameter object
    # It needs a flag byte at offset 0xc that starts non-zero
    param_obj = rnd(c, 0x100)
    c.emu.w8(param_obj + 0xc, 1)  # Set flag to non-zero to enter the loop

    # Return [this_obj, param_obj] for thiscall
    # (this will be passed as ecx and on stack respectively)
    return [this_obj, param_obj]


S(0x50af30, 'GUESS registry handler filler', 'thiscall', None, ret='eax', gen=_gen, note='batch2503')
