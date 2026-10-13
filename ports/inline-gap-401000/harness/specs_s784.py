"""specs_s784.py - gap band batch 784 (docs/20-gap-band-401000.md): 0x41f3a0, thiscall. The node list at this+0x18 has 0 to 3 nodes (each node's
first dword is the next node); the object at this+0x31 has a first dword that is zero in half the cases. The slot 0x88 of this logs each
node; 0x700390 slot 0x20 returns X; X slot 0x2c (caller-cleaned, three args) logs its arguments and ecx."""
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
    X_vt = c.emu.fake_vtable('g784-x', 0x100, {0x2c: lambda e, r: (e.calllog.append(('0x2c', e.reg('ecx'), tuple(e.arg32(k) for k in range(3)))),
                                                                   e.ret(eax=0, argbytes=0))[-1]})
    X = _rnd(c, 0x40)
    c.emu.w32(X, X_vt)
    G_vt = c.emu.fake_vtable('g784-g', 0x100, {0x20: lambda e, r: (e.calllog.append(('0x20', tuple(e.arg32(k) for k in range(2)))),
                                                                 e.ret(eax=X, argbytes=8))[-1]})
    G = _rnd(c, 0x40)
    c.emu.w32(G, G_vt)
    c.emu.w32(0x700390, G)
    c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000)
    c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)


def _gen(c):
    self_ = _rnd(c, 0x80)
    vt = c.emu.fake_vtable('g784-this', 0x200, {0x88: lambda e, r: (e.calllog.append(('0x88', e.reg('ecx'), (e.arg32(0),))), e.ret(eax=0, argbytes=4))[-1]})
    c.emu.w32(self_, vt)
    nodes = [_rnd(c, 0x10) for _ in range(c.rng.randint(0, 3))]
    nxt = 0
    for nd in reversed(nodes):
        c.emu.w32(nd, nxt)
        nxt = nd
    c.emu.w32(self_ + 0x18, nxt)
    o = _rnd(c, 0x20)
    c.emu.w32(o, c.rng.choice([0, c.rng.getrandbits(32) | 1]))
    c.emu.w32(self_ + 0x31, o)
    return [self_]


S(0x41f3a0, 'CRT helper 0x41f3a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, setup=_setup,
  note='gap band batch 784: release each node through slot 0x88, then the object notification')
