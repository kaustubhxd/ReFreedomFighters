"""specs_s6550.py - unclaimed-68 batch 55 (claim 56): 0x438c20 (GUESS name ZInputActions::GetActionID), thiscall, no args, returns the slot +0x58 result."""
from pilot import S
from engine_stubs import zero_obj


def _gen(c):
    o = zero_obj(c, 0x100)
    val = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('GuessInputActions', 0x80, impl={0x58: lambda e, a: (val, None)}, argwords={0x58: 0})
    c.emu.w32(o, vt)
    return [o]


S(0x438c20, 'ZInputActions::GetActionID (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-68 batch 55; tail jump to vtable slot +0x58 (no args)')
