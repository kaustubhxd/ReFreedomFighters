"""specs_s3505.py - area 35 claim 5 (docs/20-unclaimed-35.md): two leaves in slice 14.

Both objects have logged vtables: slot +4 (one argument, ret 4) for LINKREFTAB::AddEnd and slot +0x308 (no arguments, ret 0)
for the GUESS leaf. Slot results are per-case. The GUESS leaf's two stack arguments are random and not read."""
import os
import struct
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


def _addend(c):
    o = _rnd(c, 0x100)
    v = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('ZLinkRefTab', 0x40, impl={4: lambda e, a: (v, None)}, argwords={4: 1})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32)]


def _guess(c):
    o = _rnd(c, 0x100)
    v = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('ZGuessObj', 0xc8, impl={0x308: lambda e, a: (v, None)}, argwords={0x308: 0})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4cd6e0, 'LINKREFTAB::AddEnd (unknown) thiscall', 'thiscall', None, ret='eax', gen=_addend,
  note='area 35 claim 5; tail jump to vtable slot +4 (logged, one argument)')
S(0x4fa320, 'GUESS FUN_004fa320 thiscall', 'thiscall', None, ret='al', gen=_guess,
  note='area 35 claim 5; calls vtable slot +0x308 (logged), returns true, ret 8')
