"""specs_s3514.py - area 35 claim 14 (docs/20-unclaimed-35.md): six leaves in slice 14.

Stubbed (logged): 0x480980 and 0x561020 (thiscall, no arguments). The object at +0x6c has a logged vtable slot +0xc (three
arguments, ret 0xc); the object at +0x24 has a logged slot +0x14 (no arguments, returns a per-case value). The objects are
0x200 random bytes; the constructors' objects and the leaves' fields are compared in the heap. The counter for FUN_563d20 is
a heap dword set per case."""
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


def _counter(c):
    o = _rnd(c, 0x200)
    p = _rnd(c, 0x10)
    c.emu.w32(p, c.rng.getrandbits(32))
    return [o, c.rng.getrandbits(32), p, c.rng.getrandbits(32)]


def _args3(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _forward(c):
    o = _rnd(c, 0x200)
    inner = _rnd(c, 0x100)
    ivt = c.emu.logging_vtable('ZGuessInner', 0x40, impl={}, argwords={0xc: 4})   # four: this is pushed too
    c.emu.w32(inner, ivt)
    c.emu.w32(o + 0x6c, inner)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _diff(c):
    o = _rnd(c, 0x200)
    if c.rng.random() < 0.5:
        c.emu.w32(o + 0x24, 0)
    else:
        p = _rnd(c, 0x100)
        pvt = c.emu.logging_vtable('ZGuessDiff', 0x40, impl={0x14: lambda e, a, v=c.rng.getrandbits(32): (v, None)},
                                   argwords={0x14: 0})
        c.emu.w32(p, pvt)
        c.emu.w32(o + 0x24, p)
    return [o]


def _ctor(c):
    ss.patch(c, 0x480980, _thiscall_log(c, 0, 0))
    ss.patch(c, 0x561020, _thiscall_log(c, 0, 0))
    return [_rnd(c, 0x200)]


S(0x563d20, 'GUESS FUN_563d20 thiscall', 'thiscall', None, ret=None, gen=_counter,
  note='area 35 claim 14; decrement, signed compare with a1, store a3-1')
S(0x41e320, 'ZSysMem::RemoveRefController (unknown) thiscall', 'thiscall', None, ret=None, gen=_args3,
  note='area 35 claim 14; stores a3 at +8, a1 at +0xc, a2 at +0x10')
S(0x462f20, 'GUESS FUN_462f20 thiscall', 'thiscall', None, ret=None, gen=_forward,
  note='area 35 claim 14; slot +0xc of the object at +0x6c (logged; four arguments: this is pushed too)')
S(0x4cdd20, 'GUESS FUN_4cdd20 thiscall const', 'thiscall', None, ret='eax', gen=_diff,
  note='area 35 claim 14; this+0x14 minus slot +0x14 of the object at +0x24 (logged)')
S(0x480a20, 'GUESS FUN_480a20 thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='area 35 claim 14; 0x480980 stubbed; vtable 0x68b61c')
S(0x57c460, 'GUESS FUN_57c460 thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='area 35 claim 14; 0x561020 stubbed; vtable 0x6aa7b4')
