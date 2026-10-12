"""specs_s603.py - unclaimed-06 claim 3 (docs/20-unclaimed-06.md): ZActor::GetMoveFlags(unsigned int) const.
Thiscall, one argument, ret 4. The argument is random, with the values 0, 1..19 and the high end drawn often so every
jump-table slot and the default path run. The object is 0x800 random bytes (the function does not read it)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    r = c.rng.random()
    if r < 0.6:
        arg = c.rng.randint(0, 24)
    else:
        arg = c.rng.getrandbits(32)
    return [_rnd(c, 0x800), arg]


S(0x478c90, 'ZActor::GetMoveFlags (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-06 claim 3; jump table on arg-1, 0x40c for 6..10, 0x400 otherwise, ret 4')
