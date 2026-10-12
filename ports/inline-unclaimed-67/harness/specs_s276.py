"""specs_s276.py - unclaimed area 67, gap band: 0x5fc010 (first vtable entry of the object at [this+0x30] when its count is nonzero)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _case(c):
    obj = _rnd(c, 0x40)
    vt = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    c.emu.w32(obj + 8, c.rng.choice([0, 1, 2, 0x10, c.rng.getrandbits(32)]))
    c.emu.w32(vt, c.rng.getrandbits(32))
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x30, obj)
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x5fc010, 'FUN_5fc010 (firstVtableEntry)', 'thiscall', None, ret='eax', gen=_case, note='batch276; vt[0] of [this+0x30] when its count is nonzero')
