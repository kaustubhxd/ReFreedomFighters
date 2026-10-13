"""specs_s3515.py - area 35 claim 15 (docs/20-unclaimed-35.md): five leaves in slice 14.

Stubbed: 0x561020 (thiscall, no args, logged); the objects' vtable slots +0xc (two arguments, logged) and +4 (no arguments,
logged). The objects are 0x5400 random bytes so the field at +0x52fe is inside; the tree group's entries (+0x5d + 4*a, a in
0..3) point to 0x100-byte objects with a logged slot +0xc. The object at +0x52fe is null in half of the cases."""
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


def _tree(c):
    o = _rnd(c, 0x200)
    a = c.rng.randrange(0, 4)
    child = _rnd(c, 0x100)
    cvt = c.emu.logging_vtable('ZTreeEntry', 0x40, impl={}, argwords={0xc: 2})
    c.emu.w32(child, cvt)
    c.emu.w32(o + a * 4 + 0x5d, child)
    return [o, a, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _one(c):
    return [_rnd(c, 0x200), c.rng.choice([0, 1, c.rng.getrandbits(32)])]


def _history(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


def _ctor(c):
    ss.patch(c, 0x561020, _thiscall_log(c, 0, 0))
    return [_rnd(c, 0x200)]


def _sound(c):
    o = _rnd(c, 0x5400)
    if c.rng.random() < 0.5:
        child = _rnd(c, 0x100)
        cvt = c.emu.logging_vtable('ZSoundGraph', 0x40, impl={}, argwords={4: 0})
        c.emu.w32(child, cvt)
        c.emu.w32(o + 0x52fe, child)
    else:
        c.emu.w32(o + 0x52fe, 0)
    return [o]


S(0x443c60, 'ZTreeGroup::RemoveGlobalBound (unknown) thiscall', 'thiscall', None, ret=None, gen=_tree,
  note='area 35 claim 15; slot +0xc of the entry at +0x5d+4a (logged, two arguments)')
S(0x43e620, 'ZHELPER::DispText (unknown) thiscall', 'thiscall', None, ret=None, gen=_one,
  note='area 35 claim 15; bit 0x10 of +0x18 by the argument')
S(0x4c2ba0, 'ZMusicControl::SetHistory (unknown) thiscall', 'thiscall', None, ret=None, gen=_history,
  note='area 35 claim 15; +0x1cb = old +0x1cf; +0x1cf = argument')
S(0x561160, 'CDifficultySetting::CDifficultySetting (unknown) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='area 35 claim 15; 0x561020 stubbed; vtable 0x6a63bc')
S(0x5379a0, 'ZDllSound::InitializeSoundGraph (unknown) thiscall', 'thiscall', None, ret=None, gen=_sound,
  note='area 35 claim 15; tail jump to slot +4 of the object at +0x52fe (logged)')
