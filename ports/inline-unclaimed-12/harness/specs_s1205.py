"""specs_s1205.py - unclaimed-12 batch 5 (docs/20-unclaimed-12.md, claim 5): CTelePortList::Init (two DBREAD reads through
the shared dbread_patch stubs) and ZActivateBinoculars::Init (a virtual call on the render object at the global 0x70039c+0x9b,
logged by a fake vtable). Both are thiscall with two stack arguments that are not read."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup_dbread(c):
    rets32 = [c.rng.getrandbits(32) for _ in range(8)]
    rets16 = [c.rng.getrandbits(16) for _ in range(8)]
    counts = [c.rng.randint(0, 40) for _ in range(8)]
    ss.dbread_patch(c, rets32, rets16, counts)


def _teleport(c):
    return [_rnd(c, 0x100), _rnd(c, 0x40), _rnd(c, 0x40)]


def _setup_binoc(c):
    # render object: [global]+0x9b points at an object whose vtable slot +0x114 (4 stack args) logs and returns a value
    ret_val = c.rng.getrandbits(32)
    vt = c.emu.logging_vtable('binoc-rm', 0x120, impl={0x114: lambda e, a: (ret_val, None)}, argwords={0x114: 4})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    rm = _rnd(c, 0x200)
    c.emu.w32(rm + 0x9b, obj)
    c.emu.w32(0x70039c, rm)


def _binoc(c):
    return [_rnd(c, 0x100), _rnd(c, 0x20), _rnd(c, 0x20)]


S(0x4b8330, 'CTelePortList::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_teleport,
  setup=_setup_dbread, note='unclaimed-12 batch 5; dword +0x4c and +0x50 from two DBREAD reads, +0x48 = 0; DBREAD stubs')
S(0x4c92d0, 'ZActivateBinoculars::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_binoc,
  setup=_setup_binoc, note='unclaimed-12 batch 5; word +0x48 = low word of [[0x70039c]+0x9b] slot +0x114 result')
