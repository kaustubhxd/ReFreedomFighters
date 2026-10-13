"""specs_s6203.py - unclaimed-62 claim 2 (residue 03): ZKillBox::CopyEventDataBlock (0x5b1bf0). The DBREAD operators (u32 0x4e5e60, u16 0x4e5e40)
come from serial_stubs.dbread_patch (sequences per run). The byte read 0x4e5ef0 is a stub (other claims' code). The message table's slots
0x58 and 0x4c are logged. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, vtable


def _kb(c):
    e = c.emu
    r = c.rng
    # the u32 sequence: flags, the dword, the third value (zero about half the time, so the 0x4c path runs)
    u32s = [r.choice([0, 1, 0x7f, r.getrandbits(32)]) for _ in range(8)]
    u16s = [r.getrandbits(16) for _ in range(8)]
    ss.dbread_patch(c, u32s, u16s, [0] * 8)
    ss.patch(c, 0x4e5ef0, ss.rec(c, 0, ret=r.getrandbits(8)))
    objret = r.getrandbits(32)
    ret4c = r.getrandbits(32)
    msg = e.alloc(0xb00)
    e.w32(msg, vtable(c, 'killmsg', 0x40, impl={0x58: lambda em, a: objret, 0x4c: lambda em, a: ret4c},
                      argwords={0x58: 1, 0x4c: 1}))
    sysi = e.alloc(0xa0)
    e.w32(sysi + 0x9b, msg)
    e.w32(0x70039c, sysi)
    self_ = rnd(c, 0x100)
    rd = e.alloc(0x20)
    return [self_, rd]


S(0x5b1bf0, 'ZKillBox::CopyEventDataBlock', 'thiscall', None, gen=_kb, n=1000)
