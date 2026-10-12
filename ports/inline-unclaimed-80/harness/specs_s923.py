"""specs_s923.py - unclaimed-80 claim 3 (docs/20-unclaimed-80.md): ZFenceGate::ReadInput (0x5c2870). DBREAD operators stubbed:
0x4e5e60, 0x4e5e40, GetRefTab 0x4e6330 and REFTAB count via serial_stubs.dbread_patch; 0x4e5ea0 and 0x4e5ef0 by seqr sequences
(one per call, wrapping). The DBREAD's first dword points at a buffer whose first byte is 0xff (25%), low six bits 9 (25%), or
random."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _readinput(c):
    buf = _rnd(c, 0x40)
    r = c.rng.random()
    if r < 0.25:
        c.emu.wbytes(buf, b'\xff')
    elif r < 0.5:
        c.emu.wbytes(buf, bytes([(c.rng.getrandbits(8) & 0xc0) | 0x09]))
    dbr = _rnd(c, 0x40)
    c.emu.w32(dbr, buf)
    ss.dbread_patch(c, [c.rng.getrandbits(32) for _ in range(8)], [c.rng.getrandbits(16) for _ in range(8)], [0])
    ss.patch(c, 0x4e5ea0, ss.seqr(c, 0, [c.rng.getrandbits(32) for _ in range(8)]))
    ss.patch(c, 0x4e5ef0, ss.seqr(c, 0, [c.rng.getrandbits(8) for _ in range(8)]))
    return [_rnd(c, 0x400), dbr]


S(0x5c2870, 'ZFenceGate::ReadInput (unknown) thiscall', 'thiscall', None, ret=None, gen=_readinput,
  note='unclaimed-80 claim 3; DBREAD operators stubbed (0x4e5ea0 and 0x4e5ef0 by seqr)')
