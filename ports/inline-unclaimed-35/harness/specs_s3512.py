"""specs_s3512.py - area 35 claim 12 (docs/20-unclaimed-35.md): four leaves in slice 14.

The objects are 0x2000 random bytes with logged vtables whose slots take no arguments (+0x24, +0x28, +0x70, +0x358). The
fields written are all inside the object (the largest is +0x1b59). FUN_61c5a0 is cdecl (pilot's 'cdecl' ABI)."""
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


def _obj(c, slots):
    o = _rnd(c, 0x2000)
    vt = c.emu.logging_vtable('ZGuessChain', 0x200, impl={}, argwords={s: 0 for s in slots})
    c.emu.w32(o, vt)
    return o


def _three(c):
    return [_obj(c, []), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _bar(c):
    return [_obj(c, [0x358]), c.rng.getrandbits(32)]


def _cdecl(c):
    return [_rnd(c, 0x2000), c.rng.getrandbits(32)]


def _chain(c):
    return [_obj(c, [0x70, 0x24, 0x28])]


S(0x42f8a0, 'GUESS FUN_42f8a0 thiscall', 'thiscall', None, ret=None, gen=_three,
  note='area 35 claim 12; byte +0x1b59 = 1; dword +0x1b49 = a0')
S(0x4fa6e0, 'ZScrollbar::SetBarSize (unknown) thiscall', 'thiscall', None, ret=None, gen=_bar,
  note='area 35 claim 12; dword +0xab = a1; slot +0x358 (logged)')
S(0x61c5a0, 'GUESS FUN_61c5a0 cdecl', 'cdecl', None, ret=None, gen=_cdecl,
  note='area 35 claim 12; cdecl; dword +0x50 = a1; dword +0x128 = 0')
S(0x431f60, 'GUESS FUN_431f60 thiscall', 'thiscall', None, ret=None, gen=_chain,
  note='area 35 claim 12; slots +0x70, +0x24, +0x28 (logged)')
