"""specs_s266.py - area 22, batch266 (src/batch266.cpp): CAction::CAction. Engine db vt[0x114] (four words, logged,
per-call random result), vt[0x30] and the float at +0xae0 for the base constructor 0x469870 (exe code). The 13 global
message words (0x7002ac to 0x7002dc) are cleared before each case."""
import struct
from pilot import S
from helpers22 import _rnd, _multi_vt


def _g_49f2d0(c):
    e = c.emu
    db = _rnd(c, 0xb00)
    e.w32(db, _multi_vt(c, {0x114: (lambda em, a: (c.rng.getrandbits(32), None), 4), 0x30: (lambda em, a: (0, None), 1)}))
    e.w32(db + 0xae0, struct.unpack('<I', struct.pack('<f', c.rng.uniform(0.0, 1.2)))[0])
    rm = _rnd(c, 0x100)
    e.w32(rm + 0x9b, db)
    e.w32(0x70039c, rm)
    e.wbytes(0x7002ac, bytes(0x34))
    e.mu.ctl_flush_tb()
    return [_rnd(c, 0x110)]


S(0x49f2d0, 'CAction::CAction', 'thiscall', None, ret='eax', gen=_g_49f2d0,
  note='batch266; base ctor 0x469870 as exe code; SEH frame and cookie not reproduced')
