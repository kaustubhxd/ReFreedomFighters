"""specs_s268.py - unclaimed area 67, slice 6: a constructor (writes a global) and a conditional pair store (ret 0xc)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ctor(c):
    o = _rnd(c, 0x100)
    c.emu.mu.ctl_flush_tb()
    return [o]


def _pair(c):
    o = _rnd(c, 0x100)
    a = c.rng.choice([0, 1, 0x1234, c.rng.getrandbits(32)])
    b = c.rng.choice([0, 2, 0x5678, c.rng.getrandbits(32)])
    if c.rng.random() < 0.4:
        c.emu.w32(o + 0xeb, a)
        c.emu.w32(o + 0xf3, b if c.rng.random() < 0.5 else (b ^ 1))
    c.emu.mu.ctl_flush_tb()
    return [o, a, b, c.rng.getrandbits(32)]


S(0x435ae0, 'FUN_435ae0 (ctorBlock)', 'thiscall', None, ret='eax', gen=_ctor, note='batch268; ctor, global 0x7003a0 = this')
S(0x5edc20, 'FUN_5edc20 (setPair)', 'thiscall', None, ret=None, gen=_pair, note='batch268; pair store, ret 0xc')
