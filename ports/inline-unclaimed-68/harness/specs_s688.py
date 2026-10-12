"""specs_s688.py - unclaimed-68 batch 8 (claim 7): 0x4cf1f0 (GUESS FUN_4cf1f0). The object's slot +0x64 logs its argument and returns
a pointer to a block with a fixed dword (about four times in five) or null (the other cases), so both branches run."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _gen(c):
    blk = zero_obj(c, 0x40)
    c.emu.w32(blk, c.rng.getrandbits(32))
    ptr = blk if c.rng.random() < 0.8 else 0
    o = logged_obj(c, 'ZSlotObj', 0x40, impl={0x64: lambda e, a: (ptr, None)}, argwords={0x64: 1})
    return [o, c.rng.getrandbits(32)]


S(0x4cf1f0, 'GUESS FUN_4cf1f0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-68 batch 8; GUESS name; slot +0x64 result dereferenced when non-null')
