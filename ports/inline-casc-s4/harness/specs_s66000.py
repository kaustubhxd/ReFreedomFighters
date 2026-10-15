"""specs_s66000.py - cascade s4 batch 66000: 0x4c5770."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _g4c5770(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    # Set up this object at t+0x48 with vtable
    main_obj = e.alloc(0x100, 4)
    t = rnd(c, 0x60)
    e.w32(t + 0x48, main_obj)

    # Set up this object at t+0x53 with vtable
    obj2 = e.alloc(0x100, 4)
    e.w32(t + 0x53, obj2)

    # Hook the vtable calls
    hook_rec(c, main_obj + 0x4c, 1, pop=0)  # slot 0x4c(local_addr)
    hook_rec(c, main_obj + 0x5c, 1, pop=0)  # slot 0x5c(local_addr)
    hook_rec(c, main_obj + 0x80, 2, pop=0)  # slot 0x80(&local2, &local3)
    hook_rec(c, obj2 + 0x21c, 3, pop=0)     # slot 0x21c(arg, &local2, &local3)

    arg = r.getrandbits(32)
    return [t, arg]


S(0x4c5770, 'GUESS engine loop vtable', 'thiscall', None, ret=None, gen=_g4c5770, note='batch66000')
