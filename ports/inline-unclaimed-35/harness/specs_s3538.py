"""specs_s3538.py - claim 38: 0x5b2ac0 ZActionControlMap::~ZActionControlMap() (SEH not reproduced; the null-hook int3 is not
reproduced, the hook is always installed). Stubs: 0x5b2a00 (thiscall, no args, logs ecx), 0x4690b0 (cdecl, two args, logs them),
the hook at [0x7003b0] (cdecl, no args, counts calls)."""
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


def _log_ecx_ret0(c):
    cells = c.emu.alloc(4, 4)
    c.emu.wbytes(cells, bytes(4))
    return ss.code(c, b'\x89\x0d' + ss.P(cells) + b'\xb8' + ss.P(0) + b'\xc2\x00\x00')


def _cdecl2(c):
    cells = c.emu.alloc(8, 4)
    c.emu.wbytes(cells, bytes(8))
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cells)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cells + 4)
            + b'\xc3')
    return ss.code(c, code)


def _hook(c):
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    return ss.code(c, b'\xff\x05' + ss.P(cnt) + b'\xc3')


def _gen(c):
    ss.patch(c, 0x5b2a00, _log_ecx_ret0(c))
    ss.patch(c, 0x4690b0, _cdecl2(c))
    c.emu.w32(0x7003b0, _hook(c))
    return [_rnd(c, 0x200), c.rng.choice([0, 1, 2, 3, 4, 5, 7, 0x10, 0x11])]


S(0x5b2ac0, 'ZActionControlMap::~ZActionControlMap() thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='claim 38; SEH not reproduced; base dtor, helper and hook stubbed')
