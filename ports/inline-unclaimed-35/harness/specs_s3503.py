"""specs_s3503.py - area 35 claim 3 (docs/20-unclaimed-35.md): six small leaves in slice 14.

Stubbed (unverified): 0x45fa00 and 0x4dcd10, the tail-jump targets of ZSNDOBJ::Select and ZGEOM::SetPos. Each is a thiscall
stub with one argument (ret 4) that logs ecx and the argument. The objects are 0x1000 random bytes, so every stored field
is compared in the heap. ZGEOM::SetPos's this + 8 points to a second 0x1000-byte object."""
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


def _self(c):
    return [_rnd(c, 0x1000)]


def _self_arg(c):
    return [_rnd(c, 0x1000), c.rng.getrandbits(32)]


def _select(c):
    ss.patch(c, 0x45fa00, _thiscall_log(c, 1, 0))
    return _self_arg(c)


def _setpos(c):
    ss.patch(c, 0x4dcd10, _thiscall_log(c, 1, 0))
    o = _rnd(c, 0x1000)
    sub = _rnd(c, 0x1000)
    c.emu.w32(o + 8, sub)
    return [o, c.rng.getrandbits(32)]


S(0x481920, 'ZPlayer::CenterSpeed (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_self,
  note='area 35 claim 3; returns this + 0x445')
S(0x483ea0, 'ZPlayer::GetSoundSet (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_self,
  note='area 35 claim 3; returns the dword at +0x60e')
S(0x44c220, 'ZSNDOBJ::Select (unknown) thiscall', 'thiscall', None, ret=None, gen=_select,
  note='area 35 claim 3; tail jump to 0x45fa00 (stubbed, logged)')
S(0x45fd20, 'ZGEOM::SetPos (unknown) thiscall', 'thiscall', None, ret=None, gen=_setpos,
  note='area 35 claim 3; tail jump to 0x4dcd10 on [this+8] (stubbed, logged)')
S(0x47bde0, 'ZActor::SetFootStepVolume (unknown) thiscall', 'thiscall', None, ret=None, gen=_self_arg,
  note='area 35 claim 3; stores the argument at +0x777')
S(0x4682e0, 'ZCTRLIKLNKOBJ::SetController (unknown) thiscall', 'thiscall', None, ret=None, gen=_self_arg,
  note='area 35 claim 3; stores the argument at +0x1d2')
