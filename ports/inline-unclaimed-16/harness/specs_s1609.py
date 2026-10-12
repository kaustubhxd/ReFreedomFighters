"""specs_s1609.py - unclaimed-16 batch 9 (docs/20-unclaimed-16.md): ZInputActions::CheckAction(ZInputAction*, void*).
The callee 0x437d60 is patched per case to a recording stub (no stack arguments) that returns a chosen low byte, so the
exe and the port see the same result. The callee itself is NOT verified."""
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


def _check(c):
    ss.patch(c, 0x437d60, ss.rec(c, 0, ret=c.rng.choice([0, 1, 0x100, 0x101, c.rng.getrandbits(32)])))
    obj = _rnd(c, 0x1400)
    c.emu.w32(obj + 0x120c, c.rng.choice([0, 0, 1, c.rng.getrandbits(32)]))
    action = 0 if c.rng.random() < 0.2 else _rnd(c, 0x100)
    return [obj, action, c.rng.choice([0, c.rng.getrandbits(32)])]


S(0x437f70, 'ZInputActions::CheckAction (unknown) thiscall', 'thiscall', None, ret='al', gen=_check,
  note='unclaimed-16 b9; callee 0x437d60 stubbed (not verified); second argument unused')
