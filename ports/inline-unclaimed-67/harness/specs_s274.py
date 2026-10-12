"""specs_s274.py - unclaimed area 67, gap band: 0x5f1580, tail call slot 4 of the object at [this+0xc]+8."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _case(c):
    vt = c.emu.logging_vtable('Nest', 0x140, impl={4: lambda e, a: (c.rng.getrandbits(32), None)}, argwords={4: 0})
    blk = _rnd(c, 0x40)
    obj = blk + 0x0  # the object is at [this+0xc] + 8, so the block starts 8 bytes before it
    o = _rnd(c, 0x80)
    c.emu.w32(o, vt)
    base = o - 8
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0xc, base)
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x5f1580, 'FUN_5f1580 (fwdNested)', 'thiscall', None, ret='eax', gen=_case, note='batch274; tail call slot 4 of [this+0xc]+8')
