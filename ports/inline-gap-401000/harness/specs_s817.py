"""specs_s817.py - core batch 817 (docs/20-unclaimed-65.md). 0x438790 and 0x4fdd10 are thiscall, no arguments: a decrement of the dword at
+0x120c and a byte store at +0x69. 0x51cad0 is a tail jump through slot 0x360 of the vtable of the object in ecx; the spec's fake slot
(a bare return that logs ecx and pops nothing, GUESS) returns zero. The object is random with a fake vtable of size 0x400."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_obj(c):
    return [_rnd(c, 0x1300)]


def _gen_tail(c):
    vt = c.emu.fake_vtable('c817-360', 0x400, {
        0x360: lambda e, r: (e.calllog.append(('0x360', e.reg('ecx'))), e.ret(eax=0, argbytes=0))[-1]})
    o = _rnd(c, 0x40)
    c.emu.w32(o, vt)
    return [o]


S(0x438790, 'core method 0x438790 (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen_obj,
  note='core batch 817: decrement the dword at +0x120c')


S(0x4fdd10, 'core method 0x4fdd10 (unknown) thiscall no args', 'thiscall', None, ret=None, gen=_gen_obj,
  note='core batch 817: set the byte at +0x69')


S(0x51cad0, 'core method 0x51cad0 (unknown) thiscall tail jump slot 0x360', 'thiscall', None, ret='eax', gen=_gen_tail,
  note='core batch 817: tail jump through the vtable slot 0x360 (hooked)')
