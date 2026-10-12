"""specs_s959.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x49da60 (see src/batch959.cpp). The callee 0x49da90 (GUESS, its own
row) is hooked by address with a recording stub (no arguments, returns 0). The counter at +0x18 starts from a value near 0xc8 (about
half the time, so the threshold is crossed) and the byte at +0x28 is zero half the time. The argument is random and unused."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    ss.patch(c, 0x49da90, ss.rec(c, 0, ret=0))
    o = _rnd(c, 0x40)
    r = c.rng.random()
    if r < 0.5:
        c.emu.w32(o + 0x18, c.rng.choice([0xc6, 0xc7, 0xc8]))
    else:
        c.emu.w32(o + 0x18, c.rng.getrandbits(32))
    c.emu.wbytes(o + 0x28, bytes([0 if c.rng.random() < 0.5 else c.rng.randint(1, 255)]))
    return [o, c.rng.getrandbits(32)]


S(0x49da60, 'GUESS counter and call (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-80 gap band; 0x49da60 has one unused stack argument (ret 4); callee 0x49da90 hooked by address (GUESS)')
