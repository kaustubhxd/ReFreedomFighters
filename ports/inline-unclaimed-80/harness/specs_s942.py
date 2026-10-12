"""specs_s942.py - unclaimed-80 (docs/20-unclaimed-80.md): GUESS FUN_460bb0 (0x460bb0). The leaf reads a float at this+4, a count at
this+0x10 (0..4, never zero here, so the division is by a nonzero count) and a pointer at this+0xc to items of stride 0x38 with a float
at +0x34. Values are finite; the result is bool (al)."""
import struct
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _leaf(c):
    o = _rnd(c, 0x40)
    c.emu.wf32(o + 4, c.rng.uniform(-1000.0, 1000.0))
    count = c.rng.randint(1, 4)
    c.emu.w32(o + 0x10, count)
    arr = _rnd(c, 0x38 * count + 0x40)
    for i in range(count):
        c.emu.wf32(arr + 0x38 * i + 0x34, c.rng.uniform(-1000.0, 1000.0))
    c.emu.w32(o + 0xc, arr - 0x34 + 0x34)   # the base pointer; items at base + 0x34 + 0x38 i
    return [o]


S(0x460bb0, 'GUESS FUN_460bb0 (unknown) thiscall', 'thiscall', None, ret='al', gen=_leaf,
  note='unclaimed-80 GUESS leaf; bool; stride 0x38, float at +0x34 vs ref = (+4)/count with limit ref*C')
