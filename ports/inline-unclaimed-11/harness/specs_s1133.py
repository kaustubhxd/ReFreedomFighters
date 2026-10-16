"""specs_s1133.py - unclaimed-11 batch 34: 0x5ab2a0 (GUESS, no name), thiscall, one stack arg (ret 4).
obj = dword at this+0x648. If arg == 0: obj byte +8 = 0 (the PC calls 0x5acac0, which stores its argument's low byte at +8, and
the port stores it inline). Otherwise 0x5ac940(obj, arg) runs (stubbed: rec, one argument; it is a dispatcher on the object's
+0x6a in the PC), then obj byte +8 = 1. The object is 0x700 random bytes; obj is 0x40 bytes; arg is 0 in a third of cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x700, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x700)))
    obj = c.emu.alloc(0x40, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(o + 0x648, obj)
    ss.patch(c, 0x5ac940, ss.rec(c, 1))
    arg = 0 if c.rng.random() < 0.33 else c.rng.getrandbits(32)
    return [o, arg]


S(0x5ab2a0, 'GUESS (no name) flag byte on object at +0x648 thiscall ret 4', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 34; 0x5ac940 stubbed')
