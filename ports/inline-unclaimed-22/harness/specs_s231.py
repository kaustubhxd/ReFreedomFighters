"""specs_s231.py - unclaimed area 22, batch231 (src/batch231.cpp): 0x46f510 (residue 01).

0x45f3a0 and 0x46f240 are real bodies owned elsewhere. Both are replaced by recorders that store ecx and return 0; this
checks the call order, the object passed to each, and the returned eax of the tail target (random per case).
"""
from pilot import S
import serial_stubs as ss
from helpers22 import _rnd, _rec_ecx, _flush_heap_code, jmp_patch


def _g_46f510(c):
    _rec_ecx(c, 0x45f3a0, 0)
    # the tail target returns a random eax (the port must hand it back); it stores ecx and returns the value
    slot = c.emu.alloc(4, 4)
    c.emu.w32(slot, 0)
    jmp_patch(c, 0x46f240, ss.code(c, b'\x89\x0d' + ss.P(slot) + b'\xb8' + ss.P(c.rng.getrandbits(32)) + b'\xc3'))
    _flush_heap_code(c)
    return [_rnd(c, 0x40)]


S(0x46f510, 'callThenTail (GUESS)', 'thiscall', None, ret='eax', gen=_g_46f510,
  note='batch231; call 0x45f3a0, tail jump 0x46f240 (both stubbed, ecx recorded)')
