"""specs_s1128.py - unclaimed-11 batch 29 (gap band): 0x5a45c0 (GUESS, no name), thiscall, one pointer argument (ret 4), returns a
pointer. If the argument is nonnull and its vtable slot 0x1e0 called with 0x2003e8 returns true, the index is the dword at
arg+0x684; if index-1 is 0..3 the result is this+0x99+16*index, else null. The argument is a serial_stubs.mkobj whose slot
0x1e0 is a rec stub returning a random bool byte; the index is -2..6. The object is 0x200 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x200, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x200)))
    if c.rng.random() < 0.1:
        return [o, 0]
    obj = ss.mkobj(c, {0x1e0: ss.rec(c, 1, ret=c.rng.choice([0, 1, 0x100]))}, size=0x800)
    c.emu.w32(obj + 0x684, c.rng.randint(-2, 6) & 0xffffffff)
    return [o, obj]


S(0x5a45c0, 'GUESS (no name) indexed pointer from argument thiscall ret 4', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-11 batch 29 (gap band)')
