"""specs_s1137.py - unclaimed-11 batch 38 (gap band): 0x5b7eb0 (GUESS, no name), thiscall, one object argument (ret 4).
Calls the argument's vtable: slot 0x64 with the dword at this+0, slot 0x4c with the float at this+4, slot 0x4c with the float
at this+8, slot 0x64 with the dword at this+0xc. The argument object is serial_stubs.mkobj with rec stubs (no GC names; unverified).
The float arguments are passed as their bits. The object is 0x100 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    arg = ss.mkobj(c, {0x64: ss.rec(c, 1), 0x4c: ss.rec(c, 1)}, size=0x40)
    return [o, arg]


S(0x5b7eb0, 'GUESS (no name) four arg-vtable calls thiscall ret 4', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 38 (gap band)')
