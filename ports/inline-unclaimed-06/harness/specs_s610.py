"""specs_s610.py - unclaimed-06 claim 10 (docs/20-unclaimed-06.md): ZActionControlMap::Save(ZSaveGame*). Thiscall, one
argument, ret 4. The object is 0x1000 random bytes. The ZSaveGame is a stand-in (serial_stubs.save_obj) with counting rec
stubs on the four slots the exe calls (0x3c, 0x64, 0x4c, 0x44). The function has no original callees."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    self = _rnd(c, 0x1000)
    sg = ss.save_obj(c, {0x3c: ss.rec(c, 1), 0x44: ss.rec(c, 1), 0x4c: ss.rec(c, 1), 0x64: ss.rec(c, 1)})
    return [self, sg]


S(0x5b5310, 'ZActionControlMap::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-06 claim 10; clears bit 0x40 at +4; ZSaveGame slots 0x3c, 0x64, 0x4c, 0x44 via serial stubs')
