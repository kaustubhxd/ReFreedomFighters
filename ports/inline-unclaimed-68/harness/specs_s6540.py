"""specs_s6540.py - unclaimed-68 batch 54 (claims 54, 55). Both names are GUESS.
0x488ba0: thiscall, no args, plain ret; stores vt+0x58(0x68d420) at this+0x1d. The object's vtable logs slot +0x58 (one argument).
0x5c2790: fastcall with the value in ecx, plain ret; appends it to the list at [0x7003b8] (count at +0xbe5, entries from +0xbe9)."""
from pilot import S
from engine_stubs import zero_obj, set_global


def _thiscall_obj(c):
    o = zero_obj(c, 0x100)
    val = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('GuessSlotObj', 0x80, impl={0x58: lambda e, a: (val, None)}, argwords={0x58: 1})
    c.emu.w32(o, vt)
    c.emu.wbytes(o + 0x1d, bytes(c.rng.getrandbits(8) for _ in range(4)))
    return [o]


def _list_gen(c):
    lst = zero_obj(c, 0x1000)
    c.emu.w32(lst + 0xbe5, c.rng.randrange(0, 200))
    set_global(c, 0x7003b8, lst)
    return [c.rng.getrandbits(32)]


S(0x488ba0, 'FUN_488ba0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_thiscall_obj,
  note='unclaimed-68 batch 54; stores vt slot +0x58 result at this+0x1d')
S(0x5c2790, 'FUN_5c2790 (GUESS) fastcall', 'fastcall', None, ret=None, gen=_list_gen,
  note='unclaimed-68 batch 54; global list append at [0x7003b8]')
