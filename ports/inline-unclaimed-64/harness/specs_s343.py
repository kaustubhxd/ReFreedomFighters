"""specs_s343.py - decomp area 64 (docs/20-unclaimed-64.md): 0x4dc630 flag merge; exe helpers 0x4d9d20, 0x4da770, 0x4da360,
0x4dbb00, 0x4db840 are patched to stubs; global child slots 0x178, 0x40 and X slots 0x24, 0x28 are logging stubs."""
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


def _ctl(c):
    e = c.emu
    # Exe helpers: plain returns with the arity of their call sites (0x4d9d20, 0x4da770, 0x4dbb00: one word; 0x4da360: two).
    # 0x4db840 returns a per-case eax (it decides which branch runs).
    r = c.rng.choice([0x800000, 0xa00000, 0x200000, 0x0, 0x800000 | 0x200000])
    # 0x4d9d20 and 0x4da770 bump a heap counter each (inc dword [cnt]), so a missing or extra call shows in the compare.
    cnt = e.alloc(8, 4)
    e.wbytes(cnt, bytes(8))
    ss.patch(c, 0x4d9d20, ss.code(c, b'\xff\x05' + ss.P(cnt) + b'\xb8' + ss.P(0) + b'\xc2\x04\x00'))
    ss.patch(c, 0x4da770, ss.code(c, b'\xff\x05' + ss.P(cnt + 4) + b'\xb8' + ss.P(0) + b'\xc2\x04\x00'))
    ss.patch(c, 0x4dbb00, ss.code(c, b'\xb8' + ss.P(0) + b'\xc2\x04\x00'))
    ss.patch(c, 0x4da360, ss.code(c, b'\xb8' + ss.P(0) + b'\xc2\x08\x00'))
    ss.patch(c, 0x4db840, ss.code(c, b'\xb8' + ss.P(r) + b'\xc3'))

    # Global child: slot 0x178 and 0x40 return al (per case); X = child[+0x5d35] with slots 0x24 and 0x28.
    rv178 = 1 if c.rng.random() < 0.3 else 0
    rv40 = 1 if c.rng.random() < 0.7 else 0
    X_vt = e.logging_vtable('X4dc6', 0x60, argwords={0x24: 1, 0x28: 1}, impl={0x24: lambda em, a: (0x1357, None), 0x28: lambda em, a: (0, None)})
    X = _rnd(c, 0x40)
    e.w32(X, X_vt)
    child_vt = e.logging_vtable('child4dc6', 0x180, argwords={}, impl={0x178: lambda em, a: (rv178, None), 0x40: lambda em, a: (rv40, None)})
    child = _rnd(c, 0x5d40)
    e.w32(child, child_vt)
    if c.rng.random() < 0.85:
        e.w32(child + 0x5d35, X)
    else:
        e.w32(child + 0x5d35, 0)
    sys_ = _rnd(c, 0x100)
    e.w32(sys_ + 0x9b, child)
    e.w32(0x70039c, sys_)

    # self: flags word with random bits (the test bits 0x2000, 0x8000, 0x8008000 and 0x1000000 come up), a list of 0-3 nodes,
    # and a result word.
    self_ = _rnd(c, 0x80)
    e.w32(self_ + 0x3c, c.rng.getrandbits(32))
    e.w32(self_ + 0x6c, c.rng.choice([0, 1, 7]))
    nodes = []
    for _ in range(c.rng.randrange(0, 4)):
        n = _rnd(c, 0x60)
        nodes.append(n)
    prev = 0
    for n in reversed(nodes):
        e.w32(n + 0x50, prev)
        prev = n
    e.w32(self_ + 0x50, prev)

    a = c.rng.getrandbits(32)
    b = c.rng.getrandbits(32)
    return [self_, a, b]


S(0x4dc630, 'setControl (GUESS)', 'thiscall', None, ret=None, gen=_ctl,
  note='batch343; two stack words a, b; ret 8; exe helpers 0x4d9d20, 0x4da770, 0x4da360, 0x4dbb00, 0x4db840 stubbed (both sides)')
