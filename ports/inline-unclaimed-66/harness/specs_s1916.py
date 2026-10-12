"""specs_s1916.py - unclaimed-66 batch 1916: GUESS FUN_00628e50 (wrapper of the BOM dispatcher), cdecl(R, pos, end, out).

The dispatcher's table is the exe's global at 0x6f4408: the spec writes 256 entry pointers at 0x6f4408 + 4*i (i = -128..127),
each one of the eight entry objects from batch 1915 (their stubs log (X, pos, end, out)). The R object, the buffer and the
result slot are as in batch 1915; the mode is always 1 for this wrapper (the wrapper passes it)."""
from pilot import S
import specs_s1915 as b15

TABLE = 0x6f4408


def _wrap(c):
    xs = b15._entries(c)
    for i in range(-128, 128):
        c.emu.w32(TABLE + 4 * i, c.rng.choice(xs))
    args = b15._bom(c)
    _, R, _, pos, end, out = args
    return [R, pos, end, out]


S(0x628e50, 'GUESS FUN_00628e50 (wrapper of the BOM dispatcher)', 'cdecl', None, ret='eax', gen=_wrap,
  note='unclaimed-66 batch 1916; wrapper with T = 0x6f4408 (exe global), mode 1')
