"""specs_s3506.py - area 35 claim 6 (docs/20-unclaimed-35.md): ZActor::EnableMovePool (0x478460).

The actor (self) is 0x1000 random bytes with a logged vtable: slot +0x20 returns an object O (logged, no arguments). O has a
logged vtable: slot +0x80 (two arguments). The render manager's sub-object has a logged slot +0x4c (one argument) that returns
R, a per-case value. The pool object G (global 0x7003b8) has a count of 0..5 at +0x4b0 and that many entry pointers at +0x4b4;
each entry points to a 0x10-byte object whose first dword is random, and in half the cases one entry's dword is set to R
(so the found path runs). The enable byte is random. The loop bound is the count (0x12d * 4 == 0x4b4), so entries beyond
the count are random bytes that are never read."""
import os
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
    import struct
    cells = c.emu.alloc(4 * (1 + nargs), 4)
    c.emu.wbytes(cells, bytes(4 * (1 + nargs)))
    code = b'\x89\x0d' + ss.P(cells)
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + ss.P(cells + 4 + 4 * i)
    code += b'\xb8' + ss.P(ret) + b'\xc2' + struct.pack('<H', 4 * nargs)
    return ss.code(c, code)


def _enable(c):
    self_obj = _rnd(c, 0x1000)
    o = _rnd(c, 0x100)
    ovt = c.emu.logging_vtable('ZMovePoolObj', 0x40, impl={}, argwords={0x80: 2})
    c.emu.w32(o, ovt)
    rval = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('ZActorPool', 0x40, impl={0x20: lambda e, a: (o, None)}, argwords={0x20: 0})
    c.emu.w32(self_obj, vt)
    sub = _rnd(c, 0x200)
    subvt = c.emu.fake_vtable('ZMovePoolRender', 0x140, {0x4c: _thiscall_log(c, 1, rval)})
    c.emu.w32(sub, subvt)
    rm = _rnd(c, 0x1000)
    c.emu.w32(rm + 0x9b, sub)
    c.emu.w32(0x70039c, rm)
    n = c.rng.randrange(0, 6)
    g = _rnd(c, 0x4b4 + 4 * 8 + 0x40)
    c.emu.w32(g + 0x4b0, n)
    planted = c.rng.randrange(n) if n and c.rng.random() < 0.5 else -1
    for i in range(n):
        e = _rnd(c, 0x10)
        c.emu.w32(e, rval if i == planted else c.rng.getrandbits(32))
        c.emu.w32(g + 0x4b4 + 4 * i, e)
    c.emu.w32(0x7003b8, g)
    return [self_obj, c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])]


S(0x478460, 'ZActor::EnableMovePool (unknown) thiscall', 'thiscall', None, ret=None, gen=_enable,
  note='area 35 claim 6; slot +0x20 (no args), render slot +0x4c (logged), slot +0x80 of the object (logged)')
