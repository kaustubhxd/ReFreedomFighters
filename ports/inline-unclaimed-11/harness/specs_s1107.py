"""specs_s1107.py - unclaimed-11 batch 7 (core-todo residue-10): CCheckInsideBox::Save(ZSaveGame*) at 0x5b82e0, thiscall,
ret 4, returns true. The body clears bit 0x40 of this+4 and then makes five save calls on the ZSaveGame, in this order:
slot 0x3c(this+0x48), slot 0x3c(this+0x4c), slot 0x64(this+0x50), slot 0x64(this+0x54), slot 0x3c(this+0x5c). One rec
stub (serial_stubs) serves both slots so its ring logs the five values in order. The save object is a serial_stubs.save_obj
(unverified callees, stubbed). The object is 0x80 random bytes."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _save(c):
    o = c.emu.alloc(0x80, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    r = ss.rec(c, 1)
    sv = ss.save_obj(c, {0x3c: r, 0x64: r})
    return [o, sv]


S(0x5b82e0, 'CCheckInsideBox::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-11 batch 7 (residue 10); save object stubbed')
