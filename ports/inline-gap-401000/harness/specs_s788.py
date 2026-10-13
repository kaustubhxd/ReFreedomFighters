"""specs_s788.py - gap band batch 788 (docs/20-gap-band-401000.md): 0x420270, thiscall (this, idx). The byte at this + 5*idx + 0xa0b is random;
the float at render+0x9c7 is the constant at 0x6785d0 in half the cases (so the compare is equal) and random otherwise; the vtable slot 0x1f8 of
this is a fake returning a per-case bool (one argument, callee pops 4). idx is 0 to 7 (the byte stays inside the block)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct


def _gen(c):
    konst = bytes(c.emu.rbytes(0x6785d0, 4))
    seed = c.rng.getrandbits(32)
    this = c.emu.alloc(0x2000, 4)
    c.emu.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x2000)))
    vt = c.emu.fake_vtable('g788-this', 0x400, {0x1f8: lambda e, r: (e.calllog.append(('0x1f8', e.arg32(0))), e.ret(eax=(seed >> (e.arg32(0) & 15)) & 1, argbytes=4))[-1]})
    c.emu.w32(this, vt)
    render = c.emu.alloc(0xa00, 4)
    c.emu.wbytes(render, bytes(c.rng.getrandbits(8) for _ in range(0xa00)))
    if c.rng.random() < 0.5:
        c.emu.wbytes(render + 0x9c7, konst)
    else:
        c.emu.wbytes(render + 0x9c7, struct.pack('<f', c.rng.uniform(-3, 3)))
    c.emu.w32(0x70039c, render)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)
    return [this, c.rng.randint(0, 7)]


S(0x420270, 'ZFF class flag 0x420270 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band batch 788: byte flag update, SSE compare, vtable call on the flag')
