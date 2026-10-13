"""specs_s3519.py - area 35 claim 19 (docs/20-unclaimed-35.md): two tail-jump thunks (GUESS names). PARTIAL for 0x535560.

Stubbed: 0x445330 by address (thiscall, no args; tag log of ecx). The thunk 0x535560 jumps through slot +0x208 of this; the
spec's vtable logs that slot (thiscall, no args, returns a per-case eax)."""
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


def _dtor(c):
    ss.patch(c, 0x445330, _thiscall_log(c, 0, 0))
    return [_rnd(c, 0x200)]


def _slot(c):
    o = _rnd(c, 0x200)
    vt = c.emu.logging_vtable('ZTailSlot208', 0x90, impl={0x208: lambda e, a, v=c.rng.getrandbits(32): (v, None)},
                              argwords={0x208: 0})
    c.emu.w32(o, vt)
    return [o]


S(0x5b21a0, 'GUESS thunk to 0x445330 (thiscall)', 'thiscall', None, ret='eax', gen=_dtor,
  note='area 35 claim 19; sets vtable 0x6b1650; 0x445330 stubbed by address (tag log)')
S(0x535560, 'GUESS thunk through slot +0x208 (thiscall) PARTIAL', 'thiscall', None, ret='eax', gen=_slot,
  note='area 35 claim 19; slot target hooked by the fake vtable; arity unverified')
