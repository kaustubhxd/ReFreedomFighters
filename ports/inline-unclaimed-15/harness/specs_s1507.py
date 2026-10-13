"""specs_s1507.py - unclaimed-15 claim 7 (docs/20-unclaimed-15.md): ZFFActor::~ZFFActor (0x59da20), scalar deleting.

Stubbed callees (unverified, not lifted): the base destructor 0x59d930 (thiscall, no args; serial_stubs.rec with 0 args) and
the two cdecl deletes 0x4690b0 (this, size) and 0x45c510 (this). The cdecl stubs store all their stack arguments in heap
dwords, so a wrong argument shows in the heap comparison. The objects are 0x200 random bytes. Flags come from
{0, 1, 4, 5, 2, random}: 1 and 5 take the delete branch, with 4 choosing the sized delete. Return value (this) is compared."""
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


def _cdecl_log(c, nargs):
    """cdecl stub: copies its nargs stack arguments into nargs heap dwords, returns with ret 0."""
    cell = c.emu.alloc(4 * nargs, 4)
    c.emu.wbytes(cell, bytes(4 * nargs))
    code = b''
    for i in range(nargs):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i])      # mov eax, [esp + 4 + 4i]
        code += b'\xa3' + ss.P(cell + 4 * i)               # mov [cell + 4i], eax
    code += b'\xc3'
    return ss.code(c, code)


def _zffdtor(c):
    o = _rnd(c, 0x200)
    ss.patch(c, 0x59d930, ss.rec(c, 0, ret=0))
    ss.patch(c, 0x4690b0, _cdecl_log(c, 2))
    ss.patch(c, 0x45c510, _cdecl_log(c, 1))
    return [o, c.rng.choice([0, 1, 4, 5, 2, c.rng.getrandbits(32)])]


S(0x59da20, 'ZFFActor::~ZFFActor (unknown) thiscall', 'thiscall', None, ret='eax', gen=_zffdtor,
  note='unclaimed-15 claim 7; base dtor 0x59d930, deletes 0x4690b0 (size 0x951) and 0x45c510 stubbed')
