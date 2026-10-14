"""specs_s1139.py - unclaimed-11 batch 40 (slice 10): 0x656760 (GUESS), thiscall, one stack arg (ret 4), returns a word.
The object's vtable slot 0xc is called with the argument (thiscall stub, returns a pointer P); the result is the word at P+2
(zero-extended). P is a 0x40-byte buffer. The object is serial_stubs.mkobj with a rec stub for slot 0xc."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _gen(c):
    p = c.emu.alloc(0x40, 4)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    o = ss.mkobj(c, {0xc: ss.rec(c, 1, ret=p)}, size=0x40)
    return [o, c.rng.getrandbits(32)]


S(0x656760, 'GUESS (no name) word at result+2 of vt[0xc](arg) thiscall ret 4', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-11 batch 40 (slice 10)')
