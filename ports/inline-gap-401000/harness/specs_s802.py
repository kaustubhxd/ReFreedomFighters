"""specs_s802.py - gap band batch 802 (docs/20-gap-band-401000.md): 0x4204e0, thiscall. The slot 0x16c of this (no args, logged) returns nothing used.
The record's bytes are random, so every zeroed field must show in the memory compare."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _gen(c):
    this = c.emu.alloc(0x2400, 4)
    c.emu.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x2400)))
    vt = c.emu.fake_vtable('g802', 0x200, {0x16c: lambda e, r: (e.calllog.append(('0x16c', e.reg('ecx'))), e.ret(eax=0, argbytes=0))[-1]})
    c.emu.w32(this, vt)
    return [this]


S(0x4204e0, 'ZFF class reset 0x4204e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  setup=lambda c: (c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000), c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)),
  note='gap band batch 802: zero the fields, then the vtable call')
