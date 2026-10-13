"""specs_s3513.py - area 35 claim 13 (docs/20-unclaimed-35.md): three leaves in slice 14.

Stubbed (unverified): the hook at 0x7003b0 (a counting no-op, always set: a null hook reaches an int3 in the exe), 0x4d0c00 (thiscall, no arguments, logged
ecx). The objects: ZBigFile::Add takes four stack arguments (random); ReserveTexture's object is 0x23000 random bytes so the
field at +0x22030 is inside it, with the value drawn from {0x3d, 0x3e, random}; FUN_41f9a0's object holds a pointer at +0x31."""
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


def _bigfile(c):
    # The hook is always set: with it null, the exe jumps to an int3 at 0x4d4dae (the game never reaches that state).
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=0))
    return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _texture(c):
    o = _rnd(c, 0x23000)
    c.emu.w32(o + 0x22030, c.rng.choice([0x3d, 0x3e, c.rng.getrandbits(32)]))
    return [o]


def _tail(c):
    ss.patch(c, 0x4d0c00, _thiscall_log(c, 0, 0))
    o = _rnd(c, 0x200)
    p = _rnd(c, 0x100)
    c.emu.w32(o + 0x31, p)
    return [o]


S(0x4d4da0, 'ZBigFile::Add (unknown) thiscall', 'thiscall', None, ret=None, gen=_bigfile,
  note='area 35 claim 13; hook at 0x7003b0 (rec stub or null); four arguments')
S(0x613360, 'ZTextureManagerGC::ReserveTexture (unknown) thiscall', 'thiscall', None, ret='al', gen=_texture,
  note='area 35 claim 13; compare dword +0x22030 with 0x3d and 0x3e')
S(0x41f9a0, 'GUESS FUN_41f9a0 thiscall', 'thiscall', None, ret=None, gen=_tail,
  note='area 35 claim 13; tail jump to 0x4d0c00 (stubbed, logged) with this = [this+0x31]')
