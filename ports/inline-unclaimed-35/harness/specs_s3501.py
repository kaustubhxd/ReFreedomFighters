"""specs_s3501.py - area 35 claim 1 (docs/20-unclaimed-35.md): CFFCoverList::Save (0x588120).

Stubbed (unverified): 0x5df440 (the per-record save, thiscall, one argument), a code stub that logs ecx and its argument in
heap cells and returns ret 4. The save object's slots +0x3c (count) and +0x64 (one argument) are logged. The cover list
(self) is 0x100 random bytes; its start and end (+0x5f, +0x63) point into a heap array of 0x48-byte records, with the
record count 0..12 per case (wide enough that a wrong divisor changes the count) (end - start is a multiple of 0x48, as the loop needs)."""
import os
import struct
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _thiscall_log(c, nargs, ret):
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _save(c):
    self_obj = _rnd(c, 0x100)
    k = c.rng.randrange(0, 13)
    recs = _rnd(c, 0x48 * 13 + 0x10)
    c.emu.w32(self_obj + 0x5f, recs)
    c.emu.w32(self_obj + 0x63, recs + 0x48 * k)
    c.emu.w32(self_obj + 0x6f, c.rng.getrandbits(32))
    ss.patch(c, 0x5df440, _thiscall_log(c, 1, 0))
    zsave = _rnd(c, 0x40)
    zvt = c.emu.logging_vtable('ZSave', 0x80, impl={}, argwords={0x3c: 1, 0x64: 1})
    c.emu.w32(zsave, zvt)
    return [self_obj, zsave]


S(0x588120, 'CFFCoverList::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='area 35 claim 1; 0x5df440 stubbed (logs ecx and argument); save slots +0x3c and +0x64 logged')
