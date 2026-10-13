"""specs_s783.py - gap band batch 783 (docs/20-gap-band-401000.md): 0x4205a0, thiscall. The global 0x700390 has slot 0x20 (two args, callee
pops 8; returns the object X); X has slot 0x2c (caller-cleaned, two args) that logs its arguments and the 0x80 bytes the exe copied onto
the stack (the copy is at esp+12 inside the callee). The branch on this+0x22c2 is random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    def s2c(e, r):
        buf = e.rbytes((e.reg('esp') + 12) & 0xffffffff, 0x80)
        e.calllog.append(('0x2c', tuple(e.arg32(k) for k in range(2)), buf))
        e.ret(eax=0, argbytes=0)
    X_vt = c.emu.fake_vtable('g783-x', 0x100, {0x2c: s2c})
    X = _rnd(c, 0x40)
    c.emu.w32(X, X_vt)
    G_vt = c.emu.fake_vtable('g783-g', 0x100, {0x20: lambda e, r: (e.calllog.append(('0x20', tuple(e.arg32(k) for k in range(2)))),
                                                                 e.ret(eax=X, argbytes=8))[-1]})
    G = _rnd(c, 0x40)
    c.emu.w32(G, G_vt)
    c.emu.w32(0x700390, G)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    self_ = _rnd(c, 0x2400)
    c.emu.w32(self_ + 0x22c2, c.rng.choice([0, 1, 5]))
    return [self_]


S(0x4205a0, 'CRT helper 0x4205a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 783: flag set, object slot 0x20, 0x80-byte copy, slot 0x2c with the leftover ecx')
