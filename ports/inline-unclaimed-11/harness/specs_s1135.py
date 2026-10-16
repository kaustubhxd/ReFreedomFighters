"""specs_s1135.py - unclaimed-11 batch 36: 0x5a5c80 (GUESS, no name), thiscall, three stack args (ret 0xc).
obj = dword at this+0x62c; the PC pushes the third argument and calls 0x5ef040 with ecx = obj. 0x5ef040 is original code: it
sets ecx to [obj+0xc] and jumps to 0x5ac940, which is stubbed (rec, one argument, ret 4) so the stub pops the argument.
The object is 0x700 random bytes; obj is 0x40 bytes with a random +0xc."""
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
    c.emu.w32(o + 0x62c, obj)
    ss.patch(c, 0x5ac940, ss.rec(c, 1))
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5a5c80, 'GUESS (no name) forward third arg to dispatcher thiscall ret 0xc', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 36; 0x5ac940 stubbed')
