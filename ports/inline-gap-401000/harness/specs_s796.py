"""specs_s796.py - gap band batch 796 (docs/20-gap-band-401000.md): 0x420f40, thiscall. The slot 0x160 of this (one argument, callee pops 4)
writes a per-case value to its argument; the object at [0x70039c]+0x9b has slot 0xb8 returning a bool (AL). The float at this+0x48 is compared
bit-for-bit (single precision product)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    konst = bytes(c.emu.rbytes(0x6785e4, 4))
    if c.rng.random() < 0.5:
        c.emu.wbytes(0x6785e4, konst)   # (the constant is kept as it is)
    seed = c.rng.getrandbits(32)
    this_vt = c.emu.fake_vtable('g796-this', 0x200, {0x160: lambda e, r: (e.calllog.append(('0x160', e.reg('ecx'))),
                                                                          e.w32(e.arg32(0), (seed * 7) & 0xffffffff), e.ret(eax=0, argbytes=4))[-1]})
    obj_vt = c.emu.fake_vtable('g796-obj', 0x200, {0xb8: lambda e, r: (e.calllog.append(('0xb8',)), e.ret(eax=seed & 0x100, argbytes=0))[-1]})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, obj_vt)
    render = _rnd(c, 0xa00)
    c.emu.w32(render + 0x9b, obj)
    c.emu.w32(0x70039c, render)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    c.thisvt = this_vt


def _gen(c):
    this = _rnd(c, 0x100)
    c.emu.w32(this, c.thisvt)
    c.emu.w32(this + 0x40, c.rng.getrandbits(32))
    c.emu.w32(this + 0x44, c.rng.getrandbits(32))
    c.emu.w32(this + 0x4c, c.rng.getrandbits(32))
    return [this]


S(0x420f40, 'ZFF class float 0x420f40 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 796: slot 0x160 out value, optional copy, float difference times a constant')
