"""specs_s1607.py - unclaimed-16 batch 7 (docs/20-unclaimed-16.md): ZInputActions::GetActionBase. The lookup helper
0x4d8fc0 is patched per case to a recording stub (serial_stubs.rec) that returns a chosen object pointer, so the exe
and the port see the same result. The helper itself is NOT verified here."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _base(c):
    # The null page is mapped in this emulator but its content is not zero; a port that reads through a null result
    # would see that content. Zero the two dwords the function reads (p+0 and p+8 with p = 0) so a missing null test
    # shows as a store the exe does not make.
    pass   # TEB fix: page 0 is unmapped now, a NULL read faults
    pass   # TEB fix: page 0 is unmapped now, a NULL read faults
    ptr = 0
    if c.rng.random() < 0.8:
        ptr = _rnd(c, 0x20)
        c.emu.w32(ptr, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)]))
        c.emu.w32(ptr + 8, c.rng.choice([0, 4, 5, 0x20, c.rng.getrandbits(32)]))
    ss.patch(c, 0x4d8fc0, ss.rec(c, 1, ret=ptr))
    obj = _rnd(c, 0x1400)
    c.emu.w32(obj + 0x1330, _rnd(c, 0x40))
    return [obj, c.rng.getrandbits(32)]


S(0x438bc0, 'ZInputActions::GetActionBase (unknown) thiscall', 'thiscall', None, ret='eax', gen=_base,
  note='unclaimed-16 b7; helper 0x4d8fc0 stubbed (not verified); dword 0/1 stores (+8)-4 at +0x1334')
