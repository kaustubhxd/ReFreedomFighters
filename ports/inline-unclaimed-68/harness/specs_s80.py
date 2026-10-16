"""specs_s80.py - unclaimed-68 batch 80 (slice 7). Names GUESS (FUN_addr).
Simple specs that test basic logic paths without complex vtable calls.
"""
from pilot import S
from engine_stubs import zero_obj


def _g57bc70(c):
    # 0x57bc70: thiscall, one argument, ret 4.
    # Reads this+0xc82 (state field) and arg, decides whether to call vtable slot.
    # For now, test with states that DON'T trigger the call.
    self_obj = zero_obj(c, 0xcb0)

    # Use state values that don't trigger vtable call (not 0xa, 0x11, or 0x20)
    state = c.rng.choice([0, 1, 2, 0x100, c.rng.getrandbits(32)])
    c.emu.w32(self_obj + 0xc82, state)
    c.emu.w32(self_obj + 0xcae, c.rng.getrandbits(32))

    # Set up a dummy vtable just in case
    vt = c.emu.logging_vtable('ZSlot57bc70', 0xd8, impl={})
    c.emu.w32(self_obj, vt)

    arg = c.rng.getrandbits(32)
    return [self_obj, arg]


def _g48b4f0(c):
    # 0x48b4f0: stdcall, two arguments, ret 8.
    # Complex function that calls engine vtable slots.
    # For now, just test with null engine vtable to avoid faults.
    c.emu.w32(0x700390, 0)  # NULL engine vtable
    c.emu.w32(0x7003b0, 0)  # NULL hook

    return [0, 0]


S(0x57bc70, 'FUN_57bc70 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g57bc70,
  note='unclaimed-68 batch 80: conditional vtable call (simple path)')
S(0x48b4f0, 'FUN_48b4f0 (GUESS) stdcall', 'stdcall', None, ret='al', gen=_g48b4f0,
  note='unclaimed-68 batch 80: engine vtable calls')
