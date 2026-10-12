"""specs_s1905.py - unclaimed-66 batch 1905: five slice-5 leaves (GUESS names), thiscall, no stack arguments.

Each object is random bytes; the sub-object for 0x49a4d0 (at +0xc, then +0xc) is a random 0x40-byte object, and the object
for 0x54bb90 is 0xa300 bytes so that +0xa274 is inside it."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _obj(c):
    return [_rnd(c, 0x100)]


def _chain(c):
    inner = _rnd(c, 0x40)
    obj = _rnd(c, 0x100)
    c.emu.w32(obj + 0xc, inner)
    return [obj]


def _big(c):
    return [_rnd(c, 0xa300)]


S(0x440b10, 'GUESS FUN_00440b10 (leaf float getter)', 'thiscall', None, ret='st0', gen=_obj,
  note='unclaimed-66 batch 1905; slice-5 leaf (GUESS name)')
S(0x49a4d0, 'GUESS FUN_0049a4d0 (leaf chained getter)', 'thiscall', None, ret='eax', gen=_chain,
  note='unclaimed-66 batch 1905; slice-5 leaf (GUESS name)')
S(0x54bb90, 'GUESS FUN_0054bb90 (leaf getter at +0xa274)', 'thiscall', None, ret='eax', gen=_big,
  note='unclaimed-66 batch 1905; slice-5 leaf (GUESS name)')
S(0x600810, 'GUESS FUN_00600810 (leaf difference)', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-66 batch 1905; slice-5 leaf (GUESS name)')
S(0x4cdc90, 'GUESS FUN_004cdc90 (leaf zero store)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1905; slice-5 leaf (GUESS name)')
