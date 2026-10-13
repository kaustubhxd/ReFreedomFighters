"""specs_s4106.py - unclaimed-41 batch 6 (slice 13): 0x42ac56 (cdecl wrapper over 0x42abbd) and 0x45d290 (thiscall wrapper over
0x45d1e0).

0x42abbd and 0x45d1e0 are checksum stubs (GUESS). The fifth argument of 0x42abbd is a pointer into the wrapper's own frame, so it
is left out of the checksum (the PC and the port have different stack addresses). The cdecl wrapper's arguments are random.
The spec for 0x42ac56 is a cdecl call: the harness pushes its arguments and the wrapper's caller cleans up.
Faulting cases must be 0 (JSON)."""
from pilot import S
import helper_stubs as hs
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _wrap42(c):
    s, _, _ = hs.stub(c, 5, ecx=False, edx=False, mask=[1, 2, 3, 4], cleanup=False)
    ss.patch(c, 0x42abbd, s)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _wrap45(c):
    s, _, _ = hs.stub(c, 2, ecx=True, edx=False)
    ss.patch(c, 0x45d1e0, s)
    o = _rnd(c, 0x100)
    c.emu.w32(o + 8, _rnd(c, 0x80))
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x42ac56, 'wrap42ac56 (GUESS) cdecl', 'cdecl', None, ret='eax', gen=_wrap42,
  note='unclaimed-41 batch 6; 0x42abbd is a checksum stub, cdecl; fifth argument is a stack address (excluded)')
S(0x45d290, 'wrap45d290 (GUESS) thiscall', 'thiscall', None, ret='al', gen=_wrap45,
  note='unclaimed-41 batch 6; 0x45d1e0 is a checksum stub (two arguments)')
