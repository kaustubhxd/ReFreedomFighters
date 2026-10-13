"""specs_s3537.py - claim 37: 0x5c56c0 CTargetObtained::Load(ZLoadGame*). Stubs: 0x6352f0 (thiscall, one pointer arg, writes a
value W through it), 0x5c56f0 (thiscall, one arg, logs ecx and the pointed value)."""
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


def _write_w(c, W):
    return ss.code(c, b'\x8b\x54\x24\x04' + b'\xc7\x02' + struct.pack('<I', W) + b'\xc2\x04\x00')


def _log_deref(c):
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x89\x0d' + ss.P(cells)                              # mov [cells], ecx
            + b'\x8b\x44\x24\x04' + b'\x8b\x00' + b'\xa3' + ss.P(cells + 4)   # mov eax,[esp+4]; mov eax,[eax]; mov [cells+4], eax
            + b'\xb8' + ss.P(0) + b'\xc2\x04\x00')
    return ss.code(c, code)


def _gen(c):
    W = c.rng.getrandbits(32)
    ss.patch(c, 0x6352f0, _write_w(c, W))
    ss.patch(c, 0x5c56f0, _log_deref(c))
    obj = _rnd(c, 0x200)
    return [obj, c.rng.getrandbits(32)]


S(0x5c56c0, 'CTargetObtained::Load(ZLoadGame*) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='claim 37; 0x6352f0 and 0x5c56f0 stubbed (GUESS)')
