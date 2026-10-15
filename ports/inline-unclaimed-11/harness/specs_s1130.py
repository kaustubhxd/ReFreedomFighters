"""specs_s1130.py - unclaimed-11 batch 31 (gap band): 0x5bf9b0 (GUESS, no name), thiscall, one pointer argument (ret 4), returns true.
Order: local = 0; GetInput(&local) (0x6352f0, stdcall, stubbed); this+4 &= ~0x40; this vt[0x84](&local) (rec stub); 0x5bf940(this)
(stubbed, no args); then the argument's vt[0x48](this+0x59), vt[0x48](this+0x6a), vt[0x68](this+0x72).
All callees are rec stubs (unverified; no GC names). The object is 0x100 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    o = ss.mkobj(c, {0x84: ss.rec(c, 1, log=False)}, size=0x100)
    c.emu.w32(o + 4, c.rng.getrandbits(32))
    arg = ss.mkobj(c, {0x48: ss.rec(c, 1), 0x68: ss.rec(c, 1)}, size=0x40)
    ss.patch(c, 0x6352f0, ss.rec(c, 1, log=False))
    ss.patch(c, 0x5bf940, ss.rec(c, 0))
    return [o, arg]


S(0x5bf9b0, 'GUESS (no name) GetInput-driven predicate thiscall ret 4', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-11 batch 31 (gap band); callees stubbed')
