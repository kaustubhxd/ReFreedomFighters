"""specs_s1612.py - unclaimed-16 batch 12 (docs/20-unclaimed-16.md): CAction::UpdateObjectsInRange. The object has 0 to 4
items (pointers from +0x82, count at +0x7e); each item has a logging vtable (slot 0x84 returns a chosen byte, one
argument) and a sub-object at +0x44 with a logging vtable (slot 0x128, three arguments). The word 0x7002c8 is random. The
callees 0x4a02e0 and 0x4a01c0 are patched to recording stubs (one argument); they are NOT verified."""
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


def _item(c):
    it = _rnd(c, 0x100)
    ret = c.rng.choice([0, 1, 0x100, 0x101, c.rng.getrandbits(32)])
    c.emu.w32(it, c.emu.logging_vtable('item', 0x100, impl={0x84: lambda e, a, v=ret: (v, None)},
                                       argwords={0x84: 1}))
    sub = _rnd(c, 0x100)
    c.emu.w32(sub, c.emu.logging_vtable('sub', 0x100, argwords={0x128: 3}))
    c.emu.w32(it + 0x44, sub)
    c.emu.wbytes(it + 0x5a, bytes([c.rng.choice([0, 1, 2, 3, 0xff, c.rng.getrandbits(8)])]))
    c.emu.wbytes(it + 0x63, bytes([c.rng.choice([0, 0, 1, 2, c.rng.getrandbits(8)])]))
    return it


def _upd(c):
    ss.patch(c, 0x4a02e0, ss.rec(c, 1))
    ss.patch(c, 0x4a01c0, ss.rec(c, 1))
    c.emu.w16(0x7002c8, c.rng.getrandbits(16))
    obj = _rnd(c, 0x200)
    n = c.rng.choice([0, 1, 1, 2, 3, 4])
    c.emu.w32(obj + 0x7e, n)
    for i in range(n):
        c.emu.w32(obj + 0x82 + 4 * i, _item(c))
    a1 = 0 if c.rng.random() < 0.12 else c.rng.getrandbits(32) | 1
    return [obj, a1]


S(0x4a20e0, 'CAction::UpdateObjectsInRange (unknown) thiscall', 'thiscall', None, ret=None, gen=_upd,
  note='unclaimed-16 b12; loop over items +0x82, slot 0x84 then slot 0x128; 0x4a02e0 or 0x4a01c0 stubbed')
