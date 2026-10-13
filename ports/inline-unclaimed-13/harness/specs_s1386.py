"""specs_s1386.py - unclaimed-13 claim 5 (docs/20-unclaimed-13.md): CHitpointControl::End (0x583380, GUESS name). The
global pointer at 0x7003b8 is set to a fresh 0xd00-byte object whose count (+0xb61) is 0..15 and whose array (+0xb65)
is random. The value is taken from the array in half the cases (so the removal path runs) and random otherwise."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hp(c):
    g = _rnd(c, 0xd00)
    n = c.rng.randint(0, 15)
    c.emu.w32(g + 0xb61, n)
    c.emu.w32(0x7003b8, g)
    if n and c.rng.random() < 0.5:
        return [c.emu.r32(g + 0xb65 + 4 * c.rng.randrange(n))]
    return [c.rng.getrandbits(32)]


S(0x583380, 'CHitpointControl::End (GUESS) fastcall', 'fastcall', None, ret=None, gen=_hp,
  note='unclaimed-13 claim 5; removes ecx from the array at +0xb65 of the global at 0x7003b8')
