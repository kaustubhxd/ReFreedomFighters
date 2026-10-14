"""specs_s1140.py - unclaimed-11 batch 41 (slice 10): 0x5646e0 (GUESS), thiscall, one stack arg (unused, ret 4).
If the dword at this+0xc82 is 0x20, calls the object's vtable slot 0xfc with the argument 0 (thiscall, one arg: rec stub).
The object is 0x1000 random bytes; the field is 0x20 in about half of cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = ss.mkobj(c, {0xfc: ss.rec(c, 1)}, size=0x1000)
    c.emu.w32(o + 0xc82, 0x20 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [o, c.rng.getrandbits(32)]


S(0x5646e0, 'GUESS (no name) conditional vt[0xfc](0) thiscall ret 4', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 41 (slice 10)')
