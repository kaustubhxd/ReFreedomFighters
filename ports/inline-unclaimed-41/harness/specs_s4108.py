"""specs_s4108.py - unclaimed-41 batch 8 (slice 13): 0x557c90 (thiscall, one stack argument, ret 4).

The array accessor 0x5003d0 is the ORIGINAL code: the structs are built so every index is in range. Struct S = [data D, offset,
count]; D = [table T, _, limit 0x100]; T is 0x80 random bytes. S (x+4): offset 0, count 4; S2 (x+8): offset 0, count 1.
0x59dae0 (five stack arguments, ret 0x14) and 0x5002f0 (one argument, ret 4) are checksum stubs (GUESS). Faulting cases must be
0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _struct(c, count):
    t = _rnd(c, 0x80)
    d = _rnd(c, 0x20)
    c.emu.w32(d, t)
    c.emu.w32(d + 8, 0x100)
    st = _rnd(c, 0x20)
    c.emu.w32(st, d)
    c.emu.w32(st + 4, 0)
    c.emu.w32(st + 8, count)
    return st


def _fn(c):
    s, _, _ = hs.stub(c, 5, ecx=True, edx=False)
    ss.patch(c, 0x59dae0, s)
    s, _, _ = hs.stub(c, 1, ecx=True, edx=False)
    ss.patch(c, 0x5002f0, s)
    self_ = _rnd(c, 0x100)
    x = _rnd(c, 0x20)
    c.emu.w32(x + 4, _struct(c, 4))
    c.emu.w32(x + 8, _struct(c, 1))
    return [self_, x]


S(0x557c90, 'fn557c90 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-41 batch 8; 0x5003d0 is original code; 0x59dae0 and 0x5002f0 are checksum stubs (GUESS)')
