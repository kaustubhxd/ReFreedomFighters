"""specs_s3511.py - area 35 claim 11 (docs/20-unclaimed-35.md): four GUESS-named leaves in slice 14.

The objects are 0x200 random bytes with logged vtables: slot +0x24 (two arguments, ret 8) and slot +0x28 (one argument,
ret 4). FUN_61bce0 is cdecl: the object is its first stack argument (pilot's 'cdecl' ABI)."""
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


def _obj(c):
    o = _rnd(c, 0x200)
    vt = c.emu.logging_vtable('ZGuessSlots', 0x40, impl={}, argwords={0x24: 2, 0x28: 1})
    c.emu.w32(o, vt)
    return o


def _pair(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _store_pair(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _one(c):
    return [_obj(c), c.rng.getrandbits(32)]


def _cdecl(c):
    return [_obj(c), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x524760, 'GUESS FUN_524760 thiscall', 'thiscall', None, ret=None, gen=_store_pair,
  note='area 35 claim 11; stores the two arguments at +0x18 and +0x1c')
S(0x499a20, 'GUESS FUN_499a20 thiscall', 'thiscall', None, ret='eax', gen=_one,
  note='area 35 claim 11; slot +0x28 (logged), returns this')
S(0x600260, 'GUESS FUN_600260 thiscall', 'thiscall', None, ret=None, gen=_pair,
  note='area 35 claim 11; stores a1 at +4 and a1+a2 at +8')
S(0x61bce0, 'GUESS FUN_61bce0 cdecl', 'cdecl', None, ret=None, gen=_cdecl,
  note='area 35 claim 11; cdecl; slot +0x24 (logged) on the first argument')
