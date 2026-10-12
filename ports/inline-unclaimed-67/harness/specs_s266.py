"""specs_s266.py - unclaimed area 67, slice 6: three pure functions (fastcall float pair, thiscall flag, stdcall compare)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sub(c):
    out = _rnd(c, 0x10)
    b = _rnd(c, 0x10)
    a = _rnd(c, 0x10)
    c.emu.mu.ctl_flush_tb()
    return [out, b, a]


def _flag(c):
    o = _rnd(c, 0x100)
    c.emu.w32(o + 0x18, c.rng.choice([0, 1, 4, 0x5, 0xa, 0xb, 0x14, c.rng.getrandbits(32)]))
    c.emu.mu.ctl_flush_tb()
    return [o, c.rng.choice([0, 1, 0x80000000, c.rng.getrandbits(32)])]


def _cmp(c):
    c.emu.mu.ctl_flush_tb()
    return [c.rng.choice([8, 6, 7, 0, 1, 5, 9, c.rng.getrandbits(32)])]


S(0x4dffe0, 'FUN_4dffe0 (subVec2)', 'fastcall', None, ret=None, gen=_sub, note='batch266; out = b - a (two floats)')
S(0x43e5a0, 'FUN_43e5a0 (setFlagBit2)', 'thiscall', None, ret=None, gen=_flag, note='batch266; bit 2 of +0x18 when bits 1 and 3 clear')
S(0x479060, 'FUN_479060 (isMoveKind)', 'stdcall', None, ret='al', gen=_cmp, note='batch266; 1 for 6, 7, 8')
