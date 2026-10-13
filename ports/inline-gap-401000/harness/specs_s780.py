"""specs_s780.py - gap band batch 780 (docs/20-gap-band-401000.md): 0x41ee90, thiscall (this, v). The object X at this+4 has a virtual slot 4
returning a small hash h (0..0x3f); its field at +0x10 is random, so the index (field & h) stays inside the 0x100-byte array at this+0x28.
G (0x70038c) is an object with slot 0x2c (three args, logged) in half the cases, else 0."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _gen(c):
    h = c.rng.randint(0, 0x3f)
    X_vt = c.emu.fake_vtable('g780-x', 0x100, {0x4: lambda e, r: (e.calllog.append(('0x4',)), e.ret(eax=h, argbytes=0))[-1]})
    X = c.emu.alloc(0x40, 4)
    c.emu.w32(X, X_vt)
    c.emu.w32(X + 0x10, c.rng.getrandbits(32))
    self_ = c.emu.alloc(0x40, 4)
    c.emu.w32(self_ + 4, X)
    arr = c.emu.alloc(0x100, 4)
    c.emu.wbytes(arr, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    c.emu.w32(self_ + 0x28, arr)
    if c.rng.random() < 0.5:
        G_vt = c.emu.fake_vtable('g780-g', 0x100, {0x2c: lambda e, r: (e.calllog.append(('0x2c', tuple(e.arg32(k) for k in range(3)))),
                                                                       e.ret(eax=0, argbytes=12))[-1]})
        G = c.emu.alloc(0x40, 4)
        c.emu.w32(G, G_vt)
        c.emu.w32(0x70038c, G)
    else:
        c.emu.w32(0x70038c, 0)
    return [self_, c.rng.getrandbits(32)]


S(0x41ee90, 'CRT helper 0x41ee90 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen, setup=lambda c: (c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000), c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)),
  note='gap band batch 780: store into a hashed slot, notify the global object')
