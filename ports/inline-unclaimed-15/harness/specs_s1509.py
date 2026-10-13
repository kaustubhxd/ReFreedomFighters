"""specs_s1509.py - unclaimed-15 claim 9 (docs/20-unclaimed-15.md): CImpactResponse::~CImpactResponse (0x5dc0e0).

The impact response is a 0x200-byte random object. Its member at +0x48 is null in half the cases; otherwise a logged
object whose slot 0 takes one argument. The render manager (global 0x70039c, +0x9b sub-object) has a logged slot +0x34
taking one argument. The CRT delete 0x4690b0 is a cdecl stub recording (this, size). The global hook at 0x7003b0 is always a
counting no-op (a null hook jumps to an int3 in the exe, so that state is not part of the game and is not tested).
Flags come from {0, 1, 4, 5, 2, random}. Return value (this) is compared."""
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


def _cdecl_log2(c):
    """cdecl (this, size) stub: stores the two stack arguments in two heap dwords, returns with ret 0."""
    cell = c.emu.alloc(8, 4)
    c.emu.wbytes(cell, bytes(8))
    code = (b'\x8b\x44\x24\x04' + b'\xa3' + ss.P(cell)
            + b'\x8b\x44\x24\x08' + b'\xa3' + ss.P(cell + 4)
            + b'\xc3')
    return ss.code(c, code)


def _dtor(c):
    o = _rnd(c, 0x200)
    if c.rng.random() < 0.5:
        member = _rnd(c, 0x200)
        mvt = c.emu.logging_vtable('ZImpactMember', 0x40, impl={0: lambda e, a: (0, None)}, argwords={0: 1})
        c.emu.w32(member, mvt)
        c.emu.w32(o + 0x48, member)
    else:
        c.emu.w32(o + 0x48, 0)
    rm = _rnd(c, 0x1000)
    robj = _rnd(c, 0x200)
    rvt = c.emu.logging_vtable('ZRenderSub', 0x100, impl={0x34: lambda e, a: (c.rng.getrandbits(32), None)},
                               argwords={0x34: 1})
    c.emu.w32(robj, rvt)
    c.emu.w32(rm + 0x9b, robj)
    c.emu.w32(0x70039c, rm)
    c.emu.w32(0x7003b0, ss.rec(c, 0, ret=0))
    ss.patch(c, 0x4690b0, _cdecl_log2(c))
    return [o, c.rng.choice([0, 1, 4, 5, 2, c.rng.getrandbits(32)])]


S(0x5dc0e0, 'CImpactResponse::~CImpactResponse (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-15 claim 9; member slot 0 logged; render slot +0x34 logged; delete size 0x80 stubbed')
