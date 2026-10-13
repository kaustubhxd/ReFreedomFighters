"""specs_s3509.py - area 35 claim 9 (docs/20-unclaimed-35.md): four leaves in slice 14.

Stubbed (unverified): this's vtable slot +0x84 (logged, no arguments, returns a per-case eax), the tail-jump target of
CWaves::FrameUpdate. The global at 0x6e7e1c is written per case (a random dword). The objects are 0x200 random bytes."""
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


def _waves(c):
    o = _rnd(c, 0x200)
    v = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('ZWaves', 0x40, impl={0x84: lambda e, a: (v, None)}, argwords={0x84: 0})
    c.emu.w32(o, vt)
    return [o]


def _global(c):
    c.emu.w32(0x6e7e1c, c.rng.getrandbits(32))
    return [_rnd(c, 0x200)]


def _self(c):
    return [_rnd(c, 0x200)]


S(0x5852e0, 'CWaves::FrameUpdate (unknown) thiscall', 'thiscall', None, ret='eax', gen=_waves,
  note='area 35 claim 9; tail jump to vtable slot +0x84 (logged)')
S(0x4f1860, 'ZActionMapZWINDOWSKEYS_3::GetActionDefinitions (unknown) thiscall', 'thiscall', None, ret='eax', gen=_global,
  note='area 35 claim 9; global dword at 0x6e7e1c')
S(0x607ce0, 'ZPrimControlBase::GetSizeOfLightSpot (unknown) thiscall const', 'thiscall', None, ret='eax', gen=_self,
  note='area 35 claim 9; returns 0x38')
S(0x428820, 'GUESS FUN_428820 thiscall', 'thiscall', None, ret='al', gen=_self,
  note='area 35 claim 9; byte +0x75 = 1, returns true')
