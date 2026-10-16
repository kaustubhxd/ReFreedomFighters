"""specs_s5733.py - unclaimed-57, band batch 33: 0x5d8440 (GUESS). Thiscall, no arguments. TAGGED STACK-COMPARE: the object's +0xb3 slot is
compared with the function's frame slot; the spec's object is a heap block, so the not-equal path always runs (the equal path is not
exercised here). The engine (global 0x70039c, +0x40 dword) and the block at global 0x7003a0 (byte +0x79) are heap fakes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tick(c):
    eng = _rnd(c, 0x100)
    c.emu.w32(eng + 0x40, c.rng.getrandbits(32))
    c.emu.w32(0x70039c, eng)
    p = _rnd(c, 0x100)
    c.emu.w32(0x7003a0, p)
    obj = _rnd(c, 0x200)
    return [obj]


S(0x5d8440, 'unnamed_5d8440 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_tick,
  note='unclaimed-57 band batch 33; TAGGED STACK-COMPARE (not-equal path only); engine +0x40 and global 0x7003a0 heap fakes')
