"""specs_s1134.py - unclaimed-11 batch 35: 0x5a5c60 (GUESS, no name), thiscall, no args.
obj = dword at this+0x62c. The PC calls 0x5ef050(obj, 1) (stubbed: rec, one argument) and then tail-jumps through obj's
vtable slot 0x8 (the port calls it and returns). The vtable slot 0x8 is a rec stub with no arguments. The object is 0x700 random
bytes; obj is 0x40 random bytes."""
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
    obj = ss.mkobj(c, {0x8: ss.rec(c, 0)}, size=0x40)
    c.emu.w32(o + 0x62c, obj)
    ss.patch(c, 0x5ef050, ss.rec(c, 1))
    return [o]


S(0x5a5c60, 'GUESS (no name) call helper then tail virtual slot 8 thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 35; 0x5ef050 stubbed')
