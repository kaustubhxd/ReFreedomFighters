"""specs_s1142.py - unclaimed-11 batch 43 (slice 10): 0x566ee0 (GUESS), thiscall, no args.
Calls 0x5672c0 with this as ecx and the dword at this+0x198 as its one argument (stubbed: rec, one argument, callee pops), then
calls this vtable slot 0xd0 with the argument 0 (rec stub, one argument). The object is 0x200 random bytes with its vtable."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = ss.mkobj(c, {0xd0: ss.rec(c, 1)}, size=0x200)
    c.emu.w32(o + 0x198, c.rng.getrandbits(32))
    ss.patch(c, 0x5672c0, ss.rec(c, 1))
    return [o]


S(0x566ee0, 'GUESS (no name) call 0x5672c0 then vt[0xd0](0) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 43 (slice 10); 0x5672c0 stubbed')
