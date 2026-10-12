"""specs_s277.py - unclaimed area 67, gap band: two stores (0x5f33d0 with two arguments, 0x600240 copying a triple)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _two(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _src(c):
    o = _rnd(c, 0x100)
    src = _rnd(c, 0x20)
    c.emu.mu.ctl_flush_tb()
    return [o, src]


S(0x5f33d0, 'FUN_5f33d0 (setPair33)', 'thiscall', None, ret=None, gen=_two, note='batch277; stores a, a, a+b, b and a flag byte')
S(0x600240, 'FUN_600240 (copyTriple240)', 'thiscall', None, ret=None, gen=_src, note='batch277; copies a triple from the argument')
