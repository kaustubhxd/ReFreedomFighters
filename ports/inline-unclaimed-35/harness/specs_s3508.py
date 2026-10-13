"""specs_s3508.py - area 35 claim 8 (docs/20-unclaimed-35.md): six plain leaves in slice 14. No stubs: no calls are made.
The objects are 0x200 random bytes, so every field the leaves read or write is inside them and is compared in the heap."""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _self(c):
    return [_rnd(c, 0x200)]


def _self_arg(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


S(0x41eaa0, 'GUESS FUN_41eaa0 thiscall', 'thiscall', None, ret=None, gen=_self,
  note='area 35 claim 8; decrements dword +0x49')
S(0x428fa0, 'GUESS FUN_428fa0 thiscall', 'thiscall', None, ret='eax', gen=_self,
  note='area 35 claim 8; returns this+0xd')
S(0x4d8c20, 'CConsoleCommand::Name (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_self,
  note='area 35 claim 8; returns this+4')
S(0x5f2de0, 'SerialInfo_t::getCurrentOffset (unknown) thiscall', 'thiscall', None, ret='eax', gen=_self,
  note='area 35 claim 8; dword at +8')
S(0x449660, 'ZLIGHT::SetCanChangePosition (unknown) thiscall', 'thiscall', None, ret=None, gen=_self,
  note='area 35 claim 8; OR 0x10 into dword +0x18')
S(0x45e920, 'ZGEOM::GetActionID (unknown) thiscall', 'thiscall', None, ret='eax', gen=_self_arg,
  note='area 35 claim 8; returns -1')
