"""specs_s3502.py - area 35 claim 2 (docs/20-unclaimed-35.md): CFFCoverList::Load (0x587fe0).

Stubbed (unverified, not lifted):
- 0x5887e0 (reserve, thiscall, one argument): logs ecx and the count.
- 0x5885c0 (insert, thiscall, two arguments): logs ecx and the first argument; the second is a stack address and is not logged.
- 0x5df1c0 (fill a record, thiscall, one argument): copies a per-case 0x48-byte table into the record (ecx, a stack address),
  and logs ecx and the load object.
- The load object's slot +0x48 writes a count (0..3) through its stack-address argument; slot +0x40 writes a per-case value.
- The render sub-object's slots +0x4c and +0x58 are logged (one argument each; return per-case values).
The cover list (self) is 0x200 random bytes: its begin is a heap array; the end is that array; the capacity is either the
array's end (insert path) or four records past it (append path), drawn per case. The global at 0x7003b8 is 0x2c30 bytes."""
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


def _insert_log(c):
    """thiscall, two arguments: logs ecx and arg0 only (arg1 is a stack address)."""
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x89\x0d' + ss.P(cells)
            + b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells + 4)
            + b'\xb8' + ss.P(0) + b'\xc2\x08\x00')
    return ss.code(c, code)


def _fill_record(c, table):
    """thiscall, one argument (the load object): logs arg0 (ecx is a stack address), copies the 0x48-byte table into [ecx] (a stack local)."""
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    tab = c.emu.alloc(len(table), 4)
    c.emu.wbytes(tab, bytes(table))
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells + 4)   # mov eax, [esp+4] ; mov [cells+4], eax (ecx is a stack address: not logged)
            + b'\x56' + b'\x57'                            # push esi ; push edi
            + b'\xbe' + ss.P(tab)                          # mov esi, tab
            + b'\x89\xcf'                                  # mov edi, ecx
            + b'\xb9' + ss.P(0x48)                         # mov ecx, 0x48
            + b'\xf3\xa4'                                  # rep movsb
            + b'\x5f' + b'\x5e'                            # pop edi ; pop esi
            + b'\xb8' + ss.P(0)                            # mov eax, 0
            + b'\xc2\x04\x00')                             # ret 4
    return ss.code(c, code)


def _writer_value(c, value):
    """thiscall, one stack-address argument: stores value through it, ret 4."""
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\xb9' + ss.P(value) + b'\x89\x0a' + b'\xc2\x04\x00')


def _load(c):
    self_obj = _rnd(c, 0x200)
    g = _rnd(c, 0x2c30)
    c.emu.w32(0x7003b8, g)
    ss.patch(c, 0x5887e0, _thiscall_log(c, 1, 0))
    ss.patch(c, 0x5885c0, _insert_log(c))
    k = c.rng.randrange(0, 4)
    table = bytes(c.rng.getrandbits(8) for _ in range(0x48))
    ss.patch(c, 0x5df1c0, _fill_record(c, table))
    buf = _rnd(c, 0x48 * 4)
    c.emu.w32(self_obj + 0x44, c.rng.getrandbits(32))
    c.emu.w32(self_obj + 0x5f, buf)
    c.emu.w32(self_obj + 0x63, buf)
    c.emu.w32(self_obj + 0x67, buf if c.rng.random() < 0.5 else buf + 0x48 * 4)
    zsub = c.emu.fake_vtable('ZCoverLoad', 0x80, {0x40: _writer_value(c, c.rng.getrandbits(32)),
                                                   0x48: _writer_value(c, k)})
    zload = _rnd(c, 0x40)
    c.emu.w32(zload, zsub)
    sub = _rnd(c, 0x200)
    subvt = c.emu.fake_vtable('ZCoverRenderSub', 0x140, {
        0x4c: _thiscall_log(c, 1, c.rng.getrandbits(32)),
        0x58: _thiscall_log(c, 1, c.rng.getrandbits(32)),
    })
    c.emu.w32(sub, subvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, sub)
    c.emu.w32(0x70039c, rm)
    return [self_obj, zload]


S(0x587fe0, 'CFFCoverList::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_load,
  note='area 35 claim 2; 0x5887e0, 0x5885c0, 0x5df1c0 stubbed; load slots +0x40 and +0x48 are writers; render slots logged')
