"""specs_s1508.py - unclaimed-15 claim 8 (docs/20-unclaimed-15.md): CActionController::~CActionController (0x49f7e0) and
CTargetObtained::~CTargetObtained (0x5c52a0).

The render manager (global 0x70039c) is a random 0x1000-byte object whose +0x9b holds a logged sub-object; its slot +0x34
is logged and returns a random eax. The global hook at 0x7003b0 is always a counting no-op stub (rec, 0 args); a null hook is not tested (see below). The
CRT delete 0x4690b0 is a cdecl stub that records its two arguments in heap dwords. The object is 0x200 random bytes.
Flags come from {0, 1, 4, 5, 2, random}: 1 takes the hook branch, 5 takes the sized delete. Return value (this) is compared."""
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
    rm = _rnd(c, 0x1000)
    robj = _rnd(c, 0x200)
    rvt = c.emu.logging_vtable('ZRenderSub', 0x100, impl={0x34: lambda e, a: (c.rng.getrandbits(32), None)},
                              argwords={0x34: 1})   # the exe pushes this before the call
    c.emu.w32(robj, rvt)
    c.emu.w32(rm + 0x9b, robj)
    c.emu.w32(0x70039c, rm)
    # The hook is always set: with bit 1 set and bit 4 clear, a null hook jumps to an int3 in the exe (0x49f869), so the
    # game never reaches that state and the spec does not test it.
    hook = ss.rec(c, 0, ret=0)
    c.emu.w32(0x7003b0, hook)
    ss.patch(c, 0x4690b0, _cdecl_log2(c))
    return [o, c.rng.choice([0, 1, 4, 5, 2, c.rng.getrandbits(32)])]


S(0x49f7e0, 'CActionController::~CActionController (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-15 claim 8; render slot +0x34 logged; hook 0x7003b0; delete size 0x8b4 stubbed')
S(0x5c52a0, 'CTargetObtained::~CTargetObtained (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-15 claim 8; render slot +0x34 logged; hook 0x7003b0; delete size 0x153 stubbed')
